################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SelfTestMode/UserLed/user_led.c 

OBJS += \
./SelfTestMode/UserLed/user_led.o 

C_DEPS += \
./SelfTestMode/UserLed/user_led.d 


# Each subdirectory must supply rules for building sources it contributes
SelfTestMode/UserLed/%.o SelfTestMode/UserLed/%.su SelfTestMode/UserLed/%.cyclo: ../SelfTestMode/UserLed/%.c SelfTestMode/UserLed/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401xE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../CMSIS/Device/Include -I../CMSIS/Include -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/UserLed" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/Motor" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/ADCFeedback" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/UserInputButton" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/TimeBase" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/DebugPort" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SelfTestMode-2f-UserLed

clean-SelfTestMode-2f-UserLed:
	-$(RM) ./SelfTestMode/UserLed/user_led.cyclo ./SelfTestMode/UserLed/user_led.d ./SelfTestMode/UserLed/user_led.o ./SelfTestMode/UserLed/user_led.su

.PHONY: clean-SelfTestMode-2f-UserLed

