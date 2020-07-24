#include <string>
#include<fstream>
#include<iostream>
using namespace std;


class Player{
public:
	
	string name;
	
	struct Highscore{
		int score=0;
		char name[100];
		int level=0;
		int time=0;
	};
	
	
	Highscore*scores=new Highscore[4];
	
	struct save{
		int score=0;
		char name[100];
		int level=0;
		int time=0;
	};
	
save savedata;
	void setName(string n);
	void sortData(Highscore scores[],int size)

{

    Highscore temp;
	//using selection sort algrorithm to sort scores
	for (int i = 0; i <= size ; i++) {
	// finding the index of largest score in the unsorted array
	int index_max = i;
	for (int j = i + 1; j <= size; j++)

         if (scores[j].score > scores[index_max].score)
                index_max = j;

    // swapping element at i with element at index_max

            temp = scores[index_max];
			scores[index_max] = scores[i];
			scores[i] = temp;

      }

}
void readfile(Highscore scores[]){
	
	
   
    ifstream    infile ("Player.txt");
        

   int t;
   
   while(infile >> scores[t].name)
   {
	   infile>>scores[t].score;
	   infile>>scores[t].level;
	   infile>>scores[t].time;
	   t++;
	   if(t==4){
		   break;
	   }
   }
   

}

void write(){
fstream new_files; 
new_files.open("Player.txt",ios::out);  

for(int i=0;i<4;i++){



new_files<<scores[i].name<<" ";
new_files<<scores[i].time<<" ";
new_files<<scores[i].level<<" ";
new_files<<scores[i].score<<" ";
new_files<<endl;


}

new_files.close(); 
   
}


void savefilewrite(){
	fstream new_files; 
new_files.open("save.txt",ios::out);  





new_files<<savedata.name<<" ";
new_files<<savedata.time<<" ";
new_files<<savedata.level<<" ";
new_files<<savedata.score<<" ";
new_files<<endl;





}
void savefileread(){
	ifstream    infile ("save.txt");
        

   
   
  
	   infile>>savedata.name;
	   infile>>savedata.time;
	   infile>>savedata.level;
	   infile>>savedata.score;
	 
   

}



};
