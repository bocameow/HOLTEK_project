#include <iostream>
#include <wiringPi.h>

using namespace std;
int outPin = 0;

int main(int argc, char **argv)
{
	wiringPiSetup();
	int a;
	pinMode(outPin, INPUT);
	while(1){
		if(digitalRead(outPin) == 0)
			{
				a=1;
			}
		else
			{
				a=0;
			}
			cout << a ;
		}
	return 0;
}

