#include <ESP8266WiFi.h>

bool bitTimerPostura = false;
unsigned long retardoPostura = 0;
extern int alarmePostura;
bool contaAlarmePostura = false;

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
            if(contaAlarmePostura == false){
                alarmePostura++;
                contaAlarmePostura = true;
            }                                                 
        }
        else{            
        }
    }
    else{
        digitalWrite(saida, LOW);                      
        bitTimerPostura = false;
        retardoPostura = 0;  
        contaAlarmePostura = false;      
    }   
    
}
 