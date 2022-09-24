################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/soucrce/croutine.c \
../FreeRTOS/soucrce/list.c \
../FreeRTOS/soucrce/queue.c \
../FreeRTOS/soucrce/tasks.c \
../FreeRTOS/soucrce/timers.c 

OBJS += \
./FreeRTOS/soucrce/croutine.o \
./FreeRTOS/soucrce/list.o \
./FreeRTOS/soucrce/queue.o \
./FreeRTOS/soucrce/tasks.o \
./FreeRTOS/soucrce/timers.o 

C_DEPS += \
./FreeRTOS/soucrce/croutine.d \
./FreeRTOS/soucrce/list.d \
./FreeRTOS/soucrce/queue.d \
./FreeRTOS/soucrce/tasks.d \
./FreeRTOS/soucrce/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/soucrce/%.o: ../FreeRTOS/soucrce/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\programs system\imt_sdk\FREE_RTOS_test_rev\FreeRTOS" -I"D:\programs system\imt_sdk\FREE_RTOS_test_rev\FreeRTOS\include" -I"D:\programs system\imt_sdk\FREE_RTOS_test_rev\FreeRTOS\portable" -I"D:\programs system\imt_sdk\FREE_RTOS_test_rev\FreeRTOS\soucrce" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


