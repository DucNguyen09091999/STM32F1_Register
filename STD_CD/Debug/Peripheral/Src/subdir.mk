################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/Src/rcc.c 

OBJS += \
./Peripheral/Src/rcc.o 

C_DEPS += \
./Peripheral/Src/rcc.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/Src/%.o: ../Peripheral/Src/%.c Peripheral/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -c -I../Inc -I"D:/Git_Temple/STM32_F1_Register/STD_CD/Core/Inc" -I"D:/Git_Temple/STM32_F1_Register/STD_CD/CMSIS/Include" -I"D:/Git_Temple/STM32_F1_Register/STD_CD/Peripheral/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Peripheral-2f-Src

clean-Peripheral-2f-Src:
	-$(RM) ./Peripheral/Src/rcc.d ./Peripheral/Src/rcc.o

.PHONY: clean-Peripheral-2f-Src

