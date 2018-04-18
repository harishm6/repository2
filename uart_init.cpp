
//uart init cpp file
#include<Arduino.h>

void USART_Init(int ubrr)
{
/*Set baud rate */
UBRR0H =(ubrr>>8);
UBRR0L =ubrr;
//Enable receiver and transmitter */
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
/* Set frame format: 8data, 2stop bit */
UCSR0C = (0<<USBS0)|(3<<UCSZ00);
}

void USART_Transmit( unsigned char data )
{
/* Wait for empty transmit buffer */
while (!( UCSR0A & (1<<UDRE0)));
/* Put data into buffer, sends the data */
UDR0 = data; 
}

unsigned char USART_Receive( void )
{
  
/* Wait for data to be received */
while ( !(UCSR0A & (1<<RXC0)) );
/* Get and return received data from buffer */
return UDR0;
}

void uart_string(char *sp)
{
  while(*sp!='\0')
  {
    USART_Transmit(*sp);
    sp++;
  }
}
