
#define F_CPU  8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "USART_RS232_H_file.h"		/* include USART library */

#define LED PORTB
#define LED1 PORTC					/* connected LED on PORT pin */

int main(void)
{
    char Data_in;
    DDRB = 0xff;
    DDRC = 0xff;
    PORTA = 0x00;
    DDRA  = 0x01;						/* make PORT as output port */
    USART_Init(9600);						/* initialize USART with 9600 baud rate */
    LED = 0;
    LED1=0;
    unsigned char c=0,d=0,e=0,c1=0,d1=0,e1=0;


    while(1)
    {
        Data_in = USART_RxChar();						/* receive data from Bluetooth device*/
        if(Data_in =='1')
        {
            if(c==0)
            {
                LED |= (1<<PB0);							/* Turn ON LED */
                //USART_SendString("LED_ON");
                c=1;
            }
            else
            {
                LED &= ~(1<<PB0);							/* Turn OFF LED */
                //USART_SendString("LED_OFF");
                c=0;
            }
            /* send status of LED i.e. LED ON */

        }
        else if(Data_in =='2')
        {
            if(e==0)
            {
                LED |= (1<<PB1);							/* Turn ON LED */
                //USART_SendString("LED_ON");
                e=1;
            }
            else
            {
                LED &= ~(1<<PB1);							/* Turn OFF LED */
                //USART_SendString("LED_OFF");
                e=0;
            }				/* send status of LED i.e. LED OFF */
        }
        else if(Data_in =='3')
        {
            if(d==0)
            {
                LED |= (1<<PB2);							/* Turn ON LED */
                //USART_SendString("LED_ON");
                d=1;
            }
            else
            {
                LED &= ~(1<<PB2);							/* Turn OFF LED */
                //USART_SendString("LED_OFF");
                d=0;
            }				/* send status of LED i.e. LED ON */

        }
        else if(Data_in =='4')
        {
            if(c1==0)
            {
                LED1 |= (1<<PC0);							/* Turn ON LED */
                //USART_SendString("LED_ON");
                c1=1;
            }
            else
            {
                LED1 &= ~(1<<PC0);							/* Turn OFF LED */
                //USART_SendString("LED_OFF");
                c1=0;
            }				/* send status of LED i.e. LED OFF */
        }
        else if(Data_in =='5')
        {
            if(d1==0)
            {
                LED1 |= (1<<PC1);							/* Turn ON LED */
                //USART_SendString("LED_ON");
                d1=1;
            }
            else
            {
                LED1 &= ~(1<<PC1);							/* Turn OFF LED */
                //USART_SendString("LED_OFF");
                d1=0;
            }				/* send status of LED i.e. LED OFF */
        }
        else if(Data_in =='6')
        {
            if(e1==0)
            {
                LED1 |= (1<<PC6);							/* Turn ON LED */
                //USART_SendString("LED_ON");
                e1=1;
            }
            else
            {
                LED1 &= ~(1<<PC6);							/* Turn OFF LED */
                //USART_SendString("LED_OFF");
                e1=0;
            }				/* send status of LED i.e. LED OFF */
        }
        //

        //        else
        //            USART_SendString("Select proper option");	/* send message for selecting proper option */
        //        //LED = 1 - LED;
        //        //_delay_ms(1000);
        //
        //        //int a=PINC+2;
        //        //if(PINC | 0x00)    // read PINB.1
        //        //PORTC |= 0b00000001;
        //        //PORTC &= 0b11111110;   // set PORTB.0
        //        //else
        //        //PORTC &= 0b11111110;
        //        //PORTC |= 0b00000001;
        //
        //        ADCSRA |= (1 << ADSC);
        //        while(ADCSRA & (1 << ADSC))
        //        {
        //        }
        //
        //        uint16_t res = 0;
        //        res = ADCL;
        //        uint16_t temp;
        //        temp = ADCH;
        //        temp = (temp << 8);
        //        res |= temp;
        //
        //
        //
        //        double final_result = 1.0 * res / 256 ;
        //        int final_int = (int)(final_result * 100);

// 							if ((PINA & 0x02) != 0)
// 							{
// 								PORTA |= 0b00000001;
// 							}
// 							else
// 							PORTA &= 0b11111110;

    }
    return 0;
}
