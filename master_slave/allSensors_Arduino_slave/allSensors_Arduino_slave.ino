#include "DHT.h"

#define DHTTYPE DHT11   
int DHTPIN = 2; 
int LED = 13;
int flame_sensor = 4;
int Gas1 = A3;
int Gas2 = A0;
int flame_detected;


DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  pinMode(flame_sensor, INPUT);
    dht.begin();
}

void loop()
{

  
  int sensorValue1 = analogRead(Gas1);
   int sensorValue2 = analogRead(Gas2);
  Serial.print("Value: ");
  Serial.println(sensorValue1);
   Serial.print("Value: ");
  Serial.println(sensorValue2);

  flame_detected = digitalRead(flame_sensor);
  if (flame_detected == 0 || sensorValue1<500 || sensorValue2<500 )
  {
    Serial.println("Flame detected...! take action immediately.");
    digitalWrite(LED, HIGH);
   
  
  }
  else
  { 
    Serial.println("No flame detected. stay cool");
 
    digitalWrite(LED, LOW);
  }

float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));

  
  Serial.println("   ");
  
  Serial.println("   ");
  


  delay(1000);
}
