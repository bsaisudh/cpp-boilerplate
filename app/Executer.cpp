/*
 * @file Executer.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * @author Bala Murali Manoghar Sai Sudhakar
 * @brief Executes the controller
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

#include "../include/Executer.h"

Executer::Executer(PIDController &_pid)
    : pid(_pid) {
}

void Executer::runPID() {
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

