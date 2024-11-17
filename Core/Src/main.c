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
#include "ili9341.h"
#include "math.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define min(a,b) (((a)<(b))?(a):(b))
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
void demoLCD(int i);
unsigned long testFillScreen();
unsigned long testText();
unsigned long testLines(uint16_t color);
unsigned long testFastLines(uint16_t color1, uint16_t color2);
unsigned long testRects(uint16_t color);
unsigned long testFilledRects(uint16_t color1, uint16_t color2);
unsigned long testFilledCircles(uint8_t radius, uint16_t color);
unsigned long testCircles(uint8_t radius, uint16_t color);
unsigned long testTriangles();
unsigned long testFilledTriangles();
unsigned long testRoundRects();
unsigned long testFilledRoundRects();
unsigned long testDrawImage();
void Screen1();
void Screen2();


void TextTitle(int16_t x, int16_t y);
void TableMain (int16_t x, int16_t y ,int temperature , int huminity );
void WeatherDay (int x , int y );
void TextTemperature16 (int x , int y , int temperature);
void TextHumidyti16 (int x , int y , int humidyti);
void OneDay(int x , int y, int rate ,  int day, int MinTem , int MaxTem);

//Draw Icon
void DrawIconHumidyti1 (int x, int y);
void DrawIconDate (int x, int y);
void DrawIconWeather (int x, int y);
void DrawIconTem (int x, int y);
void DrawIconHumidyti2 (int x, int y);
void DrawIconHot (int x, int y);
void DrawIconIce (int x, int y);
void DrawIconWind (int x, int y);
void DrawIconWater (int x, int y);

void CloudRain (int x, int y);
void CloudSun (int x, int y);
void CloudMoon (int x, int y);
void CloudThunder (int x, int y);


void lcdDrawThickArc(int x0, int y0, int r, int start_angle, int end_angle, int thickness, uint16_t color);
void DrawClock (int x0, int y0, int r, int start_angle, int end_angle, int thickness);
void DrawCloud(int x , int y);


