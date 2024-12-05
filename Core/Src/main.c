/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "ili9341.h"
#include "math.h"
#include "string.h"
#include "front_end.h"
#include "touch.h"
#include "cJSON.h"
#include "stdlib.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define min(a,b) (((a)<(b))?(a):(b))
#define BUFFER_SIZE 2048 // Adjust buffer size as needed
char rxBuffer[BUFFER_SIZE];
char uart_rx_byte;
uint8_t uart_index;
uint8_t recording;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi2;

UART_HandleTypeDef huart1;

SRAM_HandleTypeDef hsram1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_FSMC_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_SPI2_Init(void);
/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
void processWeather(const char *jsonString);
void UART_ReceiveString(UART_HandleTypeDef *huart, char *buffer, int buffer_size);
void Send_AT_Commands(UART_HandleTypeDef *huart);


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int *temp_max = {0};
int *temp_min = {0};
int *wind_speed = {0};
int *day_code = {0};
char day_name[7][4];
char Date[7][6];
char Time[30];
char date[30];
char jsonString[BUFFER_SIZE] = "{\"latitude\":10.875,\"longitude\":106.75,\"generationtime_ms\":0.105977058410645,\"utc_offset_seconds\":25200,\"timezone\":\"Asia/Bangkok\",\"timezone_abbreviation\":\"+07\",\"elevation\":31,\"current_units\":{\"time\":\"iso8601\",\"interval\":\"seconds\",\"temperature_2m\":\"°C\",\"relative_humidity_2m\":\"%\"},\"current\":{\"time\":\"2024-11-27T09:45\",\"interval\":900,\"temperature_2m\":28.5,\"relative_humidity_2m\":71},\"daily_units\":{\"time\":\"iso8601\",\"weather_code\":\"wmo code\",\"apparent_temperature_max\":\"°C\",\"apparent_temperature_min\":\"°C\",\"wind_speed_10m_max\":\"km/h\"},\"daily\":{\"time\":[\"2024-11-27\",\"2024-11-28\",\"2024-11-29\",\"2024-11-30\",\"2024-12-01\",\"2024-12-02\",\"2024-12-03\"],\"weather_code\":[3,80,3,3,45,3,3],\"apparent_temperature_max\":[37.2,37.9,32.7,34.2,37.1,36.6,38.9],\"apparent_temperature_min\":[28.3,28.1,26.5,25.1,29.5,29.6,31],\"wind_speed_10m_max\":[5.6,7.9,8.8,6.4,8.7,8.4,11.3]}}";
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

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
  MX_FSMC_Init();
  MX_USART1_UART_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
  LCD_BL_ON();
  TouchCalibrate();

  lcdInit();
  int i = 0;
  lcdSetOrientation(i%4);
  lcdFillRGB(COLOR_BLACK);


  int current = 1;
  bool updated = true;
  int16_t tx , ty;
  processWeather(jsonString);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  if (current == 1){
		  if (updated == true){
			  Screen1();
			  HAL_Delay(1000);
			  updated = false;
		  }
		  if (TouchGetCalibratedPoint(&tx, &ty)){
			  if (tx >= 180 && tx <= 230 && ty >= 10 && ty <= 100){
				  current = 2;
				  updated = true;
				  HAL_Delay(100);
			  }
		  }
	  }
	  else if (current == 2){
		  if (updated == true){
			  Screen2(temp_max, temp_min, day_code, day_name, wind_speed, Date);
			  HAL_Delay(1000);
			  updated = false;
		  }
		  if (TouchGetCalibratedPoint(&tx, &ty)){
			  if (tx >= 180 && tx <= 230 && ty >= 10 && ty <= 100){
				  current = 1;
				  updated = true;
				  HAL_Delay(100);
			  }
		  }
	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
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
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LCD_BL_Pin|TOUCH_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : TC_PEN_Pin */
  GPIO_InitStruct.Pin = TC_PEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(TC_PEN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_BL_Pin TOUCH_CS_Pin */
  GPIO_InitStruct.Pin = LCD_BL_Pin|TOUCH_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* FSMC initialization function */
static void MX_FSMC_Init(void)
{

  /* USER CODE BEGIN FSMC_Init 0 */

  /* USER CODE END FSMC_Init 0 */

  FSMC_NORSRAM_TimingTypeDef Timing = {0};

  /* USER CODE BEGIN FSMC_Init 1 */

  /* USER CODE END FSMC_Init 1 */

  /** Perform the SRAM1 memory initialization sequence
  */
  hsram1.Instance = FSMC_NORSRAM_DEVICE;
  hsram1.Extended = FSMC_NORSRAM_EXTENDED_DEVICE;
  /* hsram1.Init */
  hsram1.Init.NSBank = FSMC_NORSRAM_BANK1;
  hsram1.Init.DataAddressMux = FSMC_DATA_ADDRESS_MUX_DISABLE;
  hsram1.Init.MemoryType = FSMC_MEMORY_TYPE_SRAM;
  hsram1.Init.MemoryDataWidth = FSMC_NORSRAM_MEM_BUS_WIDTH_16;
  hsram1.Init.BurstAccessMode = FSMC_BURST_ACCESS_MODE_DISABLE;
  hsram1.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
  hsram1.Init.WrapMode = FSMC_WRAP_MODE_DISABLE;
  hsram1.Init.WaitSignalActive = FSMC_WAIT_TIMING_BEFORE_WS;
  hsram1.Init.WriteOperation = FSMC_WRITE_OPERATION_ENABLE;
  hsram1.Init.WaitSignal = FSMC_WAIT_SIGNAL_DISABLE;
  hsram1.Init.ExtendedMode = FSMC_EXTENDED_MODE_DISABLE;
  hsram1.Init.AsynchronousWait = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
  hsram1.Init.WriteBurst = FSMC_WRITE_BURST_DISABLE;
  hsram1.Init.PageSize = FSMC_PAGE_SIZE_NONE;
  /* Timing */
  Timing.AddressSetupTime = 1;
  Timing.AddressHoldTime = 15;
  Timing.DataSetupTime = 5;
  Timing.BusTurnAroundDuration = 0;
  Timing.CLKDivision = 16;
  Timing.DataLatency = 17;
  Timing.AccessMode = FSMC_ACCESS_MODE_A;
  /* ExtTiming */

  if (HAL_SRAM_Init(&hsram1, &Timing, NULL) != HAL_OK)
  {
    Error_Handler( );
  }

  /* USER CODE BEGIN FSMC_Init 2 */

  /* USER CODE END FSMC_Init 2 */
}

/* USER CODE BEGIN 4 */


void Send_AT_Commands(UART_HandleTypeDef *huart) {
    uint8_t at_command[] = "AT\r\n";
    uint8_t at_command1[] = "AT+CWMODE=3\r\n";
    uint8_t at_command2[] = "AT+CWJAP=\"RedmiTurbo3\",\"88888888\"\r\n";
    uint8_t at_command3[] = "AT+CIPSTART=\"TCP\",\"api.open-meteo.com\",80\r\n";
    uint8_t at_command4[] = "AT+CIPSEND=248\r\n";
    uint8_t at_command5[] = "GET /v1/forecast?latitude=10.870035&longitude=106.803706&current=temperature_2m,relative_humidity_2m&daily=temperature_2m_max,temperature_2m_min,wind_speed_10m_max&timezone=Asia%2FSingapore HTTP/1.1 \r\nHost: api.open-meteo.com\r\nConnection: close\r\n\r\n";

    // Send each command and wait for a response
    HAL_UART_Transmit(huart, at_command, strlen((char *)at_command), HAL_MAX_DELAY);
    HAL_Delay(3000); // Wait for 3 seconds

    HAL_UART_Transmit(huart, at_command1, strlen((char *)at_command1), HAL_MAX_DELAY);
    HAL_Delay(3000); // Wait for 3 seconds

    HAL_UART_Transmit(huart, at_command2, strlen((char *)at_command2), HAL_MAX_DELAY);
    HAL_Delay(9000); // Wait for 9 seconds

    HAL_UART_Transmit(huart, at_command3, strlen((char *)at_command3), HAL_MAX_DELAY);
    HAL_Delay(3000); // Wait for 3 seconds

    HAL_UART_Transmit(huart, at_command4, strlen((char *)at_command4), HAL_MAX_DELAY);
    HAL_Delay(3000); // Wait for 3 seconds

    // Send the final command and receive the response
    HAL_UART_Transmit(huart, at_command5, strlen((char *)at_command5), HAL_MAX_DELAY);




}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART1) {

    }
}

