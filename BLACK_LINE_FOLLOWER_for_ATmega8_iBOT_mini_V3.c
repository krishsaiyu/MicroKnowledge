

/* Program for "Black_LINE_FOLLOWER/Follows white path using 2 IR Sensors connected on PC0 and PC3" 
___________________________________________________________________________________________________ */

#include<avr/io.h>
#include<util/delay.h>

void main()
{
	DDRD=0b11111111;  // set PD4 as output bit
	DDRC=0b0000000;   // set PORTC as input port
	DDRB=0b00011110;  // PB1, PB2, PB3, PB4 as output port
    int ls=0, rs=0, a=1;   // define & initialize ls, rs integer as 0 to 
					       // acquire the left sensor status in ls and right sensor
					       // status in rs 
	
	while(1)          // create infinite loop
	{
	
	rs=(PINC&0b0000001);    // acquire only left sensor status connected at PC0
	ls=(PINC&0b0001000);    // acquire only right sensor status connected at PC3
	PORTD = ~PORTD;		
		
		if((rs==0b0000001)||(ls==0b0001000)) 
		{
		PORTD=(1<<4);
		}

		if((rs==0b0000000)&&(ls==0b0000000)) // check sensor status for both sensor OFF 
		{

			PORTB=0b00000000;
			_delay_ms(1000);  
			PORTB=0b00000000;
			_delay_ms(1000);     //turn left
			PORTD =(1<<4);

			ls=0;                 // set sensor status off
			rs=0; 				  // set sensor status off
			
		}

		if((rs==0b0000001)&(ls==0b0000000))  // check sensor status for left sensor=ON and
		                                     // right sensor=OFF
		{PORTB=0b00000000;
			_delay_ms(1000);  			
			PORTB=0b00010000;
			_delay_ms(1000);    // turn right
			PORTD =(1<<4);
			ls=0;                // set sensor status off
			rs=0; 				 // set sensor status off
				            
		}
	
	
		if((rs==0b0000000)&(ls==0b0001000))  //check sensor status for left sensor=OFF and
		                                     // right sensor=ON
		{
PORTB=0b00000000;
			_delay_ms(500);  			
					PORTB=0b00000010;
			_delay_ms(1000);     //turn left
			PORTD =(1<<4);
			ls=0;                 // set sensor status off
			rs=0; 				  // set sensor status off
			 
		}
	
		

        if((rs==0b0000001)&&(ls==0b0001000) ) // check sensor status for both sensor ON 
		{  
		     	PORTB=0b00010010;
		_delay_ms(100);
		PORTB=0b00000000;
		_delay_ms(100);
		       //move forward
			PORTD =~PORTD;     
			ls=0;               //set sensor status off
			rs=0;               //set sensor status off
	
		}
		
		
	}

}
