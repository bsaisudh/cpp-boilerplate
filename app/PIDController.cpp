/**
 * @brief Code written as a part of the Test Driven Development Assignment
 * @Copyright [2018]<Akshay>
 * @author Akshay
 * @file PIDController.cpp
 */

#include "../include/PIDController.h"

PIDController::PIDController()
    : Kp(0), Kd(0), Ki(0), initError(0), prevError(0) {}

PIDController::~PIDController() {}

double PIDController::compute(double currentVelocity, double endVelocity) {
  return 0;
}

double PIDController::getKd() { return Kd; }

void PIDController::setKd(double KdIn) { this->Kd = KdIn; }

double PIDController::getKi() { return Ki; }

void PIDController::setKi(double KiIn) { this->Ki = KiIn; }

double PIDController::getKp() { return Kp; }

void PIDController::setKp(double KpIn) { this->Kp = KpIn; }
