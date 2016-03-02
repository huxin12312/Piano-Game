#ifndef WAVE_PLAYER_H
#define WAVE_PLAYER_H

#include <windows.h>
#include <mmsystem.h>
#include <functional>
#include <vector>
#include <map>

class WaveManager 
{
public:

    int Load( unsigned int waveId, char* file );  // Load a wav from a file and associate it with waveId.
    int LoadFromResource( unsigned int waveId, char* rsrc); // Load a wav from a resource and associate it with waveId.
    int Play( unsigned int waveId );       // play the wave associated with waveId

    WaveManager( size_t maxSimultaneousWaves );
    virtual ~WaveManager();

private:
    struct WaveInfo
    {
        WaveInfo();
        ~WaveInfo();
        char* data; 
        unsigned long size;
        WAVEFORMATEX wfx;      
        bool isWaiting;
    };
    
    struct DevInterface
    {
        DevInterface();

        HWAVEOUT handle;
        bool isInUse;				
        WAVEHDR CurWave;
    };

    typedef std::map<int, WaveInfo> WaveMap;

    static CRITICAL_SECTION cs;
	std::vector<DevInterface> m_Dev;
    WaveMap m_Waves;
    bool isClosing;
	HANDLE m_ThreadWakeUp;	
    HANDLE m_Thread;
    int m_RunThread;

    int AddInterface(int dev, int wave);      
    int RemoveInterfaces();                
	int PlayWave(unsigned int waveId);

    static unsigned int CALLBACK PlayThread( LPVOID lp );
    static void CALLBACK waveOutProc( HWAVEOUT  hWaveOut, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2 );

    template<typename T>
    int LoadWave( unsigned int waveId, T handle, const std::function<int(T, char*, size_t, size_t*)>& );
};

#endif 
