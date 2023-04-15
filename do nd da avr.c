//Clock frequency     : 8.000000 MHz
#include <mega16.h>
// Khai bao giao tiep LCD
#asm
.equ __lcd_port=0x12 ;PORTC
#endasm
#define up    PINB.0
#define down    PINB.1

#define loa    PORTC.0
unsigned char cd=50;
#include <string.h>  
#include <stdio.h>
#include <lcd.h>  
#include <delay.h>
#define ADC_VREF_TYPE 0x00
//khai bao bien
int temp,adc; 
// Ham doc nhiet do
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input|ADC_VREF_TYPE;
// bat dau doc
ADCSRA|=0x40;
// cho doc xong
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCW;
}
void main(void)
{
PORTA=0x00;
DDRA=0xF0;
PORTB=0x00;
DDRB=0xF0;
PORTC=0x00;
DDRC=0xFF;
PORTD=0x00;
DDRD=0xFF;
// khoi tao ADC
ADMUX=ADC_VREF_TYPE;
ADCSRA=0x83;
// cho phap ngat
#asm("sei")
loa=1;
lcd_init(16);
lcd_gotoxy(0,0);
lcd_putsf("Do Nhiet Do LCD ");
lcd_gotoxy(0,1);
lcd_putsf("Bao Nhiet Do Cao");
delay_ms(1000);
while (1)
      { 
       lcd_gotoxy(0,0); lcd_putsf("Muc cai dat: ");  
       lcd_putchar(cd/10+0x30); lcd_putchar(cd%10+0x30);lcd_putsf("C ");
      adc = read_adc(PORTA.0);
      temp = adc/2.046;  
      lcd_gotoxy(0,1); lcd_putsf("Nhiet do: "); 
      lcd_putchar(temp/10+0x30); lcd_putchar(temp%10+0x30); lcd_putsf(" C  "); 
         if(temp>cd) loa = 0; if(temp<cd) loa = 1;
         if(up==0) { while(up==0){}  if(cd<99) cd++; }
         if(down==0) { while(down==0){}  if(cd>0) cd--; }
      };
}
