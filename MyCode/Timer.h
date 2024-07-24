#ifndef __TIMER_H_
#define __TIMER_H_

#include "my_headfile.h"

void Timer_A1_init(void);
void Timer_A2_init(void);
void Timer_A3_init(void);

extern int state;
extern int car_open;  


extern int target_location;
extern int target_speed; //目标速度

extern int speed_now_LF; //当前速度        
extern int speed_now_rt; 

extern int speed_out_LF;  //速度环运算pid        
extern int speed_out_rt;  

extern int speed_flag_t; //速度环控制周期
extern int location_flag_t; //位置环控制周期

extern float KP_L;extern float KI_L;extern float KD_L; //速度环PI参数
extern float KP_R;extern float KI_R;extern float KD_R; //速度环PI参数

int location_L;
int location_R;


#endif


