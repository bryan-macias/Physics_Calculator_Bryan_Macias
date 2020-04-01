//Bryan Macias
//Header file where all of the functions are used for the calc.
//
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <iomanip> 
#include "Input_Validation_Extended.h" 
using namespace std;

//function prototypes
void showMenu();
void handleOption(string);
void motionMenu();

//function definitions
//function to display the menu.
void showMenu()
{
  cout << "\n\nMENU" << endl; 
  cout << "A: Velocity Calculator" <<endl; 
  cout << "B: Acceleration Calculator" << endl; 
  cout << "C: Motion (Contains 4 other options)" << endl; 
  cout << "D: Newtons Second Law" << endl;
  cout << "F: Weight" << endl;
  cout << "G: Momentum" << endl;
  cout << "E: Exit" << endl; 
  cout << "X: clear the screen" << endl;  
}

void motionMenu()
{
  cout << "\nMOTION MENU" << endl;
  cout << "1: Ma = solve for v" << endl;
  cout << "2: Ms = solve for s" << endl;
  cout << "3: Mv2 = solve for v^2" << endl;
  cout << "4: Mv = solve for v_bar" << endl;
}
void handleOption(string userOption)
{
  cout << fixed << setprecision(4.0);

  //variables for the Velocity Calculator:
  double ds = 0.0, dt = 0.0, v = 0.0;
  string dsUnits = "", dtUnits = "";

  //variable for the Acceleration Calculator.
  double dv = 0.0, a = 0.0;
  string dvUnits = "";

  //variables for motion function
  int motionOption = 0;
  double vSub0 = 0.0, time = 0.0, sSub0 = 0.0, sFinal = 0.0, timeFinal = 0.0, v_bar = 0.0;

  //variable for Newtons Second Law function
  double mass = 0.0, newton = 0.0;
  string massUnits = "", aUnits = "", units = "";

  //variables for Weight
  double gravityUser = 0.0, weightFinal = 0.0;

  //variables for Momentum
  double pMomentum = 0.0;

  if(userOption =="A" || userOption =="a")
  {
    cout << "\nYou selected the Velocity Calculator. Using the formula V = ds/dt \n";
    //asking for user input of the ds and dt. Also for the unit input.
    cout << "Please enter your ds:";
    ds = validateDouble(ds);
    cout << "\nPlease enter your unit for ds:";
    dsUnits = validateString(dsUnits);
    cout << "PLease enter your dt:";
    dt = validateDouble(dt);
    cout << "\nPlease enter your unit for dt:";
    dtUnits = validateString(dtUnits);
    //process for finding v.
    v = ds/dt;
    //output the process to user.
    cout << "Here is your result: \n V = " << v << dsUnits << "/" << dtUnits << "." << endl;
  }
  else if(userOption == "B" || userOption == "b")
  {
    cout << "\nYou selected the Acceleration Calculator. Using the formula: A = dv/dt \n";
    cout << "\nPlease enter your dv:";
    dv = validateDouble(dv);
    cout << "\nPlease enter your unit for dv:";
    dvUnits = validateString(dvUnits);
    cout << "\nPlease enter your dt:";
    dt = validateDouble(dt);
    cout << "\nPlease enter your unit for dt:";
    dtUnits = validateString(dtUnits);
    //process for finding accel.
    a = dv/dt;
    //output to the user.
    cout << "Here is your result: " << "\nFor Dv:" << dv << " and Dt:" << dt << "\nAcceleration = " << a << dvUnits << "/" << dtUnits << "." << endl;
  }
  else if(userOption == "C" || userOption == "c")
  {
    cout << "You selected the Motion Menu. Please specify which equation you would like." << endl;
    motionMenu();
    motionOption = validateInt(motionOption);

    if(motionOption == 1 || motionOption == 1)
    {
      //asking for user input
      cout << "You selected to solve for v. Using the following equation: v = v0 + at" << endl;
      cout << "Please enter V_sub0:";
      vSub0 = validateDouble(vSub0);
      cout << "\nPlease enter your Acceleration:";
      a = validateDouble(a);
      cout << "\nPlease enter your Time:";
      time = validateDouble(time);
      //process for finding v using formula given.
      v = vSub0 + (a*time);
      //outputing answer to user
      cout << "Your result is V = " << v << "." << endl;
    }
    else if(motionOption == 2 || motionOption == 2)
    {
      //asking for user input
      cout << "You selected to solve for s. Using the following equation: s = s0 + v0t + ½at2" << endl;
      cout << "Please enter secondSub0:";
      sSub0 = validateDouble(sSub0);
      cout << "Please enter V_sub0:";
      vSub0 = validateDouble(vSub0);
      cout << "\nPlease enter your Time:";
      time = validateDouble(time);
      cout << "\nPlease enter your Acceleration:";
      a = validateDouble(a);
      //process using formula given
      sFinal = sSub0 + (vSub0*time) + (.5*a*time*time);
      //output to the user
      cout << "Your result for S = " << sFinal << "." << endl;
    }
    else if(motionOption == 3 || motionOption == 3)
    {
      cout << "You selected to solve for v^2. Using the following equation: v2 = v02 + 2a(s − s0)" << endl;
      cout << "Please enter V_sub0:";
      vSub0 = validateDouble(vSub0);
      cout << "\nPlease enter your Acceleration:";
      a = validateDouble(a);
      cout << "Please enter your starting time:";
      time = validateDouble(time);
      cout << "Please enter your final time:";
      timeFinal = validateDouble(timeFinal);
      //process using formula
      v = (vSub0*vSub0) + 2.0 * a *  (time - timeFinal);
      v = v*v;
      //output to user
      cout << "Your result for v^s = " << v << "." << endl;
    }
    else if(motionOption ==4 || motionOption == 4)
    {
      //asking for user input
      cout << "You selected to solve for v_bar. Using the following equation: v_bar = ½(v + v0)" << endl;
      cout << "Please enter your v: ";
      v = validateDouble(v);
      cout << "Please enter your vSub0: ";
      vSub0 = validateDouble(vSub0);
      //process using the formula
      v_bar = 0.5*(v+vSub0);
      //outputting to the user
      cout << "Your result for v_bar = " << v_bar << "." << endl;
    }
    else
    {
      cout << "An error occurred please try again." << endl;
    }
  }
  else if (userOption == "D" || userOption == "d")
  {
    cout << "\nYou selected the Calculator for Newtons Second Law. Using the formula: N = m*a \n";
    //asking for user input
    cout << "Please enter your mass, m:";
    mass = validateDouble(mass);
    cout << "Please enter the units for mass: ";
    massUnits = validateString(massUnits);
    cout << "Please enter your acceleration, a:";
    a = validateDouble(a);
    cout << "Please enter your units for acceleration: ";
    aUnits = validateString(aUnits);
    //process using formula
    newton = mass * a;
    //output to user, and append units
    cout << "Your result for Newtons = " << newton << ".";
  }
  else if (userOption == "F" || userOption == "f")
  {
    cout << "You selected the Calculator for Weight. Using the formula: W = mg" << endl;
    cout << "Please enter your mass, m:";
    mass = validateDouble(mass);
    cout << "Please enter the units for your mass:";
    massUnits = validateString(massUnits);
    cout << "Please enter your gravity coefficient: ";
    gravityUser = validateDouble(gravityUser);
    //process using formula
    weightFinal = mass * gravityUser;
    //output to user
    cout << "Your result for weight is, weight = " << weightFinal << " " << massUnits << endl;
  }
  else if (userOption == "G" || userOption == "g")
  {
    //input from user
    cout << "You selected the Momentum Calculator. Using the formula p = mv" << endl;
    cout << "Please enter your mass, m: ";
    mass = validateDouble(mass);
    cout << "Please enter the expected measure units: ";
    units = validateString(units);
    cout << "Please enter your velocity, v: ";
    v = validateDouble(v);
    //process for finding p = Momentum
    pMomentum = mass * v;
    //output to user
    cout << "The result for your Momentum is, Momentum = " << pMomentum << " " << units << endl;
  }
  else if (userOption == "X" || userOption == "x")
  {
     string reset = "\x1b[0m";
      cout << reset; 
      cout << "\033[2J\033[1;1H"; 
      system("clear");
  }
  else if (userOption == "E" || userOption == "e")
  {
    cout << "\nEnd program. See you later!" << endl;
  }
  else
  {
    cout << "\nInvalid input. There was an error. Please try again" << endl;
  }
}

#endif