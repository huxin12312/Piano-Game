/* graphics.h has 16 available colors:
BLACK (1), BLUE (2), GREEN (3), CYAN (4), RED (5), MAGENTA (6), 
BROWN (7), LIGHTGRAY (8), DARKGRAY (9), LIGHTBLUE (10), 
LIGHTGREEN (11), LIGHTCYAN (12), LIGHTRED (13), LIGHTMAGENTA (14), 
YELLOW (15), WHITE (16)
*/

//we want to include math library in this header file because functions in this file cannot look up libraries in main file
#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <omp.h>
#include "WaveManager.h"

//same concept applies for defines
#define pi 3.14159265359

//initial ball position
int x = 100, y = 100;
short true_ = 1;

//Like in CyCalc V2, DECLARE FUNCTIONS FIRST
double sum(float a, float b);//summing function
double sub(float a, float b);
double mul(float a, float b);
double Div(float a, float b);
double Sine(float degree);//sine function that accepte degrees
double Deg2Rad(float degree); //degree rad conversion
double Rad2Deg(float degree); //rad degree conversion
void welcome(); //prints welcome graphic
void error(); //prints error graphic
void help();
void draw(int Color);
int plotter (int mode);
double sampleNormal();
int pong(int direction);
int runpong();
void fullcolor();

short int change = 1;

int mousehandle = 0;
int selector = 0;
int score = 100;

///// Piano Function Prototypes /////////////
void Fail();
void RockBombStart();
void PianoInstructions();
void OneOctave();
void FreePlay();
void PlaySong();
int KeyHit(char note);
int piano();
void EasySong(int CountSet);
void RockOn();
void ResetCounters();

void PlaySongEasy();
void StartCountdown();
void songone(int CountSet);
void Practice();

// Note Calling Functions ////////////
int SoundA(int NoteHit);
int SoundB(int NoteHit);
int SoundC(int NoteHit);
int SoundD(int NoteHit);
int SoundE(int NoteHit);
int SoundF(int NoteHit);
int SoundG(int NoteHit);
int SoundH(int NoteHit);
int SoundI(int NoteHit);
int SoundJ(int NoteHit);
int SoundK(int NoteHit);
int SoundL(int NoteHit);
int SoundM(int NoteHit);
int SoundN(int NoteHit);
int SoundO(int NoteHit);
int SoundP(int NoteHit);
int SoundQ(int NoteHit);
int SoundR(int NoteHit);
int SoundS(int NoteHit);
int SoundT(int NoteHit);
int SoundU(int NoteHit);
int SoundV(int NoteHit);
int SoundW(int NoteHit);
int SoundX(int NoteHit);
int SoundY(int NoteHit);
int SoundZ(int NoteHit);

int SoundOne(int Set);
int SoundTwo(int Set);
int SoundThree(int Set);
int SoundFour(int Set);
int SoundFive(int Set);
int SoundSix(int Set);
int SoundSeven(int Set);
int SoundEight(int Set);
int SoundNine(int Set);
int SoundTen(int Set);
int SoundEleven(int Set);
int SoundTwelve(int Set);

////////////////////////////////////////////////

/*////////////////////////////////////////////////////////////
WaveManager song_wav(4);
song_wav.Load(0, "SOUNDS\\1G.wav");
song_wav.Load(1, "SOUNDS\\2A.wav");
song_wav.Load(2, "SOUNDS\\3Bb.wav");
song_wav.Load(3, "SOUNDS\\4B.wav");
song_wav.Load(4, "SOUNDS\\5C.wav");
*////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////


float foo1(float a, float b, float c){
if(a/b == c) return a/b;
if(a/b != c) return (a/b) + (a/b);
}

float foo2(float a, float b, float c){
float result = a/b;
if(result == c) return result;
else return result * 2;}

///////////////////////////////
void generate();
int findMax();
void plot ( int max );
void clear();
void run();

void pano();

