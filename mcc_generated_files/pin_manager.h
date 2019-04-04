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
        Device            :  PIC16LF15325
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

// get/set CS aliases
#define CS_TRIS                 TRISAbits.TRISA2
#define CS_LAT                  LATAbits.LATA2
#define CS_PORT                 PORTAbits.RA2
#define CS_WPU                  WPUAbits.WPUA2
#define CS_OD                   ODCONAbits.ODCA2
#define CS_ANS                  ANSELAbits.ANSA2
#define CS_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define CS_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define CS_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define CS_GetValue()           PORTAbits.RA2
#define CS_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define CS_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define CS_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define CS_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define CS_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define CS_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define CS_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SCK aliases
#define SCK_TRIS                 TRISCbits.TRISC0
#define SCK_LAT                  LATCbits.LATC0
#define SCK_PORT                 PORTCbits.RC0
#define SCK_WPU                  WPUCbits.WPUC0
#define SCK_OD                   ODCONCbits.ODCC0
#define SCK_ANS                  ANSELCbits.ANSC0
#define SCK_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SCK_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SCK_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SCK_GetValue()           PORTCbits.RC0
#define SCK_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SCK_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SCK_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SCK_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SCK_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SCK_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SCK_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SDI aliases
#define SDI_TRIS                 TRISCbits.TRISC1
#define SDI_LAT                  LATCbits.LATC1
#define SDI_PORT                 PORTCbits.RC1
#define SDI_WPU                  WPUCbits.WPUC1
#define SDI_OD                   ODCONCbits.ODCC1
#define SDI_ANS                  ANSELCbits.ANSC1
#define SDI_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SDI_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SDI_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SDI_GetValue()           PORTCbits.RC1
#define SDI_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SDI_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SDI_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SDI_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SDI_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SDI_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SDI_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SDI_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SDO aliases
#define SDO_TRIS                 TRISCbits.TRISC2
#define SDO_LAT                  LATCbits.LATC2
#define SDO_PORT                 PORTCbits.RC2
#define SDO_WPU                  WPUCbits.WPUC2
#define SDO_OD                   ODCONCbits.ODCC2
#define SDO_ANS                  ANSELCbits.ANSC2
#define SDO_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SDO_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SDO_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SDO_GetValue()           PORTCbits.RC2
#define SDO_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SDO_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SDO_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SDO_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SDO_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SDO_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SDO_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SDO_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

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