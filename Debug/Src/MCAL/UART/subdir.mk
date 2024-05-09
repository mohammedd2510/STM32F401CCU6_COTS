################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/UART/UART_Lcfg.c \
../Src/MCAL/UART/UART_program.c 

OBJS += \
./Src/MCAL/UART/UART_Lcfg.o \
./Src/MCAL/UART/UART_program.o 

C_DEPS += \
./Src/MCAL/UART/UART_Lcfg.d \
./Src/MCAL/UART/UART_program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/UART/%.o Src/MCAL/UART/%.su Src/MCAL/UART/%.cyclo: ../Src/MCAL/UART/%.c Src/MCAL/UART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-UART

clean-Src-2f-MCAL-2f-UART:
	-$(RM) ./Src/MCAL/UART/UART_Lcfg.cyclo ./Src/MCAL/UART/UART_Lcfg.d ./Src/MCAL/UART/UART_Lcfg.o ./Src/MCAL/UART/UART_Lcfg.su ./Src/MCAL/UART/UART_program.cyclo ./Src/MCAL/UART/UART_program.d ./Src/MCAL/UART/UART_program.o ./Src/MCAL/UART/UART_program.su

.PHONY: clean-Src-2f-MCAL-2f-UART

