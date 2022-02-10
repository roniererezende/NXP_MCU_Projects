#ifndef _TEST_NXP_PWM_H
#define _TEST_NXP_PWM_H

#define  PWM_CHANNEL_1 1

#define   SENSE_DUTYCYCLE_INCREASE false
#define   SENSE_DUTYCYCLE_DECREASE true


typedef struct s_PWM
{
	tpm_config_t				Config;
	tpm_chnl_pwm_signal_param_t Param_Config;

	uint8_t updatedDutycycle;
	bool Dutycycle_Sense;
}s_PWM;

void PWM_Init(void);
void PWM_Signal_Releasing(void);

#endif
