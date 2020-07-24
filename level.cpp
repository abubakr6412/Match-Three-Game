#include "level.h";

	Level::Level(){
		levelTimes[0] = requiredScores[0] = 10;
		levelTimes[1] = requiredScores[1] = 30;
		levelTimes[2] = requiredScores[2] = 50;
		levelTimes[3] = requiredScores[3] = 75;
		levelTimes[4] = requiredScores[4] = 800;
		
		completedLevels[0] = false;
		completedLevels[1] = false;
		completedLevels[2] = false;
		completedLevels[3] = false;
		completedLevels[4] = false;

		currentScore = 0.0;
		Trialtimer=0.0;
	}
	void Level::nextLevel(){
	
	}
	void Level::reset(){
	
	}

int Level::timer(){
	time=glutGet(GLUT_ELAPSED_TIME)/1000;
	return time;
}

double Level::trialtimer(){
	Trialtimer=currentScore-glutGet(GLUT_ELAPSED_TIME)/1000;
	return Trialtimer;
}