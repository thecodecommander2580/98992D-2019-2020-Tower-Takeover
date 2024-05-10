/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftIntake           motor         7               
// RightIntake          motor         12              
// ArmMotor             motor         8               
// RampMotor            motor         4               
// Controller1          controller                    
// Drivetrain           drivetrain    1, 10, 9, 11    
// Potentiometer        pot           A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
 
using namespace vex;
 
// A global instance of competition
competition Competition;
 
// define your global instances of motors and other devices here
 
// Functions
 
float Intake_Tuning=4;
int Low_Battery_Amount=25;
int Low_Battry_Timing=1000;
int Low_Battry_Pulse=1;
int Low_Battry_Timer=0;
 
//Base Movement Controls
 
void Forward_Drive(int speed, float distance)
{
 
 Drivetrain.setDriveVelocity(speed,percent);
 Drivetrain.setStopping(brake);
 Drivetrain.driveFor(forward,distance,inches);
 
}
 
void Reverse_Drive(int speed, float distance)
{
 
 Drivetrain.setDriveVelocity(speed,percent);
 Drivetrain.setStopping(brake);
 Drivetrain.driveFor(reverse,distance,inches);
 
}
 
void Left_Turn(int speed, float angle)
{
 
 Drivetrain.setTurnVelocity(speed,percent);
 Drivetrain.setStopping(brake);
 Drivetrain.turnFor(left,angle*.566666666666666666666666666666666666666666666666666666666667,degrees);
 
}
 
void Right_Turn(int speed, float angle)
{
 
 Drivetrain.setTurnVelocity(speed,percent);
 Drivetrain.setStopping(brake);
 Drivetrain.turnFor(right,angle*.566666666666666666666666666666666666666666666666666666666667,degrees);//.93889
 
}
 
//Intake Controls
 
void Intake_In(int speed, float rotations)
{
 
 LeftIntake.setVelocity(speed, percent);
 RightIntake.setVelocity(speed, percent);
 
 LeftIntake.setStopping(hold);
 RightIntake.setStopping(hold);
 
 LeftIntake.spinFor(reverse,-(Intake_Tuning*rotations), turns, false);
 RightIntake.spinFor(forward, (Intake_Tuning*rotations), turns, false);
 
}
 
void Intake_Out(int speed, float rotations){
 
 LeftIntake.setVelocity(speed, percent);
 RightIntake.setVelocity(speed, percent);
 
 LeftIntake.setStopping(hold);
 RightIntake.setStopping(hold);
 
 LeftIntake.spinFor(reverse, (Intake_Tuning*rotations), turns, false);
 RightIntake.spinFor(reverse, (Intake_Tuning*rotations), turns, false);
 
}
 
//Ramp Controls
 
void Ramp_Movement(int speed, float degreese)
{
  RampMotor.setMaxTorque(100,percent);
 
 RampMotor.setVelocity(speed, percent);
 RampMotor.setStopping(hold);
 
 RampMotor.spinFor(forward,degreese*7,degrees);
 
}
 
//Arm Controls
 
void Arm_Movement(int speed, float degreese)
{
 
 ArmMotor.setVelocity(speed, percent);
 ArmMotor.setStopping(hold);
 
 ArmMotor.setPosition(degreese, degrees);
 
}
 
//Controller Stuff

void Controller_Reset()
{

 Controller1.Screen.clearScreen();
 Controller1.Screen.setCursor(1,1);

}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
 
void pre_auton(void) {
 // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();
 
  // Display Program Info
 Controller_Reset();
 Controller1.Screen.print("Comp-Red");
 Controller1.Screen.newLine();
 
 if(Potentiometer.angle(degrees) <= 10)
 {

   Controller1.Screen.print("1 Point Auto");

 }

 else if(Potentiometer.angle(degrees) >= 186.5 && Potentiometer.angle(degrees) >= 10) //right
 {

  
Controller1.Screen.print("Straight Auto");
 }

 else if(Potentiometer.angle(degrees) <= 186.5 && Potentiometer.angle(degrees) >= 10 && Potentiometer.angle(degrees) >= 10) //left
 {

    Controller1.Screen.print("Scattered Auto");

 }

 else
 {

 }

 wait(3, seconds);
 
 Controller_Reset();
 Controller1.Screen.print("Battry = ", Brain.Battery.capacity());

}
 // All activities that occur before the competition starts
 // Example: clearing encoders, setting servo positions, ...

 
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
 
