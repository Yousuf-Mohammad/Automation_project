
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define LED 14
#define flame_sensor 12
char auth[] = "P1yG69YN4AxEwYFfeSuqYAw7j7RmJDVH";//authcode of blynk
char ssid[] = "dishting dishting_plus";//wifi credentials.
char pass[] = "01521331371";//wifi password
void setup()
{
  Serial.begin(19200);
  Blynk.begin(auth, ssid, pass);
  pinMode(LED, OUTPUT);
  pinMode(flame_sensor, INPUT);
 
}

void loop()
{

     Blynk.run();// library code run 

 int flame_detected = digitalRead(flame_sensor);
  if (flame_detected == 1 )
  {
    Serial.println("Flame detected...! take action immediately.");
    digitalWrite(LED, HIGH);
   
  
  }
  else
  { 
    Serial.println("No flame detected. stay cool");
 
    digitalWrite(LED, LOW);
  }
  delay(1000);
}
