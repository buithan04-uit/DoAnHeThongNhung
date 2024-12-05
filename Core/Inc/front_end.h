/*
 * front_end.h
 *
 *  Created on: Nov 27, 2024
 *      Author: buith
 */

#ifndef INC_FRONT_END_H_
#define INC_FRONT_END_H_

#include "ili9341.h"
#include "math.h"

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
void Screen2(int Max_temp[] , int Min_temp[] , int day_code[] , char day_name[][4] , int Wind_speed[] , char date[][6]);


void TextTitle(int16_t x, int16_t y);
void TableMain (int16_t x, int16_t y ,int temperature , int huminity );
void WeatherDay (int x , int y );
void TextTemperature16 (int x , int y , int temperature);
void TextHumidyti16 (int x , int y , int humidyti);
void OneDay(int x , int y, int MinTem , int MaxTem , int wind , char day_name[] , int day_code , char date[]);
void TextTime(int x , int y);
void TextDate(int x , int y);
void TextLocation(int x , int y);
void TextSensor(int x , int y);

//Draw Icon
void DrawIconHumidyti1 (int x, int y);
void DrawIconDate (int x, int y);
void DrawIconWeather (int x, int y);
void DrawIconTem (int x, int y);
void DrawIconWind (int x, int y);
void DrawIconHot (int x, int y);
void DrawIconIce (int x, int y);
void DrawIconTree (int x, int y);
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


#endif /* INC_FRONT_END_H_ */
