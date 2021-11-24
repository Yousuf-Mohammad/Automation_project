#include <Blynk.h>

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

#include <ThingSpeak.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <BlynkSimpleEsp32.h>// Blynk library included from here:https://github.com/blynkkk/blynk-library/releases/latest
String apikey = "5JKMFH4GXYCYTXQE";
// char ssid= 'Icloud';
// char pass= 'arnob0162';
 char server= 'api.thingspeak.com';


#define FLAME 12 // connect DO pin of sensor to this pin
#define ALARM 32 // pin 8 for Alarm 
#define DHTPIN 34     // Digital pin connected to the DHT sensor 
#define Buzzer 14
#define SENSOR 35
int sensorValue = 0 ;
char auth[] = "P1yG69YN4AxEwYFfeSuqYAw7j7RmJDVH";//authcode of blynk
char ssid[] = "dishting dishting_plus";//wifi credentials.
char pass[] = "01521331371";//wifi password



#define DHTTYPE    DHT11     // DHT 11


DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600);
  // Initialize device.
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  pinMode(FLAME, INPUT);//define FLAME input pin
  pinMode(ALARM, OUTPUT);//define ALARM output pin
  pinMode(Buzzer, OUTPUT);
  
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  

  dht.humidity().getSensor(&sensor);
  delayMS = sensor.min_delay / 1000;
}

void loop() {
    Blynk.run();// library code run 

  int fire = digitalRead(FLAME);// read FLAME sensor


  if( fire != HIGH)
  {
    digitalWrite(ALARM,HIGH);// set the buzzer ON

  }else{
    digitalWrite(ALARM,LOW); // Set the buzzer OFF
    }

int sensorValue = analogRead(SENSOR);
Serial.print("Value: ");
Serial.print(sensorValue);
if(sensorValue>=400){
  digitalWrite(Buzzer,HIGH);
}
else{
  digitalWrite(Buzzer,LOW);

} }
