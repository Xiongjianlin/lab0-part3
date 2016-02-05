/* 
 * File:   main.c
 * Author: gvanhoy
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"
#include "switch.h"

#define OUTPUT 0
#define INPUT 1
#define P 0
#define R 1

//TODO: Define states of the state machine
typedef enum stateTypeEnum{
    LED1,LED2,LED3,LED1W,LED2W,LED3W
    
}stateType;
//typedef enum stateTypeEnum{
//} stateType;

//TODO: Use volatile variables that change within interrupts
volatile stateType state;
volatile int transfer; 


int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.

    //TODO: Write each initialization function
    initLEDs();
    initTimer1();
    initSwitch();
    state = LED3; // start at LED3
    //turnOnLED(1);
    while(1){
        switch(state){
            case LED1:
                transfer = 0;
                TMR1 = 0;
                turnOnLED(1);
                if(PORTDbits.RD6 == P)//press
                {
                    state = LED1W;
                }
                break;
            case LED2:
                transfer = 0;
                TMR1 = 0;
                turnOnLED(2);
                if(PORTDbits.RD6 == P)//press
                {
                    state = LED2W;
                }
                break;
            case LED3:
                transfer = 0;
                TMR1 = 0;
                turnOnLED(3);
                if(PORTDbits.RD6 == P)//press bottom transfer to state LED3W
                {
                    state = LED3W;
                }
                break;
            case LED1W:
                turnOnLED(1);
                if(PORTDbits.RD6 == P)
                {
                    state = LED1W;
                }
                else if(PORTDbits.RD6 == R && transfer == 1)
                {
                    state = LED3;
                }
                else if(PORTDbits.RD6 == R && transfer == 0)
                {
                    state = LED2;
                }
                break;
            case LED2W:
                turnOnLED(2);
                if(PORTDbits.RD6 == P)
                {
                    state = LED2W;
                }
                else if(PORTDbits.RD6 == R && transfer == 1)
                {
                    state = LED1;
                }
                else if(PORTDbits.RD6 == R && transfer == 0)
                {
                    state = LED3;
                }
                break;
            case LED3W:
                turnOnLED(3);
                if(PORTDbits.RD6 == P)
                {
                    state = LED3W;
                }
                else if(PORTDbits.RD6 == R && transfer == 0)
                {
                    state = LED1;
                }
                else if(PORTDbits.RD6 == R && transfer == 1)
                {
                    state = LED2;
                }
                break;
        }
                
        

        //TODO: Implement a state machine to create the desired functionality
        
    }
    
    return 0;

}
//TODO: Add interrupt service routines that manage the change of states
//for particular events as needed
void __ISR(_TIMER_1_VECTOR, IPL3SRS)_T1Interrupt()
{
    IFS0bits.T1IF = 0;
    
    transfer = 1;
    /*if(LATDbits.LATD0 == 1) // led1 turn on
    {
        turnOnLED(2);
    }
    else if(LATDbits.LATD1 == 1)
    {
        turnOnLED(3);
    }
    else if(LATDbits.LATD2 == 1)
    {
        turnOnLED(1);
    }
    */
}

