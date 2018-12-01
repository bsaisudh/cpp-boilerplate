/*
 * @file PIDController.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * @author Bala Murali Manoghar Sai Sudhakar
 * @author Akshay
 * @brief PID controller class header file
 */

/*
 * MIT License
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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
  // Calculating error
  double error = endVelocity - currentVelocity;
  // Calculate integral error
  initError += error;
  // Calculate differential error
  double difError = error - prevError;
  // Calculate integral constant
  double intConstant = initError * Ki;
  // Calculate proportional constant
  double proConstant = error * Kp;
  // Calculate differential constant
  double difConstant = difError * Kd;
  // Save current error
  prevError = error;
  // Return PID output
  return intConstant + proConstant + difConstant;
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
