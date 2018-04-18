
/*To send message*/

#include"replay_message_header.h"

void motor_status_message(char *number, char *rply_message) 
{
  uart_string("AT+CMGF=1");   //by using AT+CMGF=1 command giving message possition
  delay(1000);

  USART_Transmit(0x0d);
  delay(1000);
  uart_string("AT+CMGS=");    //by using AT+CMGS="mobile no" sending message
  delay(1000);
  USART_Transmit('"');
  while (*number != '\0') 
  {
    USART_Transmit(*number++);
  }
  USART_Transmit('"');
  delay(1000);
  USART_Transmit(0x0d);
  delay(1000);

  while (*rply_message != '\0') 
  {
    USART_Transmit(*rply_message++);
  }
  delay(1000);
  USART_Transmit(0x1a);
  delay(2000);
  uart_string("AT+CMGD=1");
  delay(1000);
  USART_Transmit(0x0d);
  delay(2000);
}
