//#define MELTDOWN //if defined, compiles the meltdown sequence
//#define SOUNDfx //if defined, enables sound effects
#define CAFFEINE //if defined, prevents some Sleep() functions from compiling - nothe that #ifndef is used (opposite effect of #ifdef)

#pragma comment( lib, "winmm" ) //request Windows multimedia API, this is a .DLL file you are linking into.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h> //required for sound fucntionality
#include <time.h>
#include "graphics.h"
#include "CyCalc.h"
#include "WaveManager.h"

int main(){


//Graphing variables (do not modify)
int dr, md, gd;
int gm, drawing_color;

//CyCalc Variables
//declare all variables for main() usage
//do this before everything else in main()
char operation;// = 0x00; //8 bit variable, stores one ASCII character
double first = 0; //does not matter what you initialize to
double second = 0;
int quit = 1; //do not quit


//___Initializes Game Engine__________
initwindow(640, 480);

setbkcolor(WHITE);
welcome();


registermousehandler(WM_LBUTTONDOWN, LClick);


readimagefile("PIX//Final_Cycalc.jpg", 0, 0, 640, 480);




while (quit) {

printf("\nEnter first number >");
scanf("%lf", &first); //Do not forget the address operator &


printf("Enter second number >");
scanf("%lf", &second);


printf("Please, Choose Operation. (Type ? for HELP)>");
scanf("%s", &operation); //%s is string, %c is character



	if(operation == '+'){
	printf("SUM = %lf", sum(first, second));
	}//if + ends

	if(operation == '-'){
		printf("SUB = %lf", sub(first, second));
	}//if - ends

	if(operation == '*'){
		printf("MUL = %lf", mul(first, second));
	}//if * ends

	if(operation == '/'){
		printf("DIV = %lf", Div(first, second));
	}//if / ends

	if(operation == 's'){
		printf("SINE > %lf", Sine(first));	
	}//if / ends

	if(operation == 'h') run(); //run histograms

	if(operation == '?') help();

	if(operation == 'q') quit = 0;

	if(operation == 'd') draw(14); //send color to draw application

	if(operation == 'D') draw(4);

	if(operation == 'S') plotter(1);
	
	if(operation == 'c') cleardevice();

	if(operation == 'p') runpong();

	if (operation == 't') RockBombStart();

}//while ends


 getchar();
 return 0;
}




/*
int i = 0, j = 1, k = 5;

while (k>0){

	while (i <= 5-k){printf("."); i++;}
	while (j <= 2 * k - 1){printf("Are we there yet?\n");}

	printf("\n");

	k--;
}
*/