/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\19.jayden.liffick                                */
/*    Created:      Wed Feb 05 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Potentiometer        pot           H               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Controller1.Screen.clearScreen();

  while(true)
  {

    Controller1.Screen.print(Potentiometer.angle(degrees)); // Min=0.6187 Max=249.94
    Controller1.Screen.setCursor(1,1);

  }
}
