/**
 * @copyright Akshay
 * @author Akshay
 * @file PIDController_test.cpp
 * @brief unit tests to test the compute function of the PIDController class
 */
#include "../include/PIDController.h"
#include <gtest/gtest.h>

TEST(computePass, should_pass) {
  PIDController pid;
  pid.setKd(0.1);
  pid.setKp(0.1);
  pid.setKi(0.1);
  EXPECT_DOUBLE_EQ(3.0, pid.compute(0, 10));
}

TEST(computeFail, should_pass) {
  PIDController pid;
  pid.setKd(0.0);
  pid.setKp(0.0);
  pid.setKi(0.0);
  EXPECT_NE(3, pid.compute(1, 10));
}
