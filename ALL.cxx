#include <iostream>
#include <wiringPi.h>
#include "libSonar.h"
#include <pthread.h>
#include <unistd.h>

using namespace std;
//=======Pin================
int redPin1 = 0;
int redPin2 = 1;
int trigger = 3, echo = 2;
int SWIT=5;
int m[]={22, 23, 24, 25};
//===========================
int ra=0, rb=0, us=0;
void redline1();
void redline2();
Sonar::Sonar(){}
void ultrasound();
void motor();
void backmotor();

int main(int argc, char **argv)
{
	wiringPiSetup();
	while(1)
	{
		if(ra==1){
			void motor();
			void ultrasound();
			if(us>7){
				//water begin
				digitalWrite(SWIT,LOW);
				while(1)
				{
					void ultrasound();
					if(us<=7){
						//water stop
						digitalWrite(SWIT,HIGH);
						//motor goback
						void backmotor();
						break;
					}
				}
			}
			else{
				//motor goback
				void backmotor();
			}
		}
		while(1)
		{
			if(ra==0)
			break;
		}
	}
	return 0;
}

void ultrasound ()
{
    Sonar sonar;
    sonar.init(trigger, echo);
    //cout << "Distance is " << sonar.distance(30000) << " cm." << endl;
    delay(500);
    us=sonar.distance(30000);
}

void redline1()
{
	pinMode(redPin1, INPUT);
	while(1){
		if(digitalRead(redPin1) == 0)
			{
				ra=1;
			}
		else
			{
				ra=0;
			}
	}
}

void redline2()
{
	pinMode(redPin2, INPUT);
	while(1){
		if(digitalRead(redPin2) == 0)
			{
				rb=1;
			}
		else
			{
				rb=0;
			}
	}
}

void motor()
{
	for(auto i:m)
	pinMode(i, OUTPUT);
	auto i=0;
	while(1){
		for(int mot=0;mot<50;mot++){
			for(auto j=0;j<4;++j){
				if(i==j)
					digitalWrite(m[j], 1);
				else
					digitalWrite(m[j], 0);
			}
			i++;
			if(i==4)i=0;
			delay(3);
		}
		if(rb==1)
		break;
	}
}

void backmotor()
{
	for(auto i:m)
	pinMode(i, OUTPUT);
	auto i=3;
	while(1){
		for(int motb=0;motb<50;motb++){
			for(auto j=3;j>-1;--j){
				if(i==j)
					digitalWrite(m[j], 1);
				else
					digitalWrite(m[j], 0);
			}
			i--;
			if(i==-1)i=3;
			delay(3);
		}
		if(rb==1)
		break;
	}
}

//================================================================

void Sonar::init(int trigger, int echo)
{
    this->trigger=trigger;
    this->echo=echo;
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    digitalWrite(trigger, LOW);
    delay(500);
}

double Sonar::distance(int timeout)
{
    delay(10);

    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    now=micros();

    while (digitalRead(echo) == LOW && micros()-now<timeout);
        recordPulseLength();

    travelTimeUsec = endTimeUsec - startTimeUsec;
    distanceMeters = 100*((travelTimeUsec/1000000.0)*340.29)/2;

    return distanceMeters;
}

void Sonar::recordPulseLength()
{
    startTimeUsec = micros();
    while ( digitalRead(echo) == HIGH );
    endTimeUsec = micros();
}
