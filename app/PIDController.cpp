/**
 * @brief Code written as a part of the Test Driven Development Assignment
 * @Copyright [2018]<Akshay>
 * @author Akshay
 * @file PIDController.cpp
 */

#include "../include/PIDController.h"

PIDController::PIDController()
    : Kp(0),
      Kd(0),
      Ki(0),
      initError(0),
      prevError(0) {
}

PIDController::~PIDController() {
}

double PIDController::compute(double currentVelocity, double endVelocity) {
  double error = endVelocity - currentVelocity;   // Calculating error
  initError += error;                             // Calculate integral error
  double difError = error - prevError;            // Calculate differential error
  double intConstant = initError * Ki;            // Calculate integral constant
  double proConstant = error * Kp;                // Calculate proportional constant
  double difConstant = difError * Kd;             // Calculate differential constant
  prevError = error;                              // Save current error
  return intConstant + proConstant + difConstant; // return PID output
}

double PIDController::getKd() {
  return Kd;
}

void PIDController::setKd(double KdIn) {
  this->Kd = KdIn;
}

double PIDController::getKi() {
  return Ki;
}

void PIDController::setKi(double KiIn) {
  this->Ki = KiIn;
}

double PIDController::getKp() {
  return Kp;
}

void PIDController::setKp(double KpIn) {
  this->Kp = KpIn;
}
