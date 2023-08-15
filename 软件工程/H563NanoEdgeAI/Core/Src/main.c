/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
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
#include "usart.h"
#include "gpio.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "NanoEdgeAI.h"
#include "knowledge.h"
#include "MPU6050.h"
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define AXIS_NUMBER 6//六轴传感器
#define DATA_INPUT_USER 50//导入数据数量
#define NEAI_MODE 1 //功能开启端口
#define CLASS_NUMBER 4 //class_NUMBER 调整根据实际
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int16_t AX, AY, AZ, GX, GY, GZ;
char buffer[20];

uint16_t id_class = 0; // Point to id class (see argument of neai_classification fct)
float input_user_buffer[DATA_INPUT_USER * AXIS_NUMBER]; // Buffer of input values
float output_class_buffer[CLASS_NUMBER] = { 0 }; // Buffer of class probabilities
const char *id2class[CLASS_NUMBER + 1] = { // Buffer for mapping class id to class name
		"unknown", "state-normal", "fly_normal", "fly_error_L_qian", "down", };
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void fill_input_user_buffer(void);
void print_input_user_buffer(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_LPUART1_UART_Init();
	MX_USART3_UART_Init();
	/* USER CODE BEGIN 2 */
	MPU6050_Init();
	neai_classification_init(knowledge_buffer);//分类器初始化
	int count[5] = { 0 };
	int check[5] = { 4, 4, 6, 6, 2 };

	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		/*关于LED�?
		 * �?测一次故障，黄灯闪烁�?次；�?测到故障；检测到故障，红灯亮
		 * �?灯：HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_SET);
		 *关灯：HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin, GPIO_PIN_RESET);
		 *翻转：HAL_GPIO_TogglePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin);
		 * LED1_GREEN
		 * LED2_YELLOW
		 * LED3_RED
		 * LED4_RED（在拓展板上�?
		 */

		/*关于串口�?
		 * USART3为VCP（USB串口�?
		 * HAL_UART_Transmit(&huart3, (uint8_t*) buffer, strlen(buffer), 1000);
		 * LPUART1与WiFi模组通信
		 * HAL_UART_Transmit(&hlpuart1, (uint8_t*) buffer, strlen(buffer), 1000);
		 */

		/*关于协议�?
		 * H563通过LPUART1与WiFi模块通信，用�?位数字代表故障类�?
		 * 0：未知情�?
		 * 1：正�?
		 * 2：左前电机故�?
		 * 3：右前电机故�?
		 * 4：左后电机故�?
		 * 5：右后电机故�?
		 * 6：自由落�?
		 * 7：前方障�?
		 * 8：电量不�?
		 */

		//读取数据，伴随黄灯微�?
		HAL_GPIO_WritePin(LED2_YELLOW_GPIO_Port, LED2_YELLOW_Pin,
				GPIO_PIN_RESET);
		fill_input_user_buffer();

		//print_input_user_buffer(); //调试时取消注释，运行时需要注释以加�?�循�?

		//使用NEAI�?测，并依据分类结果执行不同语�?

		neai_classification(input_user_buffer, output_class_buffer, &id_class); //n-class分类器
		if (1) {
			count[id_class] = count[id_class] + 1;
			if (count[id_class] == check[id_class]) { //check为各分类阈值
				sprintf(buffer, "%hu", id_class);
				HAL_UART_Transmit(&hlpuart1, (uint8_t*) buffer, strlen(buffer),
						1000);
				HAL_UART_Transmit(&hlpuart1, (uint8_t*) "\n", strlen("\n"),
						1000);
				HAL_UART_Transmit(&huart3, (uint8_t*) buffer, strlen(buffer),
						1000);
				HAL_UART_Transmit(&huart3, (uint8_t*) "\n", strlen("\n"), 1000);
				for (int i = 0; i < 5; i++)
					count[i] = 0;
			}
		} //滤波串口输出函数
	}
}
/* USER CODE END WHILE */

/* USER CODE BEGIN 3 */

/* USER CODE END 3 */

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Configure the main internal regulator output voltage
	 */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

	while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {
	}

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS_DIGITAL;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLL1_SOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 4;
	RCC_OscInitStruct.PLL.PLLN = 250;
	RCC_OscInitStruct.PLL.PLLP = 2;
	RCC_OscInitStruct.PLL.PLLQ = 2;
	RCC_OscInitStruct.PLL.PLLR = 2;
	RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1_VCIRANGE_1;
	RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1_VCORANGE_WIDE;
	RCC_OscInitStruct.PLL.PLLFRACN = 0;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_PCLK3;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */
void fill_input_user_buffer(void) {
	for (int i = 0; i < DATA_INPUT_USER; i++) {
		MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);
		HAL_Delay(8);
		input_user_buffer[AXIS_NUMBER * i + 0] = AX;
		input_user_buffer[AXIS_NUMBER * i + 1] = AY;
		input_user_buffer[AXIS_NUMBER * i + 2] = AZ;
		input_user_buffer[AXIS_NUMBER * i + 3] = GX;
		input_user_buffer[AXIS_NUMBER * i + 4] = GY;
		input_user_buffer[AXIS_NUMBER * i + 5] = GZ;
	}
}
void print_input_user_buffer(void) {
	for (int i = 0; i < 300; i++) {
		sprintf(buffer, "%d,", input_user_buffer[i]);
		HAL_UART_Transmit(&huart3, (uint8_t*) buffer, strlen(buffer), 1000);
	}
	HAL_UART_Transmit(&huart3, (uint8_t*) "\n", 10, 1000);
}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
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
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
