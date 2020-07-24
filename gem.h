#include <string>
using namespace std;

class Gem{
public:
	string gtype;
	int color;
	int getX();
	int getY();
	int positionX;
	int positionY;
	int interval;
	bool endAnimation;
	Gem(int c,int px,int py);
	void updatePosition();
	void animate();
	void addAnimation();
};
