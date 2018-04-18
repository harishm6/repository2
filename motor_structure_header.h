

/*structure header*/

typedef struct 
{
  char message[15];
  char mobile_number[15];
}mobile_no_message;

typedef struct com
{
  char *message_motor_on;
  char *message_motor_off;
  char *mobile_no;
}comparing;

typedef struct
{
  mobile_no_message user;
  comparing compare;
}main_structure;

extern main_structure motor; 



