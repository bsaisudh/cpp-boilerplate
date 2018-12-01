/*
 * @file PIDController_test.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * @author Bala Murali Manoghar Sai Sudhakar
 * @brief unit tests to test the compute function of the PIDController class
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
#include <gtest/gtest.h>

/**
 * @brief Test the passing condition of pid controller
 */
TEST(computePass, should_pass) {
  PIDController pid;
  pid.setKd(0.1);
  pid.setKp(0.1);
  pid.setKi(0.1);
  EXPECT_DOUBLE_EQ(3.0, pid.compute(0, 10));
}

/**
 * @brief Test the faliure condition of PID class
 */
TEST(computeFail, should_pass) {
  PIDController pid;
  pid.setKd(0.0);
  pid.setKp(0.0);
  pid.setKi(0.0);
  EXPECT_NE(3, pid.compute(1, 10));
}
