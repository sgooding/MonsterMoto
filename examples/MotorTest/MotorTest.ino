#include <MonsterMoto.h>

MonsterMoto motor;

void setup()
{
  Serial.begin(9600);
  Serial.println("Monster Moto - Motor test");

  Serial.println("Enable");
  motor.enable();

}

void loop()
{
  Serial.println("Move both motors CW");
  motor.setDir(0, MM_CW);
  motor.setDir(1, MM_CW);
  motor.setSpeed(0,255);
  motor.setSpeed(1,255);
  delay(500);

  Serial.println("Move both motors CCW");
  motor.setDir(0, MM_CCW);
  motor.setDir(1, MM_CCW);
  motor.setSpeed(0,255);
  motor.setSpeed(1,255);
  delay(500);

  Serial.println("Move CW shortcut");
  motor.run(0, MM_CW, 255);
  motor.run(1, MM_CW, 255);
  delay(500);

  Serial.println("Current Sense");
  if(not motor.currentSense())
  {
    Serial.println("Over-current sensed.");
  }
}