void autonomous(void) {

  /*if(Potentiometer.angle(degrees) <= 10) 
  {
  // 1 Point
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.setStopping(brake);
  Drivetrain.setTurnVelocity(80, percent);
  Drivetrain.driveFor(reverse, 52, inches);
  Drivetrain.driveFor(forward, 52, inches);
  
  // FLipout
  RampMotor.setVelocity(35,percent);
  ArmMotor.setVelocity(60,percent);//55
  LeftIntake.setVelocity(100,percent);
  RightIntake.setVelocity(100,percent);
  LeftIntake.spin(reverse);
  RightIntake.spin(reverse);
  RampMotor.spin(forward);
  ArmMotor.spin(forward);
  wait(2,seconds);
  RightIntake.stop(coast);
  LeftIntake.stop(coast);
  RampMotor.stop(coast);
  ArmMotor.stop(coast);
  // wait(.001,seconds);
  
  //Stack Towers
  RampMotor.spin(reverse);
  wait(.5,seconds);
 
  //Intake_Out(100,0.25);
   
   wait(.5,seconds);
 }

 else
 {*/
  // FLipout
  RampMotor.setVelocity(35,percent);
  ArmMotor.setVelocity(60,percent);//55
  LeftIntake.setVelocity(100,percent);
  RightIntake.setVelocity(100,percent);

  LeftIntake.spin(reverse);
  RightIntake.spin(reverse);
  RampMotor.spin(forward);
  ArmMotor.spin(forward);
  wait(2,seconds);
  RightIntake.stop(coast);
  LeftIntake.stop(coast);
  RampMotor.stop(coast);
  ArmMotor.stop(coast);
  // wait(.001,seconds);
  
  //intake back in place
  RampMotor.spin(reverse);
  wait(.5,seconds);
 
  //Intake_Out(100,0.25);
  
   
   wait(.5,seconds);

  //Blake==THE BIG DUMB
 // 1 = 249.94, 2 = 185.85, 3 = 90.095, 4 = 0.6115 |||| 1 = 249.94, Mid Point = 186.5, 2 = 86.6, 3 = 1 - 0.6115
 if(Potentiometer.angle(degrees) >= 186.5 && Potentiometer.angle(degrees) >= 10) //right
 {

  //Arm_Movement(30, 200);
  Intake_In(100,3);
  Forward_Drive(35,41);//45
  Reverse_Drive(65,27);//50
  Right_Turn(35,123);//35
  Forward_Drive(45,13);//35
  //Arm_Movement(50,25);
  //Intake_Out(100,0.007);
  Drivetrain.stop(coast);
  LeftIntake.setStopping(coast);
  RightIntake.setStopping(coast);
  LeftIntake.setVelocity(10,percent);
  RightIntake.setVelocity(10,percent);
  //Stacking
  LeftIntake.spinFor(reverse,.13*4,turns,false);
  RightIntake.spinFor(reverse,.13*4,turns,false);
  Ramp_Movement(31,115);
  Drivetrain.driveFor(forward,1,inches);
  wait(0.05,seconds);
  Drivetrain.driveFor(reverse,12,inches);

 }
 else if(Potentiometer.angle(degrees) <= 186.5 && Potentiometer.angle(degrees) >= 10) //left still in progress
 {
 
    
RightIntake.stop(coast);
  LeftIntake.stop(coast);
  RampMotor.stop(coast);
  ArmMotor.stop(coast);
LeftIntake.setVelocity(100,percent);
RightIntake.setVelocity(100,percent);
  LeftIntake.spin(forward);
  RightIntake.spin(forward);
  Drivetrain.setDriveVelocity(35,percent);
  Drivetrain.driveFor(forward,18,inches);
  Right_Turn(37,90);//25
 Drivetrain.setDriveVelocity(50,percent);//10
 Drivetrain.driveFor(forward,5,inches);

 Drivetrain.setDriveVelocity(60,percent);//35
 Drivetrain.driveFor(reverse,5,inches);
 Left_Turn(35,200);
 Drivetrain.driveFor(forward,19, inches);
 Left_Turn(50,52);
 Drivetrain.driveFor(forward,6.8,inches);
 LeftIntake.setVelocity(10,percent);
 RightIntake.setVelocity(10,percent);

 //Stacking
 LeftIntake.spinFor(reverse,.13*4,turns,false);
  RightIntake.spinFor(reverse,.13*4,turns,false);
  Ramp_Movement(31,115);
  Drivetrain.driveFor(forward,1.5,inches);
  wait(0.05,seconds);
  Drivetrain.driveFor(reverse,12,inches);


 }
 else // If the autonomous fails to run for some reason
 {
  Controller1.rumble(rumbleShort);
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1,1);
  Controller1.Screen.print("Something Broke");
  Controller1.Screen.newLine();
  Controller1.Screen.print("Check EVERYTHING");
  Controller1.Screen.newLine();
  Controller1.Screen.print("Pot: %f", Potentiometer.angle(degrees));

 }
}

 
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
 
