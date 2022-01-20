#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "steering.h" 

double kp, ki, kd, w0, w1;
double LtD, HdE;
double PIDerror, PIDvalue, PIDtemp;
struct timeval Start, End, StartPID, EndPID;

double d_temp;
double i_temp = 0;

int initSTEER(){
    wiringPiSetupGpio();    
	pwmSetMode(PWM_MODE_MS);    
	pinMode(BCM12_PWM0, PWM_OUTPUT); 
    //pwmSetclock()

    kp = 0.1;
    ki = 0.001;
    kd = 0.0001;
    w0 = 1;
    w1 = 1;
}

void setvariable(double k_p, double k_i, double k_d, double w_0, double w_1){
    kp = k_p;
    ki = k_i;
    kd = k_d;
    w0 = w_0;
    w1 = w_1;
}

double getPIDerror(double Lt_D, double Hd_E){
    PIDerror = w0*Lt_D+w1*Hd_E;
    return PIDerror;
}


double getPIDvalue(double PID_error){
    double p_error;
    double i_error = 0;
    double d_error = 0;
    double error_sum = 0;
    error = -PID_error;
    p_error = kp*error;
    i_temp += ki*error;
    i_error = i_temp;
    d_error = kd*(PID_error - d_temp);
    d_temp = PID_error;
    error_sum = p_error+i_error+d_error;
    if(error_sum>pwm_limit){
        error_sum = pwm_limit;
    }else if(error_temp<-pwm_limit){
        error_sum = -pwm_limit;
    }
    return error_sum;
}

int getPIDPWM(double PID_error){
    int output;
    output = (int)getPIDvalue(PID_error) / pwm_limit * 511 + 512

    return output;
}


double time_diff(struct timeval x, struct timeval y){
    double x_ms, y_ms, diff;
	x_ms = (double)x.tv_sec +(double) x.tv_usec/1000000;
	y_ms = (double)y.tv_sec + (double)y.tv_usec/1000000;
	diff = (double)y_ms - (double)x_ms;

	return diff;
}