////////////////////////////////////////////////
const int barWidth = 50; //bar width
const int limit = 500 ; //generation limit
const int maxPlus = 20 ; //histo limit
int histo[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//THEN, WRITE FUNCTION BODIES BELOW TO HOST THEM

double sum(float a, float b){

return a + b;

}//sum function ends

double sub(float a, float b){

return a - b;

}//sub function ends

double mul(float a, float b){

return a * b;

}//mul function ends

double Div(float a, float b){

//check for div/0 condition

while((int)b==0){
error();
printf("CANNOT DIVIDE BY ZERO, enter second number again! >");
scanf("%f", &b); 
//printf("%f", b);

}//while ends

return a / b;

}//div function ends

double Sine(float degree){

return sin(Deg2Rad(degree));

}//sine ends

double Deg2Rad(float degree){

double radians = 0;//store output

radians = degree * (pi / 180);

return radians;

}//deg2rad ends

double Rad2Deg(float radians){

double degrees = 0;//store output

degrees = radians * (180/pi);

return degrees;

}//deg2rad ends

void welcome(){

printf(" _____________________\n");
printf("|  _________________  |\n");
printf("| | Welcome to  /   | |\n");
printf("| |       /|   /    | |\n");
printf("| |  /|  / |  /     | |\n");
printf("| | / |_/  |_/      | |\n");
printf("| |/         CyCalc | |\n");
printf("| |_________________| |\n");
printf("|  __ __ __ __ __ __  |\n");
printf("| |__|__|__|__|__|__| |\n");
printf("| |__|__|__|__|__|__| |\n");
printf("| |__|__|__|__|__|__| |\n");
printf("| |__|__|__|__|__|__| |\n");
printf("|  ___ ___ ___   ___  |\n");
printf("| | 7 | 8 | 9 | | + | |\n");
printf("| |___|___|___| |___| |\n");
printf("| | 4 | 5 | 6 | | - | |\n");
printf("| |___|___|___| |___| |\n");
printf("| | 1 | 2 | 3 | | x | |\n");
printf("| |___|___|___| |___| |\n");
printf("| | . | 0 | = | | / | |\n");
printf("| |___|___|___| |___| |\n");
printf("|_____________________|\n");
true_--;
}


void error(){

#ifdef SOUNDfx
PlaySound("SOUNDS\\div0.wav", NULL, SND_ASYNC);
#endif

readimagefile("PIX\\cydiv0.jpg",0,0,640,480);

}


///////////////////////////////////////

/* Generate the random numbers and histogram them. */
void generate()
{
 int j, r ;
 for ( j=0; j<limit; j++ )
 {
   r = rand()%maxPlus;
   histo[r]++;
 }
}



/* Find the maximum of all the histogram bins */
int findMax()
{
 int j;
 int max = histo[0];

 for ( j=1; j < maxPlus; j++ )
 {
   if ( histo[j] > max )
     max = histo[j];
 }
 
 return max;
}

/* Plot the histogram */
void plot ( int max )
{
 
 int j, s;

 for ( j=0; j<maxPlus; j++ )
 {
   printf("%3d (%5d) > ", j, histo[j] );
   for ( s=0; s<histo[j]*barWidth/max; s++ ) printf("|");
    
   printf("\n");
 }
}


void clear(){
int i = 0;    
    
for(i = 0; i<maxPlus; i++) histo[i] = 0;     
    
    }


void run(){
    
 int max;

 while(1){
 srand( time(NULL) );
 generate();
 max = findMax();
 plot( max );
 getchar();
   
}}



void help(){

printf("\n");
printf("--------------CyCalc V5 HELP MENU--------------\n");
printf("Type +, -, *, or / for arithmetic ops.\n");
printf("Type s for SINE(first)\n");
printf("Type h for HISTOGRAM app.\n");
printf("Type d to access DRAW app.\n");
printf("Type p to run simple pong.\n");
printf("Type q to quit CyCalc.\n");
printf("Type c to CLEAR the graphing screen.\n");
printf("Type S to access graphing calculator.\n");
printf("-----------------------------------------------\n");
printf("\n");
//printf("Type p to plot y = sin(x)\n");
//printf("Type P to plot y = t^2(cos(x)sin(x))\n");



}


void draw(int Color){
//create two character arrays (for sprintf)
//sprintf is equivalent to printf but it prints into strings (char arrays) instead of screen
char buff1[100];
char buff2[100];

 while(1){

//read mouse x, write it into buff1 
sprintf(buff1, "X = %d\n", mousex());
//read mouse y, write it into buff2
sprintf(buff2, "Y = %d\n", mousey());

outtextxy(200, 200, buff1);
outtextxy(300, 200, buff2);
outtextxy(200, 400, "Hit spacebar to finish drawing.");

putpixel(mousex(), mousey(), Color);
circle(mousex(), mousey(), 2);

if (kbhit()) {getch(); break;}
}//while ends

}//draw ends


int plotter(int mode){

short flip = 1; //toggle switch

   
setbkcolor(WHITE);
setcolor(RED);
cleardevice(); 
   readimagefile("PIX\\OscilloscopeScreen.jpg", 0, 0, 640, 480);


int midx,midy,mx,my; //middle of graphing screen
double tpi; //two times PI
int t = 0; //sine function sampling rate
midx = getmaxx()/2; midy = getmaxy()/2;
tpi = pi * 2.0;
t=100;


while(true){

for (t = 0; t < 600; t++){
Sleep(1);
printf("SINE of %d, is %.2f\n",t, sin(t*pi/180));

circle(t+20, sin(t*pi/180)*120 + 243, 5);
circle(t+20, 2*cos(t*pi/180)*120 + 243, 2);

if(flip < 0) setcolor(WHITE);
if(flip > 0) setcolor(RED);

}

flip = flip * -1;
}

return 0;

}//plot ends


double sampleNormal() {
   double u = ((double) rand() / (RAND_MAX)) * 2 - 1;
   double v = ((double) rand() / (RAND_MAX)) * 2 - 1;
   double r = u * u + v * v;
   if (r == 0 || r > 1) return sampleNormal();
   double c = sqrt(-2 * log(r) / r);
   return u * c;
}


int pong3D(int direction){

switch (direction){

case 0:
y = y + 1;
//readimagefile("PIX\\3dball.bmp", x, y, x + 20, y + 20);
//readimagefile("PIX\\3dball_green", x, y, x + 20, y + 20);

break;

case 1:
y = y + 1;
x = x + 1;
//readimagefile("PIX\\3dball.bmp", x, y, x + 20, y + 20);
//readimagefile("PIX\\3dball_green", x, y, x + 20, y + 20);
break;

case 2: 
x = x + 1;
  //readimagefile("PIX\\3dball.bmp", x, y, x + 20, y + 20);
//readimagefile("PIX\\3dball_green", x, y, x + 20, y + 20);
break;

case 3: 
x = x + 1;
y = y - 1; 
//readimagefile("PIX\\3dball.bmp", x, y, x + 20, y + 20);
break;

case 4: 
y = y - 1;
//readimagefile("PIX\\3dball.bmp", x, y, x + 20, y + 20);
break;

case 5 :
y = y - 1;
x = x - 1;
//readimagefile("PIX\\3dball.bmp", x, y, x + 20, y + 20);
//readimagefile("PIX\\3dball_green", x, y, x + 20, y + 20);
break;

case 6: 
x = x - 1;
//readimagefile("PIX\\3dball.bmp", x, y, x + 20, y + 20);
break;

case 7: 
x = x - 1;
y = y + 1;
//readimagefile("PIX\\3dball.bmp", x, y, x + 20, y + 20);
//readimagefile("PIX\\3dball_green", x, y, x + 20, y + 20);

break;


}
if (change > 0) readimagefile("PIX\\3dball_green.jpg", x-10, y-10, x + 10, y + 10);
if (change < 0) readimagefile("PIX\\3dball.bmp", x - 20, y - 20, x + 20, y + 20);
//readimagefile("PIX\\pinball_machine.jpg",0,0,640,480);

//readimagefile("PIX\\my_background.jpg", 0, 0, 640, 480);
//readimagefile("PIX\\flipper_up.jpg", 0, 0, 640, 480);

if (x < 432 && y>382 && x > 206) readimagefile("PIX\\flipper_up.jpg", 0, 0, 640, 480);
else readimagefile("PIX\\flipper_down.jpg", 0, 0, 640, 480);



//collision detected
if (x > 620 || y > 460 || x < 20 || y < 20 || (x >140 && y >140&&x<160&&y<160) || (x >100 && y>340&&x<120&&y<360) || (x>520 && y >210&&x<540&&y<230) || (x < 432 && y>382 && x>206)) return 1;

else return 0;
}


int runpong(){

int directions = 1;
int collisions = 0;

char buff1[100];
char buff2[100];





setbkcolor(COLOR(255,255,255));
setcolor(COLOR(0,0,255));

//Introducing the background picture in here causes a smear effect
//you need to disable it in pong() for this to work
//readimagefile("PIX\\pinball_machine.jpg",0,0,640,480);


while (1){
sprintf(buff1, "X = %d\n", mousex());
sprintf(buff2, "Y = %d\n", mousey());

outtextxy(200, 200, buff1);
outtextxy(300, 200, buff2);
outtextxy(200, 400, "Hit spacebar to stop.");

collisions = pong3D(directions);
int tempir = directions;
if (collisions){
if (x < 432 && y>382 && x > 206) change = -1;
else change = 1;

directions--;
/*do {
directions = rand() % 8;
} while ((directions == tempir) && (x < 20 && y < 20) || (x>640 && y < 20) || (x < 20 && y>440) || (x>640 && y > 440) || (x > 140 && y > 140 && x < 160 && y < 160) || (x >100 && y>340 && x < 120 && y < 360) || (x>520 && y >210 && x < 540 && y < 230) || (x < 432 && y>382 && x>206));

*/

if (directions < 0) directions = 7;

Sleep(100);
#ifdef SOUNDfx
PlaySound("SOUNDS\\bam.wav", NULL, SND_ASYNC);
#endif
}
//for(int i =0; i<99; i++){}//slow down animation speed BAD WAY 2 DELAY
//cleardevice();

if (kbhit()) {
switch (getch()){

case 'a': PlaySound("SOUNDS\\Sound_A.wav", NULL, SND_ASYNC);
break;
case 'b': PlaySound("SOUNDS\\Sound_B.wav", NULL, SND_ASYNC);
break;
}

//("PIX\\flipper_down.jpg", 0, 0, 640, 480);



}//while
}
return 0;}



int piano(){

//cleardevice();
setbkcolor(COLOR(255, 255, 255));
setcolor(COLOR(0, 0, 255));
mousehandle = 4;
int quit = 1;

WaveManager Piano_wave(26);
Piano_wave.Load(0, "SOUNDS\\Sound_A.wav");
Piano_wave.Load(1, "SOUNDS\\Sound_B.wav");
Piano_wave.Load(2, "SOUNDS\\Sound_C.wav");
Piano_wave.Load(3, "SOUNDS\\Sound_D.wav");
Piano_wave.Load(4, "SOUNDS\\Sound_E.wav");
Piano_wave.Load(5, "SOUNDS\\Sound_F.wav");
Piano_wave.Load(6, "SOUNDS\\Sound_G.wav");
Piano_wave.Load(7, "SOUNDS\\Sound_H.wav");
Piano_wave.Load(8, "SOUNDS\\Sound_I.wav");
Piano_wave.Load(9, "SOUNDS\\Sound_J.wav");
Piano_wave.Load(10, "SOUNDS\\Sound_K.wav");
Piano_wave.Load(11, "SOUNDS\\Sound_L.wav");
Piano_wave.Load(12, "SOUNDS\\Sound_M.wav");
Piano_wave.Load(13, "SOUNDS\\Sound_N.wav");
Piano_wave.Load(14, "SOUNDS\\Sound_O.wav");
Piano_wave.Load(15, "SOUNDS\\Sound_P.wav");
Piano_wave.Load(16, "SOUNDS\\Sound_Q.wav");
Piano_wave.Load(17, "SOUNDS\\Sound_R.wav");
Piano_wave.Load(18, "SOUNDS\\Sound_S.wav");
Piano_wave.Load(19, "SOUNDS\\Sound_T.wav");
Piano_wave.Load(20, "SOUNDS\\Sound_U.wav");
Piano_wave.Load(21, "SOUNDS\\Sound_V.wav");
Piano_wave.Load(22, "SOUNDS\\Sound_W.wav");
Piano_wave.Load(23, "SOUNDS\\Sound_X.wav");
Piano_wave.Load(24, "SOUNDS\\Sound_Y.wav");
Piano_wave.Load(25, "SOUNDS\\Sound_Z.wav");
int nthreads, tid;

readimagefile("PIX\\piano\\1.jpg", 0, 0, 640, 460);
/*#pragma omp parallel private(nthreads, tid)
{

	tid = omp_get_thread_num();*/
	while (quit)
	{
		
		//printf("%d", tid);


		while ((int) selector == 8){

			PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
			selector = 0;
			quit = 0;
			RockBombStart();

		}


		int key;

		while (kbhit()) {


			key = getch();

			//printf("%d", tid);
			if (key == 'a'){
				Piano_wave.Play(0);
				readimagefile("PIX\\piano\\2.jpg", 0, 0, 640, 460);

				//PlaySound("SOUNDS\\Sound_A.wav", NULL, SND_ASYNC);

			}

			else if (key == 'b'){
				readimagefile("PIX\\piano\\3.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(1);
				//PlaySound("SOUNDS\\Sound_B.wav", NULL, SND_ASYNC);

			}


			else if (key == 'c'){
				readimagefile("PIX\\piano\\4.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(2);
				//PlaySound("SOUNDS\\Sound_C.wav", NULL, SND_ASYNC);

			}

			else if (key == 'd'){
				readimagefile("PIX\\piano\\5.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(3);
				//PlaySound("SOUNDS\\Sound_D.wav", NULL, SND_ASYNC);

			}
			else if (key == 'e'){
				readimagefile("PIX\\piano\\6.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(4);
				//PlaySound("SOUNDS\\Sound_E.wav", NULL, SND_ASYNC);

			}
			else if (key == 'f'){
				readimagefile("PIX\\piano\\7.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(5);
				//PlaySound("SOUNDS\\Sound_F.wav", NULL, SND_ASYNC);

			}




			else if (key == 'g'){
				readimagefile("PIX\\piano\\8.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(6);
				//PlaySound("SOUNDS\\Sound_G.wav", NULL, SND_ASYNC);

			}
			else if (key == 'h'){
				readimagefile("PIX\\piano\\9.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(7);
				//PlaySound("SOUNDS\\Sound_H.wav", NULL, SND_ASYNC);

			}
			else if (key == 'i'){
				readimagefile("PIX\\piano\\10.jpg", 0, 0, 640, 460);
				Piano_wave.Play(8);
				//PlaySound("SOUNDS\\Sound_I.wav", NULL, SND_ASYNC);

			}
			else if (key == 'j'){
				readimagefile("PIX\\piano\\11.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(9);
				//PlaySound("SOUNDS\\Sound_J.wav", NULL, SND_ASYNC);

			}


			else if (key == 'k'){
				readimagefile("PIX\\piano\\12.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(10);
				//PlaySound("SOUNDS\\Sound_K.wav", NULL, SND_ASYNC);

			}
			else if (key == 'l'){
				readimagefile("PIX\\piano\\13.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(11);
				//PlaySound("SOUNDS\\Sound_L.wav", NULL, SND_ASYNC);

			}

			else if (key == 'm'){

				readimagefile("PIX\\piano\\14.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(12);
				//PlaySound("SOUNDS\\Sound_M.wav", NULL, SND_ASYNC);

			}





			else if (key == 'n'){
				readimagefile("PIX\\piano\\15.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(13);
				//PlaySound("SOUNDS\\Sound_N.wav", NULL, SND_ASYNC);

			}
			else if (key == 'o'){
				readimagefile("PIX\\piano\\16.jpg", 0, 0, 640, 460); 
                Piano_wave.Play(14);
				//PlaySound("SOUNDS\\Sound_O.wav", NULL, SND_ASYNC);

			}
			else if (key == 'p'){
				readimagefile("PIX\\piano\\17.jpg", 0, 0, 640, 460); 
				
				Piano_wave.Play(15);
				//PlaySound("SOUNDS\\Sound_P.wav", NULL, SND_ASYNC);

			}
			else if (key == 'q'){

				readimagefile("PIX\\piano\\18.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(16);
				//PlaySound("SOUNDS\\Sound_Q.wav", NULL, SND_ASYNC);

			}
			else if (key == 'r'){
				readimagefile("PIX\\piano\\19.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(17);
				//PlaySound("SOUNDS\\Sound_R.wav", NULL, SND_ASYNC);

			}

			else if (key == 's'){
				readimagefile("PIX\\piano\\20.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(18);
				//PlaySound("SOUNDS\\Sound_S.wav", NULL, SND_ASYNC);

			}
			else if (key == 't'){
				readimagefile("PIX\\piano\\21.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(19);
				//PlaySound("SOUNDS\\Sound_T.wav", NULL, SND_ASYNC);

			}
			else if (key == 'u'){
				readimagefile("PIX\\piano\\22.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(20);
				//PlaySound("SOUNDS\\Sound_U.wav", NULL, SND_ASYNC);

			}
			else if (key == 'v'){
				readimagefile("PIX\\piano\\23.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(21);
				//PlaySound("SOUNDS\\Sound_V.wav", NULL, SND_ASYNC);

			}
			else if (key == 'w'){
				readimagefile("PIX\\piano\\24.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(22);
				//PlaySound("SOUNDS\\Sound_W.wav", NULL, SND_ASYNC);

			}
			else if (key == 'x'){
				readimagefile("PIX\\piano\\25.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(23);
				//PlaySound("SOUNDS\\Sound_X.wav", NULL, SND_ASYNC);

			}
			else if (key == 'y'){
				readimagefile("PIX\\piano\\26.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(24);
				//PlaySound("SOUNDS\\Sound_Y.wav", NULL, SND_ASYNC);

			}
			else if (key == 'z'){
				readimagefile("PIX\\piano\\27.jpg", 0, 0, 640, 460); 
				Piano_wave.Play(25);
				//PlaySound("SOUNDS\\Sound_Z.wav", NULL, SND_ASYNC);
			}
		}//kbhit end

	}//while end
//omp end


return 0; }

void Fail(){
	mousehandle = 2;
	int Quit = 1;
	ResetCounters();
	readimagefile("PIX//fail3.jpg", 0, 0, 640, 480);
	//PlaySound("SOUNDS\\fail.wav", NULL, SND_ASYNC);
	while(Quit){
	if((int) selector == 4){
		PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
				selector = 0;
			RockBombStart();
		}
	if((int) selector == 5){
		PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
				selector = 0;
				RockBombStart();
			Quit = 0;
		}
	}
}
/*
void RockBombStart(){
	mousehandle = 1;
	int Quit = 1;
	readimagefile("PIX//RBOpen.jpg", 0, 0, 640, 480);
	while(Quit){
	if((int)selector == 1){
		PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
		selector = 0;
			readimagefile("PIX//FreePlayModes.jpg", 0, 0, 640, 480);
			mousehandle = 3;
			while(Quit){
			if((int) selector == 6){
				PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
				OneOctave();
			}
			if((int) selector == 7){
				PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
				piano();
			}
		}
	}
	if((int) selector == 2){
		PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
		selector = 0;
			PlaySongEasy();
		}
	}
}
*/
void RockBombStart(){
	mousehandle = 1;
	int Quit = 1;
	int SongSelect = 0;
	PlaySound("SOUNDS\\main_menu.wav", NULL, SND_ASYNC);
	readimagefile("PIX//MainMenu.jpg", 0, 0, 640, 480);

	while (Quit){

		if ((int) selector == 1){
			// Free Play Clicked
			selector = 0;
			readimagefile("PIX//FreePlayModes.jpg", 0, 0, 640, 480);
			mousehandle = 3;
			while (Quit){
				if ((int) selector == 6){
					PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
					OneOctave();
				}
				if ((int) selector == 7){
					PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
					piano();
				}
			}
		} // End If Free Play clicked
		if ((int) selector == 2){
			// Play Song Clicked
			PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
			selector = 0;
			mousehandle = 5;
			readimagefile("PIX//SongSelectMenu.jpg", 0, 0, 640, 480);
			while (Quit){
				if ((int) selector == 10){
					// Easy Mode Clicked
					PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
					PlaySongEasy();
				}
				if ((int) selector == 11){
					// Hard Mode Clicked
					PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
					PlaySong();
				}
				if ((int) selector == 14){
					// Back Clicked
					PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
					selector = 0;
					RockBombStart();
				}
			}
		} // End If Free Play clicked

		if ((int) selector == 9){
			// Exit Button Clicked
			PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
			selector = 0;
			Quit = 0;
			readimagefile("PIX//Final_Cycalc.jpg", 0, 0, 640, 480);
		}
		if ((int) selector == 12){
			// Practice Button Clicked
			PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
			selector = 0;
			Quit = 0;
			Practice();
		}
		if ((int) selector == 3){
			// Instructions Button Clicked
			PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
			mousehandle = 7;
			selector = 0;
			readimagefile("PIX//Instructions.jpg", 0, 0, 640, 480);
		}
		if ((int) selector == 15){
			// Instructions Back Button Clicked
			selector = 0;
			PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
			RockBombStart();
		}
	} // End While Quit
} // End Rock Bomb Start

void LClick(int, int){

	switch (mousehandle){
	case 1: // Start Menu
		if (mousex() > 29 && mousex() < 175 && mousey() > 75 && mousey() < 100){
			selector = 1;
			mousehandle = 0;
		}
		if (mousex() > 29 && mousex() < 175 && mousey() > 120 && mousey() < 145){
			selector = 2;
			mousehandle = 0;
		}
		if (mousex() > 29 && mousex() < 175 && mousey() > 165 && mousey() < 190){
			selector = 3;
			mousehandle = 0;
		}
		if (mousex() > 565 && mousex() < 640 && mousey() > 415 && mousey() < 460){
			selector = 9;
			mousehandle = 0;
		}
		if (mousex() > 29 && mousex() < 175 && mousey() > 210 && mousey() < 242){
			selector = 12;
			mousehandle = 0;
		}
		break;
	case 2: // Fail
		if (mousex() > 67 && mousex() < 241 && mousey() > 280 && mousey() < 435){
			selector = 4;
			mousehandle = 0;
		}
		if (mousex() > 357 && mousex() < 531 && mousey() > 280 && mousey() < 435){
			selector = 5;
			mousehandle = 0;
		}
		break;
	case 3:  // Free Play Modes Menu
		if (mousex() > 415 && mousex() < 613 && mousey() > 145 && mousey() < 264){
			selector = 6;
			mousehandle = 0;
		}
		if (mousex() > 415 && mousex() < 613 && mousey() > 303 && mousey() < 423){
			selector = 7;
			mousehandle = 0;
		}
		break;
	case 4:
		if (mousex() > 570 && mousex() < 640 && mousey() > 440 && mousey() < 480){
			selector = 8;
			mousehandle = 0;
		}
		break;
	case 5:  // Song Select
		if (mousex() > 57 && mousex() < 278 && mousey() > 330 && mousey() < 448){
			selector = 10;
			mousehandle = 0;
		}
		if (mousex() > 369 && mousex() < 591 && mousey() > 330 && mousey() < 448){
			selector = 11;
			mousehandle = 0;
		}
		if (mousex() > 11 && mousex() < 125 && mousey() > 13 && mousey() < 75){
			selector = 14;
			mousehandle = 0;
		}
	case 6: // Practice
		if (mousex() > 0 && mousex() < 62 && mousey() > 438 && mousey() < 467){
			selector = 13;
			mousehandle = 0;
		}
	case 7:
		if (mousex() > 40 && mousex() < 144 && mousey() > 40 && mousey() < 101){
			selector = 15;
			mousehandle = 0;
		}
	} // End Switch mousehandle
};


void OneOctave(){
	int Quit = 1;
	WaveManager Piano_wav(26);
	Piano_wav.Load(0, "SOUNDS\\1G.wav");
	Piano_wav.Load(1, "SOUNDS\\2A.wav");
	Piano_wav.Load(2, "SOUNDS\\3Bb.wav");
	Piano_wav.Load(3, "SOUNDS\\4B.wav");
	Piano_wav.Load(4, "SOUNDS\\5C.wav");
	Piano_wav.Load(5, "SOUNDS\\6Db.wav");
	Piano_wav.Load(6, "SOUNDS\\7D.wav");
	Piano_wav.Load(7, "SOUNDS\\8Eb.wav");
	Piano_wav.Load(8, "SOUNDS\\9E.wav");
	Piano_wav.Load(9, "SOUNDS\\10F.wav");
	Piano_wav.Load(10, "SOUNDS\\11Gb.wav");
	Piano_wav.Load(11, "SOUNDS\\12G.wav");

	int key;
	while (Quit){
		readimagefile("PIX//OneOctave.jpg", 0, 0, 640, 480);
		while (kbhit()) {

			key = getch();

			if (key == 's'){
				Piano_wav.Play(0);
				readimagefile("PIX//BlueButton.jpg", 132, 290, 176, 360);
			}
			else if (key == 'e'){
				Piano_wav.Play(1);
				readimagefile("PIX//BlueButton.jpg", 168, 240, 194, 270);
			}
			else if (key == 'd'){
				readimagefile("PIX//BlueButton.jpg", 184, 290, 231, 360);
				Piano_wav.Play(2);
			}
			else if (key == 'r'){
				readimagefile("PIX//BlueButton.jpg", 223, 240, 248, 270);
				Piano_wav.Play(3);
			}
			else if (key == 'f'){
				readimagefile("PIX//BlueButton.jpg", 239, 290, 286, 360);
				Piano_wav.Play(4);
			}
			else if (key == 'g'){
				readimagefile("PIX//BlueButton.jpg", 294, 290, 341, 360);
				Piano_wav.Play(5);
			}
			else if (key == 'y'){
				readimagefile("PIX//BlueButton.jpg", 326, 240, 349, 270);
				Piano_wav.Play(6);
			}
			else if (key == 'h'){
				readimagefile("PIX//BlueButton.jpg", 349, 290, 396, 360);
				Piano_wav.Play(7);
			}
			else if (key == 'u'){
				readimagefile("PIX//BlueButton.jpg", 389, 240, 412, 270);
				Piano_wav.Play(8);
			}
			else if (key == 'j'){
				readimagefile("PIX//BlueButton.jpg", 404, 290, 453, 360);
				Piano_wav.Play(9);
			}
			else if (key == 'i'){
				readimagefile("PIX//BlueButton.jpg", 447, 240, 470, 270);
				Piano_wav.Play(10);
			}
			else if (key == 'k'){
				readimagefile("PIX//BlueButton.jpg", 461, 290, 508, 360);
				Piano_wav.Play(11);
			}
			else if (key == 'q'){
				RockBombStart();
			}
		} // End while(kbhit())
	} //End while(Quit)
} // End OneOctave

void FreePlay(){
	int Quit = 1;
	readimagefile("PIX//RockBombPiano.jpg", 0, 0, 640, 480);
	while(Quit){
			switch (getch()){

			case 'q': 
				PlaySound("SOUNDS\\Sound_A.wav", NULL, SND_ASYNC);
				break;
			case 'w': 
				PlaySound("SOUNDS\\Sound_B.wav", NULL, SND_ASYNC);
				break;
			case 'e': 
				PlaySound("SOUNDS\\Sound_C.wav", NULL, SND_ASYNC);
				break;
			case 'r': 
				PlaySound("SOUNDS\\Sound_D.wav", NULL, SND_ASYNC);
				break;
			case 't': 
				PlaySound("SOUNDS\\Sound_E.wav", NULL, SND_ASYNC);
				break;
			case 'y': 
				PlaySound("SOUNDS\\Sound_F.wav", NULL, SND_ASYNC);
				break;
			case 'a': 
				PlaySound("SOUNDS\\Sound_G.wav", NULL, SND_ASYNC);
				break;
			case 's': 
				PlaySound("SOUNDS\\Sound_H.wav", NULL, SND_ASYNC);
				break;
			case 'd': 
				PlaySound("SOUNDS\\Sound_I.wav", NULL, SND_ASYNC);
				break;
			case 'f': 
				PlaySound("SOUNDS\\Sound_J.wav", NULL, SND_ASYNC);
				break;
			case 'g': 
				PlaySound("SOUNDS\\Sound_K.wav", NULL, SND_ASYNC);
				break;
			case 'h': 
				PlaySound("SOUNDS\\Sound_L.wav", NULL, SND_ASYNC);
				break;
			case 'u': 
				PlaySound("SOUNDS\\Sound_M.wav", NULL, SND_ASYNC);
				break;
			case 'i': 
				PlaySound("SOUNDS\\Sound_N.wav", NULL, SND_ASYNC);
				break;
			case 'o': 
				PlaySound("SOUNDS\\Sound_O.wav", NULL, SND_ASYNC);
				break;
			case 'p': 
				PlaySound("SOUNDS\\Sound_P.wav", NULL, SND_ASYNC);
				break;
			case '[': 
				PlaySound("SOUNDS\\Sound_Q.wav", NULL, SND_ASYNC);
				break;
			case ']': 
				PlaySound("SOUNDS\\Sound_R.wav", NULL, SND_ASYNC);
				break;
			case '=':
				PlaySound("SOUNDS\\Sound_S.wav", NULL, SND_ASYNC);
				break;
			case 'j': 
				PlaySound("SOUNDS\\Sound_T.wav", NULL, SND_ASYNC);
				break;
			case 'k': 
				PlaySound("SOUNDS\\Sound_U.wav", NULL, SND_ASYNC);
				break;
			case 'l': 
				PlaySound("SOUNDS\\Sound_V.wav", NULL, SND_ASYNC);
				break;
			case ';': 
				PlaySound("SOUNDS\\Sound_W.wav", NULL, SND_ASYNC);
				break;
			case '/': 
				PlaySound("SOUNDS\\Sound_X.wav", NULL, SND_ASYNC);
				break;
				case 'n': 
				PlaySound("SOUNDS\\Sound_Y.wav", NULL, SND_ASYNC);
				break;
			case 'm': 
				PlaySound("SOUNDS\\Sound_Z.wav", NULL, SND_ASYNC);
				break;
			case 'z': 
				PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
				RockBombStart();
				break;
			
			}
	}
}



int KeyHit(char key){
	switch (key){

			case 'q': 
				//PlaySound("SOUNDS\\Sound_A.wav", NULL, SND_ASYNC);
				if(SoundA(1)){
					PlaySound("SOUNDS\\Sound_A.wav", NULL, SND_ASYNC);
					
					score += 10;
				}
				else {
					PlaySound("SOUNDS\\chuck.wav", NULL, SND_ASYNC);
					
					score -= 10;
				}
				break;
			case 'w': 
				//PlaySound("SOUNDS\\Sound_B.wav", NULL, SND_ASYNC);
				if(SoundB(1)){
					PlaySound("SOUNDS\\Sound_B.wav", NULL, SND_ASYNC);
					
					score += 10;
				}
				else {
					PlaySound("SOUNDS\\chuck.wav", NULL, SND_ASYNC);
					
					score -= 10;
				}
				break;
			case 'e': 
				PlaySound("SOUNDS\\Sound_C.wav", NULL, SND_ASYNC);
				if(SoundC(1)) score += 10;
				else score -= 10;
				break;
			case 'r': 
				PlaySound("SOUNDS\\Sound_D.wav", NULL, SND_ASYNC);
				if(SoundD(1)) score += 10;
				else score -= 10;
				break;
			case 't': 
				PlaySound("SOUNDS\\Sound_E.wav", NULL, SND_ASYNC);
				if(SoundE(1)) score += 10;
				else score -= 10;
				break;
			case 'y': 
				PlaySound("SOUNDS\\Sound_F.wav", NULL, SND_ASYNC);
				if(SoundF(1)) score += 10;
				else score -= 10;
				break;
			case 'a': 
				PlaySound("SOUNDS\\Sound_G.wav", NULL, SND_ASYNC);
				if(SoundG(1)) score += 10;
				else score -= 10;
				break;
			case 's': 
				PlaySound("SOUNDS\\Sound_H.wav", NULL, SND_ASYNC);
				if(SoundH(1)) score += 10;
				else score -= 10;
				break;
			case 'd': 
				PlaySound("SOUNDS\\Sound_I.wav", NULL, SND_ASYNC);
				if(SoundI(1)) score += 10;
				else score -= 10;
				break;
			case 'f': 
				PlaySound("SOUNDS\\Sound_J.wav", NULL, SND_ASYNC);
				if(SoundJ(1)) score += 10;
				else score -= 10;
				break;
			case 'g': 
				PlaySound("SOUNDS\\Sound_K.wav", NULL, SND_ASYNC);
				if(SoundK(1)) score += 10;
				else score -= 10;
				break;
			case 'h': 
				PlaySound("SOUNDS\\Sound_L.wav", NULL, SND_ASYNC);
				if(SoundL(1)) score += 10;
				else score -= 10;
				break;
				/*
			case 'u': 
				PlaySound("SOUNDS\\Sound_M.wav", NULL, SND_ASYNC);
				if(SoundM(1)) score += 10;
				else score -= 10;
				break;
			case 'i': 
				PlaySound("SOUNDS\\Sound_N.wav", NULL, SND_ASYNC);
				if(SoundN(1)) score += 10;
				else score -= 10;
				break;
			case 'o': 
				PlaySound("SOUNDS\\Sound_O.wav", NULL, SND_ASYNC);
				if(SoundO(1)) score += 10;
				else score -= 10;
				break;
			case 'p': 
				PlaySound("SOUNDS\\Sound_P.wav", NULL, SND_ASYNC);
				if(SoundP(1)) score += 10;
				else score -= 10;
				break;
			case '[': 
				PlaySound("SOUNDS\\Sound_Q.wav", NULL, SND_ASYNC);
				if(SoundQ(1)) score += 10;
				else score -= 10;
				break;
			case ']': 
				PlaySound("SOUNDS\\Sound_R.wav", NULL, SND_ASYNC);
				if(SoundR(1)) score += 10;
				else score -= 10;
				break;
			case '=':
				PlaySound("SOUNDS\\Sound_S.wav", NULL, SND_ASYNC);
				if(SoundS(1)) score += 10;
				else score -= 10;
				break;
			case 'j': 
				PlaySound("SOUNDS\\Sound_T.wav", NULL, SND_ASYNC);
				if(SoundT(1)) score += 10;
				else score -= 10;
				break;
			case 'k': 
				PlaySound("SOUNDS\\Sound_U.wav", NULL, SND_ASYNC);
				if(SoundU(1)) score += 10;
				else score -= 10;
				break;
			case 'l': 
				PlaySound("SOUNDS\\Sound_V.wav", NULL, SND_ASYNC);
				if(SoundV(1)) score += 10;
				else score -= 10;
				break;
			case ';': 
				PlaySound("SOUNDS\\Sound_W.wav", NULL, SND_ASYNC);
				if(SoundW(1)) score += 10;
				else score -= 10;
				break;
			case '/': 
				PlaySound("SOUNDS\\Sound_X.wav", NULL, SND_ASYNC);
				if(SoundX(1)) score += 10;
				else score -= 10;
				break;
				*/
			
			}
	return 0;
}



void StartCountdown(){
	readimagefile("PIX//Ready.jpg", 0, 0, 640, 480);
	Sleep(1000);
	PlaySound("SOUNDS\\DrumBeat.wav", NULL, SND_ASYNC);
	readimagefile("PIX//Three.jpg", 0, 0, 640, 480);
	Sleep(1000);
	PlaySound("SOUNDS\\DrumBeat.wav", NULL, SND_ASYNC);
	readimagefile("PIX//Two.jpg", 0, 0, 640, 480);
	Sleep(1000);
	PlaySound("SOUNDS\\DrumBeat.wav", NULL, SND_ASYNC);
	readimagefile("PIX//One.jpg", 0, 0, 640, 480);
	Sleep(1000);
	PlaySound("SOUNDS\\DrumBeat.wav", NULL, SND_ASYNC);
	readimagefile("PIX//Go.jpg", 0, 0, 640, 480);
	Sleep(1000);
}

void RockOn(){
	char scorekeep[4];
	readimagefile("PIX//RockOn.jpg", 0, 0, 640, 480);
	sprintf(scorekeep, "%d", score);
	outtextxy(290, 413, scorekeep);
	ResetCounters();
	Sleep(2200);
	RockBombStart();
}

void PianoInstructions(){

}

//////////////// Note Calling Functions (One-Octave) /////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////

void ResetCounters(){
	/// Sets Song Counters to 0 ///
	songone(0);
	EasySong(0);
	/// Resets yOne ///
	SoundOne(2);
	SoundTwo(2);
	SoundThree(2);
	SoundFour(2);
	SoundFive(2);
	SoundSix(2);
	SoundSeven(2);
	SoundEight(2);
	SoundNine(2);
	SoundTen(2);
	SoundEleven(2);
	SoundTwelve(2);
	/// Resests yTwo ///
	SoundOne(3);
	SoundTwo(3);
	SoundThree(3);
	SoundFour(3);
	SoundFive(3);
	SoundSix(3);
	SoundSeven(3);
	SoundEight(3);
	SoundNine(3);
	SoundTen(3);
	SoundEleven(3);
	SoundTwelve(3);
	// Resests Score for next Game
	score = 100;
}

void PlaySong(){

	readimagefile("PIX//RockBombPiano.jpg", 0, 0, 640, 460);
	char scorekeep[4];
	int quit = 1;
	char KEY;
	mousehandle = 6;
	///////// Loads Piano Wave /////////////////////////
	WaveManager Piano_wave(26);
	Piano_wave.Load(0, "SOUNDS\\Sound_A.wav");
	Piano_wave.Load(1, "SOUNDS\\Sound_B.wav");
	Piano_wave.Load(2, "SOUNDS\\Sound_C.wav");
	Piano_wave.Load(3, "SOUNDS\\Sound_D.wav");
	Piano_wave.Load(4, "SOUNDS\\Sound_E.wav");
	Piano_wave.Load(5, "SOUNDS\\Sound_F.wav");
	Piano_wave.Load(6, "SOUNDS\\Sound_G.wav");
	Piano_wave.Load(7, "SOUNDS\\Sound_H.wav");
	Piano_wave.Load(8, "SOUNDS\\Sound_I.wav");
	Piano_wave.Load(9, "SOUNDS\\Sound_J.wav");
	Piano_wave.Load(10, "SOUNDS\\Sound_K.wav");
	Piano_wave.Load(11, "SOUNDS\\Sound_L.wav");
	Piano_wave.Load(12, "SOUNDS\\Sound_M.wav");
	Piano_wave.Load(13, "SOUNDS\\Sound_N.wav");
	Piano_wave.Load(14, "SOUNDS\\Sound_O.wav");
	Piano_wave.Load(15, "SOUNDS\\Sound_P.wav");
	Piano_wave.Load(16, "SOUNDS\\Sound_Q.wav");
	Piano_wave.Load(17, "SOUNDS\\Sound_R.wav");
	Piano_wave.Load(18, "SOUNDS\\Sound_S.wav");
	Piano_wave.Load(19, "SOUNDS\\Sound_T.wav");
	Piano_wave.Load(20, "SOUNDS\\Sound_U.wav");
	Piano_wave.Load(21, "SOUNDS\\Sound_V.wav");
	Piano_wave.Load(22, "SOUNDS\\Sound_W.wav");
	Piano_wave.Load(23, "SOUNDS\\Sound_X.wav");
	Piano_wave.Load(24, "SOUNDS\\Sound_Y.wav");
	Piano_wave.Load(25, "SOUNDS\\Sound_Z.wav");
	Piano_wave.Load(26, "SOUNDS\\chuck.wav");
while ((int) selector == 12){

			PlaySound("SOUNDS\\off.wav", NULL, SND_ASYNC);
			selector = 0;
			quit = 0;
			RockBombStart();

		}



		
	///////////////////////////////////////////////////////////////////////
	//int nthreads, tid;

	//#pragma omp parallel private(nthreads, tid)
	//{

	//tid = omp_get_thread_num();
	//while (quit)
	//{
	//readimagefile("PIX//RockBombPiano.jpg", 0, 0, 640, 480);
	StartCountdown();
	while (quit){
		readimagefile("PIX//RockBombPiano.jpg", 0, 0, 640, 480);
		songone(1);
		int key;

		while (kbhit()) {


			key = getch();

			//printf("%d", tid);
			if (key == 'a'){
				Piano_wave.Play(0);
				if (SoundA(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}

			else if (key == 'b'){
				//readimagefile("PIX\\piano\\3.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(1);
				//PlaySound("SOUNDS\\Sound_B.wav", NULL, SND_ASYNC);
				if (SoundB(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}


			else if (key == 'c'){
				//readimagefile("PIX\\piano\\4.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(2);
				//PlaySound("SOUNDS\\Sound_C.wav", NULL, SND_ASYNC);
				if (SoundC(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}

			else if (key == 'd'){
				//readimagefile("PIX\\piano\\5.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(3);
				//PlaySound("SOUNDS\\Sound_D.wav", NULL, SND_ASYNC);
				if (SoundD(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'e'){
				//readimagefile("PIX\\piano\\6.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(4);
				//PlaySound("SOUNDS\\Sound_E.wav", NULL, SND_ASYNC);
				if (SoundE(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'f'){
				//readimagefile("PIX\\piano\\7.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(5);
				//PlaySound("SOUNDS\\Sound_F.wav", NULL, SND_ASYNC);
				if (SoundF(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}




			if (key == 'g'){
				//readimagefile("PIX\\piano\\8.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(6);
				//PlaySound("SOUNDS\\Sound_G.wav", NULL, SND_ASYNC);
				if (SoundG(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'h'){
				//readimagefile("PIX\\piano\\9.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(7);
				//PlaySound("SOUNDS\\Sound_H.wav", NULL, SND_ASYNC);
				if (SoundH(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'i'){
				//readimagefile("PIX\\piano\\10.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(8);
				//PlaySound("SOUNDS\\Sound_I.wav", NULL, SND_ASYNC);
				if (SoundI(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'j'){
				//readimagefile("PIX\\piano\\11.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(9);
				//PlaySound("SOUNDS\\Sound_J.wav", NULL, SND_ASYNC);
				if (SoundJ(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}


			else if (key == 'k'){
				//readimagefile("PIX\\piano\\12.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(10);
				//PlaySound("SOUNDS\\Sound_K.wav", NULL, SND_ASYNC);
				if (SoundK(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'l'){
				//readimagefile("PIX\\piano\\13.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(11);
				//PlaySound("SOUNDS\\Sound_L.wav", NULL, SND_ASYNC);
				if (SoundL(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}

			else if (key == 'm'){

				//readimagefile("PIX\\piano\\14.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(12);
				//PlaySound("SOUNDS\\Sound_M.wav", NULL, SND_ASYNC);
				if (SoundM(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}


			if (key == 'n'){
				//readimagefile("PIX\\piano\\15.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(13);
				//PlaySound("SOUNDS\\Sound_N.wav", NULL, SND_ASYNC);
				if (SoundN(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'o'){
				//readimagefile("PIX\\piano\\16.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(14);
				//PlaySound("SOUNDS\\Sound_O.wav", NULL, SND_ASYNC);
				if (SoundO(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'p'){
				//readimagefile("PIX\\piano\\17.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(15);
				//PlaySound("SOUNDS\\Sound_P.wav", NULL, SND_ASYNC);
				if (SoundP(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'q'){

				//readimagefile("PIX\\piano\\18.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(16);
				//PlaySound("SOUNDS\\Sound_Q.wav", NULL, SND_ASYNC);
				if (SoundQ(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'r'){
				//readimagefile("PIX\\piano\\19.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(17);
				//PlaySound("SOUNDS\\Sound_R.wav", NULL, SND_ASYNC);
				if (SoundR(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}

			else if (key == 's'){
				//readimagefile("PIX\\piano\\20.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(18);
				//PlaySound("SOUNDS\\Sound_S.wav", NULL, SND_ASYNC);
				if (SoundS(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 't'){
				//readimagefile("PIX\\piano\\21.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(19);
				//PlaySound("SOUNDS\\Sound_T.wav", NULL, SND_ASYNC);
				if (SoundT(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'u'){
				//readimagefile("PIX\\piano\\22.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(20);
				//PlaySound("SOUNDS\\Sound_U.wav", NULL, SND_ASYNC);
				if (SoundU(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'v'){
				//readimagefile("PIX\\piano\\23.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(21);
				//PlaySound("SOUNDS\\Sound_V.wav", NULL, SND_ASYNC);
				if (SoundV(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'w'){
				//readimagefile("PIX\\piano\\24.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(22);
				//PlaySound("SOUNDS\\Sound_W.wav", NULL, SND_ASYNC);
				if (SoundW(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'x'){
				//readimagefile("PIX\\piano\\25.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(23);
				//PlaySound("SOUNDS\\Sound_X.wav", NULL, SND_ASYNC);
				if (SoundX(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'y'){
				//readimagefile("PIX\\piano\\26.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(24);
				//PlaySound("SOUNDS\\Sound_Y.wav", NULL, SND_ASYNC);
				if (SoundY(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
			else if (key == 'z'){
				//readimagefile("PIX\\piano\\27.jpg", 0, 0, 640, 460); Sleep(50);
				Piano_wave.Play(25);
				//PlaySound("SOUNDS\\Sound_Z.wav", NULL, SND_ASYNC);
				if (SoundZ(4)){

					score += 10;
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
			}
		}



		//readimagefile("PIX//Slices//ScoreSlice.jpg", 11, 0, 55, 462);
		if (score > 75){
			readimagefile("PIX//green.jpg", 26, 384 - score, 46, 384);
		}
		else{
			readimagefile("PIX//red.jpg", 26, 384 - score, 46, 384);
		}
		sprintf(scorekeep, "%d", score);
		outtextxy(15, 437, scorekeep);
		//readimagefile("PIX//RockBombPiano.jpg", 0, 0, 640, 480);
		if (score == 0){
			quit = 0;
			Fail();
		
	} // End Fail Check
	} // End While
} // End PlaySong

void PlaySongEasy(){

	char scorekeep[4];
	int quit = 1;
	int KB = 1;
	char KEY;
	WaveManager Piano_wav(26);
	Piano_wav.Load(0, "SOUNDS\\1G.wav");
	Piano_wav.Load(1, "SOUNDS\\2A.wav");
	Piano_wav.Load(2, "SOUNDS\\3Bb.wav");
	Piano_wav.Load(3, "SOUNDS\\4B.wav");
	Piano_wav.Load(4, "SOUNDS\\5C.wav");
	Piano_wav.Load(5, "SOUNDS\\6Db.wav");
	Piano_wav.Load(6, "SOUNDS\\7D.wav");
	Piano_wav.Load(7, "SOUNDS\\8Eb.wav");
	Piano_wav.Load(8, "SOUNDS\\9E.wav");
	Piano_wav.Load(9, "SOUNDS\\10F.wav");
	Piano_wav.Load(10, "SOUNDS\\11Gb.wav");
	Piano_wav.Load(11, "SOUNDS\\12G.wav");
	Piano_wav.Load(12, "SOUNDS\\chuck.wav");
	//int nthreads, tid;

	StartCountdown();

	//#pragma omp parallel private(nthreads, tid)
	//{

	//tid = omp_get_thread_num();
	readimagefile("PIX//EasyPlayScreen.jpg", 0, 0, 640, 480);
	while (quit){
		EasySong(3);
		while (kbhit() && KB == 1){
			KEY = getch();
			KB = 0;
			switch (KEY){

			case 's':
				if (SoundOne(4)){
					Piano_wav.Play(0);
					score += 10;
				}
				else{
					Piano_wav.Play(12);
					score -= 10;
				}
				break;
			case 'e':
				if (SoundTwo(4)){
					Piano_wav.Play(1);
					score += 10;
				}
				else{
					Piano_wav.Play(12);
					score -= 10;
				}
				break;
			case 'd':
				if (SoundThree(4)){
					Piano_wav.Play(2);
					score += 10;
				}
				else{
					Piano_wav.Play(12);
					score -= 10;
				}
				break;
			case 'r':
				if (SoundFour(4)){
					Piano_wav.Play(3);
					score += 10;
				}
				else{
					Piano_wav.Play(12);
					score -= 10;
				}
				break;
			case 'f':
				if (SoundFive(4)){
					Piano_wav.Play(4);
					score += 10;
				}
				else{
					Piano_wav.Play(12);
					score -= 10;
				}
				break;
			case 'g':
				if (SoundSix(4)){
					Piano_wav.Play(5);
					score += 10;
				}
				else{
					Piano_wav.Play(12);
					score -= 10;
				}
				break;
			case 'y':
				if (SoundSeven(4)){
					Piano_wav.Play(6);
					score += 10;
				}
				else{
					Piano_wav.Play(12);
					score -= 10;
				}
				break;
			case 'h':
				if (SoundEight(4)){
					Piano_wav.Play(7);
					score += 10;
				}
				else{
					Piano_wav.Play(12);
					score -= 10;
				}
				break;
			case 'u':
				if (SoundNine(4)){
					Piano_wav.Play(8);
					score += 10;
				}
				else{
					Piano_wav.Play(12);
					score -= 10;
				}
				break;
			case 'j':
				if (SoundTen(4)){
					Piano_wav.Play(9);
					score += 10;
				}
				else{
					Piano_wav.Play(12);
					score -= 10;
				}
				break;
			case 'i':
				if (SoundEleven(4)){
					Piano_wav.Play(10);
					score += 10;
				}
				else{
					Piano_wav.Play(12);
					score -= 10;
				}
				break;
			case 'k':
				if (SoundTwelve(4)){
					Piano_wav.Play(11);
					score += 10;
				}
				else{
					Piano_wav.Play(12);
					score -= 10;
				}
				break;
			} // End Switch
		} // End While KBHit
		KB = 1;
		readimagefile("PIX//Slices//ScoreSlot.jpg", 38, 0, 71, 374);
		readimagefile("PIX//Slices//ScoreDisplay.jpg", 20, 432, 82, 462);
		readimagefile("PIX//Slices//KeyGreen.jpg", 134, 310, 534, 355);
		if (score > 75){
			readimagefile("PIX//green.jpg", 40, 380 - score, 68, 380);
		}
		else{
			readimagefile("PIX//red.jpg", 40, 380 - score, 68, 380);
		}
		sprintf(scorekeep, "%d", score);
		outtextxy(23, 437, scorekeep);
		if (score == 0){
			quit = 0;
			Fail();
		} // End Fail Check
	} // End While
	// } // End Parallel
} // End PlaySongEasy

void EasySong(int CountSet){
	static int counter = 0;
	if (CountSet == 0)counter = 0;
	if (CountSet == 1){
		if (counter > 30 && counter < 98)SoundSix(0);
		if (counter > 38 && counter < 106)SoundEight(0);
		if (counter > 45 && counter < 113)SoundTen(0);
		if (counter > 50 && counter < 118)SoundTwelve(0);
		if (counter > 55 && counter < 123)SoundTen(1);
		if (counter > 60 && counter < 128)SoundEight(1);
		if (counter > 70 && counter < 138)SoundSix(1);
		if (counter > 82 && counter < 150)SoundFive(0);
		if (counter > 90 && counter < 158)SoundThree(0);
		if (counter > 98 && counter < 166)SoundOne(0);
		if (counter > 105 && counter < 173)SoundOne(1);
		if (counter > 110 && counter < 178)SoundThree(1);
		if (counter > 120 && counter < 188)SoundTwo(0);
		if (counter > 125 && counter < 193)SoundFour(0);
		if (counter > 140 && counter < 208)SoundSeven(0);
		if (counter > 147 && counter < 215)SoundNine(0);
		if (counter > 170 && counter < 238)SoundFive(0);
		if (counter > 174 && counter < 242)SoundThree(1);
		if (counter > 178 && counter < 246)SoundOne(1);
		if (counter > 185 && counter < 253)SoundOne(0);
		if (counter > 189 && counter < 257)SoundThree(0);
		if (counter == 300)RockOn();
		counter++;
	}
	if (CountSet == 2){
		if (counter > 0 && counter < 68)SoundOne(0);
		if (counter > 34 && counter < 102)SoundOne(1);
		if (counter > 82 && counter < 150)SoundOne(0);
		if (counter > 116 && counter < 184)SoundOne(1);

		counter++;
	}
	if (CountSet == 3){
		// Hunger Games /////////////
		if (counter > 0 && counter < 68)SoundEight(0);
		if (counter > 15 && counter < 83)SoundEleven(0);
		if (counter > 41 && counter < 109)SoundTen(0);
		if (counter > 59 && counter < 127)SoundThree(0);
		// Harry's Theme /////////////
		if (counter > 130 && counter < 198)SoundOne(0);
		if (counter > 134 && counter < 202)SoundFive(0);
		if (counter > 141 && counter < 209)SoundEight(1);
		if (counter > 145 && counter < 213)SoundSeven(0);
		if (counter > 150 && counter < 218)SoundFive(1);
		if (counter > 157 && counter < 225)SoundTwelve(0);
		if (counter > 161 && counter < 229)SoundTen(0);
		if (counter > 169 && counter < 237)SoundSeven(1);
		if (counter > 178 && counter < 246)SoundFive(5);
		if (counter > 185 && counter < 253)SoundEight(0);
		if (counter > 189 && counter < 257)SoundSeven(5);
		if (counter > 194 && counter < 262)SoundThree(0);
		if (counter > 205 && counter < 273)SoundSix(0);
		if (counter > 212 && counter < 280)SoundOne(0);
		// Lyra's Lullaby /////////////////
		if (counter > 280 && counter < 348)SoundFive(0);
		if (counter > 285 && counter < 353)SoundSeven(0);
		if (counter > 290 && counter < 358)SoundEight(1);
		if (counter > 300 && counter < 368)SoundSeven(1);
		if (counter > 305 && counter < 373)SoundEight(0);
		if (counter > 315 && counter < 383)SoundTwelve(0);
		if (counter > 323 && counter < 391)SoundThree(0);
		if (counter > 327 && counter < 395)SoundTen(0);
		if (counter > 337 && counter < 405)SoundFive(1);
		if (counter > 342 && counter < 410)SoundTen(1);
		if (counter > 351 && counter < 419)SoundEight(5);
		if (counter > 365 && counter < 433)SoundSeven(0);
		if (counter > 373 && counter < 441)SoundFive(0);
		counter++;
		if (counter == 455)RockOn();
	}
	printf("Counter: %d\n", counter);
}

void songone(int CountSet){
	static int counter = 0;
	if (CountSet == 0)counter = 0;
	if (CountSet == 1){
		if (counter > 0 && counter < 40)SoundH(0);
		if (counter > 5 && counter < 45)SoundJ(0);
		if (counter > 7 && counter < 47)SoundL(0);
		if (counter > 9 && counter < 49)SoundO(0);

		if (counter > 14 && counter < 54)SoundE(0);
		if (counter > 19 && counter < 59)SoundI(0);
		if (counter > 21 && counter < 61)SoundL(1);
		if (counter > 23 && counter < 63)SoundN(0);

		if (counter > 28 && counter < 68)SoundF(0);
		if (counter > 35 && counter < 75)SoundH(1);
		if (counter > 37 && counter < 77)SoundJ(0);
		if (counter > 39 && counter < 79)SoundM(0);

		if (counter > 42 && counter < 321)SoundC(0);
		if (counter > 49 && counter < 341)SoundG(0);
		if (counter > 51 && counter < 361)SoundI(0);
		if (counter > 53 && counter < 381)SoundL(0);

		if (counter > 67 && counter < 401)SoundD(0);
		if (counter > 73 && counter < 421)SoundF(0);
		if (counter > 75 && counter < 441)SoundH(0);
		if (counter > 77 && counter < 461)SoundK(0);

		if (counter > 91 && counter < 481)SoundA(0);
        if (counter > 97 && counter < 501)SoundE(0);
		if (counter > 99 && counter < 521)SoundH(0);
		if (counter > 101 && counter < 541)SoundJ(0);

		if (counter > 115 && counter < 561)SoundD(0);
		if (counter > 121 && counter < 581)SoundF(0);
		if (counter > 123 && counter < 561)SoundH(0);
		if (counter > 125 && counter < 581)SoundK(0);

		if (counter > 139 && counter < 561)SoundE(0);
		if (counter > 145 && counter < 581)SoundG(0);
		if (counter > 147 && counter < 561)SoundI(0);
		if (counter > 149 && counter < 581)SoundL(0);

		if (counter > 163 && counter < 561)SoundH(0);
		if (counter > 166 && counter < 561)SoundQ(0);

		if (counter > 178 && counter < 581)SoundJ(0);
		if (counter > 185 && counter < 561)SoundL(0);
		if (counter > 187 && counter < 581)SoundO(0);

		if (counter > 198 && counter < 561)SoundE(0);
		if (counter > 202 && counter < 561)SoundP(0);

		if (counter > 220 && counter < 581)SoundJ(0);
		if (counter > 226 && counter < 561)SoundL(0);
		if (counter > 230 && counter < 581)SoundO(0);

		if (counter > 250 && counter < 561)SoundO(0);
		if (counter > 255 && counter < 561)SoundF(0);

		if (counter > 267 && counter < 581)SoundH(0);
		if (counter > 269 && counter < 561)SoundJ(0);
		if (counter > 271 && counter < 581)SoundM(0);

		if (counter > 287 && counter < 561)SoundN(0);
		if (counter > 291 && counter < 561)SoundC(0);

		if (counter > 308 && counter < 581)SoundG(0);
		if (counter > 311 && counter < 561)SoundJ(0);
		if (counter > 313 && counter < 581)SoundL(0);

		if (counter > 330 && counter < 561)SoundM(0);
		if (counter > 333 && counter < 561)SoundD(0);

		if (counter > 348 && counter < 581)SoundF(0);
		if (counter > 353 && counter < 561)SoundH(0);
		if (counter > 356 && counter < 581)SoundK(0);

		if (counter > 365 && counter < 561)SoundL(0);
		if (counter > 370 && counter < 561)SoundA(0);

		if (counter > 388 && counter < 581)SoundC(0);
		if (counter > 391 && counter < 561)SoundE(0);
		if (counter > 393 && counter < 581)SoundH(0);

		if (counter > 400) RockOn();

		/*if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 480 && counter < 561)SoundD(0);

		if (counter > 500 && counter < 581)SoundF(0);
		if (counter > 480 && counter < 561)SoundH(0);
		if (counter > 500 && counter < 581)SoundK(0);

		if (counter > 480 && counter < 561)SoundN(0);
		if (counter > 480 && counter < 561)SoundE(0);

		if (counter > 500 && counter < 581)SoundG(0);
		if (counter > 480 && counter < 561)SoundI(0);
		if (counter > 500 && counter < 581)SoundL(0);

		if (counter > 480 && counter < 561)SoundO(0);
		if (counter > 500 && counter < 581)SoundN(0);
		if (counter > 480 && counter < 561)SoundO(0);
		if (counter > 500 && counter < 581)SoundH(0);

		if (counter > 480 && counter < 561)SoundG(0);
		if (counter > 500 && counter < 581)SoundB(0);

		if (counter > 500 && counter < 581)SoundL(0);
		if (counter > 480 && counter < 561)SoundI(0);
		if (counter > 500 && counter < 581)SoundJ(0);

		if (counter > 480 && counter < 561)SoundC(0);
		if (counter > 480 && counter < 561)SoundH(0);
		if (counter > 500 && counter < 581)SoundO(0);
		if (counter > 480 && counter < 561)SoundN(0);
		if (counter > 500 && counter < 581)SoundM(0);

		if (counter > 480 && counter < 561)SoundC(0);
		if (counter > 480 && counter < 561)SoundN(0);
		if (counter > 500 && counter < 581)SoundQ(0);
		if (counter > 480 && counter < 561)SoundS(0);
		if (counter > 500 && counter < 581)SoundT(0);

		if (counter > 480 && counter < 561)SoundD(0);
		if (counter > 480 && counter < 561)SoundR(0);
		if (counter > 500 && counter < 581)SoundF(0);
		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 500 && counter < 581)SoundN(0);

		if (counter > 480 && counter < 561)SoundQ(0);
		if (counter > 480 && counter < 561)SoundA(0);
		if (counter > 500 && counter < 581)SoundP(0);
		if (counter > 480 && counter < 561)SoundO(0);
		if (counter > 500 && counter < 581)SoundN(0);

		if (counter > 480 && counter < 561)SoundD(0);
		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 500 && counter < 581)SoundL(0);
		if (counter > 480 && counter < 561)SoundK(0);
		if (counter > 500 && counter < 581)SoundJ(0);

		if (counter > 480 && counter < 561)SoundE(0);
		if (counter > 480 && counter < 561)SoundI(0);
		if (counter > 500 && counter < 581)SoundK(0);
		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 500 && counter < 581)SoundI(0);

		if (counter > 480 && counter < 561)SoundE(0);
		if (counter > 480 && counter < 561)SoundH(0);
		if (counter > 500 && counter < 581)SoundI(0);
		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 500 && counter < 581)SoundK(0);

		if (counter > 480 && counter < 561)SoundE(0);
		if (counter > 480 && counter < 561)SoundG(0);
		if (counter > 500 && counter < 581)SoundI(0);
		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 500 && counter < 581)SoundK(0);

		if (counter > 480 && counter < 561)SoundF(0);
		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 500 && counter < 581)SoundM(0);
		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 500 && counter < 581)SoundK(0);

		if (counter > 480 && counter < 561)SoundC(0);
		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 500 && counter < 581)SoundK(0);
		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 500 && counter < 581)SoundI(0);

		if (counter > 480 && counter < 561)SoundD(0);
		if (counter > 480 && counter < 561)SoundH(0);
		if (counter > 500 && counter < 581)SoundF(0);
		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 500 && counter < 581)SoundN(0);

		if (counter > 480 && counter < 561)SoundA(0);
		if (counter > 480 && counter < 561)SoundO(0);
		if (counter > 500 && counter < 581)SoundN(0);
		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 500 && counter < 581)SoundL(0);

		if (counter > 480 && counter < 561)SoundD(0);
		if (counter > 480 && counter < 561)SoundK(0);
		if (counter > 500 && counter < 581)SoundJ(0);
		if (counter > 480 && counter < 561)SoundI(0);
		if (counter > 500 && counter < 581)SoundM(0);

		if (counter > 500 && counter < 581)SoundL(0);
		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 500 && counter < 581)SoundL(0);

		if (counter > 480 && counter < 561)SoundS(0);
		if (counter > 480 && counter < 561)SoundJ(0);

		if (counter > 500 && counter < 581)SoundQ(0);
		if (counter > 480 && counter < 561)SoundR(0);
		if (counter > 500 && counter < 581)SoundS(0);

		if (counter > 480 && counter < 561)SoundQ(0);
		if (counter > 480 && counter < 561)SoundR(0);


		if (counter > 480 && counter < 561)SoundS(0);
		if (counter > 480 && counter < 561)SoundE(0);

		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 500 && counter < 581)SoundN(0);
		if (counter > 480 && counter < 561)SoundO(0);
		if (counter > 500 && counter < 581)SoundP(0);
		if (counter > 480 && counter < 561)SoundQ(0);
		if (counter > 480 && counter < 561)SoundR(0);
		

		if (counter > 480 && counter < 561)SoundF(0);
		if (counter > 480 && counter < 561)SoundQ(0);

		if (counter > 500 && counter < 581)SoundO(0);
		if (counter > 480 && counter < 561)SoundP(0);
		if (counter > 500 && counter < 581)SoundQ(0);

		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 480 && counter < 561)SoundK(0);

		if (counter > 500 && counter < 581)SoundG(0);
		if (counter > 480 && counter < 561)SoundL(0);

		if (counter > 500 && counter < 581)SoundM(0);
		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 480 && counter < 561)SoundK(0);
		if (counter > 500 && counter < 581)SoundL(0);
		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 500 && counter < 581)SoundK(0);
		if (counter > 500 && counter < 581)SoundL(0);

		if (counter > 500 && counter < 581)SoundF(0);
		if (counter > 500 && counter < 581)SoundK(0);

		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 500 && counter < 581)SoundK(0);

		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 500 && counter < 581)SoundI(0);

		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 480 && counter < 561)SoundE(0);

		if (counter > 500 && counter < 581)SoundI(0);
		if (counter > 480 && counter < 561)SoundH(0);
		if (counter > 500 && counter < 581)SoundI(0);
		if (counter > 500 && counter < 581)SoundJ(0);
		if (counter > 500 && counter < 581)SoundK(0);
		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 500 && counter < 581)SoundK(0);
		if (counter > 500 && counter < 581)SoundL(0);
		if (counter > 500 && counter < 581)SoundM(0);

		if (counter > 500 && counter < 581)SoundF(0);
		if (counter > 500 && counter < 581)SoundK(0);

		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 500 && counter < 581)SoundM(0);

		if (counter > 500 && counter < 581)SoundN(0);
		if (counter > 500 && counter < 581)SoundO(0);

		if (counter > 500 && counter < 581)SoundG(0);
		if (counter > 480 && counter < 561)SoundL(0);

		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 500 && counter < 581)SoundN(0);
		if (counter > 480 && counter < 561)SoundO(0);
		if (counter > 500 && counter < 581)SoundP(0);
		if (counter > 480 && counter < 561)SoundQ(0);
		if (counter > 480 && counter < 561)SoundR(0);
        if (counter > 480 && counter < 561)SoundS(0);
		
		if (counter > 480 && counter < 561)SoundS(0);
		if (counter > 500 && counter < 581)SoundI(0);

		if (counter > 480 && counter < 561)SoundQ(0);
		if (counter > 500 && counter < 581)SoundR(0);
		if (counter > 480 && counter < 561)SoundS(0);

		if (counter > 480 && counter < 561)SoundQ(0);
		if (counter > 500 && counter < 581)SoundR(0);

		if (counter > 480 && counter < 561)SoundS(0);
		if (counter > 480 && counter < 561)SoundE(0);

		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 500 && counter < 581)SoundN(0);
		if (counter > 480 && counter < 561)SoundO(0);
		if (counter > 500 && counter < 581)SoundP(0);
		if (counter > 480 && counter < 561)SoundQ(0);
		if (counter > 480 && counter < 561)SoundR(0);

		if (counter > 480 && counter < 561)SoundF(0);
		if (counter > 480 && counter < 561)SoundQ(0);

		if (counter > 500 && counter < 581)SoundO(0);
		if (counter > 480 && counter < 561)SoundP(0);
		if (counter > 500 && counter < 581)SoundQ(0);

		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 480 && counter < 561)SoundK(0);

		if (counter > 500 && counter < 581)SoundG(0);
		if (counter > 480 && counter < 561)SoundL(0);

		if (counter > 500 && counter < 581)SoundM(0);
		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 480 && counter < 561)SoundK(0);
		if (counter > 500 && counter < 581)SoundL(0);
		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 500 && counter < 581)SoundK(0);
		if (counter > 500 && counter < 581)SoundL(0);

		if (counter > 500 && counter < 581)SoundF(0);
		if (counter > 500 && counter < 581)SoundK(0);

		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 500 && counter < 581)SoundK(0);

		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 500 && counter < 581)SoundI(0);

		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 480 && counter < 561)SoundE(0);

		if (counter > 500 && counter < 581)SoundI(0);
		if (counter > 480 && counter < 561)SoundH(0);
		if (counter > 500 && counter < 581)SoundI(0);
		if (counter > 500 && counter < 581)SoundJ(0);
		if (counter > 500 && counter < 581)SoundK(0);
		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 500 && counter < 581)SoundK(0);
		if (counter > 500 && counter < 581)SoundL(0);
		if (counter > 500 && counter < 581)SoundM(0);

		if (counter > 500 && counter < 581)SoundF(0);
		if (counter > 500 && counter < 581)SoundK(0);

		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 500 && counter < 581)SoundM(0);

		if (counter > 500 && counter < 581)SoundN(0);
		if (counter > 500 && counter < 581)SoundO(0);

		if (counter > 500 && counter < 581)SoundG(0);
		if (counter > 480 && counter < 561)SoundL(0);

		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 500 && counter < 581)SoundN(0);
		if (counter > 480 && counter < 561)SoundO(0);
		if (counter > 500 && counter < 581)SoundP(0);
		if (counter > 480 && counter < 561)SoundQ(0);
		if (counter > 480 && counter < 561)SoundR(0);
		if (counter > 480 && counter < 561)SoundS(0);

		if (counter > 480 && counter < 561)SoundH(0);
		if (counter > 480 && counter < 561)SoundQ(0);

		if (counter > 500 && counter < 581)SoundJ(0);
		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 500 && counter < 581)SoundO(0);

		if (counter > 480 && counter < 561)SoundE(0);
		if (counter > 480 && counter < 561)SoundP(0);

		if (counter > 500 && counter < 581)SoundJ(0);
		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 500 && counter < 581)SoundO(0);

		if (counter > 480 && counter < 561)SoundO(0);
		if (counter > 480 && counter < 561)SoundF(0);

		if (counter > 500 && counter < 581)SoundH(0);
		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 500 && counter < 581)SoundM(0);

		if (counter > 480 && counter < 561)SoundN(0);
		if (counter > 480 && counter < 561)SoundC(0);

		if (counter > 500 && counter < 581)SoundG(0);
		if (counter > 480 && counter < 561)SoundJ(0);
		if (counter > 500 && counter < 581)SoundL(0);

		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 480 && counter < 561)SoundD(0);

		if (counter > 500 && counter < 581)SoundF(0);
		if (counter > 480 && counter < 561)SoundH(0);
		if (counter > 500 && counter < 581)SoundK(0);

		if (counter > 480 && counter < 561)SoundL(0);
		if (counter > 480 && counter < 561)SoundA(0);

		if (counter > 500 && counter < 581)SoundC(0);
		if (counter > 480 && counter < 561)SoundE(0);
		if (counter > 500 && counter < 581)SoundH(0);

		if (counter > 480 && counter < 561)SoundM(0);
		if (counter > 480 && counter < 561)SoundD(0);

		if (counter > 500 && counter < 581)SoundF(0);
		if (counter > 480 && counter < 561)SoundH(0);
		if (counter > 500 && counter < 581)SoundK(0);

		if (counter > 480 && counter < 561)SoundN(0);
		if (counter > 480 && counter < 561)SoundE(0);

		if (counter > 500 && counter < 581)SoundG(0);
		if (counter > 480 && counter < 561)SoundI(0);
		if (counter > 500 && counter < 581)SoundL(0);

		if (counter > 500 && counter < 581)SoundG(0);
		if (counter > 480 && counter < 561)SoundI(0);
		if (counter > 500 && counter < 581)SoundL(0);
		if (counter > 500 && counter < 581)SoundN(0);
		if (counter > 480 && counter < 561)SoundQ(0);
		if (counter > 500 && counter < 581)SoundO(0);
		if (counter > 500 && counter < 581)SoundQ(0);
		if (counter > 480 && counter < 561)SoundP(0);
		if (counter > 500 && counter < 581)SoundO(0);

		*/
		counter++;
	}
}
///////////////////////////////////////////////////////////////////////////////////
////////////////// Note-Calling Function Definitions //////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

int SoundOne(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 134, yOne - 5, 166, yOne + 15);
		readimagefile("PIX//BlueButton.jpg", 134, yOne, 166, yOne + 20);
		yOne += 5;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 134, yTwo - 5, 166, yTwo + 15);
		readimagefile("PIX//BlueButton.jpg", 134, yTwo, 166, yTwo + 20);
		yTwo += 5;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 314 && yOne < 331){
			switch (yOne){
			case 330:
				yOne = 505;
				break;
			case 325:
				yOne = 500;
				break;
			case 320:
				yOne = 495;
				break;
			case 315:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 314 && yTwo < 331){
			switch (yTwo){
			case 330:
				yTwo = 505;
				break;
			case 325:
				yTwo = 500;
				break;
			case 320:
				yTwo = 495;
				break;
			case 315:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 335) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 134, 320, 166, 340);
		score -= 10;
	}
	if (yTwo == 335) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 134, 320, 166, 340);
		Sleep(50);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundOne

int SoundTwo(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 172, yOne - 5, 198, yOne + 15);
		readimagefile("PIX//RedButton.jpg", 172, yOne, 198, yOne + 20);
		yOne += 5;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 172, yTwo - 5, 198, yTwo + 15);
		readimagefile("PIX//RedButton.jpg", 172, yTwo, 198, yTwo + 20);
		yTwo += 5;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 314 && yOne < 331){
			switch (yOne){
			case 330:
				yOne = 505;
				break;
			case 325:
				yOne = 500;
				break;
			case 320:
				yOne = 495;
				break;
			case 315:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 314 && yTwo < 331){
			switch (yTwo){
			case 330:
				yTwo = 505;
				break;
			case 325:
				yTwo = 500;
				break;
			case 320:
				yTwo = 495;
				break;
			case 315:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 335) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 172, 320, 198, 340);
		score -= 10;
	}
	if (yTwo == 335) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 172, 320, 198, 340);
		Sleep(50);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundTwo

int SoundThree(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 205, yOne - 5, 226, yOne + 15);
		readimagefile("PIX//BlueButton.jpg", 205, yOne, 226, yOne + 20);
		yOne += 5;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 205, yTwo - 5, 226, yTwo + 15);
		readimagefile("PIX//BlueButton.jpg", 205, yTwo, 226, yTwo + 20);
		yTwo += 5;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 314 && yOne < 331){
			switch (yOne){
			case 330:
				yOne = 505;
				break;
			case 325:
				yOne = 500;
				break;
			case 320:
				yOne = 495;
				break;
			case 315:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 314 && yTwo < 331){
			switch (yTwo){
			case 330:
				yTwo = 505;
				break;
			case 325:
				yTwo = 500;
				break;
			case 320:
				yTwo = 495;
				break;
			case 315:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 335) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 205, 320, 226, 340);
		score -= 10;
	}
	if (yTwo == 335) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 205, 320, 226, 340);
		Sleep(50);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundThree

int SoundFour(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 232, yOne - 5, 259, yOne + 15);
		readimagefile("PIX//RedButton.jpg", 232, yOne, 259, yOne + 20);
		yOne += 5;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 232, yTwo - 5, 259, yTwo + 15);
		readimagefile("PIX//RedButton.jpg", 232, yTwo, 259, yTwo + 20);
		yTwo += 5;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 314 && yOne < 331){
			switch (yOne){
			case 330:
				yOne = 505;
				break;
			case 325:
				yOne = 500;
				break;
			case 320:
				yOne = 495;
				break;
			case 315:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 314 && yTwo < 331){
			switch (yTwo){
			case 330:
				yTwo = 505;
				break;
			case 325:
				yTwo = 500;
				break;
			case 320:
				yTwo = 495;
				break;
			case 315:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 335) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 232, 320, 259, 340);
		score -= 10;
	}
	if (yTwo == 335) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 232, 320, 259, 340);
		Sleep(50);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundFour

int SoundFive(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 265, yOne - 5, 299, yOne + 15);
		readimagefile("PIX//BlueButton.jpg", 265, yOne, 299, yOne + 20);
		yOne += 5;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 265, yTwo - 5, 299, yTwo + 15);
		readimagefile("PIX//BlueButton.jpg", 265, yTwo, 299, yTwo + 20);
		yTwo += 5;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 314 && yOne < 331){
			switch (yOne){
			case 330:
				yOne = 505;
				break;
			case 325:
				yOne = 500;
				break;
			case 320:
				yOne = 495;
				break;
			case 315:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 314 && yTwo < 331){
			switch (yTwo){
			case 330:
				yTwo = 505;
				break;
			case 325:
				yTwo = 500;
				break;
			case 320:
				yTwo = 495;
				break;
			case 315:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 335) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 265, 320, 299, 340);
		score -= 10;
	}
	if (yTwo == 335) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 265, 320, 299, 340);
		Sleep(50);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundFive

int SoundSix(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 305, yOne - 5, 334, yOne + 15);
		readimagefile("PIX//BlueButton.jpg", 305, yOne, 334, yOne + 20);
		yOne += 5;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 305, yTwo - 5, 334, yTwo + 15);
		readimagefile("PIX//BlueButton.jpg", 305, yTwo, 334, yTwo + 20);
		yTwo += 5;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 314 && yOne < 331){
			switch (yOne){
			case 330:
				yOne = 505;
				break;
			case 325:
				yOne = 500;
				break;
			case 320:
				yOne = 495;
				break;
			case 315:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 314 && yTwo < 331){
			switch (yTwo){
			case 330:
				yTwo = 505;
				break;
			case 325:
				yTwo = 500;
				break;
			case 320:
				yTwo = 495;
				break;
			case 315:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 335) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 305, 320, 334, 340);
		score -= 10;
	}
	if (yTwo == 335) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 305, 320, 334, 340);
		Sleep(50);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundSix

int SoundSeven(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 340, yOne - 5, 366, yOne + 15);
		readimagefile("PIX//RedButton.jpg", 340, yOne, 366, yOne + 20);
		yOne += 5;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 340, yTwo - 5, 366, yTwo + 15);
		readimagefile("PIX//RedButton.jpg", 340, yTwo, 366, yTwo + 20);
		yTwo += 5;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 314 && yOne < 331){
			switch (yOne){
			case 330:
				yOne = 505;
				break;
			case 325:
				yOne = 500;
				break;
			case 320:
				yOne = 495;
				break;
			case 315:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 314 && yTwo < 331){
			switch (yTwo){
			case 330:
				yTwo = 505;
				break;
			case 325:
				yTwo = 500;
				break;
			case 320:
				yTwo = 495;
				break;
			case 315:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 335) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 340, 320, 366, 340);
		score -= 10;
	}
	if (yTwo == 335) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 265, 320, 366, 340);
		Sleep(50);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundSeven

int SoundEight(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 372, yOne - 5, 400, yOne + 15);
		readimagefile("PIX//BlueButton.jpg", 372, yOne, 400, yOne + 20);
		yOne += 5;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 372, yTwo - 5, 400, yTwo + 15);
		readimagefile("PIX//BlueButton.jpg", 372, yTwo, 400, yTwo + 20);
		yTwo += 5;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 314 && yOne < 331){
			switch (yOne){
			case 330:
				yOne = 505;
				break;
			case 325:
				yOne = 500;
				break;
			case 320:
				yOne = 495;
				break;
			case 315:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 314 && yTwo < 331){
			switch (yTwo){
			case 330:
				yTwo = 505;
				break;
			case 325:
				yTwo = 500;
				break;
			case 320:
				yTwo = 495;
				break;
			case 315:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 335) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 372, 320, 400, 340);
		score -= 10;
	}
	if (yTwo == 335) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 372, 320, 400, 340);
		Sleep(50);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundEight

int SoundNine(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 407, yOne - 5, 435, yOne + 15);
		readimagefile("PIX//RedButton.jpg", 407, yOne, 435, yOne + 20);
		yOne += 5;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 407, yTwo - 5, 435, yTwo + 15);
		readimagefile("PIX//RedButton.jpg", 407, yTwo, 435, yTwo + 20);
		yTwo += 5;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 314 && yOne < 331){
			switch (yOne){
			case 330:
				yOne = 505;
				break;
			case 325:
				yOne = 500;
				break;
			case 320:
				yOne = 495;
				break;
			case 315:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 314 && yTwo < 331){
			switch (yTwo){
			case 330:
				yTwo = 505;
				break;
			case 325:
				yTwo = 500;
				break;
			case 320:
				yTwo = 495;
				break;
			case 315:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 335) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 407, 320, 435, 340);
		score -= 10;
	}
	if (yTwo == 335) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 407, 320, 435, 340);
		Sleep(50);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundNine

int SoundTen(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 440, yOne - 5, 461, yOne + 15);
		readimagefile("PIX//BlueButton.jpg", 440, yOne, 461, yOne + 20);
		yOne += 5;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 440, yTwo - 5, 461, yTwo + 15);
		readimagefile("PIX//BlueButton.jpg", 440, yTwo, 461, yTwo + 20);
		yTwo += 5;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 314 && yOne < 331){
			switch (yOne){
			case 330:
				yOne = 505;
				break;
			case 325:
				yOne = 500;
				break;
			case 320:
				yOne = 495;
				break;
			case 315:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 314 && yTwo < 331){
			switch (yTwo){
			case 330:
				yTwo = 505;
				break;
			case 325:
				yTwo = 500;
				break;
			case 320:
				yTwo = 495;
				break;
			case 315:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 335) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 440, 320, 461, 340);
		score -= 10;
	}
	if (yTwo == 335) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 440, 320, 461, 340);
		Sleep(50);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundTen

int SoundEleven(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 468, yOne - 5, 495, yOne + 15);
		readimagefile("PIX//RedButton.jpg", 468, yOne, 495, yOne + 20);
		yOne += 5;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 468, yTwo - 5, 495, yTwo + 15);
		readimagefile("PIX//RedButton.jpg", 468, yTwo, 495, yTwo + 20);
		yTwo += 5;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 314 && yOne < 331){
			switch (yOne){
			case 330:
				yOne = 505;
				break;
			case 325:
				yOne = 500;
				break;
			case 320:
				yOne = 495;
				break;
			case 315:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 314 && yTwo < 331){
			switch (yTwo){
			case 330:
				yTwo = 505;
				break;
			case 325:
				yTwo = 500;
				break;
			case 320:
				yTwo = 495;
				break;
			case 315:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 335) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 468, 320, 495, 340);
		score -= 10;
	}
	if (yTwo == 335) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 468, 320, 495, 340);
		Sleep(50);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundEleven

int SoundTwelve(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 502, yOne - 5, 532, yOne + 15);
		readimagefile("PIX//BlueButton.jpg", 502, yOne, 532, yOne + 20);
		yOne += 5;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 502, yTwo - 5, 532, yTwo + 15);
		readimagefile("PIX//BlueButton.jpg", 502, yTwo, 532, yTwo + 20);
		yTwo += 5;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 314 && yOne < 331){
			switch (yOne){
			case 330:
				yOne = 505;
				break;
			case 325:
				yOne = 500;
				break;
			case 320:
				yOne = 495;
				break;
			case 315:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 314 && yTwo < 331){
			switch (yTwo){
			case 330:
				yTwo = 505;
				break;
			case 325:
				yTwo = 500;
				break;
			case 320:
				yTwo = 495;
				break;
			case 315:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;

	} // End Switch
	if (yOne == 335) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 502, 320, 532, 340);
		score -= 10;
	}
	if (yTwo == 335) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 502, 320, 532, 340);
		Sleep(50);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundTwelve

//////////////////////////////////////////////////////
///////////////// Sounds A - Z ///////////////////////
//////////////////////////////////////////////////////
int SoundA(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 67, yOne - 5, 84, yOne + 15);
		readimagefile("PIX//BlueButton.jpg", 67, yOne, 84, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 67, yTwo - 5, 84, yTwo + 15);
		readimagefile("PIX//BlueButton.jpg", 67, yTwo, 84, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 69, 390, 84, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 69, 390, 84, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundA

int SoundB(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//BlueButton.jpg", 89, yOne, 106, yOne + 20);
		readimagefile("PIX//Black.jpg", 89, yOne, 106, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 89, yTwo - 5, 106, yTwo + 15);
		readimagefile("PIX//BlueButton.jpg", 89, yTwo, 106, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 89, 390, 106, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 89, 390, 106, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundB

int SoundC(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 112, yOne - 5, 128, yOne + 15);
		readimagefile("PIX//BlueButton.jpg", 112, yOne, 128, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 112, yTwo - 5, 128, yTwo + 15);
		readimagefile("PIX//BlueButton.jpg", 112, yTwo, 128, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 112, 390, 128, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 112, 390, 128, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundC

int SoundD(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 134, yOne, 149, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 134, yOne, 149, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 134, yTwo, 149, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 134, yTwo, 149, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 134, 390, 149, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 134, 390, 149, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundD

int SoundE(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 155, yOne, 169, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 155, yOne, 169, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 155, yTwo, 169, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 155, yTwo, 169, yTwo + 20);
		yTwo += 10;
		break;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 155, 390, 169, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 155, 390, 169, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundE

int SoundF(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 175, yOne, 189, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 175, yOne, 189, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 175, yTwo, 189, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 175, yTwo, 189, yTwo + 20);;
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 175, 390, 189, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 175, 390, 189, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundF

int SoundG(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 196, yOne, 211, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 196, yOne, 211, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 196, yTwo, 211, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 196, yTwo, 211, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 196, 390, 211, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 196, 390, 211, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundG

int SoundH(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 218, yOne, 231, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 218, yOne, 231, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 218, yTwo, 231, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 218, yTwo, 231, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 218, 390, 231, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 218, 390, 231, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundH

int SoundI(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 239, yOne, 253, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 239, yOne, 253, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 239, yTwo, 253, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 239, yTwo, 253, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 239, 390, 253, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 239, 390, 253, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundI

int SoundJ(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 259, yOne, 274, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 259, yOne, 274, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 259, yTwo, 274, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 259, yTwo, 274, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 259, 390, 274, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 259, 390, 274, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundJ

int SoundK(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 281, yOne, 296, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 281, yOne, 296, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 281, yTwo, 296, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 281, yTwo, 296, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 281, 390, 296, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 281, 390, 296, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundK

int SoundL(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 303, yOne, 317, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 303, yOne, 317, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 303, yOne, 317, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 303, yTwo, 317, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 303, 390, 317, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 303, 390, 317, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundL


int SoundM(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 324, yOne, 337, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 324, yOne, 337, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 324, yTwo, 337, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 324, yTwo, 337, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 324, 390, 337, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 324, 390, 337, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundM

int SoundN(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 344, yOne, 359, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 344, yOne, 359, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 344, yTwo, 359, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 344, yTwo, 359, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 344, 390, 359, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 344, 390, 359, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundN

int SoundO(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 366, yOne, 380, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 366, yOne, 380, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 366, yTwo, 380, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 366, yTwo, 380, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 366, 390, 380, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 366, 390, 380, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundO

int SoundP(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 387, yOne, 402, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 387, yOne, 402, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 387, yTwo, 402, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 387, yTwo, 402, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 387, 390, 402, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 387, 390, 402, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundP

int SoundQ(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 409, yOne, 423, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 409, yOne, 423, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 409, yTwo, 423, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 409, yTwo, 423, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 409, 390, 423, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 409, 390, 423, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundQ

int SoundR(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 429, yOne, 447, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 429, yOne, 447, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 429, yTwo, 447, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 429, yTwo, 447, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 429, 390, 447, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 429, 390, 447, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundR

int SoundS(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 451, yOne, 466, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 451, yOne, 466, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 451, yTwo, 466, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 451, yTwo, 466, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 451, 390, 466, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 451, 390, 466, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundS

int SoundT(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 472, yOne, 488, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 472, yOne, 488, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 472, yTwo, 488, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 472, yTwo, 488, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 472, 390, 488, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 472, 390, 488, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundT

int SoundU(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 493, yOne, 503, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 493, yOne, 503, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 493, yTwo, 503, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 493, yTwo, 503, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 493, 390, 509, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 493, 390, 509, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundU

int SoundV(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 514, yOne, 529, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 514, yOne, 529, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 514, yTwo, 529, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 514, yTwo, 529, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 514, 390, 529, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 514, 390, 529, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundV

int SoundW(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 535, yOne, 551, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 535, yOne, 551, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 535, yTwo, 551, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 535, yTwo, 551, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 535, 390, 551, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 535, 390, 551, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundW

int SoundX(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 557, yOne, 570, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 557, yOne, 570, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 557, yTwo, 570, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 557, yTwo, 570, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 557, 390, 570, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 557, 390, 570, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundX

int SoundY(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 576, yOne, 591, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 576, yOne, 591, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 576, yTwo, 591, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 576, yTwo, 591, yTwo + 20);;
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 576, 390, 591, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 576, 390, 591, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundY

int SoundZ(int Set){
	static int yOne = 0;
	static int yTwo = 0;
	switch (Set){
	case 0: // Moves First Button
		readimagefile("PIX//Black.jpg", 596, yOne, 613, yOne + 20);
		readimagefile("PIX//BlueButton.jpg", 596, yOne, 613, yOne + 20);
		yOne += 10;
		break;
	case 1: // Moves Second Button
		readimagefile("PIX//Black.jpg", 596, yTwo, 613, yTwo + 20);
		readimagefile("PIX//BlueButton.jpg", 596, yTwo, 613, yTwo + 20);
		yTwo += 10;
		break;
	case 2: // Reset First Button
		yOne = 0;
	case 3: // Reset Second Button
		yTwo = 0;
	case 4: // Checks made by KeyHit Function
		if (yOne > 379 && yOne < 396){
			switch (yOne){
			case 395:
				yOne = 505;
				break;
			case 390:
				yOne = 500;
				break;
			case 385:
				yOne = 495;
				break;
			case 380:
				yOne = 490;
				break;
			}
			return 1;
		}
		if (yTwo > 379 && yTwo < 396){
			switch (yTwo){
			case 395:
				yTwo = 505;
				break;
			case 390:
				yTwo = 500;
				break;
			case 385:
				yTwo = 495;
				break;
			case 380:
				yTwo = 490;
				break;
			}
			return 1;
		}
		else return 0;
	} // End Switch
	if (yOne == 400) {
		// Checks if yOne was missed
		yOne = 0;
		readimagefile("PIX//notemiss.jpg", 596, 390, 613, 410);
		score -= 10;
	}
	if (yTwo == 400) {
		// Checks if yTwo was missed
		yTwo = 0;
		readimagefile("PIX//notemiss.jpg", 596, 390, 613, 410);
		score -= 10;
	}
	if (yOne == 510)yOne = 0;
	if (yTwo == 510)yTwo = 0;
} // End SoundZ


void Practice(){

	int quit = 1;
	char KEY;
	mousehandle = 6;
	///////// Loads Piano Wave /////////////////////////
	WaveManager Piano_wave(26);
	Piano_wave.Load(0, "SOUNDS\\Sound_A.wav");
	Piano_wave.Load(1, "SOUNDS\\Sound_B.wav");
	Piano_wave.Load(2, "SOUNDS\\Sound_C.wav");
	Piano_wave.Load(3, "SOUNDS\\Sound_D.wav");
	Piano_wave.Load(26, "SOUNDS\\chuck.wav");
	///////////////////////////////////////////////////////////////////////
	while (quit){
		readimagefile("PIX//Practice.jpg", 0, 0, 640, 480);
		static int counter = 0;
		if (counter > 30)SoundA(0);
		if (counter > 50)SoundB(0);
		if (counter > 64)SoundC(0);

		counter++;
		if (kbhit()){
			KEY = getch();

			switch (KEY){
			case 'a':
				if (SoundA(4)){
					Piano_wave.Play(0);
				}
				else {
					Piano_wave.Play(26);
				}
				break;
			case 'b':
				if (SoundB(4)){
					Piano_wave.Play(1);
				}
				else {
					Piano_wave.Play(26);
				}
				break;
			case 'c':
				if (SoundC(4)){
					Piano_wave.Play(2);
				}
				else {
					Piano_wave.Play(26);
				}
				break;
			case 'd':
				if (SoundD(4)){
					Piano_wave.Play(3);
				}
				else {
					Piano_wave.Play(26);
					score -= 10;
				}
				break;
			} // End Switch
		} // End if KeyHit
		if (selector == 13){
			ResetCounters();
			RockBombStart();
		} // End if Selector == 13
	} // End While
} // End PlaySong


