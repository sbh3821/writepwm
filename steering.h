#include <stdio.h>
#include "pid.h"
#include "writepwm.h"

double SamplingFrequency; //10hz

void setSamplingFrequency(double SF);

void setwvalue(double wone, double wtwo);

void initSteering();

//steering for 1 samping perod
double steering(double err);


