#include"board.h"

#include <iostream>
using namespace std;

Board::Board(){
		InitRandomizer();
		//---------------------------------------
char playerName[100];
		//-------------------------------------
		// we read player name
		// and we create new Player
		player = new Player();
		// We create new Level
		// and set default level to 1
		level = new Level();
		S=new Sound();
		S2=new Sound2();
		
		
		player->readfile(player->scores);
		cout<<"If you would like to start a new game enter 0."<<endl;
		cout<<"Else if you want to load the recent save file enter 1"<<endl;
		cin>>savestate;
		if(savestate==0){
		cout<<"Enter player name:";
		cin>>playerName;
		level->currentLevel = 1;
		level->currentScore = 0;
		}
		if(savestate==1){
			player->savefileread();
			cout<<player->savedata.name<<endl;
			cout<<player->savedata.level<<endl;
			cout<<player->savedata.score<<endl;
			cout<<player->savedata.time<<endl;

			strcpy(playerName,player->savedata.name);
			level->currentLevel=player->savedata.level;
			level->time+=player->savedata.time;
			level->currentScore=player->savedata.score;
			if(player->savedata.level==2){
				level->completedLevels[1]=true;
			}
			if(player->savedata.level==3){
				level->completedLevels[1]=true;
				level->completedLevels[2]=true;
			}
			if(player->savedata.level==4){
				level->completedLevels[1]=true;
				level->completedLevels[2]=true;
				level->completedLevels[3]=true;
			
			}
			

		}
		
			
		
		//cin>>z;	
		string s(playerName);
		player->setName(s);
		strcpy(playr,playerName);
		
		player->sortData(player->scores,4);
		
		//-----------------------------------------------
		
		//-----------------------------------------------

		
		
		
		dirX[0] =  0;
		dirY[0] = -1;
		dirX[1] =  0;
		dirY[1] =  1;	
		dirX[2] = -1;
		dirY[2] =  0;		
		dirX[3] =  1;
		dirY[3] =  0;
		restart();


	}
	
	void Board::restart(){
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
				gemMatrix[i][j] = new Gem(1+rand()%5,20+i*50,20+j*50);
			}
		}
		updateBoard();	
		nrGemClicked = 1;
		gamePaused = true;
		operation = 1;
		finish=true;
		level->currentScore = 0;
		gameOver = false;
		displayHint=false;
		showL = true;
		settings=false;
		highscore=false;
		
		
	
	}
	
	void Board::toggleShowLevels(){
		showL = !showL;
	}
	
	void Board::updateBoard(){
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
				if (getGemAtPosition(i,j)!=NULL)
					grid[i][j] = getGemAtPosition(i,j)->color;
				else 
					grid[i][j] = 0;
			}
		}
		
	}

	void Board::swapColors(Gem *g1, Gem *g2){
		int temp;
		
		cout<<"swap"<<endl;
		cout<<g1->getX()<<" "<<g1->getY()<<endl;
		cout<<g2->getX()<<" "<<g2->getY()<<endl;
		if ((abs(g1->getX() - g2->getX())==1 
			&& (g1->getY()-g2->getY())==0) ||
			(abs(g1->getY() - g2->getY())==1 
			&& (g1->getX()-g2->getX())==0))

			if((((grid[g1->getX()][g1->getY()]==grid[g2->getX()-2][g2->getY()])&&(grid[g1->getX()][g1->getY()]==grid[g2->getX()-3][g2->getY()]))
				||((grid[g1->getX()][g1->getY()]==grid[g2->getX()+1][g2->getY()-1])&&(grid[g1->getX()][g1->getY()]==grid[g2->getX()+1][g2->getY()-2]))
				||((grid[g1->getX()][g1->getY()]==grid[g2->getX()-1][g2->getY()+1])&&(grid[g1->getX()][g1->getY()]==grid[g2->getX()-1][g2->getY()-1]))
				||((grid[g1->getX()][g1->getY()]==grid[g2->getX()+2][g2->getY()])&&(grid[g1->getX()][g1->getY()]==grid[g2->getX()+3][g2->getY()]))
				||((grid[g1->getX()][g1->getY()]==grid[g2->getX()-2][g2->getY()])&&(grid[g1->getX()][g1->getY()]==grid[g2->getX()-3][g2->getY()]))
				||((grid[g1->getX()][g1->getY()]==grid[g2->getX()-1][g2->getY()-1])&&(grid[g1->getX()][g1->getY()]==grid[g2->getX()-2][g2->getY()-1]))
			||((grid[g1->getX()][g1->getY()]==grid[g2->getX()+1][g2->getY()+1])&&(grid[g1->getX()][g1->getY()]==grid[g2->getX()+2][g2->getY()+1]))||((grid[g1->getX()][g1->getY()]==grid[g2->getX()][g2->getY()+1])&&(grid[g1->getX()][g1->getY()]==grid[g2->getX()][g2->getY()+2]))||((grid[g1->getX()][g1->getY()]==grid[g2->getX()][g2->getY()+1])&&(grid[g1->getX()][g1->getY()]==grid[g2->getX()+1][g2->getY()]))||((grid[g1->getX()][g1->getY()]==grid[g2->getX()][g2->getY()+2])&&(grid[g1->getX()][g1->getY()+2]==grid[g2->getX()][g2->getY()+3]))||((grid[g1->getX()][g1->getY()]==grid[g2->getX()][g2->getY()-1])&&(grid[g1->getX()][g1->getY()]==grid[g2->getX()-1][g2->getY()])||((grid[g1->getX()][g1->getY()]==grid[g1->getX()][g1->getY()+1])&&grid[g1->getX()][g1->getY()]==grid[g1->getX()+1][g1->getY()+1]))||((grid[g1->getX()][g1->getY()]==grid[g1->getX()][g1->getY()+1])&&grid[g1->getX()][g1->getY()]==grid[g1->getX()-1][g1->getY()-1])||((grid[g1->getX()][g1->getY()]==grid[g1->getX()][g1->getY()+1])&&grid[g1->getX()][g1->getY()+1]==grid[g1->getX()][g1->getY()+3])||((grid[g1->getX()][g1->getY()]==grid[g1->getX()+1][g1->getY()])&&grid[g1->getX()][g1->getY()+1]==grid[g1->getX()+3][g1->getY()]))&&(((g2->getX()-g1->getX()>0&&g2->getX()-g1->getX()<2)||(g1->getX()-g2->getX()>0&&g1->getX()-g2->getX()<2))||((g2->getY()-g1->getY()>0&&g2->getY()-g1->getY()<2)||(g1->getY()-g2->getY()>0&&g1->getY()-g2->getY()<2)))){

			
			{

			
				temp = g1->color;
				g1->color = g2->color;
				g2->color = temp;
			
				temp = g1->interval;
				g1->interval = g2->interval;
				g2->interval = temp;
			}
			
	}
	}
	bool Board::checkBounds(int x, int y){
		if (x<0 || y<0 || x>=8 || y>=8){
			return false;
		}
		return true;
	}
	
	Gem* Board::getGemAtPosition(int _x, int _y){
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
				if (gemMatrix[i][j]!=NULL && gemMatrix[i][j]->getX()== _x && gemMatrix[i][j]->getY()== _y){
					return gemMatrix[i][j];
				}
			}
		}
		return NULL;
	}
	void Board::removeGem(int _x, int _y){
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
				if (gemMatrix[i][j]!=NULL && gemMatrix[i][j]->getX()== _x && gemMatrix[i][j]->getY()== _y){
					gemMatrix[i][j] = NULL;
				}
			}
		}		
	}
	
	// has to be modified, incomplete method
	bool Board::isGameOver(){
		return false;
	}

