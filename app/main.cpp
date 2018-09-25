/**
 * @Copyright [2018] <Akshay>
 * @brief main function for using an instance of the PIDController class
 * @author Akshay
 * @file main.cpp
 */
#include <iostream>
#include "../include/PIDController.h"

/**
 * @brief calculate the path form start velocity to end velocity through PID algorithm
 */

int main() {
  PIDController pid;          // Creating pointer for controller class
  pid.setKd(0.1);             // Set kp, kd and ki values
  pid.setKp(0.1);
  pid.setKi(0.1);
  double currentVelocity = 1; // Initializing current velocity
  double newVelocity = currentVelocity;  // Initializing new velocity
  double endVelocity = 10;    // Initializing end velocity
  // Loop till final velocity is within acceptable range
  while ((endVelocity - newVelocity) > 0.001) {
    newVelocity = pid.compute(currentVelocity, endVelocity);
    currentVelocity = newVelocity;
  }
}
