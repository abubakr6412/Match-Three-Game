#include "SFML/Audio.hpp"
class Sound {
public:
sf::Music jam;
    int music1=0;
    void playMahJam() {
        
        if (!jam.openFromFile("1.ogg")){
            
        }
        else{
            
            jam.setLoop(true);
            jam.setVolume(100);
            if(music1==0){
                jam.play();
            }
            if(music1==1){
                jam.stop();
            }
            
        }
    } // end playMahJam()

    
};

class Sound2{
public:
sf::Music jam2;
    int music2=0;
    void playMahJam() {
        
        if (!jam2.openFromFile("2.ogg")){
            
        }
        else{
            
            jam2.setLoop(false);
            jam2.setVolume(100);
            if(music2==0){
                jam2.play();
            }
            if(music2==1){
                jam2.stop();
            }
            
        }
    } // end playMahJam()

    
};