/*
 * @file PIDController.h
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

#ifndef INCLUDE_PIDCONTROLLER_H_
#define INCLUDE_PIDCONTROLLER_H_

class PIDController {
 private:
  double Kp, Kd, Ki;    // Gain values
  double prevError, initError; // error values
 public:
  /**
   * @brief Constructor for PIDcontroller CLass
   * @param None
   * @return None
   */
  PIDController();
  /**
   * @brief Destructor for PIDController class
   * @param None
   * @return None
   */
  virtual ~PIDController();
  /**
   * @brief Computes the PID value
   * @param startPoint Start point of velocity
   * @param endPoint end point of velocity
   * @return Double computed velocity
   */
  virtual double compute(double startPoint, double endPoint);
  /**
   * @brief Sets proportional gain value
   * @param KpIn Proportional gain value
   * @return None
   */
  virtual void setKp(double KpIn);
  /**
   * @brief Gets proportional gain value
   * @param None
   * @return Double Proportional gain value
   */
  virtual double getKp();
  /**
   * @brief Sets differential gain value
   * @param KdIn Differential gain value
   * @return None
   */
  virtual void setKd(double KdIn);
  /**
   * @brief Gets  gain value
   * @param None
   * @return Double Differential gain value
   */
  virtual double getKd();
  /*
   * @brief Sets integral gain value
   * @param KdIn Integral gain value
   * @return None
   */
  virtual void setKi(double KiIn);
  /**
   * @brief Gets integral gain value
   * @param None
   * @return Double Integral gain value
   */
  virtual double getKi();
};

#endif  // INCLUDE_PIDCONTROLLER_H_
