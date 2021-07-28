#include <BlynkSimpleStream.h> // Library of Stream Blynk


char auth[] = "P1yG69YN4AxEwYFfeSuqYAw7j7RmJDVH"; //BLynk auth code 


void setup()
{



  Serial.begin(9600); // Serial key  
  Blynk.begin(Serial, auth); // Input for Blynk inticalization. 
}

void loop()

  Blynk.run(); // Running Blynk in a infinite loop
}
