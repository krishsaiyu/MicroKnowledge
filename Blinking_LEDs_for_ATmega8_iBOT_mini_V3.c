/* Program for "BLINKING LED/Toggeling LEDs connected with PB1, PB2, PB3, PB4" 
______________________________________________________________________________

Connection settings of Kit

LEDs---@--------------------->PB1
LEDs---@--------------------->PB2
LEDs---@--------------------->PB3
LEDs---@--------------------->PB4
RIGHT MOTOR(+)--------------->PB1
RIGHT MOTOR(-)--------------->PB2
LEFT MOTOR(-)---------------->PB3
LEFT MOTOR(+)---------------->PB4
Buzzer----------------------->PD4
BOOTLooder Condition Check--->PC5(If 0 bootler section else program execution section of Flash memory)
RESET------------------------>PC6
Crystal Ossilator(12MHz)----->PB6 and PB7(hence PB6 & PB7 are not available for user)
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/

#define F_CPU 120000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"robosapiens.c"
int main(void)
{

DDRD=0b11111111;  // set PD4 as output bit
DDRB=0b00011110;  // PB1,PB2,PB3 and PB4 of PORTB are set as output.  
while(1)         // infinite while loop
    {
	PORTD = ~PORTD;

    PORTB=0b00011110;  //PB1,PB2,PB3 and PB4 Led's are set ON 
    wait(.5);         // wait function defined in robosapiens.c file function argument: time in seconds
    
	PORTD =(1<<4);
	PORTB=0b00000000; // PB1,PB2,PB3 and PB4 Led's are set OFF  
    wait(.5);		  // wait function defined in robosapiens.c file function argument: time in seconds
	}

}



