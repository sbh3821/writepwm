#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "steering.h" 

int main(){
    initSTEER();
    gettimeofday(&Start,NULL);
    //gettimeofday(&End,NULL);
    gettimeofday(&StartPID,NULL);
    while(1){
        gettimeofday(&StartPID,NULL);
        PIDerror = getPIDerror(50,50);
        if(time_diff(StartPID,EndPID)<2){
            pwmwrite(BCM12_PWM0, getPIDPWM(PIDerror));

        }else{
            i_temp = 0;
            d_temp = 0;
        }
        gettimeofday(&EndPID,NULL);
    }
    return 0;
}