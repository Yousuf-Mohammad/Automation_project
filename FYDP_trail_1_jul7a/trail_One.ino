#define BLYNK_PRINT Serial 
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>// Blynk library included from here:https://github.com/blynkkk/blynk-library/releases/latest

char auth[] = "Au5Q51s60sodSMcER6msYUCHXu-fFgcg";//authcode of blynk
char ssid[] = "dishting dishting_plus";//wifi credentials.
char pass[] = "XHHFRHHT14481925";//wifi password

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()//An infinite loop to run the code from the included library
{
  Blynk.run();// library code run 
}

