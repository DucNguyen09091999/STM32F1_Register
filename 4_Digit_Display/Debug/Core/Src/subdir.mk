################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/printf_redirect.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/main.o \
./Core/Src/printf_redirect.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/printf_redirect.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I../Inc -I"D:/Git_Temple/STM32_F1_Register/4_Digit_Display/CMSIS/Include" -I"D:/Git_Temple/STM32_F1_Register/4_Digit_Display/Core/Inc" -I"D:/Git_Temple/STM32_F1_Register/4_Digit_Display/Peripheral/Inc" -I"D:/Git_Temple/STM32_F1_Register/4_Digit_Display/Application/4_digit_display/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/printf_redirect.d ./Core/Src/printf_redirect.o ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o

.PHONY: clean-Core-2f-Src

