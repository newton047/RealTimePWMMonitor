################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SelfTestMode/UserInputButton/UserInputButton.c 

OBJS += \
./SelfTestMode/UserInputButton/UserInputButton.o 

C_DEPS += \
./SelfTestMode/UserInputButton/UserInputButton.d 


# Each subdirectory must supply rules for building sources it contributes
SelfTestMode/UserInputButton/%.o SelfTestMode/UserInputButton/%.su SelfTestMode/UserInputButton/%.cyclo: ../SelfTestMode/UserInputButton/%.c SelfTestMode/UserInputButton/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401xE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../CMSIS/Device/Include -I../CMSIS/Include -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/UserLed" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/Motor" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/ADCFeedback" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/UserInputButton" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/TimeBase" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/DebugPort" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SelfTestMode-2f-UserInputButton

clean-SelfTestMode-2f-UserInputButton:
	-$(RM) ./SelfTestMode/UserInputButton/UserInputButton.cyclo ./SelfTestMode/UserInputButton/UserInputButton.d ./SelfTestMode/UserInputButton/UserInputButton.o ./SelfTestMode/UserInputButton/UserInputButton.su

.PHONY: clean-SelfTestMode-2f-UserInputButton

