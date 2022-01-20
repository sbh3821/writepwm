#include <stdio.h>
#include "pid.h"
#include "writepwm.h"
#include "steering.h"

int main(){
    initSteering();
    
    //setSamplingFrequency(20);
    //setKvalue(0.1,0.001,0.0001);
    
    steering(-100);

    /*
    while(1){
        receiveCAN();
        steering(geterror(w0,getLtd(),w1,getHde()));

    return 0;
    }
    */
}
