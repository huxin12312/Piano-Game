#pragma warning(disable:4996)

#include "WaveManager.h"
#include <algorithm>

namespace {
    /// wave & PCM marks
    #define WAVE_FILE_MARK          "RIFF"
    #define WAVE_HEAD_MARK          "WAVEfmt "
    #define WAVE_DATA_MARK          "data"
    #define WAVE_PCM_16             16
    #define WAVE_PCM_1               1

    /// wfx header offsets
    #define OFFSET_FILE_LEFT         4
    #define OFFSET_HEAD_MARK         8
    #define OFFSET_WAVE_PCM1        16
    #define OFFSET_WAVE_PCM2        20
    #define OFFSET_CHANNELS         22
    #define OFFSET_SAMPLESPERSEC    24
    #define OFFSET_AVGBYTESPERSEC   28
    #define OFFSET_BLOCKALIGN       32
    #define OFFSET_BITSPERSAMPLE    34
    #define OFFSET_DATA_MARK        36
    #define OFFSET_DATA_SIZE        40
    #define OFFSET_WAVEDATA         44
    #define HEADER_SIZE             OFFSET_WAVEDATA
    #define EOF_EXTRA_INFO          60

    /// buffering
    #define READ_BLOCK           32768       // read wave ( file ) block size

    bool GetWaveResourceData(const char* name, char*& ptr, unsigned long& size) {
        HRSRC hrsrc = FindResource(NULL, name, "WAVE");
        if (hrsrc == NULL) {
            return false;
        }
        HGLOBAL handle = LoadResource(NULL, hrsrc);
        if (handle == NULL) {
            return false;
        }
        ptr = static_cast<char*>(LockResource(handle));
        size = SizeofResource(NULL, hrsrc);
        return true;
    }
}
CRITICAL_SECTION WaveManager::cs;

WaveManager::DevInterface::DevInterface() :
        handle(0), isInUse(false) {
    ZeroMemory(&CurWave, sizeof(WAVEHDR));
}

WaveManager::WaveInfo::WaveInfo() :
        data(nullptr), size(0), isWaiting(true) {
    ZeroMemory(&wfx, sizeof(WAVEFORMATEX));
}

WaveManager::WaveInfo::~WaveInfo() {
    if (data != nullptr)
        delete [] data;
}

WaveManager::WaveManager(size_t maxSimWaves) :
    m_Dev( maxSimWaves )
{ 
    // thread suspended < used for resuming thread at first play >
    m_RunThread = 0;

    // create suspended player thread
	m_ThreadWakeUp = CreateEvent(NULL, false,false,NULL);    
	m_Thread  = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)PlayThread, (LPVOID)this, CREATE_SUSPENDED, NULL);
    
    InitializeCriticalSection( &cs );

}

WaveManager::~WaveManager()
{
	if( m_RunThread ) // thread resumed
	{
		// set thread close message
		EnterCriticalSection( &cs );
        isClosing = true;
		LeaveCriticalSection( &cs );
		SetEvent(m_ThreadWakeUp);
        WaitForSingleObject( m_Thread, INFINITE);
	} else {
		TerminateThread( m_Thread, 0 );
	}

	DeleteCriticalSection( &cs );
	CloseHandle(m_ThreadWakeUp);
	CloseHandle(m_Thread);
}

