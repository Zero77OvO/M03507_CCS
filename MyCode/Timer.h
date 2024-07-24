#ifndef __TIMER_H_
#define __TIMER_H_

#include "my_headfile.h"

void Timer_A1_init(void);
void Timer_A2_init(void);
void Timer_A3_init(void);

extern int state;
extern int car_open;  


extern int target_location;
extern int target_speed; //Ŀ���ٶ�

extern int speed_now_LF; //��ǰ�ٶ�        
extern int speed_now_rt; 

extern int speed_out_LF;  //�ٶȻ�����pid        
extern int speed_out_rt;  

extern int speed_flag_t; //�ٶȻ���������
extern int location_flag_t; //λ�û���������

extern float KP_L;extern float KI_L;extern float KD_L; //�ٶȻ�PI����
extern float KP_R;extern float KI_R;extern float KD_R; //�ٶȻ�PI����

int location_L;
int location_R;


#endif


