/*
 * Executer.h
 *
 *  Created on: Nov 30, 2018
 *      Author: bala
 */

#ifndef APP_EXECUTER_H_
#define APP_EXECUTER_H_

#include "PIDController.h"

class Executer {
  PIDController &pid;
 public:
  Executer(PIDController &_pid);
  void runPID();
  virtual ~Executer();
};

#endif /* APP_EXECUTER_H_ */
