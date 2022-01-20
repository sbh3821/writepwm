#include <stdio.h>
#include <stdlib.h>

#include "pid.h"
double kp, ki, kd;

double error;
double output;

double w0, w1, LateralDeviation, HeadingError; 

double output_max = 10;
double output_min = -10;

double i_temp = 0;
double d_temp = 0;


void setKvalue(double kpset,double kiset,double kdset){
    kp = kpset;
    ki = kiset;
    kd = kdset;
}

void initPid(){
    i_temp = 0;
    d_temp = 0;
}

double pid_cal(double reference, double error_in){
    double p_error;
    double i_error = 0;
    double d_error = 0;
    double error_temp = 0;
    error = reference - error_in;
    p_error = kp*error;
    i_temp += ki*error;
    i_error = i_temp;
    d_error = kd*(error_in - d_temp);
    d_temp = error_in;
    error_temp = p_error+i_error+d_error;
    if(error_temp>output_max){
        error_temp = output_max;
    }else if(error_temp<output_min){
        error_temp = output_min;
    }
    return error_temp;
}
double pidValueToPWMValue(double pidValue){
    //let's it is linear
    double pwm_temp;
    pwm_temp = 15*pidValue +330;
    return 1/pwm_temp;
}



double get_error(double w0, double LateralDeviation, double w1, double HeadingError){
    double error_cal;
    error_cal = w0*LateralDeviation + w1*HeadingError;
    return -error_cal;
};
