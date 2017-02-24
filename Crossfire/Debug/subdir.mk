################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sorting-Algorithm.c \
../fileIO.c \
../main.c \
../shuffle.c \
../slotsIO.c \
../sortslots.c 

OBJS += \
./Sorting-Algorithm.o \
./fileIO.o \
./main.o \
./shuffle.o \
./slotsIO.o \
./sortslots.o 

C_DEPS += \
./Sorting-Algorithm.d \
./fileIO.d \
./main.d \
./shuffle.d \
./slotsIO.d \
./sortslots.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


