/* 
 * File:   timer.c
 * Author: Xiongjian Lin
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>
#include "timer.h"
void initTimer1(){
    TMR1 = 0;
    PR1 = 39061; //1sec
    T1CONbits.TCKPS = 3;//256
    T1CONbits.TCS = 0;
    IEC0bits.T1IE = 1;
    IFS0bits.T1IF = 0;
    IPC1bits.T1IS = 3;
    IPC1bits.T1IP = 3;
    T1CONbits.TON = 1;
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
}