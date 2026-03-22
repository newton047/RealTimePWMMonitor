################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SelfTestMode/TestModeEnterPin/test_mode_enter_pin.c 

OBJS += \
./SelfTestMode/TestModeEnterPin/test_mode_enter_pin.o 

C_DEPS += \
./SelfTestMode/TestModeEnterPin/test_mode_enter_pin.d 


# Each subdirectory must supply rules for building sources it contributes
SelfTestMode/TestModeEnterPin/%.o SelfTestMode/TestModeEnterPin/%.su SelfTestMode/TestModeEnterPin/%.cyclo: ../SelfTestMode/TestModeEnterPin/%.c SelfTestMode/TestModeEnterPin/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401xE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../CMSIS/Device/Include -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/TestModeEnterPin" -I../CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SelfTestMode-2f-TestModeEnterPin

clean-SelfTestMode-2f-TestModeEnterPin:
	-$(RM) ./SelfTestMode/TestModeEnterPin/test_mode_enter_pin.cyclo ./SelfTestMode/TestModeEnterPin/test_mode_enter_pin.d ./SelfTestMode/TestModeEnterPin/test_mode_enter_pin.o ./SelfTestMode/TestModeEnterPin/test_mode_enter_pin.su

.PHONY: clean-SelfTestMode-2f-TestModeEnterPin

