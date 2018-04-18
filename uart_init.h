

/*UART init header*/


void USART_Init(int ubrr);
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );
void uart_string(char *sp);
