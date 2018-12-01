# C++ Boilerplate
[![Build Status](https://travis-ci.org/AkshayRajaramanSubramanian/cpp-boilerplate.svg?branch=master)](https://travis-ci.org/AkshayRajaramanSubramanian/cpp-boilerplate)
[![Coverage Status](https://coveralls.io/repos/github/AkshayRajaramanSubramanian/cpp-boilerplate/badge.svg?branch=master)](https://coveralls.io/github/AkshayRajaramanSubramanian/cpp-boilerplate?branch=master)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/bsaisudh/cpp-boilerplate/blob/GMock_Extra_Credit/LICENSE)
---

## Overview

This program implements a simple PID controller in C++ platform and demonstrates the useage of GTEST and GMOCK framework for unit testing.

## Dependencies

- cmake
- googletest
- google mock

## Google Gmock Useage 

GMOCK is used to test the API functionality rather thatn testing the functionality itself. For gmock all the class members have to be virtual and the mocked class will be inherited form the actual class. Some amount of refactoring may be required for integrating gmock to the existing frame code
<br><br>
The top level class that consumes low level class has to take the low level object from outside and should be a reference as shown below. Here the PIDController class will be mocked
```
class Executer {
  PIDController &pid;
 public:
  /**
   * @brief Constructor for Executer CLass
   * @param None
   * @return None
   */
  explicit Executer(PIDController &_pid);
}
```
Get the class object reference through constructor
```
Executer::Executer(PIDController &_pid)
    : pid(_pid) {
}
```
Create a mock class for PIDController class in the test file using MOCK_METHOD* macros
```
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
```
EXPECT_CALL* methods are used to specy that a particular function will be called
```
TEST(TestMock, Computetest) {
  MockPID mPID;  // Creating pointer for controller class
  Executer exe(mPID);
  EXPECT_CALL(mPID, setKd(_)).Times(AtLeast(1));
  EXPECT_CALL(mPID, setKp(_)).Times(AtLeast(1));
  EXPECT_CALL(mPID, setKi(_)).Times(AtLeast(1));
  EXPECT_CALL(mPID, compute(_, _)).Times(AtLeast(1)).WillOnce(Return(10))
      .WillRepeatedly(Return(10));
  exe.runPID();
}
```
Google mock needs to be initialized in the main test file
```
  // Initialize Google Test
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::GTEST_FLAG(throw_on_failure) = true;
  // Initialize google mock
  ::testing::InitGoogleMock(&argc, argv);
```
## Cmake chages needed

It is enough if gmock folder is alone added in toplecel folder
```
add_subdirectory(vendor/googletest/googlemock)
```
Add the mock librarties in test cmake file
```
target_include_directories(cpp-test PUBLIC ../vendor/googletest/googlemock/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest gmock)
```

### More info on google Mock
For more information on gmock please visit this [link](https://github.com/abseil/googletest/blob/master/googlemock/docs/ForDummies.md)

## Class Diagram

</p>
<p align="center">
<img src="/UML Diagrams/UML\ Class\ PID\ 1.png">
</p>
</p>

## Activity Diagram PID Controller Class

</p>
<p align="center">
<img src="/UML Diagrams/ActivityDiagram.png">
</p>
</p>

## Activity Diagram Executer Class

</p>
<p align="center">
<img src="/UML Diagrams/Activity\ Diagram\ Main\ PID.png">
</p>
</p>

## Standard install via command-line
```
git clone -b GMock_Extra_Credit --recursive https://github.com/bsaisudh/cpp-boilerplate.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/dpiet/cpp-boilerplate
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../cpp-boilerplate/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)


## Debug


1. Set breakpoint in source file (i.e. double click in the left margin on the line you want 
the program to break).

2. In Eclipse, right click on the boilerplate-eclipse in Project Explorer, select Debug As -> 
Local C/C++ Application, choose the binaries to run (e.g. shell-app).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in 
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++ 
perspetive view (or Windows->Perspective->Open Perspective->C/C++).


## Plugins

- CppChEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.


- Google C++ Sytle

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right click on the source code or folder in 
    Project Explorer and choose Source -> Format

[reference-id-for-eclipse-cpp-google-style]: https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-cpp-google-style.xml

- Git

    It is possible to manage version control through Eclipse and the git plugin, but it typically requires creating another project. If you're interested in this, try it out yourself and contact me on Canvas.
