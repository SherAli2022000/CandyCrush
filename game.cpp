//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include"GameBoard.h"
#include <iostream>
#include <fstream>
#include<string>

#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */

GameBoard ali;


void MousePressedAndMoved(int x, int y) {
	//cout << x << " " << y << endl;

if(GLUT_UP)
{
ali.setswap1(x,800-(y*(800/703)));
cout<<x<<" "<<y<<endl;

}
glutPostRedisplay();

	
}

void MouseClicked2(int button, int state, int x, int y)
{
if(ali.getchoice()==4)
{
if (button==GLUT_RIGHT_BUTTON)	
{
	
	if(state==GLUT_DOWN)
	{
	ali.setswap2(x,800-(y*(800/703))-70);
	}
		//cout<<x<<"a"<<y<<endl;
	
	glutPostRedisplay();
	
}
}
}


void MouseClicked1(int button, int state, int x, int y)
{
if(ali.getchoice()==4)
{

if (button==GLUT_LEFT_BUTTON)	
{
	if(state==GLUT_DOWN)
	{

	ali.setswap1(x,800-(y*(800/703))-70);

	//cout<<x<<" " <<y<<endl;
	
	if( (ali.returnG1x()>=270 && ali.returnG1x()<=320) && (ali.returnG1y()>=60 && ali.returnG1y()<=130))
	{
	ali.setchoice(5);
	ali.setswap1(0,0);
	ali.setswap2(0,0);
	glutPostRedisplay();
	}

	if(ali.returnG1x()>=500 && ali.returnG1x()<=560 && ali.returnG1y()>=120 && ali.returnG1y()<=170)
	{
	ali.setswap1(0,0);
	ali.setswap2(0,0);
	ali.setchoice(6);
	glutPostRedisplay();
	}	
	glutMouseFunc(MouseClicked2);
	
	
	return;
	
	}
		
	
}
}
if(ali.getchoice()==6)
{
if (button==GLUT_LEFT_BUTTON)	
{
if(state==GLUT_DOWN)
	{
ali.setswap1(0,0);
ali.setswap2(0,0);
ali.setchoice(4);
glutPostRedisplay();
}
}
}
if (button==GLUT_LEFT_BUTTON)	
	{	
		if(state==GLUT_DOWN)
		{
		if(ali.getchoice()==0)
		{	
			int l;
			l=800-(y*(800/703)+90);
				if(x>300 && l>300 && l<600)
				{
				ali.setchoice(1);
				}
				if(x<300 && l>300 && l<600)
				{
				exit(0);
				}
				if(x>300 && l<300)
				{
				ali.setchoice(2);
				}
			glutPostRedisplay();
		}
		if(ali.getchoice()==2)
		{
			int l;
			l=800-(y*(800/703)+90);
			if(x>=40 && x<=160 && l>=30 && l<=82)
			{
			ali.setchoice(0);
			} 
			glutPostRedisplay();
		}
		if(ali.getchoice()==1)
		{
			int l;
			l=800-(y*(800/703)+90);
			if(x>=40 && x<=160 && l>=30 && l<=82)
			{
			ali.setchoice(0);
			} 
			else if(x>=200 && x<=440 && l>=450 && l<=600)
			{
			ali.setchoice(4);
			}
			glutPostRedisplay();
		}
		}
		if(ali.getchoice()==5)
		{
		int l;
		l=800-(y*(800/703)+90);
		if(x>=190 && x<=440 && l>=290 && l<=400)
		{
		exit(0);
		} 
	
		else if(x>=190 && x<=440 && l>=450 && l<=550)
		{
		ali.setchoice(4);
		}
		glutPostRedisplay();
		}
	}
}



void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	
}
void MouseMoved(int x, int y) 
{
	if(ali.getchoice()==0)
	{
	int l;
	l=800-(y*(800/703)+90);
	
	ali.setMenuLoc(x,l);
	glutPostRedisplay();
	}
	
	
}





/*
 * Main Canvas drawing function.
 * */




void GameDisplay()/**/{
if (ali.getchoice()==0)
{
ali.MenuDisplay();
glutMouseFunc(MouseClicked1);
glutPassiveMotionFunc(MouseMoved);
}

else if(ali.getchoice()==2)
{
ali.PlayerDisplay();
}
else if(ali.getchoice()==1)
{
ali.gameSelect();
glutMouseFunc(MouseClicked1);
}
else if (ali.getchoice()==5)
{
ali.Pause();
glutMouseFunc(MouseClicked1);
}

else if(ali.getchoice()==6)
{
ali.hint();
glutMouseFunc(MouseClicked1);
glutSwapBuffers();
}
else if(ali.getchoice()==7)
{
ali.levelDisplay();
glutSwapBuffers();
}
else if(ali.getchoice()==4)
{ 	
	
if(ali.getGameStart()==0)
{
	
ali.getGems();
ali.setGameStart(1);
ali.setlevel(1);
ali.setscore(0);
ali.settime(20);
}		
ali.display();
glutMouseFunc(MouseClicked1);


if(ali.removePossible()==1)
{
ali.checkremove();
ali.inbetween();
}
ali.ifnoExist();
ali.Swapcheck();

glutSwapBuffers();
// do not modify this line..
}

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
	
	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	
	glutTimerFunc(1000.0, Timer, 0);
	if(ali.getchoice()==4)
	{	
	ali--;
	}
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */



/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */

/*
 * our gateway main function
 * */



int main(int argc, char*argv[]) {
	string m,n;
	cout<<"Enter your first and last name"<<endl;
	cin>>m;
	cin>>n;
	ali.setName(m,n);
	
	int width = 600, height = 800; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	
	
	
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	
	//glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	//glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);
	
	//glutMouseFunc(MouseClicked);
	//glutPassiveMotionFunc(MouseMoved); // Mouse
	//glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