template<typename T>
int WaveManager::LoadWave( unsigned int waveId, T hFile, const std::function<int(T, char*, size_t, size_t*)>& fnRead )
{
    // read wave header
    char    header[HEADER_SIZE];
    size_t rbytes  = 0;
    
    if( ! fnRead(hFile, header, sizeof(header), &rbytes) )
        return -1;

    if( !rbytes || rbytes < sizeof(header) )
        return -1;

    /// check if this is a wave file
    if( strncmp( header, WAVE_FILE_MARK, strlen( WAVE_FILE_MARK )) )
        return -1;

    if( strncmp( header + OFFSET_HEAD_MARK, WAVE_HEAD_MARK, strlen( WAVE_HEAD_MARK )) )
        return -1;

    /// check if wave is uncompressed PCM format
    if (((*(DWORD*)(header + OFFSET_WAVE_PCM1)) != WAVE_PCM_16 ) || ((*(WORD *)(header + OFFSET_WAVE_PCM2)) != WAVE_PCM_1  ))
        return -1;

    EnterCriticalSection( &cs );

    m_Waves[waveId] = WaveInfo();
    WaveInfo& wav = m_Waves[waveId];

    /// check for 'data' mark
    if( !strncmp( header + OFFSET_DATA_MARK, WAVE_DATA_MARK, strlen( WAVE_DATA_MARK )) )
        wav.size = *((DWORD*)(header + OFFSET_DATA_SIZE ));                // size of data   
    else
    {   /// if data block size cant be read
        /// try to predict data block without extra info
        /// this is unusualy case
        wav.size  = *((DWORD*)(header + OFFSET_FILE_LEFT ));  
        wav.size -=  ( HEADER_SIZE - EOF_EXTRA_INFO );             // size of data 
    }

    // fill WAVEFORMATEX from wave header
    wav.wfx.nSamplesPerSec  = *((DWORD*)(header + OFFSET_SAMPLESPERSEC )); // sample rate 
    wav.wfx.wBitsPerSample  = *((WORD *)(header + OFFSET_BITSPERSAMPLE )); // sample size 
    wav.wfx.nChannels       = *((WORD *)(header + OFFSET_CHANNELS      )); // channels    
    wav.wfx.cbSize          = 0;                                           // size of _extra_ info 
    wav.wfx.wFormatTag      = WAVE_FORMAT_PCM;
    wav.wfx.nBlockAlign     = *((WORD *)(header + OFFSET_BLOCKALIGN    ));
    wav.wfx.nAvgBytesPerSec = *((DWORD*)(header + OFFSET_AVGBYTESPERSEC));

    // get mem for wave data block
    wav.data = new char[ wav.size ];

    char buffer[READ_BLOCK];
    
    unsigned long   size         = m_Waves[waveId].size; 
    unsigned long   read_block   = 0;
                    rbytes       = 0;
                      
    do  /// copy uncompressed PCM wave data block
    {
        if( ( size -= rbytes ) >= READ_BLOCK )  
            read_block = READ_BLOCK;
        else if( size && size < READ_BLOCK )
            read_block = size;
        else
            break;

        if( ! fnRead(hFile, buffer, read_block, &rbytes) )
            break;
        if( rbytes == 0 )
            break;
        if( rbytes < sizeof(buffer) ) 
            std::fill(buffer + rbytes, buffer + sizeof(buffer), 0);
        
        std::copy( buffer, buffer + rbytes, &wav.data[wav.size - size]);

    } while( 1 );    
    
    LeaveCriticalSection( &cs );
    // return current wave count
    return 1;
}

int WaveManager::Load(unsigned int waveId, char *file )
{
    HANDLE hFile;
    if((hFile = CreateFile( file, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL )) == INVALID_HANDLE_VALUE)   
        return -1;

    int out = LoadWave<HANDLE>( waveId, hFile, 
        [&](HANDLE hnd, char* buff, size_t nBytesToRead, size_t* bytesRead)->int {
            DWORD dwBytesRead = 0;
            int result = ReadFile(hnd, static_cast<LPVOID>(buff), static_cast<DWORD>(nBytesToRead), static_cast<LPDWORD>(&dwBytesRead), NULL);
            *bytesRead = static_cast<size_t>(dwBytesRead);
            return static_cast<int>(result);
        }
    );

    CloseHandle(hFile);
    return out;
}

struct Buffer {
    Buffer(char* p, size_t sz) : data(p), pos(0), n(sz) {}

    char* data;
    size_t pos;
    size_t n;
};

int WaveManager::LoadFromResource(unsigned int waveId, char* rsrc)
{ 
    char* pRsrcData;
    unsigned long sz;
    GetWaveResourceData(rsrc, pRsrcData, sz);

    Buffer buff(pRsrcData, sz);
    int out = LoadWave<Buffer>( waveId, buff, 
        [&](Buffer src, char* dst, size_t numBytesToRead, size_t* bytesRead)->int {
            size_t spaceLeft = src.n - src.pos;
            size_t n = (numBytesToRead <= spaceLeft) ? numBytesToRead : spaceLeft;
            std::copy( src.data + src.pos, src.data + src.pos + n, dst );
            *bytesRead = n;
            return 1;
        }
    );

    return 0;
}

