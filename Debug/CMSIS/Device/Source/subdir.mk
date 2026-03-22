################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/Device/Source/system_stm32f4xx.c 

OBJS += \
./CMSIS/Device/Source/system_stm32f4xx.o 

C_DEPS += \
./CMSIS/Device/Source/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/Device/Source/%.o CMSIS/Device/Source/%.su CMSIS/Device/Source/%.cyclo: ../CMSIS/Device/Source/%.c CMSIS/Device/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401xE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../CMSIS/Device/Include -I../CMSIS/Include -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/UserLed" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/Motor" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/ADCFeedback" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/UserInputButton" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/TimeBase" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/DebugPort" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CMSIS-2f-Device-2f-Source

clean-CMSIS-2f-Device-2f-Source:
	-$(RM) ./CMSIS/Device/Source/system_stm32f4xx.cyclo ./CMSIS/Device/Source/system_stm32f4xx.d ./CMSIS/Device/Source/system_stm32f4xx.o ./CMSIS/Device/Source/system_stm32f4xx.su

.PHONY: clean-CMSIS-2f-Device-2f-Source

