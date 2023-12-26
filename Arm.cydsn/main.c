/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

typedef enum {
    BASE,
    SHOULDER,
    ELBOW,
    WRIST,
    GRIPPER
} ArmPart;


void nullify() {
    Base_1_Write(0);
    Base_2_Write(0);
    Shoulder_Up_Write(0);
    Shoulder_Down_Write(0);
    Elbow_Up_Write(0);
    Elbow_Down_Write(0);
    Wrist_Up_Write(0);
    Wrist_Down_Write(0);
    Gripper_In_Write(0);
    Gripper_Out_Write(0);
}
void activateMotor(ArmPart a, int direction) {
    nullify();
    switch(a) {
        case WRIST:
            if(direction == 0) {
                Wrist_Up_Write(0);
                Wrist_Down_Write(1);
            }
            else {
                Wrist_Up_Write(1);
                Wrist_Down_Write(0);
            }
            break;
        case ELBOW:
            break;
        case SHOULDER:
            break;
        case BASE:
            break;
        case GRIPPER:
            break;
    }
}
int main(void)
{
    CyGlobalIntEnable;
    UART_Start();
    UART_UartPutString("UART Started");
    
    char ch = ' ';
    
    for(;;)
    {
        ch = UART_UartGetChar();
        UART_UartPutChar(ch);
        if(ch == ' ')
            continue;
        switch(ch) {
            case 'w':
            case 'W':
                // activateMotor(ELBOW, 1);
                Elbow_Up_Write(1);
                Elbow_Down_Write(0);
                CyDelay(50);
                break;
            case 'q':
            case 'Q':
                Shoulder_Up_Write(1);
                Shoulder_Down_Write(0);
                CyDelay(50);
                break;
            case 'e':
            case 'E':
                Shoulder_Down_Write(1);
                Shoulder_Up_Write(0);
                CyDelay(50);
                break;
            case 's':
            case 'S':
                Elbow_Down_Write(1);
                Elbow_Up_Write(0);
                CyDelay(50);
                break;
            case 'a':
            case 'A':
                Base_1_Write(0);
                Base_2_Write(1);
                CyDelay(50);
                break;
            case 'd':
            case'D':
                Base_1_Write(1);
                Base_2_Write(0);
                CyDelay(50);
                break;
            case 'i':
            case 'I':
                Wrist_Up_Write(1);
                Wrist_Down_Write(0);
                CyDelay(50);
                break;
            case 'k':
            case 'K':
                Wrist_Down_Write(1);
                Wrist_Up_Write(0);
                CyDelay(50);
                break;
            case 'j':
            case 'J':
                Gripper_In_Write(1);
                Gripper_Out_Write(0);
                CyDelay(50);
                break;
            case 'l':
            case 'L':
                Gripper_Out_Write(1);
                Gripper_In_Write(0);
                CyDelay(50);
                break;
            default:
                nullify();
                break;
        }
        //Gripper_In_Write(0);
        //Gripper_Out_Write(0);
    }
 
}

/* [] END OF FILE */
