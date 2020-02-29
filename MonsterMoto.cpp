// MonsterMotor shield library

#include "Arduino.h"
#include "MonsterMoto.h"

MonsterMoto::MonsterMoto()
{
}

//! turn off motor
void MonsterMoto::motorOff(uint8_t motor)
{
  for(int i=0; i<2; i++)
  {
    digitalWrite(inApin[i], LOW);
    digitalWrite(inBpin[i], LOW);
  }
  analogWrite(pwmpin[motor],0);
}

void MonsterMoto::enable(void)
{
  pinMode(statpin,OUTPUT);

  // Initialize digital pins
  for(int i = 0; i < 2; i++)
  {
    pinMode(inApin[i], OUTPUT);
    pinMode(inBpin[i], OUTPUT);
    pinMode(pwmpin[i], OUTPUT);
  }

  // Initialize braked
  for(int i = 0; i < 2; i++)
  {
    digitalWrite(inApin[i],LOW);
    digitalWrite(inBpin[i],LOW);
  }
}

bool MonsterMoto::currentSense()
{
    if (    (analogRead(cspin[0]) < CS_THRESHOLD) 
        and (analogRead(cspin[1]) < CS_THRESHOLD) )
    {
      digitalWrite(statpin, HIGH);
      return true;
    }
    else
    {
      digitalWrite(statpin, LOW);
    }

    return false;
}

void Monster::run(uint8_t motor, uint8_t direction, uint8_t speed)
{
  setDir(motor, direction);
  setSpeed(motor, speed);
}

void MonsterMoto::setSpeed(uint8_t motor, uint8_t speed)
{
  // check if motor is valid
  if(motor <= 1)
  {
    analogWrite(pwmpin[motor], speed);
  }
}

 //! set motor direction. motor = 0,1. direction = MM_CW, CCW
void MonsterMoto::setDir(uint8_t motor, uint8_t direction)
{  
  if( (motor <= 1) and (direction <= 4) )
  {
    // Set inA[motor]
    if( direction <= 1)
    {
      digitalWrite(inApin[motor], HIGH);
    }
    else
    {
      digitalWrite(inApin[motor], LOW);
    }

    // Set inB[motor]
    if( (direction==0) || (direction==2) )
    {
      digitalWrite(inBpin[motor], HIGH);
    }
    else
    {
      digitalWrite(inBpin[motor], LOW);
    }
  }
}


