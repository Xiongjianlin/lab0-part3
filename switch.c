
 #include <xc.h>

void initSwitch()
{
    TRISDbits.TRISD6 = 1;//set switch to input
    CNCONDbits.ON = 1;//ENABLE INTERRUPT
    CNENDbits.CNIED6 = 1;//enable interrupt of switch
    IEC1bits.CNDIE = 1;//enable interrupt
    IFS1bits.CNDIF = 0;//put flag down  
    CNPUDbits.CNPUD6 = 1;//ENABLE RESISTOR
}