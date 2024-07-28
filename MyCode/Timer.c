#include "Timer.h"
#include "stdio.h"
#include "pid.h"
extern int yaw;
int delay_time=1;

int state=1;
////////////�������//////////
int car_open=0;     //ֱ�б�־

int car_turn_LF=0; //����ת��־
int car_turn_rt=0;

int target_speed=350; //Ŀ���ٶ�
int target_location=12000;

int speed_now_LF=0; //��ǰ�ٶ�        
int speed_now_rt=0; 

int speed_out_LF=0;  //�ٶȻ�����pid        
int speed_out_rt=0;  

int speed_flag_t=0; //�ٶȻ���������
int location_flag_t=4; //λ�û��������� ����ֱ����һ��

float KP_L=12.0;float KI_L=0.002;float KD_L=0; //�ٶȻ�PI����
float KP_R=12.0;float KI_R=0.002;float KD_R=0; //�ٶȻ�PI����

int location_L;//λ�û����
int location_R;

int stright_pid_out=0; //Ѳ��

IncrementalPID LF;
IncrementalPID RT;

////////////�������//////////


void Timer_A1_init(void)
{
	NVIC_EnableIRQ(TIMA1_INT_IRQn);
	DL_TimerA_startCounter(TIMA1);
}

void TIMA1_IRQHandler(void)
{	
    if(car_open==1){

        speed_flag_t++;
        location_flag_t++;

        if(target_location==12000){
        KP_L=12.0; KI_L=0.002; KD_L=0; 
        KP_R=12.0; KI_R=0.002; KD_R=0; 
        }

        IncrementalPID_init(&LF, KP_L, KI_L, KD_L);
        IncrementalPID_init(&RT, KP_R, KI_R, KD_R);

        DL_GPIO_togglePins(GPIOB, DL_GPIO_PIN_22);

        if(speed_flag_t>2){
        speed_now_LF=motor_speed_L();
        speed_now_rt=motor_speed_R();

        speed_out_LF=IncrementalPID_update(&LF,location_L, speed_now_LF);
        speed_out_rt=IncrementalPID_update(&RT,location_R, speed_now_rt);

        
        motor_set_L(speed_out_LF);    
        motor_set_R(speed_out_rt);
        speed_flag_t=0;
        
        }
        if(location_flag_t>4){

        if(target_location==12000){
        LocationPID_change(1,0.3,0.04,0.005);
        LocationPID_change(2,0.3,0.04,0.005);
        location_L=X_PID_X_value(12000,motor.speed_L); 
        location_R=Y_PID_X_value(12000,motor.speed_R); 


        }



        location_flag_t=0;
        }
        LocationPID_change(6,0.3,0.04,0.005);
        stright_pid_out=PID_straight_value(90, theta);

	}

    // if(car_turn_LR==1){




    // }
    

	
}
void Timer_A2_init(void)
{
	NVIC_EnableIRQ(TIMG0_INT_IRQn);
	DL_TimerG_startCounter(TIMG0);
}



void TIMG0_IRQHandler(void)
{		
	
	DL_GPIO_togglePins (GPIOB, DL_GPIO_PIN_27);



	if(state==1){

    Turn_left();

    }
	




}





// void Timer_A3_init(void)
// {
// 	NVIC_EnableIRQ(TIMG6_INT_IRQn);
// 	DL_TimerA_startCounter(TIMG6);
// }

// void TIMG6_IRQHandler(void)
// {
  
// 	delay_time--;
	
// 	if(delay_time<0){delay_time=0;}
	
// }