int WaveManager::Play(unsigned int waveId )
{
    // check wave id
    if( m_Waves.find(waveId) == m_Waves.end() )
        return -1;
    
    // set play message
    EnterCriticalSection(&cs);
    m_Waves[waveId].isWaiting = false;
    LeaveCriticalSection(&cs);
	SetEvent(m_ThreadWakeUp);

    // resume thread < at first play >
    if( !m_RunThread ){ 
        m_RunThread = 1; 
        isClosing = false;
        ResumeThread( m_Thread ); 
    }
    
    return 1;
}

int WaveManager::AddInterface( int dev, int wave)
{
	if( !waveOutGetNumDevs() )
		return -1;	
	// check for free device

	// try to open the default wave device. WAVE_MAPPER is
    // a constant defined in mmsystem.h, it always points to the
    // default wave device on the system (some people have 2 or
    // more sound cards).
	if (m_Dev[dev].handle && waveOutReset( m_Dev[dev].handle ) == MMSYSERR_NOERROR )
	   waveOutClose( m_Dev[dev].handle );
	    
	if(waveOutOpen(	&m_Dev[dev].handle, WAVE_MAPPER, &m_Waves[wave].wfx, (DWORD) waveOutProc, (DWORD) this, CALLBACK_FUNCTION	) != MMSYSERR_NOERROR )	
        return -1;
	return 1;
}

int	WaveManager::RemoveInterfaces( )
{
	// try to close given wave device / interface.
	for (size_t i = 0; i < m_Dev.size(); i++) {
	   if (m_Dev[i].handle && waveOutReset( m_Dev[i].handle ) == MMSYSERR_NOERROR && waveOutClose( m_Dev[i].handle ) != MMSYSERR_NOERROR ) 
		  return -1;
	}
	return 1;
}

void CALLBACK WaveManager::waveOutProc( HWAVEOUT hWaveOut, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2 )
{
  	// ignore calls that occur due to openining and closing the device.
    if(uMsg == WOM_DONE) {
		waveOutUnprepareHeader(hWaveOut, (WAVEHDR*)dwParam1, sizeof(WAVEHDR));
		//Mark the played interface as not used now
		((WaveManager*)dwInstance)->m_Dev[((WAVEHDR*)dwParam1)->dwUser].isInUse = false;
	}
}

int	WaveManager::PlayWave(unsigned int id)
{
	size_t d;
	for (d = 0; d < m_Dev.size(); d++) {
	    if (!m_Dev[d].isInUse) {
		    m_Dev[d].isInUse = true; 
		    AddInterface(d, id); 
		    
            //Remember the used interface, so we can mark it as not used if wave ends
	        m_Dev[d].CurWave.dwUser = (DWORD)d;
	        m_Dev[d].CurWave.lpData = m_Waves[id].data;
	        m_Dev[d].CurWave.dwBufferLength	= m_Waves[id].size;	// prepare for playback

	        if ((waveOutPrepareHeader( m_Dev[d].handle, &m_Dev[d].CurWave, sizeof(WAVEHDR) ) == MMSYSERR_NOERROR) &&
                (waveOutWrite(m_Dev[d].handle, &m_Dev[d].CurWave, sizeof(WAVEHDR)) == MMSYSERR_NOERROR))
	            return 1;
	        // else we failed
	        m_Dev[d].isInUse = false;
            return 1;
	    }
    }
    return -1; // No free preallocated devices, so no sound
}

unsigned int CALLBACK WaveManager::PlayThread( LPVOID lp )
{
    WaveManager *waveMgr = static_cast<WaveManager*>(lp);

    WaitForSingleObject(waveMgr->m_ThreadWakeUp, INFINITE);
    while(! waveMgr->isClosing) {
        EnterCriticalSection( &cs );
        std::map<int,WaveInfo>::iterator iterWaveToPlay;
        do {
            iterWaveToPlay = std::find_if(waveMgr->m_Waves.begin(), waveMgr->m_Waves.end(),
                [&](const WaveMap::value_type& mapItem)->bool {
                    return mapItem.second.isWaiting == false;
                }
            );
            if (iterWaveToPlay != waveMgr->m_Waves.end()) {
                iterWaveToPlay->second.isWaiting = true; 
                LeaveCriticalSection( &cs ); 
                waveMgr->PlayWave(iterWaveToPlay->first);
            } 

        } while(iterWaveToPlay != waveMgr->m_Waves.end());
        LeaveCriticalSection( &cs );

        WaitForSingleObject(waveMgr->m_ThreadWakeUp, INFINITE);
    }  

    waveMgr->RemoveInterfaces();
    return 0;
}
