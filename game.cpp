//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "board.h"
#include <iostream>
#include<string>

using namespace std;

Board *board = new Board();
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//--------------------------------------------------
board->draw();

	
	//---------------------------------------------------
	
	
	glutSwapBuffers(); // do not modify this line.
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
		delete board;
		exit(1); // exit the program when escape key is pressed.
	}
	
	if (key == 'p' || key == 'P') // key for pause
	{
		//do something if p is pressed
		//cout << "p pressed" << endl;
		board->gamePaused = !board->gamePaused;
		
	}
	if (key == 'h' || key == 'H') // key for pause
	{
		board->displayHint = true;
		board->hintSeconds = 0;
		board->level->currentScore-=5;
	}
	if (key == 'r' || key == 'R') // key for pause
	{
		board->restart();
		board->settings=false;
		board->lives--;
		cout<<"Lives: "<<board->lives<<endl;
	}
	if (key == 'l' || key == 'L') // key for pause
	{
		board->toggleShowLevels();
	}
	if (key == 'q' || key == 'Q') // key for pause
	{
	board->restart();
	board->settings=false;
	}
	
	if(key=='s' || key=='S'){
		board->S->music1=0;
		board->S2->music2=0;
		board->S->playMahJam();
		board->S2->playMahJam();

		
	}
	if(key=='A' || key=='a'){
		board->S->music1=1;
		board->S2->music2=1;
		board->S->playMahJam();
		board->S2->playMahJam();
		
		
	}
	if(key=='u'||key=='U'){
		board->highscore=true;
	}

	if(key=='j'||key=='J'){
		board->j=1;
	}
	if(key=='k'||key=='K'){
		board->j=2;
	}
	

	
	glutPostRedisplay();
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
	glutPostRedisplay();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(10.0, Timer, 0);
}
/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x1, int y1) {
	//cout <<"pressed:"<< x1 << " " << y1 << endl;
}
void MouseMoved(int x2, int y2) {
	cout << "moved:" << x2 << " " << y2-500 <<endl;
}
/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state==GLUT_DOWN) // dealing only with left button
	{
		
		 		if(x>=150 && x<=290 && y>=320 && y<=390){
			 board->menu=true;
			 board->tetra=false;
				 }
		 if(x>=150 && x<=290 && y>=420 && y<=490 && board->showL){
			 board->settings=true;
		 }
		 // if we show levels
		 // we catch the level clicked on the screen
		if (board->showL){

			if (x>=110 && x<=160 && y>=230 && y<=280 && !board->level->completedLevels[1]){
				board->level->currentLevel = 1; 
				board->restart();
				board->showL=false;
				board->gamePaused = false;
			}
			if (x>=170 && x<=220 && y>=230 && y<=280 && !board->level->completedLevels[2]){
				board->level->currentLevel = 2; 
				board->restart();
				board->showL=false;
				board->gamePaused = false; 
			}
			if (x>=230 && x<=280 && y>=230 && y<=280 && !board->level->completedLevels[3]){
				board->level->currentLevel = 3; 
				board->restart();
				board->showL=false;
				board->gamePaused = false;
			}
			if (x>=290 && x<=340 && y>=230 && y<=280 && !board->level->completedLevels[4]){
				board->level->currentLevel = 4; 
				board->restart();
				board->showL=false;
				board->gamePaused = false;
			}
			if (x>=170 && x<=220 && y>=300 && y<=350 ){
				board->z=1;
				cout<<"Normal Mode has been selected"<<endl;
				
			}
			if (x>=230 && x<=280 && y>=300 && y<=350 ){
				board->z=2;
				cout<<"Time Trial Mode has been selected"<<endl;
				
			}

		}

		// if we show game we
		// catch the gem clicked
		else{
		board->gemClicked(x,y);
		}
		return;
	}
	else 
		if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			}
	//glutPostRedisplay();
}

////////////////////////////////////////////////////////////
/// Play a music
///
////////////////////////////////////////////////////////////

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 440, height = 500; // i have set my window size to be 800 x 600
	// we intialize board;
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(10, 200); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Bejeweled Clone"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(50.0, Timer, 0);
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	board->S->playMahJam();
	

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	
	return 1;
}
#endif /* AsteroidS_CPP_ */
