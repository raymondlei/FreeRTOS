################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FileIO/fileIO.c 

OBJS += \
./FileIO/fileIO.o 

C_DEPS += \
./FileIO/fileIO.d 


# Each subdirectory must supply rules for building sources it contributes
FileIO/%.o: ../FileIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/FreeRTOS_Kernel/include" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/AsyncIO" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/FreeRTOS_Kernel/portable/GCC/Posix" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/Common_Demo/include" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


