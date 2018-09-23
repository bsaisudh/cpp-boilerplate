/**
 * Class declaration for a PID Controller.
 * @brief Code written as a part of the Test Driven Development Assignment
 * @author Akshay
 * @Copyright Copyright [2018] Akshay
 * @file PIDController.h
 */

#ifndef INCLUDE_PIDCONTROLLER_H_
#define INCLUDE_PIDCONTROLLER_H_

class PIDController {
 public:
  PIDController();
  ~PIDController();
  /** @params startPoint
   *  @params endPoint
   *  @brief function to compute the end velocity for controlling a moving
   * object in 1 Dimension
   */
  double compute(double startPoint, double endPoint);
  void setKp(double KpIn);
  double getKp();
  void setKd(double KdIn);
  double getKd();
  void setKi(double KiIn);
  double getKi();

 private:
  double Kp, Kd, Ki;
  double prevError, initError;
};

#endif  // INCLUDE_PIDCONTROLLER_H_
