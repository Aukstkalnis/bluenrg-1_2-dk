/**
  ******************************************************************************
  * @file    RTC/Clockwatch/BlueNRG1_it.c 
  * @author  RF Application Team
  * @version V1.0.0
  * @date    September-2015
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "BlueNRG1_it.h"
#include "SDK_EVAL_Config.h"

/** @addtogroup BlueNRG1_StdPeriph_Examples
  * @{
  */

/** @addtogroup RTC_Examples
  * @{
  */ 

/** @addtogroup RTC_Clockwatch
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
RTC_DateTimeType RTC_DateTime;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M0 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles SVCall exception.
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles PendSV_Handler exception.
  */
//void PendSV_Handler(void)
//{
//}

/**
  * @brief  This function handles SysTick Handler.
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 BlueNRG-1 Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (system_BlueNRG1.c).                                               */
/******************************************************************************/

/**
  * @brief  This function handles RTC interrupt request.
  * @param  None
  * @retval None
  */
void RTC_Handler(void)
{
  if(SET == RTC_IT_Status(RTC_IT_TIMER))
  {
    /* Clear pending interrupt flag */ 
    RTC_IT_Clear(RTC_IT_TIMER);
    
    SdkEvalLedToggle(LED1);
    
    /* Read present date and time information */
    RTC_GetTimeDate(&RTC_DateTime);
  }
  
  if(SET == RTC_IT_Status(RTC_IT_CLOCKWATCH ))
  {
    /* Clear pending interrupt flag */ 
    RTC_IT_Clear(RTC_IT_CLOCKWATCH);
    
    SdkEvalLedOn(LED2);
  }
}



/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2015 STMicroelectronics *****END OF FILE****/
