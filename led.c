/* 
 * File:   led.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */

#include <xc.h>
#include "led.h"

void initLEDs(){
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    //TODO: Initialize LEDs
    /*LATDbits.LATD0 = 0;
    LATDbits.LATD1 = 0;
    LATDbits.LATD2 = 0;*/
    //off LED
}

void turnOnLED(int led){
    if(led == 1){
        LATDbits.LATD0 = 1;// led1 turn on
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 0;
    }
    
    else if(led == 2){
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 1;
        LATDbits.LATD2 = 0;
    }
    
    else{
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 1;
    }
    //TODO: You may choose to write this function
    // as a matter of convenience
    
}