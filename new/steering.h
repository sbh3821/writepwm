#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define BCM12_PWM0 12 
#define pwm_limit 10

double kp, ki, kd, w0, w1;
double LtD, HdE;
double PIDerror, PIDvalue;
struct timeval start, End;

int initSTEER();

void setvariable(double k_p, double k_i, double k_d, double w_0, double w_1);

double getPIDerror(double Lt_D, double Hd_E);

double getPIDvalue(double PID_error);

int getPIDPWM()

double getSteeringValue();

double time_diff(struct timeval x, struct timeval y);