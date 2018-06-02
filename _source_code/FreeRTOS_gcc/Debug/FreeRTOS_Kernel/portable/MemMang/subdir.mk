################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Kernel/portable/MemMang/heap_3.c 

OBJS += \
./FreeRTOS_Kernel/portable/MemMang/heap_3.o 

C_DEPS += \
./FreeRTOS_Kernel/portable/MemMang/heap_3.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Kernel/portable/MemMang/%.o: ../FreeRTOS_Kernel/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/FreeRTOS_Kernel/include" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/AsyncIO" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/FreeRTOS_Kernel/portable/GCC/Posix" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/Common_Demo/include" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


