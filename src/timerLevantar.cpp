#include <ESP8266WiFi.h>

bool bitTimerLevantar = false;
unsigned long retardoLevantar = 0;
extern int alarmeLevanta;


void timerLevantar(unsigned long tempo, int saida, bool entrada){
               
    if (bitTimerLevantar == false){
        if(entrada == true){
            retardoLevantar = millis();
            bitTimerLevantar = true;
        }
        else{            
        }
    }
    else{        
    }

    if(entrada == true){
        if((millis() - retardoLevantar) > tempo){
            digitalWrite(saida, HIGH);
            alarmeLevanta = 1;                                                                    
        }
        else{            
        }
    }
    else{
        digitalWrite(saida, LOW);   
        alarmeLevanta = 0;                                 
        bitTimerLevantar = false;
        retardoLevantar = 0;
    } 

         
    
}


 