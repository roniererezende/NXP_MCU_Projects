
#include <../Project/Inc/Test_NXP/Test_NXP.h>

void ADC_Init(void)
{
	memcpy(&Test_NXP.ADC.adc_16_Channel_Config, &ADC_channelsConfig[0], sizeof(ADC_channelsConfig[0]));
}

void ADC_Conversion(void)
{
    ADC16_SetChannelConfig(ADC_PERIPHERAL, ADC_CH0_CONTROL_GROUP, &Test_NXP.ADC.adc_16_Channel_Config);
    while (0U == (kADC16_ChannelConversionDoneFlag &
                  ADC16_GetChannelStatusFlags(ADC_PERIPHERAL, ADC_CH0_CONTROL_GROUP)))
    {
    }

    Test_NXP.ADC.Value = ADC16_GetChannelConversionValue(ADC_PERIPHERAL, ADC_CH0_CONTROL_GROUP);
}