void usercontrol(void) {
 // User control code here, inside the loop
 while (1) {
   // This is the main execution loop for the user control program.
   // Each time through the loop your program should update motor + servo
   // values based on feedback from the joysticks.
   Drivetrain.setStopping(coast);
   
   
   if(Controller1.ButtonA.pressing()){
     if(RampMotor.position(degrees) >= 150*7)
     {

      RampMotor.spin(forward,45,percent);

     }
     else
     {
      RampMotor.spin(forward,75,percent);
     }
   }
   LeftIntake.setMaxTorque(100,percent);
   RightIntake.setMaxTorque(100,percent);
   ArmMotor.setMaxTorque(100,percent);
   RampMotor.setMaxTorque(100,percent);
 
  
   if(Controller1.ButtonY.pressing()){
     RampMotor.spin(forward,40,percent);
 
   }
   else if(Controller1.ButtonA.pressing()){
     RampMotor.spin(reverse,40,percent);
 
   }
   else if(Controller1.ButtonX.pressing()){
     RampMotor.spin(reverse,100,percent);
   }
   else{
    RampMotor.setStopping(hold);
    RampMotor.stop();
         }
   if(Controller1.ButtonL1.pressing()){
     ArmMotor.spin(forward,100,percent);
   }
   else if(Controller1.ButtonL2.pressing()){
     ArmMotor.spin(reverse,100,percent);
 
   }
   else{
     ArmMotor.setStopping(hold);
     ArmMotor.stop();
   }
   if(Controller1.ButtonR2.pressing()){
    RightIntake.spin(fwd,12.0,voltageUnits::volt);
      LeftIntake.spin(fwd,12.0,voltageUnits::volt);
 
   }
   else if(Controller1.ButtonR1.pressing()){
     RightIntake.spin(reverse,12.0,voltageUnits::volt);
      LeftIntake.spin(reverse,12.0,voltageUnits::volt);
   }
   else{
     RightIntake.setStopping(hold);
     LeftIntake.setStopping(hold);
     RightIntake.stop();
     LeftIntake.stop();
   }

   // Battry Check

   if(Brain.Battery.capacity() <= Low_Battery_Amount && Low_Battry_Pulse==1)
   {
 
    Controller1.rumble(rumblePulse);
    Low_Battry_Pulse=0;

   }
   else if(Low_Battry_Pulse==0 && Low_Battry_Timer <= Low_Battry_Timing)
   {

    Low_Battry_Timer=(Low_Battry_Timer+1);

   }
   else if(Low_Battry_Timer >= Low_Battry_Timing)
   {

    Low_Battry_Timer=0;
    Low_Battry_Pulse=1;

   }
   else
   {

   }

   // Controller Flipout

  if(Controller1.ButtonUp.pressing())
  {

  RampMotor.setVelocity(35,percent);
  ArmMotor.setVelocity(55,percent);//55
  LeftIntake.setVelocity(100,percent);
  RightIntake.setVelocity(100,percent);
  LeftIntake.spin(reverse);
  RightIntake.spin(reverse);
  RampMotor.spin(forward);
  ArmMotor.spin(forward);
  wait(2,seconds);
  RightIntake.stop(coast);
  LeftIntake.stop(coast);
  RampMotor.stop(coast);
  ArmMotor.stop(coast);
  // wait(.001,seconds);
  
  //intake back in place
  RampMotor.spin(reverse);
  wait(.5,seconds);
 
  //Intake_Out(100,0.25);
   
   wait(.5,seconds);

  }
 }
 
 
   wait(20, msec); // Sleep the task for a short amount of time to
                   // prevent wasted resources.
}
 
//
// Main will set up the competition functions and callbacks.
//
int main() {
 // Set up callbacks for autonomous and driver control periods.
 Competition.autonomous(autonomous);
 Competition.drivercontrol(usercontrol);
 
 // Run the pre-autonomous function.
 pre_auton();
 
 // Prevent main from exiting with an infinite loop.
 while (true) {
   wait(100, msec);//exsplod
 }
}


