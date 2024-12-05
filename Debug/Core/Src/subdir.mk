################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/A.c \
../Core/Src/BackGround.c \
../Core/Src/BackGround2.c \
../Core/Src/Cloud1.c \
../Core/Src/Cloud2.c \
../Core/Src/STLogo.c \
../Core/Src/Tem.c \
../Core/Src/cJSON.c \
../Core/Src/calibrate.c \
../Core/Src/doC.c \
../Core/Src/font12.c \
../Core/Src/font16.c \
../Core/Src/font20.c \
../Core/Src/font24.c \
../Core/Src/font8.c \
../Core/Src/front_end.c \
../Core/Src/hot.c \
../Core/Src/humi.c \
../Core/Src/ice.c \
../Core/Src/icon1.c \
../Core/Src/icon2.c \
../Core/Src/icon3.c \
../Core/Src/ili9341.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/touch.c \
../Core/Src/tree.c \
../Core/Src/tree1.c \
../Core/Src/water.c \
../Core/Src/weather.c \
../Core/Src/wether.c \
../Core/Src/wind.c \
../Core/Src/yourname5.1.c \
../Core/Src/z6030061336714_5dbe1c34090d7e2346532e65515815be.c 

OBJS += \
./Core/Src/A.o \
./Core/Src/BackGround.o \
./Core/Src/BackGround2.o \
./Core/Src/Cloud1.o \
./Core/Src/Cloud2.o \
./Core/Src/STLogo.o \
./Core/Src/Tem.o \
./Core/Src/cJSON.o \
./Core/Src/calibrate.o \
./Core/Src/doC.o \
./Core/Src/font12.o \
./Core/Src/font16.o \
./Core/Src/font20.o \
./Core/Src/font24.o \
./Core/Src/font8.o \
./Core/Src/front_end.o \
./Core/Src/hot.o \
./Core/Src/humi.o \
./Core/Src/ice.o \
./Core/Src/icon1.o \
./Core/Src/icon2.o \
./Core/Src/icon3.o \
./Core/Src/ili9341.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/touch.o \
./Core/Src/tree.o \
./Core/Src/tree1.o \
./Core/Src/water.o \
./Core/Src/weather.o \
./Core/Src/wether.o \
./Core/Src/wind.o \
./Core/Src/yourname5.1.o \
./Core/Src/z6030061336714_5dbe1c34090d7e2346532e65515815be.o 

