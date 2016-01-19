#include "Global.h"

void setup() 
{
	Serial.begin(9600);
	Serial.println("start");
}

void loop() 
{	
	int sample = temp.readCelsius();
	Serial.println(sample);
	if(sample > 30)
	{
		Serial.println("High Temp");
		relay.turnOn();
		delay(5000); 
		relay.turnOff();
	}
		
	delay(100);
}
