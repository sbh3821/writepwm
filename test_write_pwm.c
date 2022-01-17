#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "writepwm.h"


int main(){
	setpwm();
	testpwm(250,400,0.5,0.8);//(startFrequency, EndFrequency,Startduty,Endduty)
	
}