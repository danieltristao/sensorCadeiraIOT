#include <ESP8266WiFi.h>

const char* ssid = "poppi_wifi"; //nome da rede
const char* password = "poppipoppi"; // senha da rede
const int sentouCerto = D0; // liga quando conecta na rede
const int ledAlarmePostura = D1; // liga quando tira as costas do encosto da cadeira
const int ledAlarmeLevanta = D2; // liga quando da o tempo para levantar
const int ledAlarmeAindaNao = D3; // liga quando senta antes do tempo de descanco
const int sensorBunda = D5; // monitora a bunda na cadeira
const int sensorCosta = D6; // monitora as costas no encosto da cadeira
bool sensorBundaState = false; // estado ligado/desligado do sensor da bunda
bool sensorCostaState = false; // estado ligado/desligado do sensor das costas
bool posturaState = false;
bool seloAlarmeLevanta = false;
bool descansoState = false;
int alarmePostura = 0; // tag para leitura do alarme de postura
int alarmeLevanta = 0; // tag para leitura do alarme para levantar da cadeira
int alarmeAindaNao = 0; // tag para leitura do alarme que avisa que nao deu o tempo de descanco

extern void timerPostura(unsigned long tempo, int saida, bool entrada);
extern void timerLevantar(unsigned long tempo, int saida, bool entrada);
extern void timerAindaNao(unsigned long tempo, bool entrada);

WiFiServer server(80); //porta servidor
IPAddress ip(192,168,1,150); //ip fixo esp8266
IPAddress gateway(192,168,1,1); //gateway padrao
IPAddress subnet(255,255,255,0); //mascara sub rede
 
void setup(){
  Serial.begin(9600);

  pinMode(sentouCerto, OUTPUT); // define pino como saida
  pinMode(ledAlarmePostura, OUTPUT); // define pino como saida
  pinMode(ledAlarmeLevanta, OUTPUT); // define pino como saida
  pinMode(ledAlarmeAindaNao, OUTPUT); // define pino como saida
  pinMode(sensorBunda, INPUT); // define pino como entrada
  pinMode(sensorCosta, INPUT); // define pino como entrada
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println( ); // conecta na wifi
  Serial.print(F("Conectando na rede "));
  Serial.println(ssid);

  WiFi.mode(WIFI_STA); // coloca rede no modo de ip estatico
  WiFi.begin(ssid, password); // escreve na biblioteca <ESP8266WiFi.h> o nome da rede e senha
  WiFi.config(ip, gateway, subnet); // escreve na biblioteca <ESP8266WiFi.h> o ip, gateway e subrede
 
  while (WiFi.status() != WL_CONNECTED) { //sai do laco depois que conecta, se desconectar volta para o laco
    delay(250); // tempo para verificar conexao pela porta serial
    Serial.print(F(".")); // escreve um ponto na porta serial a cada 500 ms até conectar na rede
    digitalWrite(LED_BUILTIN, HIGH);    
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    
  } 

  
  Serial.println(); //pula uma linha
  Serial.println(F("WiFi conectada")); // escreve "wifi conectada" na porta serial
  
  server.begin(); // inicia servidor
  Serial.print(F("Servidor iniciado no IP ")); // escreve "servidor iniciado no ip"
  Serial.println(WiFi.localIP()); // escreve o ip na porta serial
  
}

void loop(){
   
  sensorCostaState = digitalRead(sensorCosta); //botao vermelho
  sensorBundaState = digitalRead(sensorBunda); //botao azul

  if((sensorCostaState == true) && (sensorBundaState == true)){
    digitalWrite(sentouCerto, HIGH);
  }
  else{
    digitalWrite(sentouCerto, LOW);
  }

    
  if((sensorCostaState == false) && (sensorBundaState == true)){
    posturaState = true;
  }
  else{
    posturaState = false;
  }

  if(alarmeLevanta == 1){
    seloAlarmeLevanta = true;
  }
  else{    
  }

  if(seloAlarmeLevanta == true){
    if((sensorCostaState == false) && (sensorBundaState == false)){
      descansoState = true;          
    }
    else{      
    }

    if(descansoState == true){
      if(sensorBundaState == true){
        digitalWrite(ledAlarmeAindaNao, HIGH);
      }
      else{
        digitalWrite(ledAlarmeAindaNao, LOW);        
      }

    }
    else{      
    }
    
  }
  else{ 
    descansoState = false;
    digitalWrite(ledAlarmeAindaNao, LOW);
  }

  
  timerPostura(1000, ledAlarmePostura, posturaState); //postura led branco
  timerLevantar(3000, ledAlarmeLevanta, sensorBundaState); //levantar led azul
  timerAindaNao(2000, descansoState);
  
 
}
 