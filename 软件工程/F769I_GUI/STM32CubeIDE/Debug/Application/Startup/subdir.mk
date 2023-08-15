################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# 将这些工具调用的输入和输出添加到构建变量 
S_SRCS += \
../Application/Startup/startup_stm32f769nihx.s 

S_DEPS += \
./Application/Startup/startup_stm32f769nihx.d 

OBJS += \
./Application/Startup/startup_stm32f769nihx.o 


# 每个子目录必须为构建它所贡献的源提供规则
Application/Startup/%.o: ../Application/Startup/%.s Application/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Application-2f-Startup

clean-Application-2f-Startup:
	-$(RM) ./Application/Startup/startup_stm32f769nihx.d ./Application/Startup/startup_stm32f769nihx.o

.PHONY: clean-Application-2f-Startup

