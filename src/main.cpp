/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       jaydenliffick                                             */
/*    Created:      Sat Jan 18 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 10           
// Ramp_Motor           motor         4               
// Arm_Motor            motor         8               
// Left_Intake          motor         6               
// Right_Intake         motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// Variables

int SSC=1;
int Temp_Limit = 75;

//Base Movement Controls

void Forward_Drive(int speed, float distance)
{

Drivetrain.setDriveVelocity(speed, percent);
Drivetrain.setStopping(brake);

Drivetrain.driveFor(forward, speed, inches);

}

void Reverse_Drive(int speed, float distance)
{

Drivetrain.setDriveVelocity(speed, percent);
Drivetrain.setStopping(brake);

Drivetrain.driveFor(reverse, speed, inches);

}

void Left_Turn(int speed, float degreese)
{

Drivetrain.setTurnVelocity(speed, percent);
Drivetrain.setStopping(brake);

Drivetrain.turnFor(left, degreese, degrees, false);

}

void Right_Turn(int speed, float degreese)
{

Drivetrain.setTurnVelocity(speed, percent);
Drivetrain.setStopping(brake);

Drivetrain.turnFor(right, degreese, degrees, false);

}

//Intake Controls

void Intake_In(int speed, float rotations)
{

Left_Intake.setVelocity(speed, percent);
Right_Intake.setVelocity(speed, percent);

Left_Intake.setStopping(hold);
Right_Intake.setStopping(hold);

Left_Intake.spinFor(reverse, rotations, turns, false);
Right_Intake.spinFor(reverse, rotations, turns, false);

}

void Intake_Out(int speed, float rotations)
{

Left_Intake.setVelocity(speed, percent);
Right_Intake.setVelocity(speed, percent);

Left_Intake.setStopping(hold);
Right_Intake.setStopping(hold);

Left_Intake.spinFor(forward, rotations, turns, false);
Right_Intake.spinFor(forward, rotations, turns, false);

}

//Ramp Controls

void Ramp_Movement(int speed, float degreese)
{

Ramp_Motor.setVelocity(speed, percent);
Ramp_Motor.setStopping(hold);

Ramp_Motor.setPosition(degreese, degrees);

}

//Arm Controls

void Arm_Movement(int speed, float degreese)
{

Arm_Motor.setVelocity(speed, percent);
Arm_Motor.setStopping(hold);

Arm_Motor.setPosition(degreese, degrees);

}

//System Monitering

void System_Monitering()
{

  while(true)
  {

    if(Brain.Battery.capacity() < 20 || Brain.Battery.capacity() == 20)
    {
      repeat(3)
      {

      Controller1.rumble(rumblePulse);
      wait(0.5, seconds);

      }
      wait(8, seconds);
    }

    if(Ramp_Motor.temperature(percent) || Arm_Motor.temperature(percent) || Left_Intake.temperature(percent) || Right_Intake.temperature(percent) || Drivetrain.temperature(percent) > Temp_Limit )
    {

      Controller1.Screen.clearScreen(); 
      Controller1.Screen.setCursor(1, 1);
      Controller1.rumble(rumbleShort); 
      Brain.Screen.setFillColor(red); 

       while(Ramp_Motor.temperature(percent) || Arm_Motor.temperature(percent) || Left_Intake.temperature(percent) || Right_Intake.temperature(percent) || Drivetrain.temperature(percent) > Temp_Limit)
      {

      if(Drivetrain.temperature(percent) > Temp_Limit)
      {

        Controller1.Screen.print("Drivetrain Temp > "); 
        Controller1.Screen.newLine(); 
        Controller1.Screen.print(Temp_Limit); 

      }

      wait(1, seconds);
      Controller1.Screen.clearScreen(); 
      Controller1.Screen.setCursor(1, 1);

      if(Arm_Motor.temperature(percent) > Temp_Limit)
      {

        Controller1.Screen.print("Arm Motor Temp > "); 
        Controller1.Screen.newLine(); 
        Controller1.Screen.print(Temp_Limit); 
        
      }

      wait(1, seconds);
      Controller1.Screen.clearScreen(); 
      Controller1.Screen.setCursor(1, 1);

      if(Ramp_Motor.temperature(percent) > Temp_Limit)
      {

        Controller1.Screen.print("Ramp Motor Temp > "); 
        Controller1.Screen.newLine(); 
        Controller1.Screen.print(Temp_Limit); 
        
      }

      wait(1, seconds);
      Controller1.Screen.clearScreen(); 
      Controller1.Screen.setCursor(1, 1);


      if(Left_Intake.temperature(percent) > Temp_Limit)
      {

        Controller1.Screen.print("Left Intake Temp > "); 
        Controller1.Screen.newLine(); 
        Controller1.Screen.print(Temp_Limit); 
        
      }
      
      wait(1, seconds);
      Controller1.Screen.clearScreen(); 
      Controller1.Screen.setCursor(1, 1);


      if(Right_Intake.temperature(percent) > Temp_Limit)
      {

        Controller1.Screen.print("Right Intake Temp > "); 
        Controller1.Screen.newLine(); 
        Controller1.Screen.print(Temp_Limit); 
        
      }

      wait(1, seconds);
      Controller1.Screen.clearScreen(); 
      Controller1.Screen.setCursor(1, 1);
      }

    }
  
  }

}



//Program

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // System Monitering
  if(SSC==1)
  {

    System_Monitering();

  }
  // Main Program

  waitUntil(Controller1.ButtonA.pressing());
  Ramp_Movement(20,20);
  waitUntil(Ramp_Motor.isDone());
  Arm_Movement(95,50);
  Intake_Out(85,7);
  waitUntil(Arm_Motor.isDone());
  Arm_Movement(95,0);
  waitUntil(Arm_Motor.isDone());
  Intake_In(100,12);
  
}
