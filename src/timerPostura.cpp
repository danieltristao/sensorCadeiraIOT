#include <ESP8266WiFi.h>

bool bitTimerPostura = false;
unsigned long retardoPostura = 0;
extern int alarmePostura;

void timerPostura(unsigned long tempo, int saida, bool entrada){
                 
    if (bitTimerPostura == false){
        if(entrada == true){
            retardoPostura = millis();
            bitTimerPostura = true;
        }
        else{            
        }
    }
    else{        
    }

    if(entrada == true){
        if((millis() - retardoPostura) > tempo){
            digitalWrite(saida, HIGH);  
            alarmePostura = 1;                                  
        }
        else{            
        }
    }
    else{
        digitalWrite(saida, LOW);  
        alarmePostura = 0;             
        bitTimerPostura = false;
        retardoPostura = 0;
    }   
    
}
 