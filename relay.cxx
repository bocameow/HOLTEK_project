#include <iostream>
#include <wiringPi.h>
#include <stdio.h>
#include <wiringPi.h>
#define SWIT 5

using namespace std;

int main()
{
	wiringPiSetup();
	pinMode(SWIT, OUTPUT);
	while(1){
	digitalWrite(SWIT,HIGH);
	delay(1000);
	digitalWrite(SWIT,LOW);
	delay(500);
	}
	return 0;
}
