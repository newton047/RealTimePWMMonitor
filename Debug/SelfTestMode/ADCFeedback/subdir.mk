################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SelfTestMode/ADCFeedback/LUT.c \
../SelfTestMode/ADCFeedback/filter.c \
../SelfTestMode/ADCFeedback/intadc.c 

OBJS += \
./SelfTestMode/ADCFeedback/LUT.o \
./SelfTestMode/ADCFeedback/filter.o \
./SelfTestMode/ADCFeedback/intadc.o 

C_DEPS += \
./SelfTestMode/ADCFeedback/LUT.d \
./SelfTestMode/ADCFeedback/filter.d \
./SelfTestMode/ADCFeedback/intadc.d 


# Each subdirectory must supply rules for building sources it contributes
SelfTestMode/ADCFeedback/%.o SelfTestMode/ADCFeedback/%.su SelfTestMode/ADCFeedback/%.cyclo: ../SelfTestMode/ADCFeedback/%.c SelfTestMode/ADCFeedback/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401xE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../CMSIS/Device/Include -I../CMSIS/Include -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/UserLed" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/Motor" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/ADCFeedback" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/UserInputButton" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/TimeBase" -I"D:/Newton/Project/Hill_ctll/wrk_spc/Hill_Control_Proto/SelfTestMode/DebugPort" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-SelfTestMode-2f-ADCFeedback

clean-SelfTestMode-2f-ADCFeedback:
	-$(RM) ./SelfTestMode/ADCFeedback/LUT.cyclo ./SelfTestMode/ADCFeedback/LUT.d ./SelfTestMode/ADCFeedback/LUT.o ./SelfTestMode/ADCFeedback/LUT.su ./SelfTestMode/ADCFeedback/filter.cyclo ./SelfTestMode/ADCFeedback/filter.d ./SelfTestMode/ADCFeedback/filter.o ./SelfTestMode/ADCFeedback/filter.su ./SelfTestMode/ADCFeedback/intadc.cyclo ./SelfTestMode/ADCFeedback/intadc.d ./SelfTestMode/ADCFeedback/intadc.o ./SelfTestMode/ADCFeedback/intadc.su

.PHONY: clean-SelfTestMode-2f-ADCFeedback

