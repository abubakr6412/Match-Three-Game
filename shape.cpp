
 #include"util.h"
 class Shape{
	 protected:
int x,x2,y,y2;


	 public:
	 Shape(){
		 x=0;
		 
		 y=0;
		 
	 }
	 void reccirc(int x,int y){
		
		 DrawSquare( x , 
									y ,
									45, 
									colors[DARK_MAGENTA]); 
									DrawCircle( x+22 , 
									y+22 ,
									15, 
									colors[DARK_OLIVE_GREEN]);	
									DrawSquare( x+11 , 
									y+11 ,
									23, 
									colors[PALE_GOLDEN_ROD]); 
									
		

	 }
	 void tricircs(int x,int y){
		// DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	
						DrawCircle( x+22, 
									y+22 ,
									23, 
									colors[RED]);
									 DrawTriangle(x+22,y+22,x+44,y+25,x+25,y+44,colors[MISTY_ROSE]);
		 							DrawTriangle(x+22,y+22,x-1,y+17,x+17,y-1,colors[MISTY_ROSE]);
	 }
	 void robo(int x,int y){
		 DrawRoundRect(x+24 , y+15 ,-3,13,colors[PERU],30);
	 }
	
	void recrec(int x,int y){
		 DrawTriangle( 
							x, 
							y+30,
							x+22,
							y, 
							x+45, 
							y+30,
							colors[PEACH_PUFF]); 
							DrawTriangle( 
							x, 
							y+40,
							x+22,
							y, 
							x+45, 
							y+40,
							colors[TAN]);
							DrawTriangle( 
							x, 
							y+20,
							x+22,
							y, 
							x+45, 
							y+20,
							colors[INDIGO]);		
	 }
	 void tritri(int x,int y){
		// DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	
		 DrawSquare( x , 
									y ,
									45, 
									colors[RED]); 
									DrawSquare( x+7 , 
									y +7,
									30, 
									colors[DARK_RED]); 
									DrawSquare( x+14 , 
									y+15 ,
									15, 
									colors[LIGHT_GOLDEN_ROD_YELLOW]); 
	 }
 };