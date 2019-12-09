/**
 * @file servo_test.cpp
 * @brief test programm of using servo motor
 * @author Yoshiki Higuchi
 * @date 2019/12/09
 */

#include <unistd.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// call function from C library
extern "C"{
#include "wiringPi_explicit.h"
}​
int MAX_PWM_CLOCK_FREQ = 74250000; // max clock frequency of TinkerBoard
//int SERVO_FREQ = 200; // frequency of servo
int servo_pin = 239; // define servo_pin

// setup servo-pin
void setup(void){
    // preparation of wiringPi
    if(wiringPiSetup()==-1){
        printf("can not use wiringPi\n");
    }
    // wiringPi setting
    printf("Servo pin init\n");
    pinMode(servo_pin, PWM_OUTPUT);
	pwmSetMode(0);
    pwmSetRange(1024);
}

// calculate pwm-clock and send signal
void run(int degree){
    printf("degree: %d\n",degree);
    int move_deg = 0; //init
    pwmSetClock(MAX_PWM_CLOCK_FREQ / 1024 / 200);

    // calculate rotate degree (PWM)
    move_deg = int((4.75 * degree / 90 + 7.25) * (1024 / 100));

    // send signal
    pwmWrite(servo_pin,move_deg);
    delay(10);
}

int main(void){
    setup();

    printf("110°\n");
    run(110);
    sleep(2);

    printf("60°\n");
    run(60);
    sleep(2);

    return 0;
}