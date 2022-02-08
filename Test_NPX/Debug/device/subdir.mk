################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_MKL27Z644.c 

OBJS += \
./device/system_MKL27Z644.o 

C_DEPS += \
./device/system_MKL27Z644.d 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c device/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL27Z64VLH4 -DCPU_MKL27Z64VLH4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DFSL_RTOS_FREE_RTOS -DSDK_OS_FREE_RTOS -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"E:\Users\Roniere Resende\Documents\Meus Documentos\Estudo de Tecnologias\NXP Microcontrollers\Projects\Test_NPX\board" -I"E:\Users\Roniere Resende\Documents\Meus Documentos\Estudo de Tecnologias\NXP Microcontrollers\Projects\Test_NPX\source" -I"E:\Users\Roniere Resende\Documents\Meus Documentos\Estudo de Tecnologias\NXP Microcontrollers\Projects\Test_NPX\freertos\freertos_kernel\include" -I"E:\Users\Roniere Resende\Documents\Meus Documentos\Estudo de Tecnologias\NXP Microcontrollers\Projects\Test_NPX\freertos\template\ARM_CM0" -I"E:\Users\Roniere Resende\Documents\Meus Documentos\Estudo de Tecnologias\NXP Microcontrollers\Projects\Test_NPX\freertos\freertos_kernel\portable\GCC\ARM_CM0" -I"E:\Users\Roniere Resende\Documents\Meus Documentos\Estudo de Tecnologias\NXP Microcontrollers\Projects\Test_NPX\drivers" -I"E:\Users\Roniere Resende\Documents\Meus Documentos\Estudo de Tecnologias\NXP Microcontrollers\Projects\Test_NPX\drivers\freertos" -I"E:\Users\Roniere Resende\Documents\Meus Documentos\Estudo de Tecnologias\NXP Microcontrollers\Projects\Test_NPX\component\serial_manager" -I"E:\Users\Roniere Resende\Documents\Meus Documentos\Estudo de Tecnologias\NXP Microcontrollers\Projects\Test_NPX\component\uart" -I"E:\Users\Roniere Resende\Documents\Meus Documentos\Estudo de Tecnologias\NXP Microcontrollers\Projects\Test_NPX\utilities" -I"E:\Users\Roniere Resende\Documents\Meus Documentos\Estudo de Tecnologias\NXP Microcontrollers\Projects\Test_NPX\component\lists" -I"E:\Users\Roniere Resende\Documents\Meus Documentos\Estudo de Tecnologias\NXP Microcontrollers\Projects\Test_NPX\CMSIS" -I"E:\Users\Roniere Resende\Documents\Meus Documentos\Estudo de Tecnologias\NXP Microcontrollers\Projects\Test_NPX\device" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


