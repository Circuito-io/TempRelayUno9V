#ifndef RELAY_H
#define RELAY_H

#include "arduino.h"

#define MinDurationBetweenSwitch 500 //at least 0.5 second between teaks

class Relay
{
	public:
		Relay(int signal);
		byte turnOn(); 
		byte turnOff();
		byte getState();
		
	private:
		const int signalPin;
		unsigned long lastSwitchTime;
		byte state;
};
#endif //RELAY_H
