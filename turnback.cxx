#include <iostream>
#include <wiringPi.h>

using namespace std;

int m[]={0, 1, 2, 3};

int main()
{
	wiringPiSetup();
	for(auto i:m)pinMode(i, OUTPUT);
	auto i=3;
	while(1){
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
	
	return 0;
}
