#include "Relay.h"

Relay::Relay(int signal) : signalPin(signal)
{
	pinMode(signalPin,OUTPUT);
	
	//Turn off:
	digitalWrite(signalPin,LOW);
	lastSwitchTime = millis();
	state = 0;
}

byte Relay::turnOn()
{
	if((millis() - lastSwitchTime) > MinDurationBetweenSwitch && state == 0) 
	{
		digitalWrite(signalPin,HIGH);
		lastSwitchTime = millis();
		state = 1;
		return 1;
	}
	return 0;
}

byte Relay::turnOff()
{
	if(millis() - lastSwitchTime > MinDurationBetweenSwitch && state == 1)
	{
		digitalWrite(signalPin,LOW);
		lastSwitchTime = millis();
		state = 0;
		return 1;
	}
	return 0;
}

byte Relay::getState()
{
	return state;
}
