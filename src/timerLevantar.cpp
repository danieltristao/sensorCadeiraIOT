#include <ESP8266WiFi.h>

bool bitTimerLevantar = false;
unsigned long retardoLevantar = 0;
extern int bitAlarmeLevanta;

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
            bitAlarmeLevanta = 1;
                                                                                        
        }
        else{            
        }
    }
    else{
        digitalWrite(saida, LOW);                                          
        bitTimerLevantar = false;
        retardoLevantar = 0;    
        bitAlarmeLevanta = 0;    
    } 

         
    
}


 