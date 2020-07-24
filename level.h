#include"util.h"
class Level{	
	public:
	int currentLevel;
	double currentScore;
	int timeRemaining;
	int requiredScores[5];
	bool completedLevels[5];
	int levelTimes[5];
	int time;
	double Trialtimer;
	Level();
	void nextLevel();
	void reset();
	int timer();
	double trialtimer();
	
};
