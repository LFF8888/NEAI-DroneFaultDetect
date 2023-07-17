/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    GPIO/GPIO_IOToggle/Src/main.c
  * @author  MCD Application Team
  * @brief   This example describes how to configure and use GPIOs through
  *          the STM32U5xx HAL API.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
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
#include "main.h"
#include "adc.h"
#include "icache.h"
#include "spi.h"
#include "ucpd.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "NanoEdgeAI.h"
#include "MPU6050.h"
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define AXIS_NUMBER 6
#define DATA_INPUT_USER 50
#define MINIMUM_ITERATION_CALLS_FOR_EFFICIENT_LEARNING 18
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int16_t AX, AY, AZ, GX, GY, GZ;
char buffer[20];
float acc_buffer[DATA_INPUT_USER * AXIS_NUMBER] = { 0 };
uint8_t similarity = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void SystemPower_Config(void);
void malfunctionDetect();
void fill_accelerometer_buffer();
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* STM32U5xx HAL library initialization:
       - Configure the Flash prefetch
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 3
       - Low Level Initialization
     */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* Configure the System Power */
  SystemPower_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_UCPD1_Init();
  MX_USART1_UART_Init();
  MX_ICACHE_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  MPU6050_Init();
  HAL_Delay(100);
  MPU6050_Init();

  // Initialization
  neai_anomalydetection_init();

  // Learning
  for (uint16_t i = 0; i < MINIMUM_ITERATION_CALLS_FOR_EFFICIENT_LEARNING; i++) {
    HAL_GPIO_TogglePin(GPIOB, LED_GREEN_Pin);

    fill_accelerometer_buffer();
    neai_anomalydetection_learn(acc_buffer);

    HAL_GPIO_TogglePin(GPIOB, LED_GREEN_Pin);
    HAL_UART_Transmit(&huart1, (uint8_t*)"Learning number ", 16, 1000);
    //HAL_UART_Transmit(&huart1, (uint8_t*)(i+1), 2, 1000);
    HAL_UART_Transmit(&huart1, (uint8_t*)"\n", 1, 1000);
  }
  HAL_UART_Transmit(&huart1, (uint8_t*)"Learning finished\n", 18, 1000);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  // Inference
	  HAL_GPIO_TogglePin(GPIOB, LED_BLUE_Pin);
	  fill_accelerometer_buffer();
	  neai_anomalydetection_detect(acc_buffer, &similarity);
	  HAL_GPIO_TogglePin(GPIOB, LED_BLUE_Pin);
	  if (similarity >= 90) {
	    HAL_UART_Transmit(&huart1, (uint8_t*)"NORMAL!\n", 10, 1000);
	    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	  }
	  else {
	    HAL_UART_Transmit(&huart1, (uint8_t*)"ERROR!\n", 10, 1000);
	    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	  }

  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_4;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLMBOOST = RCC_PLLMBOOST_DIV1;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 80;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLLVCIRANGE_0;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_PCLK3;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Power Configuration
  * @retval None
  */
static void SystemPower_Config(void)
{
  HAL_PWREx_EnableVddIO2();

  /*
   * Switch to SMPS regulator instead of LDO
   */
  if (HAL_PWREx_ConfigSupply(PWR_SMPS_SUPPLY) != HAL_OK)
  {
    Error_Handler();
  }
/* USER CODE BEGIN PWR */
/* USER CODE END PWR */
}

/* USER CODE BEGIN 4 */
void fill_accelerometer_buffer() {
  for (int i = 0; i < DATA_INPUT_USER; i++) {
	  MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);

	  sprintf(buffer, "%.3f,", (float)AX / 1000);
	  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), 1000);

	  sprintf(buffer, "%.3f,", (float)AY / 1000);
	  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), 1000);

	  sprintf(buffer, "%.3f,", (float)AZ / 1000);
	  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), 1000);

	  sprintf(buffer, "%.3f,", (float)GX / 1000);
	  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), 1000);

	  sprintf(buffer, "%.3f,", (float)GY / 1000);
	  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), 1000);

	  sprintf(buffer, "%.3f,", (float)GZ / 1000);
	  HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), 1000);

	  HAL_Delay(8);

    acc_buffer[AXIS_NUMBER * i + 0] = AX;
    acc_buffer[AXIS_NUMBER * i + 1] = AY;
    acc_buffer[AXIS_NUMBER * i + 2] = AZ;
    acc_buffer[AXIS_NUMBER * i + 3] = GX;
    acc_buffer[AXIS_NUMBER * i + 4] = GY;
    acc_buffer[AXIS_NUMBER * i + 5] = GZ;
  }
  HAL_UART_Transmit(&huart1, (uint8_t*)"\n", 1, 1000);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* Infinite loop */
  while (1)
  {
  }

  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
