################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ParTest/subdir.mk
-include FreeRTOS_Kernel/portable/MemMang/subdir.mk
-include FreeRTOS_Kernel/portable/GCC/Posix/subdir.mk
-include FreeRTOS_Kernel/subdir.mk
-include FileIO/subdir.mk
-include Common_Demo/Minimal/subdir.mk
-include Common_Demo/Full/subdir.mk
-include AsyncIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: FreeRTOS_gcc.a

# Tool invocations
FreeRTOS_gcc.a: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc  -o "FreeRTOS_gcc.a" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) FreeRTOS_gcc.a
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
