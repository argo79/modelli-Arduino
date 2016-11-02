#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
ESP8266WebServer server(80);
const int util = 0;             //led di stato che dovrebbe essere collegato tra GPIO0 e GND per mostrare l'utilizzo dell'ESP8266, ma che non ho utilizzato.
const int led = 2;             // led da controllare via Wifi, collegato tra GPIO2 e GND
void handleRoot() {
  digitalWrite(util, 1);
  server.send(200, "text/plain", "Benvenuto sull'ESP8266!");
  digitalWrite(util, 0);
}
void handleNotFound(){
  digitalWrite(util, 1);
  String message = "File non trovato\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(util, 0);
}
void setup(void){
  pinMode(2, OUTPUT);
  pinMode(util, OUTPUT);
  digitalWrite(util, 0);
  Serial.begin(115200);
  Serial.println("");
  Serial.print("ESP8266 avviato, collegati alla rete Wifi aperta ESP_.…..");
  Serial.print("tramite qualsiasi dispositivo ed apri la pagina 192.168.4.1");
  server.on("/", handleRoot);
  server.on("/inline", [](){
    server.send(200, "text/plain", "Funziona anche questa pagina");
  });
  server.on("/on", [](){  //Se viene richiamata la pagina 'on'…
    digitalWrite(led, 1);  //...accende il led...
  server.send(200, "text/plain", "Led acceso");  //...e scrive che il led è stato acceso
  });
  server.on("/off", [](){  //Se viene richiamata la pagina 'off'…
    digitalWrite(led, 0);  //...spegne il led...
  server.send(200, "text/plain", "Led spento");  //...e scrive che il led è stato spento
  });
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("Server HTTP avviato");
}
void loop(void){
  server.handleClient();
}
