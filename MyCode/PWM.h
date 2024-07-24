#ifndef __PWM_H_
#define __PWM_H_

extern struct {
    float set_speed;//�趨�ٶ� 
    float actual_speed;//ʵ���ٶ�
    float error;//ƫ��  
    float error_next;//��һ��ƫ��  
    float error_last;//����һ��ƫ�� 
    float kp,ki,kd;//������������֣�΢�ֲ���  
     
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



