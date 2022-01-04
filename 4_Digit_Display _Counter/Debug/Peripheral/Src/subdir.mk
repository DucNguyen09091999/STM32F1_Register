################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/Src/gpio.c \
../Peripheral/Src/rcc.c \
../Peripheral/Src/uart.c 

OBJS += \
./Peripheral/Src/gpio.o \
./Peripheral/Src/rcc.o \
./Peripheral/Src/uart.o 

C_DEPS += \
./Peripheral/Src/gpio.d \
./Peripheral/Src/rcc.d \
./Peripheral/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/Src/%.o: ../Peripheral/Src/%.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I../Inc -I"D:/Git_Temple/STM32_F1_Register/4_Digit_Display _Counter/CMSIS/Include" -I"D:/Git_Temple/STM32_F1_Register/4_Digit_Display _Counter/Core/Inc" -I"D:/Git_Temple/STM32_F1_Register/4_Digit_Display _Counter/Peripheral/Inc" -I"D:/Git_Temple/STM32_F1_Register/4_Digit_Display _Counter/Application/4_digit_display/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Peripheral-2f-Src

clean-Peripheral-2f-Src:
	-$(RM) ./Peripheral/Src/gpio.d ./Peripheral/Src/gpio.o ./Peripheral/Src/rcc.d ./Peripheral/Src/rcc.o ./Peripheral/Src/uart.d ./Peripheral/Src/uart.o

.PHONY: clean-Peripheral-2f-Src

