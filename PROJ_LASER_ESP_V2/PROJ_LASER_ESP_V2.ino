#include <Arduino.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#define EEPROM_SIZE 4096

#ifndef APSSID
#define APSSID "TEST_PROJ"
#define APPSK  "123456789"
#endif

int texto[10][30]{
                  {0,0,1,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,1,1,0,0,1,1,0,1,1,0,0},
                  {0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,1,0,1,1,0,0},
                  {0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,1,0,1,1,0,0},
                  {0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,1,0,1,1,0,0},
                  {1,0,1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,0,1,1,1,1,0,1,1,0,1,1,0,1},
                  {1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,1,0,1,1,0,1},
                  {0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,1,0,1,1,0,0},
                  {0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0},
                  {0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,1,0,1,1,0,0},
                  {0,0,1,0,0,1,0,0,1,1,1,0,0,1,1,1,1,0,1,0,0,1,0,1,1,0,1,1,0,0},
                 };

int texto2[10][30]{
                  {0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0},
                  {0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,0,1,1,0,0,1,0,0,1,0,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0},
                 };

int texto3[10][30]{
                  {0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0},
                  {0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,0,1,1,0,0,1,0,0,1,0,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0},
                  {0,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0},
                 };

int caracter[10][30]{
                  {0,0,1,1},
                  {0,0,0,0},
                  {0,0,0,0},
                  {0,0,0,0},
                  {0,0,0,1},
                  {0,0,1,0},
                  {0,0,1,0},
                  {0,0,1,0},
                  {0,0,1,0},
                  {0,0,0,1},
                 };

                 
unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;

const char *ssid = APSSID;
const char *password = APPSK;

String pagina = "index";
String header;

const int sensorPin = 10;
volatile int pulseConter;
const int measureInterval = 100;
unsigned long delay_micro = 75;
unsigned long delay_micro2 = 910;
int n_linea = 11;

//Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
WiFiServer server(80);

void ICACHE_RAM_ATTR isr() {  
  for(int i = 0; i < n_linea; i++){
//    digitalWrite(16, HIGH);
//    delayMicroseconds(delay_micro);
//    digitalWrite(16, LOW);
    for(int j = 0; j < 30; j++){
      if(texto2[i][j] == 0){digitalWrite(16, LOW); delayMicroseconds(delay_micro);}
      if(texto2[i][j] == 1){digitalWrite(16, HIGH); delayMicroseconds(delay_micro);}
      }
    delayMicroseconds(delay_micro2);
    }
}

void setup() {
  EEPROM.begin(EEPROM_SIZE); 
  Serial.begin(115200);
  EEPROM.get(0, delay_micro);
  EEPROM.get(10, delay_micro2);
  EEPROM.get(20, n_linea);
//  EEPROM.put(0, 100);
//  EEPROM.commit();
//  EEPROM.put(10, 100);
//  EEPROM.commit();
//  EEPROM.put(20, 1);
//  EEPROM.commit();
  pinMode(sensorPin, INPUT_PULLUP);
  pinMode(16, OUTPUT);
  attachInterrupt(sensorPin, isr, RISING);
  Serial.print("Configurando punto de acceso...");
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Direccion de IP AP: ");
  Serial.println(myIP);  
  server.begin();
  Serial.println("HTTP server en linea");
}

void loop() {    
  
  webExc();
   
}
