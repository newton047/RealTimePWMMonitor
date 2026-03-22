################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SelfTestMode/TestModeEnterButton/test_mode_enter_button.c 

OBJS += \
./SelfTestMode/TestModeEnterButton/test_mode_enter_button.o 

C_DEPS += \
./SelfTestMode/TestModeEnterButton/test_mode_enter_button.d 


# Each subdirectory must supply rules for building sources it contributes
SelfTestMode/TestModeEnterButton/%.o SelfTestMode/TestModeEnterButton/%.su SelfTestMode/TestModeEnterButton/%.cyclo: ../SelfTestMode/TestModeEnterButton/%.c SelfTestMode/TestModeEnterButton/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401xE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../CMSIS/Device/Include -I../CMSIS/Include -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/UserLed" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SelfTestMode-2f-TestModeEnterButton

clean-SelfTestMode-2f-TestModeEnterButton:
	-$(RM) ./SelfTestMode/TestModeEnterButton/test_mode_enter_button.cyclo ./SelfTestMode/TestModeEnterButton/test_mode_enter_button.d ./SelfTestMode/TestModeEnterButton/test_mode_enter_button.o ./SelfTestMode/TestModeEnterButton/test_mode_enter_button.su

.PHONY: clean-SelfTestMode-2f-TestModeEnterButton

