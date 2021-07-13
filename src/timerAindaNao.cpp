#include <ESP8266WiFi.h>

bool bitTimerAindaNao = false;
unsigned long retardoAindaNao = 0;
extern int alarmeAindaNao;
extern bool seloAlarmeLevanta;

void timerAindaNao(unsigned long tempo, bool entrada){
               
    if (bitTimerAindaNao == false){
        if(entrada == true){
            retardoAindaNao = millis();
            bitTimerAindaNao = true;
        }
        else{            
        }
    }
    else{        
    }

    if(entrada == true){
        if((millis() - retardoAindaNao) > tempo){
            seloAlarmeLevanta = false;                        
        }
        else{            
        }
    }
    else{                         
        bitTimerAindaNao = false;
        retardoAindaNao = 0;
    }   
    
}
 