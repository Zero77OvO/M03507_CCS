#include "PWM.h"
#include "pid.h"
#include <stdlib.h>
#include "my_headfile.h"



//4470 4570 LD

//4524,4640 mid

//4584580 4690 RU


int counter_flag=0;//初始化一次清零 标志位
int veer_flag=0; //正在转向标志位


void PWM_work(void)
{ 

	DL_Timer_setCaptureCompareValue(PWM_0_INST,4524,GPIO_PWM_0_C0_IDX);//4000-4800 4400中间 减小向左
	DL_Timer_setCaptureCompareValue(PWM_0_INST,4640,GPIO_PWM_0_C1_IDX); // 4000-5000  4800立起来
		delay_ms(10);
}

void Servo_reset(){
	
	DL_Timer_setCaptureCompareValue(PWM_0_INST,4500,GPIO_PWM_0_C0_IDX);//4000-5000 4400中间 减小向左
	DL_Timer_setCaptureCompareValue(PWM_0_INST,4640,GPIO_PWM_0_C1_IDX); // 4000-5000  4800立起来
	
}



 void Forward(int location){


    target_location=location;

    if(target_location-encoder1_num<200||target_location-encoder2_num<200){
    car_open=0;
    Restart_move();
    encoder1_num=10000;   
    encoder2_num=10000;
    delay_ms(50);
    Reset_move();
    if(state==1){
        state=2;//状态切换}
    }

 }
 }

void Turn_left(){
    if(counter_flag==0){
    Reset();
    veer_flag=1;
    encoder1_num=10000;
    encoder2_num=10000;
    counter_flag=1;
    }
    //right_counter<=10450&&right_counter>=10000 (12000-left_counter)+(12000-right_counter)>=1600
    if(10000-encoder1_num>=180&&counter_flag==1){
        Restart_move();
        encoder1_num=10000;   
        encoder2_num=10000;
        delay_ms(50);
        Reset_move();
        counter_flag=0;
        veer_flag=11; 
        if(state==1){Reset();state=2;}
    
    }
    else{if(veer_flag==1){Left();veer_flag=1;}}


}

void Turn_right(){

	if(counter_flag==0){
	Reset();
	veer_flag=1;
    encoder1_num=10000;
    encoder2_num=10000;
	counter_flag=1;
	}
	
  	if(10000-encoder2_num>=180&&counter_flag==1){
        Restart_move();
        encoder1_num=10000;   
        encoder2_num=10000;
        delay_ms(50);
        Reset_move();
        counter_flag=0;
        veer_flag=11; 
    
    if(state==1){Reset();state=2;}

    }

	else{if(veer_flag==1){Right();veer_flag=1;}}

    
}



void Reset(){
    encoder1_num=10000;   
    encoder2_num=10000;
    Reset_move();
    counter_flag=0;
    veer_flag=0;
}

void Left(){

DL_TimerG_setCaptureCompareValue(PWM_0_INST,2000,GPIO_PWM_0_C0_IDX);
DL_TimerG_setCaptureCompareValue(PWM_0_INST,2000,GPIO_PWM_0_C1_IDX);
DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_12);//左倒转
DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_13);//右正转
}
void Right(){
DL_TimerG_setCaptureCompareValue(PWM_0_INST,2000,GPIO_PWM_0_C0_IDX);
DL_TimerG_setCaptureCompareValue(PWM_0_INST,2000,GPIO_PWM_0_C1_IDX);
DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_24); //左正转
DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_16);//右倒转
}



//
void Restart_move()
{
    DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_24);
    DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_12);
    DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_13);
    DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_16);

}
void Reset_move()
{
    DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_24);
    DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_12);
    DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_13);
    DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_16);

}