#include <stdio.h>
#include "pid.h"
#include "writepwm.h"
#include "steering.h"

double SamplingFrequency; //10hz

void setSamplingFrequency(double SF){
    SamplingFrequency = SF;
}

void initSteering(){
    setpwm();
    setKvalue(0.1,0.001,0.0001);
    setSamplingFrequency(10);
}

//steering for 1 samping perod
double steering(double err){
    double pid_temp=0;
    double counterSteering = 0;
    double steeringduration = 0.01;
    double steeringduty = 0.5;
    while(counterSteering<(1/SamplingFrequency/steeringduration)){
        pid_temp = pid_cal(0,err);
        writepwm(steeringduty,pidValueToPWMValue(pid_temp),steeringduration);
        //printf("%dth iteration, output : %.10f, d_output : %.3f\n",counterSteering, err ,pid_cal(0,err));
        counterSteering++;
        err += pid_temp;
    }
    return pid_temp;
}
