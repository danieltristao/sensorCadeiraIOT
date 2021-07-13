#include <ESP8266WiFi.h>

extern int alarmePostura;
extern int alarmeLevanta;
extern int alarmeAindaNao;

extern WiFiServer server;
extern IPAddress ip;

void html(){

    WiFiClient client = server.available(); // checa se o cliente esta conectado
  if (!client) {
    return;
  }
    
  String req = client.readStringUntil('\r');      
  client.println(F("HTTP/1.1 200 OK")); //config html
  client.println(F("Content-Type: text/html"));
  client.println("Connection: keep-alive"); 
  client.println();
  client.println(F("<!DOCTYPE html>")); //conteudo pagina html
  client.println("<html>");
  client.println("<head>");
  client.println("<title> trem do clovis </title>");
  client.println("</head>");
  client.print(F("<h1>"));
  client.print(F("Alarme Postura "));
  client.println(alarmePostura);
  client.print(F("<br></br>"));
  client.print(F("Alarme Levanta da Cadeira  "));
  client.println(alarmeLevanta);
  client.print(F("<br></br>"));
  client.print(F("Alarme Ainda nao pode sentar "));
  client.println(alarmeAindaNao);
  client.print(F("<br></br>"));
  client.print(F("</h1>"));
  client.print(F("</html>")); //termina conteudo html
}