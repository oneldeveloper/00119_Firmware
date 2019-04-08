/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC18F46K80
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SensA0 aliases
#define SensA0_TRIS                 TRISAbits.TRISA0
#define SensA0_LAT                  LATAbits.LATA0
#define SensA0_PORT                 PORTAbits.RA0
#define SensA0_ANS                  ANCON0bits.ANSEL0
#define SensA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SensA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SensA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SensA0_GetValue()           PORTAbits.RA0
#define SensA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SensA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SensA0_SetAnalogMode()      do { ANCON0bits.ANSEL0 = 1; } while(0)
#define SensA0_SetDigitalMode()     do { ANCON0bits.ANSEL0 = 0; } while(0)

// get/set SensA1 aliases
#define SensA1_TRIS                 TRISAbits.TRISA1
#define SensA1_LAT                  LATAbits.LATA1
#define SensA1_PORT                 PORTAbits.RA1
#define SensA1_ANS                  ANCON0bits.ANSEL1
#define SensA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define SensA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define SensA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define SensA1_GetValue()           PORTAbits.RA1
#define SensA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define SensA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define SensA1_SetAnalogMode()      do { ANCON0bits.ANSEL1 = 1; } while(0)
#define SensA1_SetDigitalMode()     do { ANCON0bits.ANSEL1 = 0; } while(0)

// get/set SensA2 aliases
#define SensA2_TRIS                 TRISAbits.TRISA2
#define SensA2_LAT                  LATAbits.LATA2
#define SensA2_PORT                 PORTAbits.RA2
#define SensA2_ANS                  ANCON0bits.ANSEL2
#define SensA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SensA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SensA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SensA2_GetValue()           PORTAbits.RA2
#define SensA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SensA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SensA2_SetAnalogMode()      do { ANCON0bits.ANSEL2 = 1; } while(0)
#define SensA2_SetDigitalMode()     do { ANCON0bits.ANSEL2 = 0; } while(0)

// get/set SensA3 aliases
#define SensA3_TRIS                 TRISAbits.TRISA3
#define SensA3_LAT                  LATAbits.LATA3
#define SensA3_PORT                 PORTAbits.RA3
#define SensA3_ANS                  ANCON0bits.ANSEL3
#define SensA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define SensA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define SensA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define SensA3_GetValue()           PORTAbits.RA3
#define SensA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define SensA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define SensA3_SetAnalogMode()      do { ANCON0bits.ANSEL3 = 1; } while(0)
#define SensA3_SetDigitalMode()     do { ANCON0bits.ANSEL3 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANCON1bits.ANSEL10 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANCON1bits.ANSEL10 = 0; } while(0)

// get/set CS aliases
#define CS_TRIS                 TRISCbits.TRISC2
#define CS_LAT                  LATCbits.LATC2
#define CS_PORT                 PORTCbits.RC2
#define CS_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define CS_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define CS_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define CS_GetValue()           PORTCbits.RC2
#define CS_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set SCK aliases
#define SCK_TRIS                 TRISCbits.TRISC3
#define SCK_LAT                  LATCbits.LATC3
#define SCK_PORT                 PORTCbits.RC3
#define SCK_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCK_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCK_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCK_GetValue()           PORTCbits.RC3
#define SCK_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set SDI aliases
#define SDI_TRIS                 TRISCbits.TRISC4
#define SDI_LAT                  LATCbits.LATC4
#define SDI_PORT                 PORTCbits.RC4
#define SDI_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDI_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDI_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDI_GetValue()           PORTCbits.RC4
#define SDI_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDI_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set SDO aliases
#define SDO_TRIS                 TRISCbits.TRISC5
#define SDO_LAT                  LATCbits.LATC5
#define SDO_PORT                 PORTCbits.RC5
#define SDO_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SDO_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SDO_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SDO_GetValue()           PORTCbits.RC5
#define SDO_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SDO_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set Led aliases
#define Led_TRIS                 TRISEbits.TRISE0
#define Led_LAT                  LATEbits.LATE0
#define Led_PORT                 PORTEbits.RE0
#define Led_ANS                  ANCON0bits.ANSEL5
#define Led_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define Led_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define Led_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define Led_GetValue()           PORTEbits.RE0
#define Led_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define Led_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define Led_SetAnalogMode()      do { ANCON0bits.ANSEL5 = 1; } while(0)
#define Led_SetDigitalMode()     do { ANCON0bits.ANSEL5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/