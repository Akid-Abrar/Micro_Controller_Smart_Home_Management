/*
 * GccApplication1.c
 *
 * Created: 9/13/2019 8:54:39 PM
 * Author : ASUS
 */


#define F_CPU  1000000UL

#include <avr/io.h>
#include <util/delay.h>

int isClear(unsigned char a, unsigned char b) {
	return !(a & (1 << b));
}

int main(void)
{
	//int flag1=0,flag2=0;
	//unsigned char c=0;


	// ----------------------------------------------------------

	MCUCSR |=(1 << JTD);
	MCUCSR |=(1 << JTD);
	int statecheck=0;
	DDRD=0x00;

	DDRB=0x00;
	PORTB=0xf0;

	DDRA=0xff;
	DDRC=0XFF;

    int counter=0;

	unsigned char upOn = 0, downOn = 0;
	unsigned char curState;

	while(1) {

		curState = PINB;
		PORTC = counter;

		if(isClear(curState, 0)) {
			if(downOn==1) {
				counter--;
				if(counter < 0) counter = 0;
				upOn = 0;
				downOn = 0;
			}
		}

		else if(isClear(curState, 1)) {
			upOn = 1;
			downOn = 1;
		}
		else if(isClear(curState, 2)) {
			if(upOn) {
				counter++;
				upOn = 0;
				downOn = 0;
			}
		}

		if(counter)
        {

            if(statecheck==1 && (PIND &(1<<0))==0)
            PORTA = 0X00;
            else if(statecheck==0 && (PIND &(1<<0))==0)
            PORTA = 0xff;
            else if((PIND &(1<<0))!=0)
            {
                PORTA = 0Xff;
                statecheck=1;
            }
        }
        else
        {
            PORTA = 0X00;
            statecheck=0;
        }

		_delay_ms(100);

		//if(PINB & (1<<0)) curState = 1;
		//else if(PINB & (1 << 3)) curState = 4;
		//else curState = prevState;
		//
		//if(curState != 0) PORTC=(1 << (curState-1));
		//else PORTC= 0x00;
		  //
		//// UpCount Logic
		//if(curState == 4 && prevState ==1) {
			//counter++;
			//prevState = 0;
		//}
		//else {
			//prevState = curState;
		//}
		//
		//if(counter > 0) {
			//PORTA = 0xff;
		//} else {
			//PORTA = 0x00;
		//}
		//
		//// DownCount Logic
		//if(curState == 1 && prevState ==4) {
			//counter--;
			//if(counter < 0) counter = 0;
			//prevState = 0;
		//}
		//else {
			//prevState = curState;
		//}
		//
		//if(counter > 0) {
			//PORTA = 0xff;
			//} else {
			//PORTA = 0x00;
		//}


	}


	// ---------------------------------------------------------
    //while (1)
  //{
//// 		PORTB=c;
//// 		if(c) c=0;
//// 		else c=1;
//// 		_delay_ms(1000);
//
		//
		//
 		//if((PINB & 0x02) != 0)
 		//{
			 //
			 ////counter++;
 			//flag1=1;
////  			PORTB |= 0b00000001;
 		//}
		 //if((PINB & 0x04) != 0 &&  flag1==1)
		 //{
			 //counter++;
			 //flag1=0;
			 //goto L1;
		 //}
 		//if((PINB & 0x04) != 0)
  		//{
  			//flag2=1;
 		//}
		 //if((PINB & 0x02) != 0 && flag2==1)
		 //{
			 //counter--;
			 //flag2=0;
			 //goto L1;
		 //}
 		//L1:
		 //{
 		//if(counter) PORTB |= 0b00000001;
 		//else PORTB &= 0b11111110;
		 //}
     //}
}
