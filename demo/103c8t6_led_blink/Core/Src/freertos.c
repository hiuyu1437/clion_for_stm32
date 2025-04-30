/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 64 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for LedBlinkWhite */
osThreadId_t LedBlinkWhiteHandle;
const osThreadAttr_t LedBlinkWhite_attributes = {
  .name = "LedBlinkWhite",
  .stack_size = 64 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for LedBlinkYellow */
osThreadId_t LedBlinkYellowHandle;
const osThreadAttr_t LedBlinkYellow_attributes = {
  .name = "LedBlinkYellow",
  .stack_size = 64 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for LedBlinkBlue */
osThreadId_t LedBlinkBlueHandle;
const osThreadAttr_t LedBlinkBlue_attributes = {
  .name = "LedBlinkBlue",
  .stack_size = 64 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for LedBlinkRed */
osThreadId_t LedBlinkRedHandle;
const osThreadAttr_t LedBlinkRed_attributes = {
  .name = "LedBlinkRed",
  .stack_size = 64 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for LedBlinkGreen */
osThreadId_t LedBlinkGreenHandle;
const osThreadAttr_t LedBlinkGreen_attributes = {
  .name = "LedBlinkGreen",
  .stack_size = 64 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
extern void vLedBlinkWhite(void *argument);
void vLedBlinkYellow(void *argument);
void vLedBlinkBlue(void *argument);
void vLedBlinkRed(void *argument);
void vLedBlinkGreen(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void configureTimerForRunTimeStats(void);
unsigned long getRunTimeCounterValue(void);

/* USER CODE BEGIN 1 */
/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
__weak void configureTimerForRunTimeStats(void)
{

}

__weak unsigned long getRunTimeCounterValue(void)
{
return 0;
}
/* USER CODE END 1 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of LedBlinkWhite */
  LedBlinkWhiteHandle = osThreadNew(vLedBlinkWhite, NULL, &LedBlinkWhite_attributes);

  /* creation of LedBlinkYellow */
  LedBlinkYellowHandle = osThreadNew(vLedBlinkYellow, NULL, &LedBlinkYellow_attributes);

  /* creation of LedBlinkBlue */
  LedBlinkBlueHandle = osThreadNew(vLedBlinkBlue, NULL, &LedBlinkBlue_attributes);

  /* creation of LedBlinkRed */
  LedBlinkRedHandle = osThreadNew(vLedBlinkRed, NULL, &LedBlinkRed_attributes);

  /* creation of LedBlinkGreen */
  LedBlinkGreenHandle = osThreadNew(vLedBlinkGreen, NULL, &LedBlinkGreen_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_vLedBlinkYellow */
/**
* @brief Function implementing the LedBlinkYellow thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_vLedBlinkYellow */
void vLedBlinkYellow(void *argument)
{
  /* USER CODE BEGIN vLedBlinkYellow */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END vLedBlinkYellow */
}

/* USER CODE BEGIN Header_vLedBlinkBlue */
/**
* @brief Function implementing the LedBlinkBlue thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_vLedBlinkBlue */
void vLedBlinkBlue(void *argument)
{
  /* USER CODE BEGIN vLedBlinkBlue */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END vLedBlinkBlue */
}

/* USER CODE BEGIN Header_vLedBlinkRed */
/**
* @brief Function implementing the LedBlinkRed thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_vLedBlinkRed */
void vLedBlinkRed(void *argument)
{
  /* USER CODE BEGIN vLedBlinkRed */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END vLedBlinkRed */
}

/* USER CODE BEGIN Header_vLedBlinkGreen */
/**
* @brief Function implementing the LedBlinkGreen thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_vLedBlinkGreen */
void vLedBlinkGreen(void *argument)
{
  /* USER CODE BEGIN vLedBlinkGreen */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END vLedBlinkGreen */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

