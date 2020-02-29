// Monstor Motor shield library

/*
 * Usage Notes:
 * 
 */


#ifndef _MonsterMotor_h_
#define _MonsterMotor_h_

#include <inttypes.h>
#include <avr/io.h>

#define MM_BRAKEVCC 0
#define MM_CW 1
#define MM_CCW 2
#define BRAKEGND 3
#define CS_THRESHOLD 100

class MonsterMoto
{
  public:
    MonsterMoto(void);

    //! enable motors
    void enable();

    //! run. shortcut. motor = 0,1. direction =
    void run(uint8_t motor, uint8_t direction, uint8_t speed);

    //! turn off motor
    void motorOff(uint8_t motor);

    //! set motor speed. motor = 0,1. speed = 0..255
    void setSpeed(uint8_t motor, uint8_t speed);

    //! set motor direction. motor = 0,1. direction = MM_CW, CCW
    void setDir(uint8_t motor, uint8_t direction);

    //! current sense check return true if over-current detected.
    bool currentSense();

  private:
    int inApin[2] = {7, 4}; // INA: Clockwise input
    int inBpin[2] = {8, 9}; // INB: Counter-Clockwise input
    int pwmpin[2] = {5, 6}; // PWM input
    int cspin[2]  = {2, 3}; // CS: Current sense ANALOG input
    int enpin[2]  = {0, 1}; // EN: Status of switches output
    int statpin   = 13;     // LED pin
};

#endif
