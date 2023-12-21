/**
  ******************************************************************************
  * @file    STemWin/STemWin_HelloWorld/Src/stm32f7xx_it.c
  * @author  MCD Application Team
  * @brief   Main Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "main.h"
//#include "../../../USB_HOST/Target/usbh_conf.h"
#include "../Includes/stm32f7xx_it.h"
//#include "stm32f7xx_hal_hcd.h"
#include "GUI.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern volatile GUI_TIMER_TIME OS_TimeMS;
extern TIM_HandleTypeDef TimHandle;
extern HCD_HandleTypeDef hhcd_USB_OTG_FS;
extern HCD_HandleTypeDef hhcd_USB_OTG_HS;
extern TIM_HandleTypeDef htim1;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M7 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  printf("HARDFAULT ERROR\r\n");
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  printf("MEMORY ERROR\r\n");
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  /* Update the LocalTime by adding 1 ms each SysTick interrupt */
  HAL_IncTick();

  OS_TimeMS++;
}

/******************************************************************************/
/*                 STM32F7xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f7xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @brief  This function handles TIM interrupt request.
  * @param  None
  * @retval None
  */
void TIM3_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&TimHandle);
}



void TIM1_UP_TIM10_IRQHandler(void)
{
/* USER CODE BEGIN TIM1_UP_TIM10_IRQn 0 */

/* USER CODE END TIM1_UP_TIM10_IRQn 0 */
HAL_TIM_IRQHandler(&htim1);
/* USER CODE BEGIN TIM1_UP_TIM10_IRQn 1 */

/* USER CODE END TIM1_UP_TIM10_IRQn 1 */
}

/**
* @brief This function handles USB On The Go FS global interrupt.
*/
void OTG_FS_IRQHandler(void)
{
/* USER CODE BEGIN OTG_FS_IRQn 0 */

/* USER CODE END OTG_FS_IRQn 0 */
//HAL_HCD_IRQHandler(&hhcd_USB_OTG_FS);
/* USER CODE BEGIN OTG_FS_IRQn 1 */

/* USER CODE END OTG_FS_IRQn 1 */
}

/**
* @brief This function handles USB On The Go HS global interrupt.
*/
void OTG_HS_IRQHandler(void)
{
/* USER CODE BEGIN OTG_HS_IRQn 0 */

/* USER CODE END OTG_HS_IRQn 0 */
//HAL_HCD_IRQHandler(&hhcd_USB_OTG_HS);
/* USER CODE BEGIN OTG_HS_IRQn 1 */

/* USER CODE END OTG_HS_IRQn 1 */
}
