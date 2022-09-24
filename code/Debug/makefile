################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include FreeRTOS/soucrce/subdir.mk
-include FreeRTOS/portable/subdir.mk
-include FreeRTOS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
FREE_RTOS_test_rev.lss \
FREE_RTOS_test_rev.lss \
FREE_RTOS_test_rev.lss \
FREE_RTOS_test_rev.lss \
FREE_RTOS_test_rev.lss \

FLASH_IMAGE += \
FREE_RTOS_test_rev.hex \

SIZEDUMMY += \
sizedummy \
sizedummy \
sizedummy \
sizedummy \
sizedummy \


# All Target
all: FREE_RTOS_test_rev.elf secondary-outputs

# Tool invocations
FREE_RTOS_test_rev.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,FREE_RTOS_test_rev.map -mmcu=atmega32 -o "FREE_RTOS_test_rev.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

FREE_RTOS_test_rev.lss: FREE_RTOS_test_rev.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S FREE_RTOS_test_rev.elf  >"FREE_RTOS_test_rev.lss"
	@echo 'Finished building: $@'
	@echo ' '

FREE_RTOS_test_rev.hex: FREE_RTOS_test_rev.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex FREE_RTOS_test_rev.elf  "FREE_RTOS_test_rev.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: FREE_RTOS_test_rev.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 FREE_RTOS_test_rev.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) FREE_RTOS_test_rev.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
