/*
 * Executer.cpp
 *
 *  Created on: Nov 30, 2018
 *      Author: bala
 */

#include "../include/Executer.h"

Executer::Executer(PIDController &_pid) : pid(_pid) {}

void Executer::runPID(){
    pid.setKd(0.1);               // Set kp, kd and ki values
    pid.setKp(0.1);
    pid.setKi(0.1);
    double currentVelocity = 1;   // Initializing current velocity
    double newVelocity = currentVelocity;  // Initializing new velocity
    double endVelocity = 10;    // Initializing end velocity
    // Loop till final velocity is within acceptable range
    while ((endVelocity - newVelocity) > 0.001) {
      newVelocity = pid.compute(currentVelocity, endVelocity);
      currentVelocity = newVelocity;
}
}

Executer::~Executer() {
}

