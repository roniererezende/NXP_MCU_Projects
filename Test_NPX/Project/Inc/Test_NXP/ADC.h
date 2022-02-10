#ifndef _TEST_NXP_ADC_H
#define _TEST_NXP_ADC_H

/*******************************************************************************
 * Definitions
 ******************************************************************************/


typedef struct s_ADC
{
	uint16_t Value;
	adc16_config_t ADC_16_Config;
	adc16_channel_config_t adc_16_Channel_Config;
}s_ADC;

void ADC_Init(void);
void ADC_Conversion(void);

#endif