void DrawThermometer(int x, int y, int height, int width, int fillHeight, uint16_t borderColor, uint16_t fillColor);
void DrawGradientLine(int16_t x, int16_t y, int16_t length, int16_t thickness, uint16_t colorStart, uint16_t colorEnd);
uint16_t interpolateColor(uint16_t color1, uint16_t color2, float ratio);

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
  lcdInit();
  int i = 2;
  lcdSetOrientation(i%4);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	   Screen1();
	   HAL_Delay(2000);
	   Screen2();
	   HAL_Delay(2000);
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
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
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
  HAL_GPIO_WritePin(T_Pen_GPIO_Port, T_Pen_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LCD_BL_Pin|T_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : T_Pen_Pin */
  GPIO_InitStruct.Pin = T_Pen_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(T_Pen_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_BL_Pin T_CS_Pin */
  GPIO_InitStruct.Pin = LCD_BL_Pin|T_CS_Pin;
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
void demoLCD(int i)
{
 lcdSetOrientation(i%4);

 uint32_t t = testFillScreen();
 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", t);
 HAL_Delay(2000);

 t = HAL_GetTick();
 lcdTest();
 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", HAL_GetTick() - t);
 HAL_Delay(2000);

 t = testText();
 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", t);
 HAL_Delay(2000);

 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", testLines(COLOR_CYAN));
 HAL_Delay(2000);

 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", testFastLines(COLOR_RED, COLOR_BLUE));
 HAL_Delay(2000);

 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", testRects(COLOR_GREEN));
 HAL_Delay(2000);

 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", testFilledRects(COLOR_YELLOW, COLOR_MAGENTA));
 HAL_Delay(2000);

 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", testFilledCircles(10, COLOR_MAGENTA));
 HAL_Delay(2000);

 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", testCircles(10, COLOR_WHITE));
 HAL_Delay(2000);

 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", testTriangles());
 HAL_Delay(2000);

 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", testFilledTriangles());
 HAL_Delay(2000);

 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", testRoundRects());
 HAL_Delay(2000);

 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", testFilledRoundRects());
 HAL_Delay(2000);

 lcdSetTextFont(&Font16);
 lcdSetCursor(0, lcdGetHeight() - lcdGetTextFont()->Height - 1);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("Time: %4lu ms", testDrawImage());
 HAL_Delay(2000);
}

unsigned long testFillScreen()
{
 unsigned long start = HAL_GetTick(), t = 0;
 lcdFillRGB(COLOR_BLACK);
 t += HAL_GetTick() - start;
 lcdSetCursor(0, 0);
 lcdSetTextFont(&Font24);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("BLACK");
 HAL_Delay(1000);
 start = HAL_GetTick();
 lcdFillRGB(COLOR_RED);
 t += HAL_GetTick() - start;
 lcdSetCursor(0, 0);
 lcdSetTextFont(&Font24);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("RED");
 HAL_Delay(1000);
 start = HAL_GetTick();
 lcdFillRGB(COLOR_GREEN);
 t += HAL_GetTick() - start;
 lcdSetCursor(0, 0);
 lcdSetTextFont(&Font24);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("GREEN");
 HAL_Delay(1000);
 start = HAL_GetTick();
 lcdFillRGB(COLOR_BLUE);
 t += HAL_GetTick() - start;
 lcdSetCursor(0, 0);
 lcdSetTextFont(&Font24);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdPrintf("BLUE");
 HAL_Delay(1000);
 start = HAL_GetTick();
 lcdFillRGB(COLOR_BLACK);
 return t += HAL_GetTick() - start;
}

unsigned long testText()
{
 lcdFillRGB(COLOR_BLACK);
 unsigned long start = HAL_GetTick();
 lcdSetCursor(0, 0);
 lcdSetTextColor(COLOR_WHITE, COLOR_BLACK);
 lcdSetTextFont(&Font8);
 lcdPrintf("Hello World!\r\n");
 lcdSetTextColor(COLOR_YELLOW, COLOR_BLACK);
 lcdSetTextFont(&Font12);
 lcdPrintf("%i\r\n", 1234567890);
 lcdSetTextColor(COLOR_RED, COLOR_BLACK);
 lcdSetTextFont(&Font16);
 lcdPrintf("%#X\r\n", 0xDEADBEEF);
 lcdPrintf("\r\n");
 lcdSetTextColor(COLOR_GREEN, COLOR_BLACK);
 lcdSetTextFont(&Font20);
 lcdPrintf("Groop\r\n");
 lcdSetTextFont(&Font12);
 lcdPrintf("I implore thee,\r\n");
 lcdSetTextFont(&Font12);
 lcdPrintf("my foonting turlingdromes.\r\n");
 lcdPrintf("And hooptiously drangle me\r\n");
 lcdPrintf("with crinkly bindlewurdles,\r\n");
 lcdPrintf("Or I will rend thee\r\n");
 lcdPrintf("in the gobberwarts\r\n");
 lcdPrintf("with my blurglecruncheon,\r\n");
 lcdPrintf("see if I don't!\r\n");
 return HAL_GetTick() - start;
}

unsigned long testLines(uint16_t color)
{
  unsigned long start, t;
  int           x1, y1, x2, y2,
                w = lcdGetWidth(),
                h = lcdGetHeight();

  lcdFillRGB(COLOR_BLACK);

  x1 = y1 = 0;
  y2 = h - 1;
  start = HAL_GetTick();
  for(x2 = 0; x2 < w; x2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  x2 = w - 1;
  for(y2 = 0; y2 < h; y2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  t = HAL_GetTick() - start; // fillScreen doesn't count against timing

  HAL_Delay(1000);
  lcdFillRGB(COLOR_BLACK);

  x1 = w - 1;
  y1 = 0;
  y2 = h - 1;

  start = HAL_GetTick();

  for(x2 = 0; x2 < w; x2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  x2 = 0;
  for(y2 = 0; y2 < h; y2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  t += HAL_GetTick() - start;

  HAL_Delay(1000);
  lcdFillRGB(COLOR_BLACK);

  x1 = 0;
  y1 = h - 1;
  y2 = 0;
  start = HAL_GetTick();

  for(x2 = 0; x2 < w; x2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  x2 = w - 1;
  for(y2 = 0; y2 < h; y2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  t += HAL_GetTick() - start;

  HAL_Delay(1000);
  lcdFillRGB(COLOR_BLACK);

  x1 = w - 1;
  y1 = h - 1;
  y2 = 0;

  start = HAL_GetTick();

  for(x2 = 0; x2 < w; x2 += 6) lcdDrawLine(x1, y1, x2, y2, color);
  x2 = 0;
  for(y2 = 0; y2 < h; y2 += 6) lcdDrawLine(x1, y1, x2, y2, color);

  return t += HAL_GetTick() - start;
}

unsigned long testFastLines(uint16_t color1, uint16_t color2)
{
  unsigned long start;
  int x, y, w = lcdGetWidth(), h = lcdGetHeight();

  lcdFillRGB(COLOR_BLACK);
  start = HAL_GetTick();
  for(y = 0; y < h; y += 5) lcdDrawHLine(0, w, y, color1);
  for(x = 0; x < w; x += 5) lcdDrawVLine(x, 0, h, color2);

  return HAL_GetTick() - start;
}

unsigned long testRects(uint16_t color)
{
  unsigned long start;
  int n, i, i2,
      cx = lcdGetWidth()  / 2,
      cy = lcdGetHeight() / 2;

  lcdFillRGB(COLOR_BLACK);
  n = min(lcdGetWidth(), lcdGetHeight());
  start = HAL_GetTick();
  for(i = 2; i < n; i += 6)
  {
    i2 = i / 2;
    lcdDrawRect(cx - i2, cy - i2, i, i, color);
  }

  return HAL_GetTick() - start;
}

unsigned long testFilledRects(uint16_t color1, uint16_t color2)
{
  unsigned long start, t = 0;
  int n, i, i2,
      cx = lcdGetWidth() / 2 - 1,
      cy = lcdGetHeight() / 2 - 1;

  lcdFillRGB(COLOR_BLACK);
  n = min(lcdGetWidth(), lcdGetHeight());

  for(i = n; i > 0; i -= 6)
  {
    i2 = i / 2;
    start = HAL_GetTick();
    lcdFillRect(cx-i2, cy-i2, i, i, color1);
    t    += HAL_GetTick() - start;
    // Outlines are not included in timing results
    lcdDrawRect(cx-i2, cy-i2, i, i, color1);
  }

  return t;
}

unsigned long testFilledCircles(uint8_t radius, uint16_t color)
{
  unsigned long start;
  int x, y, w = lcdGetWidth(), h = lcdGetHeight(), r2 = radius * 2;

  lcdFillRGB(COLOR_BLACK);
  start = HAL_GetTick();
  for(x = radius; x < w; x += r2)
  {
    for(y = radius; y < h; y += r2)
    {
      lcdFillCircle(x, y, radius, color);
    }
  }

  return HAL_GetTick() - start;
}

unsigned long testCircles(uint8_t radius, uint16_t color)
{
  unsigned long start;
  int x, y, r2 = radius * 2,
      w = lcdGetWidth()  + radius,
      h = lcdGetHeight() + radius;

  // Screen is not cleared for this one -- this is
  // intentional and does not affect the reported time.
  start = HAL_GetTick();
  for(x = 0; x < w; x += r2)
  {
    for(y = 0; y < h; y += r2)
    {
      lcdDrawCircle(x, y, radius, color);
    }
  }

  return HAL_GetTick() - start;
}

unsigned long testTriangles()
{
  unsigned long start;
  int n, i, cx = lcdGetWidth() / 2 - 1,
            cy = lcdGetHeight() / 2 - 1;

  lcdFillRGB(COLOR_BLACK);
  n = min(cx, cy);
  start = HAL_GetTick();
  for(i = 0; i < n; i += 5)
  {
    lcdDrawTriangle(
      cx    , cy - i, // peak
      cx - i, cy + i, // bottom left
      cx + i, cy + i, // bottom right
      lcdColor565(i, i, i));
  }

  return HAL_GetTick() - start;
}

unsigned long testFilledTriangles()
{
  unsigned long start, t = 0;
  int i, cx = lcdGetWidth() / 2 - 1,
         cy = lcdGetHeight() / 2 - 1;

  lcdFillRGB(COLOR_BLACK);
  for(i = min(cx, cy); i > 10; i -= 5)
  {
    start = HAL_GetTick();
    lcdFillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i, lcdColor565(0, i*10, i*10));
    t += HAL_GetTick() - start;
    lcdFillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i, lcdColor565(i*10, i*10, 0));
  }

  return t;
}

unsigned long testRoundRects()
{
  unsigned long start;
  int w, i, i2,
      cx = lcdGetWidth() / 2 - 1,
      cy = lcdGetHeight() / 2 - 1;

  lcdFillRGB(COLOR_BLACK);
  w = lcdGetWidth(), lcdGetHeight();
  start = HAL_GetTick();
  for(i = 0; i < w; i += 6)
  {
    i2 = i / 2;
    lcdDrawRoundRect(cx-i2, cy-i2, i, i, i/2, lcdColor565(i, 0, 0));
    HAL_Delay(100);
  }

  return HAL_GetTick() - start;
}

unsigned long testFilledRoundRects()
{
  unsigned long start;
  int i, i2,
      cx = lcdGetWidth()  / 2 - 1,
      cy = lcdGetHeight() / 2 - 1;

  lcdFillRGB(COLOR_BLACK);
  start = HAL_GetTick();
  for(i = min(lcdGetWidth(), lcdGetHeight()); i > 20; i -=6 )
  {
    i2 = i / 2;
    lcdFillRoundRect(cx - i2, cy - i2, i, i, i / 8, lcdColor565(0, i, 0));
  }

  return HAL_GetTick() - start;
}

unsigned long testDrawImage()
{
 unsigned long start;

 start = HAL_GetTick();

 if (lcdGetOrientation() == LCD_ORIENTATION_LANDSCAPE || lcdGetOrientation() == LCD_ORIENTATION_LANDSCAPE_MIRROR)
 {
  lcdDrawImage((lcdGetWidth() - bmBackGround.xSize)/2, 0, &bmBackGround);
 }
 else
 {
  lcdDrawImage(0, (lcdGetHeight() - bmBackGround.ySize) / 2, &bmBackGround);
 }
 return HAL_GetTick() - start;
}

void DrawCloud(int x, int y) {
	lcdDrawImage(x, y, &bmicon3);
}

void TextTitle(int16_t x, int16_t y){
	lcdSetCursor(x, y);
	lcdSetTextColor(COLOR_WHITE, COLOR_THEME_SKYBLUE_BASE);
	lcdSetTextFont(&Font16);
	lcdPrintf("Weather Report\r\n");

}
void TableMain (int16_t x, int16_t y ,int temperature , int huminity )
{
	lcdDrawRect(x, y, 140 , 50 , COLOR_WHITE);
	lcdDrawLine(x, y + 15, x + 139 , y + 15, COLOR_WHITE);
	lcdDrawLine(x + 70, y , x + 70, y + 49, COLOR_WHITE);

	lcdSetCursor(x + 7, y + 4);
    lcdSetTextColor(COLOR_WHITE, COLOR_THEME_SKYBLUE_BASE);
    lcdSetTextFont(&Font8);
    lcdPrintf("Temperature\r\n");

    lcdSetCursor(x + 85 , y + 4);
    lcdSetTextColor(COLOR_WHITE, COLOR_THEME_SKYBLUE_BASE);
    lcdSetTextFont(&Font8);
    lcdPrintf("Huminity\r\n");

    lcdSetCursor(x + 4 , y + 25);
    lcdSetTextColor(COLOR_WHITE, COLOR_THEME_SKYBLUE_BASE);
    lcdSetTextFont(&Font20);
    if (10 < temperature)
    {
    	lcdSetCursor(x + 7 , y + 25);
    	lcdPrintf("%d C\r\n" , temperature);
		lcdDrawCircle( x + 40 , y + 28 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 40 , y + 28 , 2, COLOR_WHITE);
    }
    else if ( 0 <  temperature)
    {
        lcdSetCursor(x + 14 , y + 25);
    	lcdPrintf("%d C\r\n" , temperature);
    	lcdDrawCircle( x + 35 , y + 28 , 3, COLOR_WHITE);
    	lcdDrawCircle( x + 35 , y + 28 , 2, COLOR_WHITE);
    }
    else if (-10 < temperature )
    {
    	lcdSetCursor(x + 7 , y + 25);
    	lcdPrintf("%d C\r\n" , temperature);
		lcdDrawCircle( x + 40 , y + 28 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 40 , y + 28 , 2, COLOR_WHITE);
    }
    else
    {
    	lcdPrintf("%d" , temperature);
    	lcdSetCursor(x + 53 , y + 25);
    	lcdPrintf("C\r\n");
		lcdDrawCircle( x + 49 , y + 28 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 49 , y + 28 , 2, COLOR_WHITE);
    }

    lcdSetCursor(x + 84 , y + 25);
    lcdSetTextColor(COLOR_WHITE, COLOR_THEME_SKYBLUE_BASE);
    lcdSetTextFont(&Font20);
    if (huminity < 10){
    	lcdSetCursor(x + 91 , y + 25);
    	lcdPrintf("%d/\r\n" , huminity);
		lcdDrawCircle( x + 108 , y + 28 , 2, COLOR_WHITE);
		lcdDrawCircle( x + 116 , y+ 37 , 2, COLOR_WHITE);
    }
    else {
    	lcdPrintf("%d/\r\n" , huminity);
    	lcdDrawCircle( x + 115 , y + 28 , 2, COLOR_WHITE);
    	lcdDrawCircle( x + 123 , y + 37 , 2, COLOR_WHITE);
    }
}

void lcdDrawThickArc(int x0, int y0, int r, int start_angle, int end_angle, int thickness, uint16_t color) {
    for (int t = 0; t < thickness; t++) {
        int x, y;
        for (int angle = start_angle; angle <= end_angle; angle++) {
            x = x0 + (r + t) * cos(angle * M_PI / 180);
            y = y0 + (r + t) * sin(angle * M_PI / 180);
            lcdDrawPixel(x, y, color); // Giả sử bạn có hàm lcdDrawPixel để vẽ điểm ảnh
        }
    }
}
void DrawClock (int x0, int y0, int r, int start_angle, int end_angle, int thickness){
	lcdDrawThickArc(x0 , y0 ,r , start_angle , -93  , thickness , COLOR_GREEN);
	lcdDrawThickArc(x0 , y0 ,r , -87 , -23  , thickness , COLOR_BLUE);
	lcdDrawThickArc(x0 , y0 ,r , -17 , end_angle  , thickness , COLOR_ORANGE);
}

void CloudRain (int x, int y){
    // Draw the cloud body using rounded rectangles and circles
	lcdFillRoundRect(x, y, 30, 10, 5, COLOR_WHITE);
    lcdFillCircle(x + 24, y + 2, 7, COLOR_WHITE);
    lcdFillCircle(x + 15, y , 9, COLOR_WHITE);

    lcdDrawLine(x + 7, y + 13, x + 5, y + 16, COLOR_BLUE);
    lcdDrawLine(x + 8, y + 13, x + 6, y + 16, COLOR_BLUE);

    lcdDrawLine(x + 13, y + 13, x + 8, y + 19, COLOR_BLUE);
    lcdDrawLine(x + 14, y + 13, x + 9, y + 19, COLOR_BLUE);

    lcdDrawLine(x + 19, y + 13, x + 17, y + 16, COLOR_BLUE);
    lcdDrawLine(x + 20, y + 13, x + 18, y + 16, COLOR_BLUE);

    lcdDrawLine(x + 25, y + 13, x + 20, y + 19, COLOR_BLUE);
    lcdDrawLine(x + 26, y + 13, x + 21, y + 19, COLOR_BLUE);
}
void CloudSun (int x, int y){

	lcdFillCircle(x + 21, y - 5 , 7, COLOR_DARKYELLOW);
    // Draw the cloud body using rounded rectangles and circles
	lcdFillRoundRect(x, y, 30, 10, 5, COLOR_WHITE);
    lcdFillCircle(x + 24, y + 2, 7, COLOR_WHITE);
    lcdFillCircle(x + 15, y , 9, COLOR_WHITE);
}
void CloudMoon (int x, int y){

	lcdFillCircle(x + 10, y - 5 , 7, COLOR_DARKYELLOW);
	lcdFillCircle(x + 7, y - 8 , 4, COLOR_THEME_SKYBLUE_BASE);
    // Draw the cloud body using rounded rectangles and circles
	lcdFillRoundRect(x, y, 30, 10, 5, COLOR_WHITE);
    lcdFillCircle(x + 24, y + 2, 7, COLOR_WHITE);
    lcdFillCircle(x + 20, y , 9, COLOR_WHITE);


}
void CloudThunder (int x, int y){
    // Draw the cloud body using rounded rectangles and circles
	lcdFillRoundRect(x, y, 30, 10, 5, COLOR_WHITE);
    lcdFillCircle(x + 24, y + 2, 7, COLOR_WHITE);
    lcdFillCircle(x + 15, y , 9, COLOR_WHITE);

    // Draw the first thunderbolt using lines for a zigzag shape
        lcdDrawLine(x + 7, y + 10, x + 5, y + 15, COLOR_YELLOW);   // First thunderbolt
        lcdDrawLine(x + 5, y + 15, x + 9, y + 15, COLOR_YELLOW);
        lcdDrawLine(x + 9, y + 15, x + 6, y + 21, COLOR_YELLOW);

        // Draw the second thunderbolt (centered below the cloud)
        lcdDrawLine(x + 15, y + 10, x + 13, y + 15, COLOR_YELLOW);  // Second thunderbolt
        lcdDrawLine(x + 13, y + 15, x + 17, y + 15, COLOR_YELLOW);
        lcdDrawLine(x + 17, y + 15, x + 14, y + 21, COLOR_YELLOW);

        // Draw the third thunderbolt (right side)
        lcdDrawLine(x + 23, y + 10, x + 21, y + 15, COLOR_YELLOW);  // Third thunderbolt
        lcdDrawLine(x + 21, y + 15, x + 25, y + 15, COLOR_YELLOW);
        lcdDrawLine(x + 25, y + 15, x + 22, y + 21, COLOR_YELLOW);

        // Draw the first thunderbolt using lines for a zigzag shape
		lcdDrawLine(x + 7 + 1, y + 10, x + 5 + 1, y + 15, COLOR_YELLOW);   // First thunderbolt
		lcdDrawLine(x + 5 + 1, y + 15, x + 9 + 1, y + 15, COLOR_YELLOW);
		lcdDrawLine(x + 9 + 1, y + 15, x + 6 + 1, y + 21, COLOR_YELLOW);

		// Draw the second thunderbolt (centered below the cloud)
		lcdDrawLine(x + 15 + 1, y + 10, x + 13 + 1, y + 15, COLOR_YELLOW);  // Second thunderbolt
		lcdDrawLine(x + 13 + 1, y + 15, x + 17 + 1, y + 15, COLOR_YELLOW);
		lcdDrawLine(x + 17 + 1, y + 15, x + 14 + 1, y + 21, COLOR_YELLOW);

		// Draw the third thunderbolt (right side)
		lcdDrawLine(x + 23 + 1, y + 10, x + 21 + 1, y + 15, COLOR_YELLOW);  // Third thunderbolt
		lcdDrawLine(x + 21 + 1, y + 15, x + 25 + 1, y + 15, COLOR_YELLOW);
		lcdDrawLine(x + 25 + 1, y + 15, x + 22 + 1, y + 21, COLOR_YELLOW);
}

uint16_t interpolateColor(uint16_t color1, uint16_t color2, float ratio) {
    uint8_t r1 = (color1 >> 11) & 0x1F;
    uint8_t g1 = (color1 >> 5) & 0x3F;
    uint8_t b1 = color1 & 0x1F;

    uint8_t r2 = (color2 >> 11) & 0x1F;
    uint8_t g2 = (color2 >> 5) & 0x3F;
    uint8_t b2 = color2 & 0x1F;

    uint8_t r = r1 + (r2 - r1) * ratio;
    uint8_t g = g1 + (g2 - g1) * ratio;
    uint8_t b = b1 + (b2 - b1) * ratio;

    return (r << 11) | (g << 5) | b;
}

void DrawGradientLine(int16_t x, int16_t y, int16_t length, int16_t thickness, uint16_t colorStart, uint16_t colorEnd) {
    // Radius for rounded ends, equal to half the thickness of the line
    int16_t radius = thickness / 2;

    // Draw the main gradient line with thickness
    for (int16_t i = 0; i < length; i++) {
        float ratio = (float)i / length;  // Calculate the interpolation ratio
        uint16_t color = interpolateColor(colorStart, colorEnd, ratio);

        // Draw a vertical line of "thickness" pixels at each position along the gradient line
        for (int16_t j = -radius + 1; j <= radius; j++) {
            lcdDrawPixel(x + i , y + j, color);  // Center the thickness vertically
        }
    }

    // Draw rounded ends as circles with colors matching the ends of the gradient
    lcdFillCircle(x, y  , radius - 1, colorStart);                 // Start of the line
    lcdFillCircle(x + length - 1, y , radius - 1, colorEnd);      // End of the line
    lcdDrawCircle(x + length / 3, y , radius , COLOR_THEME_SKYBLUE_BASE);
    lcdDrawCircle(x + length / 3, y , radius - 1 , COLOR_WHITE);
}

void WeatherDay (int x , int y ){
	int rate = 8;
	int temperatureMin = -12;
	int temperatureMax = -10;

	  lcdSetCursor(x + 1, y + 20);
	  lcdSetTextFont(&Font16);
	  lcdSetTextColor(COLOR_WHITE, COLOR_THEME_SKYBLUE_BASE);

	  CloudRain(x + 50, y + 10);
	  lcdSetTextFont(&Font12);
	  if (rate >= 10)
	  {
		  lcdSetCursor(x + 56, y + 32);
		  lcdPrintf("%d/", rate);
	      lcdDrawCircle(x + 72, y + 33 , 1 , COLOR_WHITE);
		  lcdDrawCircle(x + 75, y + 40 , 1 , COLOR_WHITE);

	  }
	  else{
		  lcdSetCursor(x + 59, y + 32);
		  lcdPrintf("%d/", rate);
		  lcdDrawCircle(x + 68, y + 33 , 1 , COLOR_WHITE);
		  lcdDrawCircle(x + 71, y + 40 , 1 , COLOR_WHITE);
	  }

	  lcdSetCursor(x + 1, y + 20);
	  lcdSetTextFont(&Font16);
	  lcdPrintf("Now");
	  lcdSetCursor(x + 93, y + 20);
	  if (10 <= temperatureMin)
	  {
		lcdSetCursor(x + 98, y + 20);
		lcdPrintf("%d" , temperatureMin);
		lcdDrawCircle( x + 126 , y + 19 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 126 , y + 19 , 2, COLOR_WHITE);
	  }
	  else if ( 0 <  temperatureMin)
	  {
		lcdSetCursor(x + 109, y + 20);
		lcdPrintf("%d" , temperatureMin);
		lcdDrawCircle( x + 126 , y + 19 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 126 , y + 19 , 2, COLOR_WHITE);
	  }
	  else if (-10 < temperatureMin )
	  {
		lcdSetCursor(x + 98, y + 20);
		lcdPrintf("%d" , temperatureMin);
		lcdDrawCircle( x + 126 , y + 19 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 126 , y + 19 , 2, COLOR_WHITE);
	  }
	  else
	  {
		lcdSetCursor(x + 87, y + 20);
		lcdPrintf("%d" , temperatureMin);
		lcdDrawCircle( x + 126 , y + 19 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 126 , y + 19 , 2, COLOR_WHITE);
	  }

	  DrawGradientLine(x + 138, y + 25 , 50 , 6 ,  COLOR_ORANGE , COLOR_RED);

	  lcdSetCursor(x + 193, y + 20);
	  if (10 < temperatureMax)
	  {
		lcdSetCursor(x + 196, y + 20);
		lcdPrintf("%d" , temperatureMax);
		lcdDrawCircle( x + 223 , y + 19 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 223 , y + 19 , 2, COLOR_WHITE);
	  }
	  else if ( 0 <  temperatureMax)
	  {
		lcdSetCursor(x + 196, y + 20);
		lcdPrintf("%d" , temperatureMax);
		lcdDrawCircle( x + 212 , y + 19 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 212 , y + 19 , 2, COLOR_WHITE);
	  }
	  else if (-10 < temperatureMax )
	  {
		lcdSetCursor(x + 196, y + 20);
		lcdPrintf("%d" , temperatureMax);
		lcdDrawCircle( x + 223 , y + 19 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 223 , y + 19 , 2, COLOR_WHITE);
	  }
	  else
	  {
		lcdSetCursor(x + 196, y + 20);
		lcdPrintf("%d" , temperatureMax);
		lcdDrawCircle( x + 234 , y + 19 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 234 , y + 19 , 2, COLOR_WHITE);
	  }



}

void DrawThermometer(int x, int y, int height, int width, int fillHeight, uint16_t borderColor, uint16_t fillColor) {
    int bulbRadius = width / 2;                  // Radius of the bulb at the bottom
    int tubeWidth = width / 2;                   // Width of the thermometer tube
    int tubeHeight = height - bulbRadius * 2;    // Height of the thermometer tube

    // Draw the bulb at the bottom
    lcdFillCircle(x, y + height - bulbRadius, bulbRadius , borderColor);           // Outer circle for bulb
    lcdFillCircle(x, y + height - bulbRadius, bulbRadius - 2, COLOR_WHITE);       // Inner circle for bulb border
    lcdFillCircle(x, y + height - bulbRadius, bulbRadius - 3, fillColor);         // Inner fill for "mercury" in bulb

    // Draw the thermometer tube
    lcdFillRoundRect(x - tubeWidth / 2, y, tubeWidth, tubeHeight + 1 , tubeWidth / 2, borderColor);       // Outer tube border
    lcdFillRoundRect(x - tubeWidth / 2 + 2, y + 2, tubeWidth - 4, tubeHeight - 4, tubeWidth / 2 - 2, COLOR_WHITE); // Inner tube border

    // Fill the thermometer tube based on the fill height
    int filledTubeHeight = fillHeight * tubeHeight / height;  // Scale fill height to tube height
    lcdFillRect(x - tubeWidth / 2 + 2, y + tubeHeight - filledTubeHeight + 2, tubeWidth - 5, filledTubeHeight, fillColor);  // Fill tube with "mercury"

    // Draw finer scale marks on the side of the thermometer
    int markCount = 8;  // Increased number of marks for more detail
    int markSpacing = tubeHeight / markCount; // Spacing between marks
    for (int i = 0; i <= markCount; i++) {
        int markY = y + tubeHeight - i * markSpacing;
        int markLength = (i % 2 == 0) ? 8 : 5;  // Longer marks every other line for a clearer scale
        lcdDrawLine(x + tubeWidth / 2 + 3, markY, x + tubeWidth / 2 + 3 + markLength, markY, borderColor);
    }
}

void DrawIconHumidyti1 (int x, int y)
{
	lcdDrawImage(x, y , &bmicon1);
}

void DrawIconDate (int x, int y)
{
	lcdDrawImage(x, y , &bmicon2);
}
void DrawIconWeather (int x, int y)
{
	lcdDrawImage(x, y , &bmwether);
}
void DrawIconTem (int x, int y)
{
	lcdDrawImage(x, y , &bmTem);
}
void DrawIconHumidyti2 (int x, int y)
{
	lcdDrawImage(x, y , &bmhumi);
}
void TextTemperature16 (int x , int y , int temperature){
	lcdSetTextColor(COLOR_WHITE, COLOR_THEME_SKYBLUE_BASE);
	lcdSetTextFont(&Font24);
	if (10 <= temperature)
	{
		lcdSetCursor(x + 5 , y );
		lcdPrintf("%d C\r\n" , temperature);
		lcdDrawCircle( x + 47 , y + 3 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 47 , y + 3 , 2, COLOR_WHITE);
	}
	else if ( 0 <  temperature)
	{
		lcdSetCursor(x + 12  , y );
		lcdPrintf("%d C\r\n" , temperature);
		lcdDrawCircle( x + 36 , y + 3 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 36 , y + 3 , 2, COLOR_WHITE);
	}
	else if (-10 < temperature )
	{
		lcdSetCursor(x + 5  , y );
		lcdPrintf("%d C\r\n" , temperature);
		lcdDrawCircle( x + 47 , y + 3 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 47 , y + 3 , 2, COLOR_WHITE);
	}
	else
	{
		lcdSetCursor(x - 3  , y );
		lcdPrintf("%d C\r\n" , temperature);
		lcdDrawCircle( x + 56 , y + 3 , 3, COLOR_WHITE);
		lcdDrawCircle( x + 56 , y + 3 , 2, COLOR_WHITE);
	}
}

void TextHumidyti16 (int x , int y , int humidyti){
	lcdSetTextColor(COLOR_WHITE, COLOR_THEME_SKYBLUE_BASE);
	lcdSetTextFont(&Font24);
	if (humidyti < 10){
		lcdSetCursor(x  , y );
		lcdPrintf("%d/\r\n" , humidyti);
		lcdDrawCircle( x + 20 , y + 3 , 2, COLOR_WHITE);
		lcdDrawCircle( x + 29 , y + 16 , 2, COLOR_WHITE);
	}
	else {
		lcdSetCursor(x - 5  , y );
		lcdPrintf("%d/\r\n" , humidyti);
		lcdDrawCircle( x + 33 , y + 3 , 2, COLOR_WHITE);
		lcdDrawCircle( x + 41 , y + 15 , 2, COLOR_WHITE);
	}
}
void DrawIconHot (int x, int y){
	  lcdDrawImage(x, y, &bmhot);
}
void DrawIconIce (int x, int y){
	  lcdDrawImage(x, y, &bmice);
}
void DrawIconWind (int x, int y){
	  lcdDrawImage(x, y, &bmwind);
}
void DrawIconWater (int x, int y){
	  lcdDrawImage(x, y, &bmwater);
}
void OneDay(int x , int y, int rate , int day , int MinTem , int MaxTem){
	  lcdSetCursor(x , y);
	  lcdSetTextFont(&Font16);
	  lcdSetTextColor(COLOR_WHITE, COLOR_THEME_SKYBLUE_BASE);
	  if (day == 2){
		  lcdPrintf("Mon");
	  }
	  if (day == 3){
		  lcdPrintf("Tue");
	  }
	  if (day == 4){
		  lcdPrintf("Wen");
	  }
	  if (day == 5){
		  lcdPrintf("Thu");
	  }
	  if (day == 6){
		  lcdPrintf("Fri");
	  }
	  if (day == 7){
		  lcdPrintf("Sat");
	  }
	  if (day == 8){
		  lcdPrintf("Sun");
	  }

	  lcdSetCursor(x + 103, y);
	  if (MinTem < 10){
		  if (MaxTem < 10){
			lcdPrintf("0%d-0%d", MinTem , MaxTem);
		  }
		  else {
			  lcdPrintf("0%d-%d", MinTem , MaxTem);
		  }
	  }
	  else{
		  if (MaxTem < 10){
			  lcdPrintf("%d-0%d", MinTem , MaxTem);
		  }
		  else {
			  lcdPrintf("%d-%d", MinTem , MaxTem);
		  }
	  }

	  lcdDrawCircle(x + 163, y - 2, 2, COLOR_WHITE);
	  lcdDrawCircle(x + 163, y - 2, 3, COLOR_WHITE);

	  if ( 80 < rate)
	  {
		  CloudThunder (x + 51, y - 1);
	  }
	  else if (50 < rate){
		  CloudRain(x + 51 , y );
	  }
	  else{
		  CloudSun(x + 51, y + 5);
	  }

	  if (rate >= 10){
		  lcdSetCursor(x + 188, y);
		  lcdPrintf("%d/",rate);
		  lcdDrawCircle(x + 213, y + 2, 2, COLOR_WHITE);
		  lcdDrawCircle(x + 218, y + 10, 2, COLOR_WHITE);
	  }
	  else {
		  lcdSetCursor(x + 195, y);
		  lcdPrintf("%d/",rate);
		  lcdDrawCircle(x + 209, y + 2, 2, COLOR_WHITE);
		  lcdDrawCircle(x + 215, y + 10, 2, COLOR_WHITE);
	  }
}
void Screen1(){

	int temperatre = 23;
  lcdFillRGB(COLOR_THEME_SKYBLUE_BASE);
  TextTitle( 30 , 1);
  lcdDrawImage(0, 15, &bmBackGround2);

  lcdDrawRect(0, 15, 240, 60, COLOR_WHITE);

  DrawCloud (5 , 80);


  DrawThermometer(95, 80 , 40, 12, 25, COLOR_BLACK, COLOR_RED);
  TextTemperature16(120, 95, temperatre);
  if (temperatre >= 29){
	  DrawIconHot(205 , 85);
  }
  else if ( temperatre < 20){
	  DrawIconIce(205 , 85);
  }
  else {
	  DrawIconWind(205 , 85);
  }

  DrawIconHumidyti1(77, 130);
  TextHumidyti16 (140, 146 , 12);
  DrawIconWater(205 , 138);

  WeatherDay(0, 175 );
}

void Screen2(){

	int rate;
	lcdFillRGB(COLOR_THEME_SKYBLUE_BASE);
	  DrawIconDate(5, 30);
	  DrawIconWeather(55, 30);
	  DrawIconTem(120, 30);
	  DrawIconHumidyti2(190, 30);

	  lcdDrawLine(50, 30, 50, 319, COLOR_BLACK);
	  lcdDrawLine(100, 30, 100, 319, COLOR_BLACK);
	  lcdDrawLine(180, 30, 180, 319, COLOR_BLACK);

	  lcdDrawLine(0, 73 , 239, 73  , COLOR_BLACK);
	  lcdDrawLine(0, 108, 239, 108 , COLOR_BLACK);
	  lcdDrawLine(0, 143, 239, 143 , COLOR_BLACK);
	  lcdDrawLine(0, 178, 239, 178 , COLOR_BLACK);
	  lcdDrawLine(0, 213, 239, 213 , COLOR_BLACK);
	  lcdDrawLine(0, 248, 239, 248 , COLOR_BLACK);
	  lcdDrawLine(0, 283, 239, 283 , COLOR_BLACK);

	  OneDay(7, 85, 88  , 2 , 5 , 22);
	  OneDay(7, 120, 45 , 3 , 16, 28);
	  OneDay(7, 155, 72 , 4 ,22 , 33);
	  OneDay(7, 190, 19 , 5 ,24 , 37);
	  OneDay(7, 225, 27 , 6 ,18 , 29);
	  OneDay(7, 260, 35 , 7 ,12 , 26);
	  OneDay(7, 295, 65 , 8 ,27 ,39);


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
