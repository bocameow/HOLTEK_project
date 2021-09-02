#include <iostream>
#include <wiringPi.h>

using namespace std;

int m[]={22, 23, 24, 25};
int a=0;

int main()
{
	wiringPiSetup();
	for(auto i:m)pinMode(i, OUTPUT);
	auto i=0;
	while(1){
		for(auto j=0;j<4;++j){
			if(i==j)
				digitalWrite(m[j], 1);
			else
				digitalWrite(m[j], 0);
		}
		i++;
		if(i==4)i=0;
		delay(3);
		cout << a << endl;
		a++;
	}
	
	return 0;
}

//6.32 s
