################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Kernel/croutine.c \
../FreeRTOS_Kernel/list.c \
../FreeRTOS_Kernel/queue.c \
../FreeRTOS_Kernel/tasks.c 

OBJS += \
./FreeRTOS_Kernel/croutine.o \
./FreeRTOS_Kernel/list.o \
./FreeRTOS_Kernel/queue.o \
./FreeRTOS_Kernel/tasks.o 

C_DEPS += \
./FreeRTOS_Kernel/croutine.d \
./FreeRTOS_Kernel/list.d \
./FreeRTOS_Kernel/queue.d \
./FreeRTOS_Kernel/tasks.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Kernel/%.o: ../FreeRTOS_Kernel/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/FreeRTOS_Kernel/include" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/AsyncIO" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/FreeRTOS_Kernel/portable/GCC/Posix" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/Common_Demo/include" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


