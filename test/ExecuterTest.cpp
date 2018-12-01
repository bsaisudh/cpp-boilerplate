/*
 * @file ExecuterTest.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * @author Bala Murali Manoghar Sai Sudhakar
 * @brief mock test for square class
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

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <sstream>
#include <iostream>
#include <string>

#include "../include/PIDController.h"
#include "../include/Executer.h"

using ::testing::Return;
using ::testing::_;
using ::testing::AtLeast;
/**
 * @brief Mock class for Square class
 */
class MockPID : public PIDController {
 public:
  MOCK_METHOD2(compute, double(double startPoint, double endPoint));
  MOCK_METHOD1(setKp, void(double KpIn));
  MOCK_METHOD0(getKp, double());
  MOCK_METHOD1(setKd, void(double KdIn));
  MOCK_METHOD0(getKd, double());
  MOCK_METHOD1(setKi, void(double KiIn));
  MOCK_METHOD0(getKi, double());

};

/**
 * @brief Testing the inObstacle function mock
 */
TEST(TestMock,Computetest){
  MockPID mPID;  // Creating pointer for controller class
  Executer exe(mPID);
  EXPECT_CALL(mPID, setKd(_))
        .Times(AtLeast(1));
  EXPECT_CALL(mPID, setKp(_))
          .Times(AtLeast(1));
  EXPECT_CALL(mPID, setKi(_))
          .Times(AtLeast(1));
  EXPECT_CALL(mPID, compute(_,_))
      .Times(AtLeast(1))
      .WillOnce(Return(10))
      .WillRepeatedly(Return(10));
  exe.runPID();
  EXPECT_EQ(true,true);
}
