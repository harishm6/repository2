
#include"uart_init.h"
#include"read_message.h"
#include<Arduino.h>

void setup() 
{

  USART_Init(103);
  pinMode(4,OUTPUT);
  uart_string("AT+CMGF=1");
  USART_Transmit(0x0d);
  delay(1000);
  uart_string("AT+CMGD=1");
  USART_Transmit(0x0d);
  delay(1000);
  str_cmp();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
   read_message();
}
