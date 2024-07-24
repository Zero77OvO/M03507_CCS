#ifndef __PWM_H_
#define __PWM_H_

extern struct {
    float set_speed;//设定速度 
    float actual_speed;//实际速度
    float error;//偏差  
    float error_next;//上一个偏差  
    float error_last;//上上一个偏差 
    float kp,ki,kd;//定义比例，积分，微分参数  
     
}hor,ver;



void PWM_Init(void);
void PWM_work(void);
void Servo_start(void);

void Restart_move(void);
void Reset_move(void);
void Reset(void);

void Left(void);
void Right(void);
void Turn_left(void);
void Turn_right(void);

#endif



