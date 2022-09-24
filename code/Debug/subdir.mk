################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../KPD_program.c \
../LCD_program.c \
../Timer_program.c \
../main_LearnRTOS.c \
../main_SnakeGame.c 

OBJS += \
./DIO_program.o \
./KPD_program.o \
./LCD_program.o \
./Timer_program.o \
./main_LearnRTOS.o \
./main_SnakeGame.o 

C_DEPS += \
./DIO_program.d \
./KPD_program.d \
./LCD_program.d \
./Timer_program.d \
./main_LearnRTOS.d \
./main_SnakeGame.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\programs system\imt_sdk\FREE_RTOS_test_rev\FreeRTOS" -I"D:\programs system\imt_sdk\FREE_RTOS_test_rev\FreeRTOS\include" -I"D:\programs system\imt_sdk\FREE_RTOS_test_rev\FreeRTOS\portable" -I"D:\programs system\imt_sdk\FREE_RTOS_test_rev\FreeRTOS\soucrce" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


