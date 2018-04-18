

/*read_message cpp   get test*/

#include<Arduino.h>
#include"read_message.h"
#include"uart_init.h"
#include"motor_structure_header.h"
#include"replay_message_header.h"

int mobile_no,messge;
char motor_on[5]="ON";
char motor_off[5]="OFF";
char mobile_number[15]="9010957329";

main_structure motor;

void str_cmp()
{
  motor.compare.message_motor_on=&motor_on[0];
  motor.compare.message_motor_off=&motor_off[0];
  motor.compare.mobile_no=&mobile_number[0];
}

void read_message()
{
 uart_string("REPEAT");
  while (USART_Receive() != '+');
  while (USART_Receive() != 'C');
  while (USART_Receive() != 'M');
  while (USART_Receive() != 'T');
  while (USART_Receive() != 'I');  
  while (USART_Receive() != ':');

  uart_string("AT+CMGR=1");
  delay(500);
  USART_Transmit(0x0d);

  while (USART_Receive() != '+');
  while (USART_Receive() != 'C');
  while (USART_Receive() != 'M');
  while (USART_Receive() != 'G');
  while (USART_Receive() != 'R');  
  while (USART_Receive() != ':');
  while (USART_Receive() != '+');
  while (USART_Receive() != '9');  
  while (USART_Receive() != '1');

  while((motor.user.mobile_number[mobile_no++]=USART_Receive())!='"'); 
  mobile_no--;
  motor.user.mobile_number[mobile_no]='\0';
  while (USART_Receive() != 0x0A);
  while (USART_Receive() != '@');
  while((motor.user.message[messge++]=USART_Receive())!='#'); 

  messge--;
  motor.user.message[messge]='\0';
uart_string("REPEAT PASS");
  
  compare_message_mobile_no(motor.user.mobile_number, motor.user.message);
}

void compare_message_mobile_no(char *m_number, char *mssge_info)
{

  if((!strcmp(m_number, motor.compare.mobile_no))&&(!strcmp(mssge_info, motor.compare.message_motor_on)))
  {
    MOTOR_ON;
    motor_status_message(m_number,"MOTOR_ON");
  }
  else if((!strcmp(m_number, motor.compare.mobile_no))&&(!strcmp(mssge_info, motor.compare.message_motor_off)))
  {
   MOTOR_OFF;
    motor_status_message(m_number,"MOTOR_OFF");
  }

 delay(1000);
  mobile_no=0;
  messge=0;
  uart_string("AT+CMGD=1");
  delay(1000);
  USART_Transmit(0x0d);
  delay(1000);
}


