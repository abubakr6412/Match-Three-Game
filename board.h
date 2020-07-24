#include"Sound.cpp"
#include "gem.h"
#include "level.h"
#include "player.h"
#include "stdlib.h"
#include "hint.h"
#include"util.h"

#include"shape.cpp"

using namespace std;

class Board{
public:

	Gem* gemMatrix[8][8];
	int grid[8][8];
	Gem* gemClicked1;
	Gem* gemClicked2;
	Level* level;
	Shape sdraw;
	int nrGemClicked;
	int copyMatrix[8][8];
	int dropsMatrix[8][8];
	bool displayHint;
	bool showL;
	bool menu=false;
	bool ani=false;
	int zoom=0;
	int z;
	int hintSeconds;
	bool highscore;
	char playr[100];
	bool finish;
	
	
	// operation = 1 => remove gems
	// operation = 2 => calculate drops
	// operation = 3 => add animation
	// operation = 4 => stationary
	int operation; 
	int gameMode;
	bool gamePaused;
	Player *player;
	bool gameOver;
	int dirX[4];
	int dirY[4];
	int lives=3;
	bool savestate=0;
	bool tetra=false;
	bool hexa=false;
	int octa=0;
	int deca=0;
	bool click=false;
	int j=0;
	bool settings;
	Sound*S;
	Sound2*S2;
	Board();
	void swapColors(Gem* g1,Gem* g2);
	bool checkBounds(int x, int y);
	void removeCompletedGems();
	void removeGem(int posX, int posY);
	void drawInitialBoard();
	void updateBoard();
	Level * saveBoard();
	void restoreBoard();
	void reset();
	void display();
	
	void toggleShowLevels();
	void addGems();
	bool isFull();
	int nrGems();
	void calculateDrops();
	void animate();
	void restart();
	bool endAnimation();
	void performsOperations();
	void addAnimations();
	void animate00();
	Hint* hint();
	Hint* hint2();
	bool hasRemoval();
	bool hasRemoval(int px,int py);
	bool isGameOver();
	void gemClicked(int x, int y);
	Gem* getGemAtPosition(int _x, int _y);
	void draw();
	
	
};
