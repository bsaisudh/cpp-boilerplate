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
  virtual ~PIDController();
  /** @params startPoint
   *  @params endPoint
   *  @brief function to compute the end velocity for controlling a moving
   * object in 1 Dimension
   */
  virtual double compute(double startPoint, double endPoint);
  virtual void setKp(double KpIn);
  virtual double getKp();
  virtual void setKd(double KdIn);
  virtual double getKd();
  virtual void setKi(double KiIn);
  virtual double getKi();

 private:
  double Kp, Kd, Ki;
  double prevError, initError;
};

#endif  // INCLUDE_PIDCONTROLLER_H_
