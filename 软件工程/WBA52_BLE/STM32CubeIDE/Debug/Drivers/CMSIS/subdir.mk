################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/PersonalData/Prj/STM32Prj/WBA52/Core/Src/system_stm32wbaxx.c 

OBJS += \
./Drivers/CMSIS/system_stm32wbaxx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32wbaxx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32wbaxx.o: D:/PersonalData/Prj/STM32Prj/WBA52/Core/Src/system_stm32wbaxx.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32WBA52xx -c -I../../Core/Inc -I../../Drivers/STM32WBAxx_HAL_Driver/Inc -I../../Drivers/STM32WBAxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32WBAxx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS

clean-Drivers-2f-CMSIS:
	-$(RM) ./Drivers/CMSIS/system_stm32wbaxx.cyclo ./Drivers/CMSIS/system_stm32wbaxx.d ./Drivers/CMSIS/system_stm32wbaxx.o ./Drivers/CMSIS/system_stm32wbaxx.su

.PHONY: clean-Drivers-2f-CMSIS

