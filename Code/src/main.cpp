#include <Arduino.h>
#include "RobotMeteo.h"

RobotMeteo robot;

void setup()
{
  robot.Chargement();
}

void loop()
{ 
  robot.Executer();
}