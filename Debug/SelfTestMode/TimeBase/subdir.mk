################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SelfTestMode/TimeBase/timebase.c 

OBJS += \
./SelfTestMode/TimeBase/timebase.o 

C_DEPS += \
./SelfTestMode/TimeBase/timebase.d 


# Each subdirectory must supply rules for building sources it contributes
SelfTestMode/TimeBase/%.o SelfTestMode/TimeBase/%.su SelfTestMode/TimeBase/%.cyclo: ../SelfTestMode/TimeBase/%.c SelfTestMode/TimeBase/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401xE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../CMSIS/Device/Include -I../CMSIS/Include -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/UserLed" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/Motor" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/ADCFeedback" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/UserInputButton" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/TimeBase" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/DebugPort" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SelfTestMode-2f-TimeBase

clean-SelfTestMode-2f-TimeBase:
	-$(RM) ./SelfTestMode/TimeBase/timebase.cyclo ./SelfTestMode/TimeBase/timebase.d ./SelfTestMode/TimeBase/timebase.o ./SelfTestMode/TimeBase/timebase.su

.PHONY: clean-SelfTestMode-2f-TimeBase