void processWeather(const char *jsonString) {
    // Parse chuỗi JSON
    cJSON *json = cJSON_Parse(jsonString);
    if (json == NULL) {
        lcdSetCursor(10, 10);
        lcdSetTextColor(COLOR_RED, COLOR_BLACK);
        lcdPrintf("Error parsing JSON!");
        return;
    }

    // Lấy thông tin dự báo hàng ngày
    	cJSON *daily = cJSON_GetObjectItem(json, "daily");
    	if (!daily) {
    	        lcdSetCursor(10, 10);
    	        lcdSetTextColor(COLOR_RED, COLOR_BLACK);
    	        lcdPrintf("Error: Missing 'daily' object!");
    	        cJSON_Delete(json);
    	        return;
    	    }
    	cJSON *dates = cJSON_GetObjectItem(daily, "time");
        cJSON *temp_max_json = cJSON_GetObjectItem(daily, "apparent_temperature_max");
        cJSON *temp_min_json = cJSON_GetObjectItem(daily, "apparent_temperature_min");
        cJSON *weather_code = cJSON_GetObjectItem(daily, "weather_code");
        cJSON *wind_speed_json = cJSON_GetObjectItem(daily, "wind_speed_10m_max");
    // Cấp phát bộ nhớ cho các biến toàn cục
    int num_days = cJSON_GetArraySize(dates);
        temp_max = (int *)malloc(num_days * sizeof(int));
        temp_min = (int *)malloc(num_days * sizeof(int));
        wind_speed = (int *)malloc(num_days * sizeof(int));
        day_code = (int *)malloc(num_days * sizeof(int));

            // Chuyển đổi ngày từ chuỗi thành tên ngày (ví dụ: "Mon")
        for (int i = 0; i < num_days; i++) {
        		char *date = cJSON_GetArrayItem(dates, i)->valuestring;
        		temp_max[i] = (int)cJSON_GetArrayItem(temp_max_json, i)->valuedouble;
        		temp_min[i] = (int)cJSON_GetArrayItem(temp_min_json, i)->valuedouble;
        		wind_speed[i] = (int)cJSON_GetArrayItem(wind_speed_json, i)->valuedouble;
        		day_code[i] = cJSON_GetArrayItem(weather_code, i)->valueint;

        		// Extract month and day from date string
				int year, month, days;
				char tmp[6];
				sscanf(date, "%d-%d-%d", &year, &month, &days);
				sprintf(tmp, "%02d-%02d", days, month);
				strncat(Date[i], tmp, sizeof(Date[i]) - strlen(Date[i]) - 1);
        		char day[4];
				switch ((i + 2) % 7) {
					case 0: sprintf(day, "Sun"); break;
					case 1: sprintf(day, "Mon"); break;
					case 2: sprintf(day, "Tue"); break;
					case 3: sprintf(day, "Wed"); break;
					case 4: sprintf(day, "Thu"); break;
					case 5: sprintf(day, "Fri"); break;
					case 6: sprintf(day, "Sat"); break;
					default: break;
				}
				strncat(day_name[i], day, sizeof(day_name[i]) - strlen(day_name[i]) - 1);
        }
    // D�?n dẹp bộ nhớ
    cJSON_Delete(json);
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
  __disable_irq();
  while (1)
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
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
