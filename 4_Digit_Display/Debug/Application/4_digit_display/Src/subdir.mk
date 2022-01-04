################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/4_digit_display/Src/tm1637.c 

OBJS += \
./Application/4_digit_display/Src/tm1637.o 

C_DEPS += \
./Application/4_digit_display/Src/tm1637.d 


# Each subdirectory must supply rules for building sources it contributes
Application/4_digit_display/Src/%.o: ../Application/4_digit_display/Src/%.c Application/4_digit_display/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I../Inc -I"D:/Git_Temple/STM32_F1_Register/4_Digit_Display/CMSIS/Include" -I"D:/Git_Temple/STM32_F1_Register/4_Digit_Display/Core/Inc" -I"D:/Git_Temple/STM32_F1_Register/4_Digit_Display/Peripheral/Inc" -I"D:/Git_Temple/STM32_F1_Register/4_Digit_Display/Application/4_digit_display/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-4_digit_display-2f-Src

clean-Application-2f-4_digit_display-2f-Src:
	-$(RM) ./Application/4_digit_display/Src/tm1637.d ./Application/4_digit_display/Src/tm1637.o

.PHONY: clean-Application-2f-4_digit_display-2f-Src

