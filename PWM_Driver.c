/*
 * File:   PWM_Driver.c
 * Author: Mark
 *
 * Created on August 31, 2019, 1:11 PM
 */

#include "Config.h"
#include "PWM_Driver.h"

void PWM_init(unsigned char pin)
{
    GIE = 1;
    PEIE = 1;
    T2CON = 0b00000100;
    if(pin == 1)
    {
        CCPR1 = 0;
        CCP1IE = 1;
        TRISC &= 0b11111011;
        CCP1CON = 0b00001111;
    }
    else if(pin == 2)
    {
        CCPR2 = 0;
        CCP2IE = 1;
        TRISC &= 0b11111101;
        CCP2CON = 0b00001111;
    }    
}
void setPWM(unsigned short value, unsigned char pin)
{
    if(pin == 1)
    {
        CCPR1 = (0xFFFFF)&(value>>2);
        CCP1CON &= 0xFF;
        CCP1CON |= ((value)&0xF)<<4;
    }
    else if(pin == 2)
    {
        CCPR2 = (0xFFFFF)&(value>>2);
        CCP2CON &= 0xFF;
        CCP2CON |= ((value)&0xF)<<4;
    }
}
