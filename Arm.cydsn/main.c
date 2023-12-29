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
    GRIPPER,
    LIGHT
} ArmPart;


void nullify() {
    Base_Left_Write(0);
    Base_Right_Write(0);
    Shoulder_Up_Write(0);
    Shoulder_Down_Write(0);
    Elbow_Up_Write(0);
    Elbow_Down_Write(0);
    Wrist_Up_Write(0);
    Wrist_Down_Write(0);
    Gripper_In_Write(0);
    Gripper_Out_Write(0);
}

// direction 0 - Up/Right/Forward
void activateMotor(ArmPart a, int direction) {
    nullify();
    switch(a) {
        case WRIST:
            Wrist_Up_Write(!direction);
            Wrist_Down_Write(direction);
            break;
        case ELBOW:
            Elbow_Up_Write(!direction);
            Elbow_Down_Write(direction);
            break;
        case SHOULDER:
            Shoulder_Up_Write(!direction);
            Shoulder_Down_Write(direction);
            break;
        case BASE:
            Base_Right_Write(!direction);
            Base_Left_Write(direction);
            break;
        case GRIPPER:
            Gripper_In_Write(!direction);
            Gripper_Out_Write(direction);
            break;
        case LIGHT:
            Light_Switch_Write(!Light_Switch_Read());
            break;
            
    }
}
int main(void)
{
    nullify();
    CyGlobalIntEnable;
    UART_Start();
    UART_UartPutString("UART Started");
    
    char command = ' ';
    
    for(;;)
    {
        command = UART_UartGetChar();
        UART_UartPutChar(command);
        if(command == ' ')
            continue;
        switch(command) {
            case 'w':
            case 'W':
                activateMotor(ELBOW, 0);
                CyDelay(50);
                break;
            case 's':
            case 'S':
                activateMotor(ELBOW, 1);
                CyDelay(50);
                break;
                
            case 'q':
            case 'Q':
                activateMotor(SHOULDER, 1);
                CyDelay(50);
                break;
            case 'e':
            case 'E':
                activateMotor(SHOULDER, 0);
                CyDelay(50);
                break;
            
            case 'a':
            case 'A':
                activateMotor(BASE, 0);
                CyDelay(50);
                break;
            case 'd':
            case'D':
                activateMotor(BASE, 1);
                CyDelay(50);
                break;
                
            case 'i':
            case 'I':
                activateMotor(WRIST, 1);
                CyDelay(50);
                break;
            case 'k':
            case 'K':
                activateMotor(WRIST, 0);
                CyDelay(50);
                break;
            case 'j':
            case 'J':
                activateMotor(GRIPPER, 1);
                CyDelay(50);
                break;
            case 'l':
            case 'L':
                activateMotor(GRIPPER, 0);
                CyDelay(50);
                break;
            case 'U':
            case 'u':
                activateMotor(LIGHT, 0);
                break;
            default:
                nullify();
                break;
        }
    }
    nullify();
}

/* [] END OF FILE */
