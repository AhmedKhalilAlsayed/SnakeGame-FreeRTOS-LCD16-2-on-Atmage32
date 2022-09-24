################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/port.c 

OBJS += \
./FreeRTOS/portable/port.o 

C_DEPS += \
./FreeRTOS/portable/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/%.o: ../FreeRTOS/portable/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\programs system\imt_sdk\FREE_RTOS_test_rev\FreeRTOS" -I"D:\programs system\imt_sdk\FREE_RTOS_test_rev\FreeRTOS\include" -I"D:\programs system\imt_sdk\FREE_RTOS_test_rev\FreeRTOS\portable" -I"D:\programs system\imt_sdk\FREE_RTOS_test_rev\FreeRTOS\soucrce" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


