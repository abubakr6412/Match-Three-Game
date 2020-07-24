#include "gem.h"
#include <unistd.h>
#include <iostream>
using namespace std;
	Gem::Gem(int c, int px,int py){
		color = c;
		positionX = px;
		positionY = py;
		interval=0;
	}
	int Gem::getX(){
		return (int)((positionX-20)/50);
	}
	int Gem::getY(){
		return (int)((positionY-20)/50);
	}
	//20+i*50
	void Gem::updatePosition(){
		//y = (positionY-20)/50;
	}
	void Gem::addAnimation(){
		interval+=50;
		cout<<"interval"<<getX()<<" "<<getY()<<":"<<interval<<endl;
	}
	void Gem::animate(){
		if (interval>=1 && positionY>=1){
			positionY -= 1;
			interval --;
		}
	}
