################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Common_Demo/Full/BlockQ.c \
../Common_Demo/Full/PollQ.c \
../Common_Demo/Full/death.c \
../Common_Demo/Full/dynamic.c \
../Common_Demo/Full/events.c \
../Common_Demo/Full/flash.c \
../Common_Demo/Full/flop.c \
../Common_Demo/Full/integer.c \
../Common_Demo/Full/print.c \
../Common_Demo/Full/semtest.c 

OBJS += \
./Common_Demo/Full/BlockQ.o \
./Common_Demo/Full/PollQ.o \
./Common_Demo/Full/death.o \
./Common_Demo/Full/dynamic.o \
./Common_Demo/Full/events.o \
./Common_Demo/Full/flash.o \
./Common_Demo/Full/flop.o \
./Common_Demo/Full/integer.o \
./Common_Demo/Full/print.o \
./Common_Demo/Full/semtest.o 

C_DEPS += \
./Common_Demo/Full/BlockQ.d \
./Common_Demo/Full/PollQ.d \
./Common_Demo/Full/death.d \
./Common_Demo/Full/dynamic.d \
./Common_Demo/Full/events.d \
./Common_Demo/Full/flash.d \
./Common_Demo/Full/flop.d \
./Common_Demo/Full/integer.d \
./Common_Demo/Full/print.d \
./Common_Demo/Full/semtest.d 


# Each subdirectory must supply rules for building sources it contributes
Common_Demo/Full/%.o: ../Common_Demo/Full/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/FreeRTOS_Kernel/include" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/AsyncIO" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/FreeRTOS_Kernel/portable/GCC/Posix" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/Common_Demo/include" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


