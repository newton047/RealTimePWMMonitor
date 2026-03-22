################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SelfTestMode/Motor/motor.c 

OBJS += \
./SelfTestMode/Motor/motor.o 

C_DEPS += \
./SelfTestMode/Motor/motor.d 


# Each subdirectory must supply rules for building sources it contributes
SelfTestMode/Motor/%.o SelfTestMode/Motor/%.su SelfTestMode/Motor/%.cyclo: ../SelfTestMode/Motor/%.c SelfTestMode/Motor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401xE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../CMSIS/Device/Include -I../CMSIS/Include -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/UserLed" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/Motor" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/ADCFeedback" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/UserInputButton" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/TimeBase" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/DebugPort" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SelfTestMode-2f-Motor

clean-SelfTestMode-2f-Motor:
	-$(RM) ./SelfTestMode/Motor/motor.cyclo ./SelfTestMode/Motor/motor.d ./SelfTestMode/Motor/motor.o ./SelfTestMode/Motor/motor.su

.PHONY: clean-SelfTestMode-2f-Motor

