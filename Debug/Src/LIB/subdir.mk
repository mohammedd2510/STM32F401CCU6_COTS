################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/LIB/Delay.c 

OBJS += \
./Src/LIB/Delay.o 

C_DEPS += \
./Src/LIB/Delay.d 


# Each subdirectory must supply rules for building sources it contributes
Src/LIB/%.o Src/LIB/%.su Src/LIB/%.cyclo: ../Src/LIB/%.c Src/LIB/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-LIB

clean-Src-2f-LIB:
	-$(RM) ./Src/LIB/Delay.cyclo ./Src/LIB/Delay.d ./Src/LIB/Delay.o ./Src/LIB/Delay.su

.PHONY: clean-Src-2f-LIB

