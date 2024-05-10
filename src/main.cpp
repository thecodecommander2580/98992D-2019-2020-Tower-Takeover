/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\19.jayden.liffick                                */
/*    Created:      Wed Feb 19 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor1               motor         1               
// Motor2               motor         2               
// Motor3               motor         3               
// Motor4               motor         4               
// Motor5               motor         5               
// Motor6               motor         6               
// Motor7               motor         7               
// Motor8               motor         8               
// Motor9               motor         9               
// Motor10              motor         10              
// Motor11              motor         11              
// Motor12              motor         12              
// Motor13              motor         13              
// Motor14              motor         14              
// Motor15              motor         15              
// Motor16              motor         16              
// Motor17              motor         17              
// Motor18              motor         18              
// Motor19              motor         19              
// Motor20              motor         20              
// Motor21              motor         21              
// BumperA              bumper        A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  Brain.Screen.setPenColor(red);
  
  Brain.Screen.print("Please Disconect All V5 Sensors And The Radio.");
  wait(5, seconds);
  Brain.Screen.newLine();
  Brain.Screen.print("Press The Screen To Continue.");
  waitUntil(Brain.Screen.pressing());

  // Test Motors

  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  Brain.Screen.setPenColor(cyan);
  Brain.Screen.print("Testing");
  Brain.Screen.newLine();
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 1");
  Motor1.setVelocity(10, percent);
  Motor1.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 2");
  Motor2.setVelocity(10, percent);
  Motor2.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 3");
  Motor3.setVelocity(10, percent);
  Motor3.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 4");
  Motor4.setVelocity(10, percent);
  Motor4.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 5");
  Motor5.setVelocity(10, percent);
  Motor5.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 6");
  Motor6.setVelocity(10, percent);
  Motor6.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 7");
  Motor7.setVelocity(10, percent);
  Motor7.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 8");
  Motor8.setVelocity(10, percent);
  Motor8.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 9");
  Motor9.setVelocity(10, percent);
  Motor9.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 10");
  Motor10.setVelocity(10, percent);
  Motor10.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 11");
  Motor11.setVelocity(10, percent);
  Motor11.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 12");
  Motor12.setVelocity(10, percent);
  Motor12.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 13");
  Motor13.setVelocity(10, percent);
  Motor13.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 14");
  Motor14.setVelocity(10, percent);
  Motor14.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 15");
  Motor15.setVelocity(10, percent);
  Motor15.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 16");
  Motor16.setVelocity(10, percent);
  Motor16.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 17");
  Motor17.setVelocity(10, percent);
  Motor17.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 18");
  Motor18.setVelocity(10, percent);
  Motor18.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 19");
  Motor19.setVelocity(10, percent);
  Motor19.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 20");
  Motor20.setVelocity(10, percent);
  Motor20.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.print("Motor 21");
  Motor21.setVelocity(10, percent);
  Motor21.spinFor(forward, 10, degrees);
  Brain.Screen.clearLine(2);
  Brain.Screen.setCursor(1,2);
  waitUntil(BumperA.pressing());
  waitUntil(!BumperA.pressing());
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  Brain.Screen.setPenColor(green);
  Brain.Screen.print("Testing Done");
  wait(5, seconds);
  Brain.Screen.clearScreen();
  
}
