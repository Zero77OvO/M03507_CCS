#include "my_headfile.h"


int flr1=0;
int flr1_choice=0;
int flr1_topic=0;

void main_menu(void){

if(flr1==1){





    if(DL_GPIO_readPins(GPIOA, DL_GPIO_PIN_18) == DL_GPIO_PIN_18){
    flr1_choice+=16;
    }
    if(DL_GPIO_readPins(GPIOB, DL_GPIO_PIN_21) == 0){
    flr1_choice-=16;
    }

    if(flr1_choice>64){flr1_choice=0;}
    if(flr1_choice<0){flr1_choice=64;}

    switch (flr1_choice)
    {
        case 0 : OLED_ShowChar(100,0,28,16,0);break;
        case 16: OLED_ShowChar(100,2,28,16,0);break;
        case 32: OLED_ShowChar(100,4,28,16,0);break;
        case 48: OLED_ShowChar(100,6,28,16,0);break;
        default:
        break;
    }


    // if(KEY()==3){
    //     switch (flr1_choice)
    //     {
    //         case 0 : flr1_topic=1;flr1=2;break;
    //         case 16: flr1_topic=2;flr1=2;break;
    //         case 32: flr1_topic=3;flr1=2;break;
    //         case 48: flr1_topic=4;flr1=2;break;
    //         case 64: flr1_topic=5;flr1=2;break;
    //         default:
    //         break;
    //     }
    // }

}

// if(flr1==2){

// if(flr1_topic==1){
//     LCD_ShowIntNum(10, 0, 1, 1, RED, BLACK, 16);
// }
// if(flr1_topic==2){
//     LCD_ShowIntNum(10, 0, 2, 1, RED, BLACK, 16);
// }
// if(flr1_topic==3){
//     LCD_ShowIntNum(10, 0, 3, 1, RED, BLACK, 16);
// }
// if(flr1_topic==4){
//     LCD_ShowIntNum(10, 0, 4, 1, RED, BLACK, 16);
// }
// if(flr1_topic==5){
//     LCD_ShowIntNum(10, 0, 5, 1, RED, BLACK, 16);
// }

// }




}

