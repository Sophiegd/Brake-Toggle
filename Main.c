#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File

void delay_loop(void);

void main(void)
{
    InitSysCtrl();

    DINT;

    EALLOW;

 //   GpioCtrlRegs.GPAPUD.bit.GPIO10 = 0;  // Enable pullup on GPIO10
    GpioDataRegs.GPASET.bit.GPIO10 = 1;  // Load output latch
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0; // GPIO10 = GPIO10
    GpioCtrlRegs.GPADIR.bit.GPIO10 = 1;  // GPIO10 = output


    EDIS;
    InitPieCtrl();

    IER = 0x0000;
    IFR = 0x0000;

    InitPieVectTable();

    GpioDataRegs.GPASET.bit.GPIO10 = 1;
    GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;


    //
    // Use TOGGLE registers to flip the state of the pins.
    // Any bit set to a 1 will flip state (toggle)
    // Any bit set to a 0 will not toggle.
    //
    for(;;)
    {
        GpioDataRegs.GPATOGGLE.bit.GPIO10 = 1;
        delay_loop();
    }

}

void
delay_loop()
{
    double i;
    for (i = 0; i < 400000; i++)
    {

    }
}
