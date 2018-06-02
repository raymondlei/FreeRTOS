################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AsyncIO/AsyncIO.c \
../AsyncIO/AsyncIOSerial.c \
../AsyncIO/AsyncIOSocket.c \
../AsyncIO/PosixMessageQueueIPC.c 

OBJS += \
./AsyncIO/AsyncIO.o \
./AsyncIO/AsyncIOSerial.o \
./AsyncIO/AsyncIOSocket.o \
./AsyncIO/PosixMessageQueueIPC.o 

C_DEPS += \
./AsyncIO/AsyncIO.d \
./AsyncIO/AsyncIOSerial.d \
./AsyncIO/AsyncIOSocket.d \
./AsyncIO/PosixMessageQueueIPC.d 


# Each subdirectory must supply rules for building sources it contributes
AsyncIO/%.o: ../AsyncIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/FreeRTOS_Kernel/include" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/AsyncIO" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/FreeRTOS_Kernel/portable/GCC/Posix" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc/Common_Demo/include" -I"/home/intel/src/myGitHub/_source_code/FreeRTOS_gcc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


