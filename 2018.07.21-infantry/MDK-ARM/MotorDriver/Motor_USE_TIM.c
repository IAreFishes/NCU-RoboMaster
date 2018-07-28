/**
  ******************************************************************************
  * @file           : Motor_USE_TIM.c
  * @brief          : �����ģ����ʹ��TIM���п��Ƶĵ��
  ******************************************************************************
  *ʹ��TIM���Ƶĵ����Ħ���ֵ��
	*				 	��Ӧ�ͺţ� 
  *�ӿں�����
	*					Friction_Wheel_Motor(uint32_t wheelone,uint32_t wheeltwo)
	*					Friction_Wheel_Motor_Stop(void)
	*					
  ******************************************************************************
  */
#include "Motor_USE_TIM.h"


void TIM5_PWM_Init(uint32_t speed1,uint32_t speed2)
{
	  TIM5->CCR1=speed1;
	  TIM5->CCR2=speed2;
}

/**
	**************************************************************
	** Descriptions: Ħ���ֵ����ʼ������
	** Input:  NULL	
	** Output: NULL
	**************************************************************
**/
void GUN_Init(void)
{
		__HAL_TIM_ENABLE(&htim5);
		HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_1);
		HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_2);
		TIM5_PWM_Init(200,200);
		HAL_Delay(3000);
		TIM5_PWM_Init(100,100);
		HAL_Delay(2000);
	  TIM5_PWM_Init(100,100);
		//
		TIM5_PWM_Init(lowspeed,lowspeed);

		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
}

/**
	**************************************************************
	** Descriptions: Ħ���ֵ����������
	** Input: 	
	**	����ת��:
	**					wheelone
	**					wheeltwo
	** Output: NULL
	**************************************************************
**/

void Friction_Wheel_Motor(uint32_t wheelone,uint32_t wheeltwo)
{
	
	TIM5_PWM_Init(wheelone,wheeltwo);

}

void Friction_Wheel_Motor_Stop(void)
{
	
	htim5.Instance->CR1 &= ~(0x01);  //�رն�ʱ��
		
}
