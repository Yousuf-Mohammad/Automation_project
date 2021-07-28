#include <BlynkSimpleStream.h>

// Pin Assignment

//Your app authentication token (can be fetched from your blynk app
char auth[] = "P1yG69YN4AxEwYFfeSuqYAw7j7RmJDVH";//Enter blynk auth token


void setup()
{

  // Blynk will work through Serial

  Serial.begin(9600);
  Blynk.begin(Serial, auth);
}

void loop()
{
  // All the magic is here
  Blynk.run();
}
