/**
 * @Copyright [2018] <Akshay>
 * @brief main function for using an instance of the PIDController class
 * @author Akshay, Bala
 * @file main.cpp
 */

#include <iostream>
#include "../include/PIDController.h"
#include "../include/Executer.h"

/**
 * @brief calculate the path form start velocity to end velocity through PID algorithm
 */
int main() {
  PIDController pid;  // Creating pointer for controller class
  Executer exe(pid);
  exe.runPID();
}
