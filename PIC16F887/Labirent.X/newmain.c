
// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 4000000
/* ------------- NOTLAR ------------------------
Motorun biri interrup_RB ile yapýlabilir
CCPR1L =  x_motor;    ve  CCPR2L =  y_motor; kodlarý döngü dýþýnda main fonksuyonu içinde
PWM modulunu while içinde  tekrar aktifleþtirme

*/
#define x_up RB0
#define x_down RB1
#define y_up RB2
#define y_down RB3

const char max_deger = 150;
const char min_deger = 30;

unsigned char x_motor = 90; //Aç?sal de?er de?i?keni //30-150 aras? //X servo kordinat
unsigned char y_motor = 90; //Aç?sal de?er de?i?keni //30-150 aras? //Y servo kordinat

void main(void) {
 TRISC = (1<<3)|(1<<4) ;   //   configure RC3 as input (1 for input and 0 for output)

  PR2 =  0xFA;                 //oxFA for 250  (used to set time period)
  T2CON |= (1<<2)|(1<<1);              // enabling timer 2, prescalar 16
  
  CCPR1L =  x_motor;               // (used to set duty cycle) //X servo seçimi
  CCP1CON |= (1<<2)|(1<<3);            //  select for PWM mode
  CCPR2L =  y_motor;               // (used to set duty cycle) //Y servo seçimi
  CCP2CON |= (1<<2)|(1<<3);            //  select for PWM mode
 
  ANSELH = 0b00000000;//0 dijital giri? 1 analog giri//PORTB deki analog dijital seçim
  
  TRISB = 0b00001111; //RB0-RB1 ara dijital giri? seçimi
  PORTB = 0x00;//B portlar? low a çekme
  
  __delay_ms(1000); 
  while(1)
  {
 //Belirli aç?da tutmak için 
    if (x_motor > max_deger || y_motor > max_deger) { x_motor = max_deger; y_motor = max_deger;}
    else if (x_motor < min_deger | y_motor < min_deger){ x_motor = min_deger; y_motor = min_deger; } 
    
    //X kordinat motoru kontrolü
    if (x_up == 1 || x_down == 1)
    {
        while (x_up == 1 && x_motor < 150)
        {
        CCPR1L =  x_motor;               // (used to set duty cycle)
        x_motor++;
        __delay_ms(30);
        }
    
        while (x_down == 1 && x_motor > 30)
        {
            CCPR1L =  x_motor;               // (used to set duty cycle)
             x_motor--;
            __delay_ms(30);
        }         
      }
    
    //Y kordinat motoru kontrolü
    if (y_up == 1 || y_down == 1)
    {
        while (y_up == 1 && y_motor < 150)
        {
        CCPR2L =  y_motor;               // (used to set duty cycle)
        y_motor++;
        __delay_ms(30);
        }
    
        while (y_down == 1 && y_motor > 30)
        {
            CCPR2L =  y_motor;               // (used to set duty cycle)
             y_motor--;
            __delay_ms(30);
        }         
     }

    __delay_ms(50);
            
  }
}

/*
      for(a = 30; a <= 150; a++)                        // forward
       {
        CCPR1L =  a;               // (used to set duty cycle)
        T2CON |= (1<<2)|(1<<1);
        __delay_ms(100);     
       }     
     __delay_ms(800); 
    for(a = 30; a <= 150; a++)                        // forward
       {
        CCPR2L =  a;               // (used to set duty cycle)
        T2CON |= (1<<2)|(1<<1);
        __delay_ms(100);     
       }
      
    __delay_ms(100);
 */

    /*
     ////////////////////    ESK? KOD    \\\\\\\\\\\\\\\\\\\\ 
     for(a = 30; a <= 150; a++)                        // forward
       {
        CCPR1L =  a;               // (used to set duty cycle)
        T2CON |= (1<<2)|(1<<1);
        __delay_ms(100);     
       }     
     __delay_ms(800); 
    for(a = 30; a <= 150; a++)                        // forward
       {
        CCPR2L =  a;               // (used to set duty cycle)
        T2CON |= (1<<2)|(1<<1);
        __delay_ms(100);     
       }
     */