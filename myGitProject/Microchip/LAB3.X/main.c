#include <stdio.h>

//Create a structure Typedef

typedef struct{
    unsigned char u8alarmTimeSeconds;
    unsigned char u8alarmTimeMinutes;
    unsigned char u8alarmTimeHours;
}STRUCT_ALARM_Type;


//Create array of pointers to point to 5 instances of STRUCT_ALARM_Type.  Also create 5 instances of the structure.
STRUCT_ALARM_Type STRUCT_alarmDescriptor[5];
STRUCT_ALARM_Type *p_STRUCT_alarmDescriptor[5] = {&STRUCT_alarmDescriptor[0], &STRUCT_alarmDescriptor[1], 
                    &STRUCT_alarmDescriptor[2], &STRUCT_alarmDescriptor[3], &STRUCT_alarmDescriptor[4]};

//Create a single pointer to show how a single pointer can also be used for access
STRUCT_ALARM_Type *p_STRUCT_singlePointer = &STRUCT_alarmDescriptor[0];


//Function prototype for passing single pointer
void load_alarm_data_using_pointer(STRUCT_ALARM_Type *p_structure, unsigned char seconds, 
                                    unsigned char minutes, unsigned char hours);

//Function prototype for passing array of pointers
void load_alarm_data_using_pointer_array(STRUCT_ALARM_Type *p_structure[ ], unsigned char seconds, 
                                    unsigned char minutes, unsigned char hours);


int main(int argc, char** argv) 
{
   unsigned char i;
      
   
   for(i = 0; i < 5; i++)
   {    
       
//Load values directly with the pointer       
       p_STRUCT_alarmDescriptor[i]->u8alarmTimeMinutes = 1;
       p_STRUCT_alarmDescriptor[i]->u8alarmTimeSeconds = 2;
       p_STRUCT_alarmDescriptor[i]->u8alarmTimeHours = 3;
 
      
//Pass the address to change the actual alarmDescriptor location      
       load_alarm_data_using_pointer(&STRUCT_alarmDescriptor[i], 4, 5, 6);
     
//Pass the address using the pointer      
       load_alarm_data_using_pointer(p_STRUCT_alarmDescriptor[i], 7, 8, 9);
          
//Set the structure values using a single pointer
       load_alarm_data_using_pointer(p_STRUCT_singlePointer, 0xA, 0xB, 0xC);
          
//Increment the single pointer
       p_STRUCT_singlePointer++;
   }
      
//Pass array of pointers to the function
   load_alarm_data_using_pointer_array(&p_STRUCT_alarmDescriptor[0], 77, 88, 99);
      
   
   while(1);
}


//Receive one pointer and act on that location
void load_alarm_data_using_pointer(STRUCT_ALARM_Type *p_structure, unsigned char seconds, 
                                    unsigned char minutes, unsigned char hours)
{
   p_structure->u8alarmTimeSeconds = seconds;
   p_structure->u8alarmTimeMinutes = minutes;
   p_structure->u8alarmTimeHours = hours;
}


//Receive the array of pointers address and load all five instances of the array
void load_alarm_data_using_pointer_array(STRUCT_ALARM_Type *p_structure[ ], unsigned char seconds, 
                                    unsigned char minutes, unsigned char hours)
{
   unsigned char j;
    
   for(j = 0; j < 5; j++)  
   {
       p_structure[j]->u8alarmTimeSeconds = seconds; 
       p_structure[j]->u8alarmTimeMinutes = minutes;
       p_structure[j]->u8alarmTimeHours = hours;        
   }
}

