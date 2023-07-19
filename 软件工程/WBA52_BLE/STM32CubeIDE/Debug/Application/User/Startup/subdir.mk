################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Application/User/Startup/startup_stm32wba52cgux.s 

OBJS += \
./Application/User/Startup/startup_stm32wba52cgux.o 

S_DEPS += \
./Application/User/Startup/startup_stm32wba52cgux.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Startup/%.o: ../Application/User/Startup/%.s Application/User/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m33 -g -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Application-2f-User-2f-Startup

clean-Application-2f-User-2f-Startup:
	-$(RM) ./Application/User/Startup/startup_stm32wba52cgux.d ./Application/User/Startup/startup_stm32wba52cgux.o

.PHONY: clean-Application-2f-User-2f-Startup

