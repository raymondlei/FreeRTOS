################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Common_Demo/Minimal/GenQTest.c \
../Common_Demo/Minimal/QPeek.c \
../Common_Demo/Minimal/blocktim.c \
../Common_Demo/Minimal/countsem.c \
../Common_Demo/Minimal/crflash.c \
../Common_Demo/Minimal/crhook.c \
../Common_Demo/Minimal/recmutex.c 

OBJS += \
./Common_Demo/Minimal/GenQTest.o \
./Common_Demo/Minimal/QPeek.o \
./Common_Demo/Minimal/blocktim.o \
./Common_Demo/Minimal/countsem.o \
./Common_Demo/Minimal/crflash.o \
./Common_Demo/Minimal/crhook.o \
./Common_Demo/Minimal/recmutex.o 

C_DEPS += \
./Common_Demo/Minimal/GenQTest.d \
./Common_Demo/Minimal/QPeek.d \
./Common_Demo/Minimal/blocktim.d \
./Common_Demo/Minimal/countsem.d \
./Common_Demo/Minimal/crflash.d \
./Common_Demo/Minimal/crhook.d \
./Common_Demo/Minimal/recmutex.d 


# Each subdirectory must supply rules for building sources it contributes
Common_Demo/Minimal/%.o: ../Common_Demo/Minimal/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/FreeRTOS_Kernel/include" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/AsyncIO" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/FreeRTOS_Kernel/portable/GCC/Posix" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/Common_Demo/include" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


