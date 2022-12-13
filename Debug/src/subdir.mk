################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Casilla.cpp \
../src/Principal.cpp \
../src/RotaL.cpp \
../src/Tablero.cpp 

OBJS += \
./src/Casilla.o \
./src/Principal.o \
./src/RotaL.o \
./src/Tablero.o 

CPP_DEPS += \
./src/Casilla.d \
./src/Principal.d \
./src/RotaL.d \
./src/Tablero.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