bool Board::hasRemoval(int px, int py){
				for (int i=0;i<4;i++){
					int k=0;
						while (
							checkBounds(px+k*dirX[i],py+k*dirY[i])==true &&
							copyMatrix[px+k*dirX[i]][py+k*dirY[i]]==
							copyMatrix[px][py])
							{
								k++;
							}					
						if (k>=3){
							return true;
						}
					}
			return false;
		}
	bool Board::hasRemoval(){
		for (int px=0;px<8;px++)
			for (int py=0;py<8;py++)
				for (int i=0;i<4;i++){
					int k=0;
						while (
							checkBounds(px+k*dirX[i],py+k*dirY[i])==true &&
							copyMatrix[px+k*dirX[i]][py+k*dirY[i]]==
							copyMatrix[px][py])
							{
								k++;
							}					
						if (k>=3){
							return true;
						}
					}
			return false;
		}
	void Board::removeCompletedGems(){
		for (int i=0;i<8;i++)
			for (int j=0;j<8;j++){
				if (getGemAtPosition(i,j)!=NULL)
					copyMatrix[i][j] = getGemAtPosition(i,j)->color;
				else
					copyMatrix[i][j] = 0;
			}
		for (int px=0;px<8;px++)
			for (int py=0;py<8;py++)
				for (int i=0;i<4;i++){
					int k=0;
						while (
							getGemAtPosition(px+k*dirX[i],py+k*dirY[i])!=NULL &&
							checkBounds(px+k*dirX[i],py+k*dirY[i])==true &&
							getGemAtPosition(px+k*dirX[i],py+k*dirY[i])->color==
							getGemAtPosition(px,py)->color)
							{
								k++;
							}
						if (k==3){
							level->currentScore+=1.5;
							S2->playMahJam();

							//level->Trialtimer+1.5;
						}
						if (k==4){
							level->currentScore+=4;
							
							//level->Trialtimer+4;
						}	
						if (k>=5){
							level->currentScore+=12.5;
							
							//level->Trialtimer+12.5;
						}						
						if (k>=3){
							int index=0;
							while (getGemAtPosition(px+index*dirX[i],py+index*dirY[i])!=NULL &&
								checkBounds(px+index*dirX[i],py+index*dirY[i]) &&
								getGemAtPosition(px+index*dirX[i],py+index*dirY[i])->color==
								getGemAtPosition(px,py)->color &&
								index<=k)
								{
									copyMatrix[px+index*dirX[i]][py+index*dirY[i]] = 0;
									index++;
								}	
					}
		}
		for (int i=0;i<8;i++)
			for (int j=0;j<8;j++){
				if (copyMatrix[i][j]==0)
					removeGem(i,j);
					
			}
		}
	bool Board::isFull(){
		for (int i=0;i<7;i++)
		for (int j=0;j<7;j++){
			if(getGemAtPosition(i,j)!=NULL)
					return false;
			}
		return true;
	}

	void Board::animate(){
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
				if (gemMatrix[i][j]!=NULL)
					gemMatrix[i][j]->animate();
			}
		}
	}
	Level* Board::saveBoard(){
	fstream new_file; 
new_file.open("PlayerScore.txt",ios::out);  
if(!new_file) 
{
cout<<"File creation failed";
}
else
{
cout<<"New file created";
for(int i=0;i<4;i++){


new_file<<"-----------------------------------------"<<endl;
new_file<<"Player Name: "<<player->scores[i].name<<endl;
new_file<<"Play time: "<<player->scores[i].time<<"Seconds "<<endl;
new_file<<"Highest Level Reached: "<<player->scores[i].level<<endl; 
new_file<<"HighScore of Player: "<<player->scores[i].score<<endl<<endl;
new_file<<"-----------------------------------------"<<endl;
}

new_file.close(); 
}   


	}
	void Board::restoreBoard(){
	
	}
	void Board::reset(){
	
	}
	int Board::nrGems(){
		int nr=0;
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
				if (gemMatrix[i][j]!=NULL)	
				{
						//cout<<gemMatrix[i][j]->color<<" "<<endl;
						//nr++;
				}
			}
		}
		return nr;
	}
	bool Board::endAnimation(){
		//cout<<endl;
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){	
				//cout<<gemMatrix[i][j]->interval<<" ";
				if (gemMatrix[i][j]!=NULL && gemMatrix[i][j]->interval!=0)
					return false;
			}
			//cout<<endl;
		}
		return true;
	}
	void Board::calculateDrops(){
		for (int i=0;i<8;i++)
			for (int j=1;j<8;j++){	
				dropsMatrix[i][j]=0;
			}
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){	
					for (int k=j-1;k>=0;k--){
						if (grid[i][k] == 0){
								dropsMatrix[i][j]++;
						}
					}
				}
			}
	}
	void Board::addAnimations(){
		for (int i=0;i<8;i++)
			for (int j=0;j<8;j++){	
				if (getGemAtPosition(i,j) != NULL)
					for (int k=1;k<=dropsMatrix[i][j];k++){
							getGemAtPosition(i,j)->addAnimation();
					}
			}
	}
	void Board::display(){
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){	
				//cout<<getGemAtPosition(j,7-i)->color<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){	
				cout<<dropsMatrix[j][7-i]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	void Board::animate00(){
		getGemAtPosition(7,7)->addAnimation();
	}
	void Board::performsOperations(){
		//cout<<"operation="<<operation<<endl;
		switch (operation){
			case 1:
				removeCompletedGems();
				//filldrops();
				//---------------------------------
				strcpy(player->savedata.name,playr);
				player->savedata.time=level->timer();
				player->savedata.level=level->currentLevel;
				player->savedata.score=level->currentScore;
				player->savefilewrite();
				//----------------------------
				operation++;

				break;
			case 2:
				calculateDrops();
				operation++;		
				break;
			case 3:
				addAnimations();
				operation++;
				break;
			case 4:
				animate();
				if (endAnimation()==true){
					operation++;
				}
				break;
			case 5:
				if (hintSeconds>=100){
					hintSeconds=0;
					displayHint = false;
				}
				if (hint()!=NULL){
					operation = 1;
				}
				else {
					gameOver=true;
					
					
					strcpy(player->scores[3].name,playr);
					player->scores[3].score=level->currentScore;
					player->scores[3].level=level->currentLevel;
					player->scores[3].time=level->timer();
					
					if(finish){
						player->sortData(player->scores,4);
						player->write();
						finish=false;
					}
					
					
				
					saveBoard();
					break;
				}
				if (level->currentScore>=level->requiredScores[level->currentLevel]){
						level->completedLevels[level->currentLevel] = true;
						showL = true;
						
						cout<<"completed level"<<level->currentLevel;
				}
		}	
	}
	void Board::gemClicked(int x, int y){
			if (!lives==0){
				int _x = (x-20)/50;
				int _y = (500-y)/50;
				nrGemClicked=1-nrGemClicked;
				
				Gem * gClicked = getGemAtPosition(_x,_y);

				if (nrGemClicked==0 && gClicked!=NULL){
					gemClicked1 = gClicked;
					//cout<<"click1"<<endl;
				}
					
				if (nrGemClicked==1 && gClicked!=NULL && !gamePaused){
					gemClicked2 = gClicked;
					swapColors(gemClicked1,gemClicked2);
					//cout<<"click2"<<endl;
					displayHint = false;
				}
			}
	}
	
	
void Board::draw(){
	if(ani==false){
zoom++;
	}
	if(zoom==114){
		ani=true;
	}
	

	if(hexa==false){
deca++;
	}
	if(deca==70){
		hexa=true;
	}
	
		if(tetra==false){
octa++;
	}
	if(octa==50){
		tetra=true;
	}
	


if(menu){
					
	if (!showL){
		
		updateBoard();
		if (!gamePaused){
			performsOperations();
		}
		
		Hint* _hint = hint();
		if (displayHint==true && _hint!=NULL){
			
			Gem *g1 = _hint->gem1;
			Gem *g2 = _hint->gem2;
			DrawSquare( g1->positionX-5 , 
				g1->positionY-5 ,
				55, 
				colors[WHITE]); 
			DrawSquare( g2->positionX-5 , 
				g2->positionY-5 ,
				55, 
				colors[WHITE]); 
			//cout<<"hint seconds:"<<hintSeconds<<endl;
		}
		hintSeconds++;		
		// we draw the score
		char score[20];
		char time[20];
		char trialscore[20];
		//-----------------------------------------
		if(lives==3){
DrawCircle(420,440,10,colors[WHITE]);
				}
				if(lives==2){
DrawCircle(420,440,10,colors[NAVY]);
				}
				if(lives==1){
DrawCircle(420,440,10,colors[ORANGE_RED]);
				}
			//--------------------------------------------

		snprintf(score,20,"%d",(int)level->currentScore);
		snprintf(trialscore,20,"%d",(int)level->trialtimer());
		snprintf(time,20,"%d",(int)level->timer());
		DrawString(100,4700,50,20, "Score:",
			colors[WHITE]);
					
		DrawString(1650,4700,50,20, score,
			colors[WHITE]);
					
		DrawString(6700,4700,50,20, "Name:",
			colors[WHITE]);	
					
		DrawString(8400,4700,50,20, player->name,
			colors[WHITE]);		
			
			DrawString(4450,4700,50,20, "Time:",
			colors[WHITE]);
			DrawString(5900,4700,50,20, time,
			colors[WHITE]);
			
		if(z==1){

				//we draw progress normal bar
		DrawRectangle( 20, 420, 400-400*((1.0*level->currentScore)/level->requiredScores[level->currentLevel]), 40, colors[BLUE]); 
		
		DrawString(180, 430, "Progress",
			colors[WHITE]);	
	}
if(z==2){ 
		//We draw time trial progress bar;
		DrawRectangle( 20, 420, 200+level->Trialtimer, 40, colors[BLUE]);
		DrawString(180, 430, "Progress",
			colors[WHITE]);	
}


			
		for (int i=0;i<8;i++)
			for (int j=0;j<8;j++)
			{
				if (getGemAtPosition(i,j)!=NULL){
					// we draw the gems
					if (grid[i][j]==1){
						
									sdraw.reccirc(getGemAtPosition(i,j)->positionX , 
									getGemAtPosition(i,j)->positionY);
									
					}

					if (grid[i][j]==2){
							
									sdraw.recrec(getGemAtPosition(i,j)->positionX , 
									getGemAtPosition(i,j)->positionY);
					}
					if (grid[i][j]==3){
						sdraw.robo(getGemAtPosition(i,j)->positionX , 
									getGemAtPosition(i,j)->positionY);
									  		
					}
					if (grid[i][j]==4){
						sdraw.tricircs(getGemAtPosition(i,j)->positionX , 
									getGemAtPosition(i,j)->positionY);
					}
					if (grid[i][j]==5){
						 sdraw.tritri(getGemAtPosition(i,j)->positionX , 
									getGemAtPosition(i,j)->positionY);
						
					}
				}
			}
			if (
				gameOver){
					DrawRectangle(120,230,200,50,colors[BLUE_VIOLET]); 					
					DrawString(4000,2500,50,20, "Game Over !",colors[RED]);
				}
		} 
		// we draw levels
		else {
			DrawRoundRect( 100, 100 ,-3,13,colors[WHITE],octa-30);
DrawRoundRect( 150, 400 ,-3,13,colors[BLACK],octa-30);
DrawRoundRect( 60,250 ,-3,13,colors[DARK_CYAN],octa-30);
DrawRoundRect( 0, 450 ,-3,13,colors[DARK_SALMON],octa-30);
DrawRoundRect( 250, 360 ,-3,13,colors[DARK_VIOLET],octa-30);
DrawRoundRect( 30, 0 ,-3,13,colors[DARK_SLATE_BLUE],octa-30);
DrawRoundRect( 360, 150 ,-3,13,colors[SLATE_GRAY],octa-30);
DrawRoundRect( 380, 420 ,-3,13,colors[BLACKO],octa-30);
DrawRoundRect( 290, 50 ,-3,13,colors[DARK_ORANGE],octa-30);

DrawRoundRect( 100, 100 ,-3,13,colors[BLACK],20);
DrawRoundRect( 150, 400 ,-3,13,colors[BLACK],20);
DrawRoundRect( 60,250 ,-3,13,colors[BLACK],20);
DrawRoundRect( 0, 450 ,-3,13,colors[BLACK],20);
DrawRoundRect( 250, 360 ,-3,13,colors[BLACK],20);
DrawRoundRect( 30, 0 ,-3,13,colors[BLACK],20);
DrawRoundRect( 360, 150 ,-3,13,colors[BLACK],20);
DrawRoundRect( 380, 420 ,-3,13,colors[BLACK],20);
DrawRoundRect( 290, 50 ,-3,13,colors[BLACK],20);
			
				if (!level->completedLevels[1]){
					DrawSquare(110,230,50,colors[DARK_KHAKI]); 
				}
					else
				{
					DrawSquare(110,230,50,colors[GRAY]); 
				}
				
				if (!level->completedLevels[2]){
					DrawSquare(170,230,50,colors[DARK_KHAKI]);
				} 	
					else
				{
					DrawSquare(170,230,50,colors[GRAY]); 
				}	
				
				if (!level->completedLevels[3]){
					DrawSquare(230,230,50,colors[DARK_KHAKI]);
				}	
					else
				{
					DrawSquare(230,230,50,colors[GRAY]); 
				} 	
			
				if (!level->completedLevels[4]){
					DrawSquare(290,230,50,colors[DARK_KHAKI]); 
				}		
					else
				{
					DrawSquare(290,230,50,colors[GRAY]); 
				}				
					
				DrawString(130,245, "1",colors[BLACK]);
				DrawString(190,245, "2",colors[BLACK]);	
				DrawString(250,245, "3",colors[BLACK]);	
				DrawString(310,245, "4",colors[BLACK]);	
				
				DrawString(90,345, "Please select a level to play",colors[WHITE]);

				DrawSquare(170,150,50,colors[DARK_KHAKI]);
				DrawSquare(230,150,50,colors[DARK_KHAKI]);
				DrawString(170,165, "N.M",colors[BLACK]);
				DrawString(230,165, " T.T",colors[BLACK]);

				//------------------------------------------------
				
				
				//------------------------------------------------


			}
	}



if(menu==false){
		//--------------PlayButton
	DrawRectangle(153,zoom,145,70,colors[DARK_BLUE]);
	DrawRectangle(165,zoom+14,120,40,colors[SLATE_GRAY]);
	DrawString(170,zoom+28,"Play Game",colors[WHITE]);
	//---------------Aesthetics
	
	// DrawRectangle(zoom-114,0,40,510,colors[DARK_RED]);
	// DrawRectangle(515-zoom,0,40,510,colors[DARK_RED]);
	// DrawCircle(220,zoom+420,zoom+106,colors[GOLD]);
	// DrawRectangle(360,zoom-114,zoom-74,zoom+186,colors[DARK_RED]);
	// DrawRectangle(40,zoom-114,zoom-74,zoom+186,colors[DARK_RED]);
	// DrawRectangle(320,zoom-154,zoom-74,zoom+186,colors[DARK_RED]);
	// DrawRectangle(80,zoom-154,zoom-74,zoom+186,colors[DARK_RED]);
	// DrawRectangle(120,zoom+146,200,zoom-94,colors[DARK_RED]);
	// DrawRectangle(40,zoom+186,360,zoom-94,colors[DARK_RED]);
	// DrawLine(80,zoom+176,360,zoom+176,zoom-94,colors[ORANGE_RED]);
	//-------------------------------------------------------------------------
	DrawCircle(340,400,deca,colors[ORANGE]);
	DrawCircle(300,370,deca,colors[BLACK]);


//Smol Stars
	DrawRoundRect( 100, 100 ,-3,13,colors[WHITE],octa-30);
DrawRoundRect( 150, 400 ,-3,13,colors[WHITE],octa-30);
DrawRoundRect( 60,250 ,-3,13,colors[WHITE],octa-30);
DrawRoundRect( 0, 450 ,-3,13,colors[WHITE],octa-30);
DrawRoundRect( 250, 360 ,-3,13,colors[WHITE],octa-30);
DrawRoundRect( 30, 0 ,-3,13,colors[WHITE],octa-30);
DrawRoundRect( 360, 150 ,-3,13,colors[WHITE],octa-30);
//MOOV Star
DrawRoundRect( deca+200, octa+200 ,-3,13,colors[WHITE],octa-15);
DrawRoundRect( 240-deca, octa+250 ,-3,13,colors[WHITE],octa-15);

//PLANOOT
DrawCircle(10,360,80,colors[RED]);
DrawCircle(10,360,60,colors[DARK_RED]);
DrawCircle(10,360,40,colors[RED]);
DrawCircle(10,360,20,colors[DARK_RED]);


DrawRectangle(360,228,100,10,colors[DARK_MAGENTA]);

DrawRectangle(420,0,20,200,colors[SLATE_GRAY]);

DrawRoundRect(395,266,70,50,colors[SLATE_GRAY],40);
DrawRoundRect(418,198,30,70,colors[SLATE_GRAY],40);

sdraw.recrec(415-deca,353-zoom);




	//----------------Settings Button
	DrawRectangle(153,zoom-100,145,70,colors[DARK_BLUE]);
	DrawRectangle(165,zoom-86,120,40,colors[SLATE_GRAY]);
	DrawString(185,zoom-72,"Settings",colors[WHITE]);
	}
	//-------------------------------------------
	
//---------------------------------------------------------------------------
if(settings){
	DrawSquare(0,0,800,colors[WHITE]);
	DrawRectangle(80,0,280,420,colors[SLATE_GRAY]);
	DrawString(150,400,"Settings/Help",colors[WHITE]);
	DrawCircle(87,358,3,colors[BLACK]);

	DrawString(90,350,"To learn how to play"),colors[WHITE];
	DrawString(90,325,"press K"),colors[WHITE];
	DrawString(90,280,"Press P to Pause the Game "),colors[WHITE];
	DrawCircle(87,288,3,colors[BLACK]);
	DrawString(90,235,"Press R to restart the Game "),colors[WHITE];
	DrawCircle(87,243,3,colors[BLACK]);
	DrawString(90,190,"Press L to show the levels "),colors[WHITE];
	DrawCircle(87,198,3,colors[BLACK]);
	DrawString(90,145,"Press J for Hint Mechanic"),colors[WHITE];
	DrawCircle(87,153,3,colors[BLACK]);
	DrawString(90,100,"Press Q to exit this menu"),colors[WHITE];
	DrawCircle(87,107,3,colors[BLACK]);
	DrawString(90,55,"Press S/A to toggle sound"),colors[WHITE];
	DrawCircle(87,62,3,colors[BLACK]);


	if(j==1){
		DrawSquare(0,0,440,colors[SLATE_GRAY]);
		DrawString(40,400,"Hint Mechanic Explanation/Example",colors[WHITE]);
	DrawCircle(87,365,3,colors[BLACK]);
	DrawString(98,358,"The hint mechanic will activate",colors[WHITE]);
DrawString(10,318,"when the H button on the keyboard is",colors[WHITE]);
DrawString(10,278,"pressed.Each time Hint is used 5 points",colors[WHITE]);
DrawString(10,238,"will be deducted from the player's score.",colors[WHITE]);
DrawString(10,160,"Example:",colors[WHITE]);

			DrawSquare(180,89,45,colors[WHITE]);
			DrawSquare(238,89,45,colors[WHITE]);
			sdraw.tricircs(180,90);
			sdraw.recrec(238,90);
	}
if(j==2){
	DrawSquare(0,0,440,colors[SLATE_GRAY]);
	DrawString(40,400,"How to Play:",colors[WHITE]);
	DrawCircle(5,365,3,colors[BLACK]);
	DrawString(10,358,"Press Start game to get to the level menu.",colors[WHITE]);
DrawString(10,318,"Select Levels through varying through 1-4.",colors[WHITE]);
DrawString(10,278,"Two game modes are available Normal ",colors[WHITE]);
DrawString(10,238,"and Time trial Mode.Match gems of greater than 3 combos",colors[WHITE]);
DrawString(10,198,"to score points and pass each level to win ",colors[WHITE]);
DrawString(10,158,"the game.",colors[WHITE]);
}

}

if(highscore){
	DrawSquare(0,0,2000,colors[BLACKO]);
	


DrawString(10,400,"Name",colors[WHITE]);
DrawString(120,400,"Score",colors[WHITE]);
DrawString(210,400,"Highest Level",colors[WHITE]);
DrawString(370,400,"Time",colors[WHITE]);

DrawString(10,120,"Current Player Profile:",colors[WHITE]);
DrawString(0,80,string(playr),colors[WHITE]);
DrawString(140,80,std::to_string(player->savedata.score),colors[WHITE]);
DrawString(270,80,std::to_string(player->savedata.level),colors[WHITE]);
DrawString(380,80,std::to_string(player->savedata.time),colors[WHITE]);




DrawString(0,360,string(player->scores[0].name));
DrawString(0,300,string(player->scores[1].name));
DrawString(0,240,string(player->scores[2].name));
DrawString(0,180,string(player->scores[3].name));

DrawString(140,360,std::to_string(player->scores[0].score));
DrawString(140,300,std::to_string(player->scores[1].score));
DrawString(140,240,std::to_string(player->scores[2].score));
DrawString(140,180,std::to_string(player->scores[3].score));

DrawString(270,360,std::to_string(player->scores[0].level));
DrawString(270,300,std::to_string(player->scores[1].level));
DrawString(270,240,std::to_string(player->scores[2].level));
DrawString(270,180,std::to_string(player->scores[3].level));

DrawString(380,360,std::to_string(player->scores[0].time)+"s");
DrawString(380,300,std::to_string(player->scores[1].time)+"s");
DrawString(380,240,std::to_string(player->scores[2].time)+"s");
DrawString(380,180,std::to_string(player->scores[3].time)+"s");

}



}


	Hint* Board::hint(){
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){	
				copyMatrix[i][j] = grid[i][j];
			}
		}
		int temp;
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){	
				for (int dir=0;dir<4;dir++){
					if (copyMatrix[i][j]!=0 &&
						copyMatrix[i+dirX[dir]][j+dirY[dir]]!=0 &&
						checkBounds(i+dirX[dir],j+dirY[dir])){
						temp = copyMatrix[i][j];
						copyMatrix[i][j] = copyMatrix[i+dirX[dir]][j+dirY[dir]];
						copyMatrix[i+dirX[dir]][j+dirY[dir]] = temp;
						if (hasRemoval(i,j)){
							//cout<<"hint:"<<i<<j<<endl;
							return new Hint(new Gem(copyMatrix[i][j],20+i*50,20+j*50),
											new Gem(copyMatrix[i+dirX[dir]][j+dirY[dir]],20+(i+dirX[dir])*50,20+(j+dirY[dir])*50));
						} else {
								for (int i=0;i<8;i++){
									for (int j=0;j<8;j++){	
										copyMatrix[i][j] = grid[i][j];
									}
								}
							}
					}
				}
			}
		}
		return NULL;

		
	};


	
