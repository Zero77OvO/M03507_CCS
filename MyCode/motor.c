#include "my_headfile.h"


int overflow_L=0;
int overflow_R=0;

        // DL_Timer_setCaptureCompareValue(PWM_0_INST,4524,GPIO_PWM_0_C0_IDX);
        // DL_Timer_setCaptureCompareValue(PWM_0_INST,4524,GPIO_PWM_0_C1_IDX);

        // DL_Timer_setCaptureCompareValue(PWM_1_INST,4524,GPIO_PWM_1_C0_IDX);
        // DL_Timer_setCaptureCompareValue(PWM_1_INST,4524,GPIO_PWM_1_C1_IDX);

        // DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_12);
	    // DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_24);
MOTOR motor;

int motor_speed_L(void)

{   motor.speed_L_last=motor.speed_L;

    motor.speed_L = encoder1_num;
    // motor.speed_L = encoder1_num+overflow_L*60000;
    
    motor.speed_L_OUT =  motor.speed_L-motor.speed_L_last;
    return motor.speed_L_OUT;
}

int motor_speed_R(void)

{   motor.speed_R_last=motor.speed_R;

    motor.speed_R = encoder2_num;
    //motor.speed_R = encoder2_num+overflow_R*60000;

    motor.speed_R_OUT = motor.speed_R-motor.speed_R_last;
    return motor.speed_R_OUT;
}

void motor_set_L(int pwm)
{      
    
    if (pwm > 6000)
        pwm = 6000;
    if (pwm < -6000)
           pwm = -6000;
    
    if (pwm > 0)
    {
        
        DL_TimerG_setCaptureCompareValue(PWM_0_INST,pwm,GPIO_PWM_0_C0_IDX);

        DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_24);
	    DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_12);


    }
    else
    {
        

        DL_TimerG_setCaptureCompareValue(PWM_0_INST,-pwm,GPIO_PWM_0_C0_IDX);
        DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_12);
	    DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_24);
    }
}

void motor_set_R(int pwm)
{      
    
       if (pwm > 6000)
           pwm =6000;
        if (pwm < -6000)
           pwm = -6000;
    
    if (pwm > 0)
    {

        DL_TimerG_setCaptureCompareValue(PWM_0_INST,pwm,GPIO_PWM_0_C1_IDX);
        DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_13);
        DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_16);   

    }
    else
    {
        DL_TimerG_setCaptureCompareValue(PWM_0_INST,-pwm,GPIO_PWM_0_C1_IDX);
     
        DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_16);
        DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_13);  

    }
}

// void motor_run()
// {
//     // stop
//     if (motor.flag_stop == 1)
//     {

//         DL_GPIO_clearPins(GPIOB, DL_GPIO_PIN_13);
//         DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_16);
//         DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_12);
//         DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_24);
//     }
//     // run
//     if (motor.flag_stop == 0)
//     {

//         DL_GPIO_setPins(GPIOB, DL_GPIO_PIN_13);
//         DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_16);
//         DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_12);
//         DL_GPIO_setPins(GPIOA, DL_GPIO_PIN_24);
//     }
// }