C_DEPS += \
./Core/Src/A.d \
./Core/Src/BackGround.d \
./Core/Src/BackGround2.d \
./Core/Src/Cloud1.d \
./Core/Src/Cloud2.d \
./Core/Src/STLogo.d \
./Core/Src/Tem.d \
./Core/Src/cJSON.d \
./Core/Src/calibrate.d \
./Core/Src/doC.d \
./Core/Src/font12.d \
./Core/Src/font16.d \
./Core/Src/font20.d \
./Core/Src/font24.d \
./Core/Src/font8.d \
./Core/Src/front_end.d \
./Core/Src/hot.d \
./Core/Src/humi.d \
./Core/Src/ice.d \
./Core/Src/icon1.d \
./Core/Src/icon2.d \
./Core/Src/icon3.d \
./Core/Src/ili9341.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/touch.d \
./Core/Src/tree.d \
./Core/Src/tree1.d \
./Core/Src/water.d \
./Core/Src/weather.d \
./Core/Src/wether.d \
./Core/Src/wind.d \
./Core/Src/yourname5.1.d \
./Core/Src/z6030061336714_5dbe1c34090d7e2346532e65515815be.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/A.cyclo ./Core/Src/A.d ./Core/Src/A.o ./Core/Src/A.su ./Core/Src/BackGround.cyclo ./Core/Src/BackGround.d ./Core/Src/BackGround.o ./Core/Src/BackGround.su ./Core/Src/BackGround2.cyclo ./Core/Src/BackGround2.d ./Core/Src/BackGround2.o ./Core/Src/BackGround2.su ./Core/Src/Cloud1.cyclo ./Core/Src/Cloud1.d ./Core/Src/Cloud1.o ./Core/Src/Cloud1.su ./Core/Src/Cloud2.cyclo ./Core/Src/Cloud2.d ./Core/Src/Cloud2.o ./Core/Src/Cloud2.su ./Core/Src/STLogo.cyclo ./Core/Src/STLogo.d ./Core/Src/STLogo.o ./Core/Src/STLogo.su ./Core/Src/Tem.cyclo ./Core/Src/Tem.d ./Core/Src/Tem.o ./Core/Src/Tem.su ./Core/Src/cJSON.cyclo ./Core/Src/cJSON.d ./Core/Src/cJSON.o ./Core/Src/cJSON.su ./Core/Src/calibrate.cyclo ./Core/Src/calibrate.d ./Core/Src/calibrate.o ./Core/Src/calibrate.su ./Core/Src/doC.cyclo ./Core/Src/doC.d ./Core/Src/doC.o ./Core/Src/doC.su ./Core/Src/font12.cyclo ./Core/Src/font12.d ./Core/Src/font12.o ./Core/Src/font12.su ./Core/Src/font16.cyclo ./Core/Src/font16.d ./Core/Src/font16.o ./Core/Src/font16.su ./Core/Src/font20.cyclo ./Core/Src/font20.d ./Core/Src/font20.o ./Core/Src/font20.su ./Core/Src/font24.cyclo ./Core/Src/font24.d ./Core/Src/font24.o ./Core/Src/font24.su ./Core/Src/font8.cyclo ./Core/Src/font8.d ./Core/Src/font8.o ./Core/Src/font8.su ./Core/Src/front_end.cyclo ./Core/Src/front_end.d ./Core/Src/front_end.o ./Core/Src/front_end.su ./Core/Src/hot.cyclo ./Core/Src/hot.d ./Core/Src/hot.o ./Core/Src/hot.su ./Core/Src/humi.cyclo ./Core/Src/humi.d ./Core/Src/humi.o ./Core/Src/humi.su ./Core/Src/ice.cyclo ./Core/Src/ice.d ./Core/Src/ice.o ./Core/Src/ice.su ./Core/Src/icon1.cyclo ./Core/Src/icon1.d ./Core/Src/icon1.o ./Core/Src/icon1.su ./Core/Src/icon2.cyclo ./Core/Src/icon2.d ./Core/Src/icon2.o ./Core/Src/icon2.su ./Core/Src/icon3.cyclo ./Core/Src/icon3.d ./Core/Src/icon3.o ./Core/Src/icon3.su ./Core/Src/ili9341.cyclo ./Core/Src/ili9341.d ./Core/Src/ili9341.o ./Core/Src/ili9341.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/touch.cyclo ./Core/Src/touch.d ./Core/Src/touch.o ./Core/Src/touch.su ./Core/Src/tree.cyclo ./Core/Src/tree.d ./Core/Src/tree.o ./Core/Src/tree.su ./Core/Src/tree1.cyclo ./Core/Src/tree1.d ./Core/Src/tree1.o ./Core/Src/tree1.su ./Core/Src/water.cyclo ./Core/Src/water.d ./Core/Src/water.o ./Core/Src/water.su ./Core/Src/weather.cyclo ./Core/Src/weather.d ./Core/Src/weather.o ./Core/Src/weather.su ./Core/Src/wether.cyclo ./Core/Src/wether.d ./Core/Src/wether.o ./Core/Src/wether.su ./Core/Src/wind.cyclo ./Core/Src/wind.d ./Core/Src/wind.o ./Core/Src/wind.su ./Core/Src/yourname5.1.cyclo ./Core/Src/yourname5.1.d ./Core/Src/yourname5.1.o ./Core/Src/yourname5.1.su ./Core/Src/z6030061336714_5dbe1c34090d7e2346532e65515815be.cyclo ./Core/Src/z6030061336714_5dbe1c34090d7e2346532e65515815be.d ./Core/Src/z6030061336714_5dbe1c34090d7e2346532e65515815be.o ./Core/Src/z6030061336714_5dbe1c34090d7e2346532e65515815be.su

.PHONY: clean-Core-2f-Src

