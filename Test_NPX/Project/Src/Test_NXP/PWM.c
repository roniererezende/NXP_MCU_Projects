#include <../Project/Inc/Test_NXP/Test_NXP.h>

void PWM_Init(void)
{
	Test_NXP.PWM.updatedDutycycle = 90;

	Test_NXP.PWM.Param_Config.chnlNumber = (tpm_chnl_t)PWM_CHANNEL_1;
	Test_NXP.PWM.Param_Config.level      = kTPM_HighTrue;
	Test_NXP.PWM.Param_Config.dutyCyclePercent = Test_NXP.PWM.updatedDutycycle;
}

void PWM_Signal_Releasing(void)
{
    /* Disable channel output before updating the dutycycle */
    TPM_UpdateChnlEdgeLevelSelect(TPM1_PERIPHERAL, Test_NXP.PWM.Param_Config.chnlNumber, 0U);

    /* Update PWM duty cycle */
    TPM_UpdatePwmDutycycle(TPM1_PERIPHERAL, Test_NXP.PWM.Param_Config.chnlNumber, kTPM_CenterAlignedPwm,
    					   Test_NXP.PWM.updatedDutycycle);

    /* Start channel output with updated dutycycle */
    TPM_UpdateChnlEdgeLevelSelect(TPM1_PERIPHERAL, Test_NXP.PWM.Param_Config.chnlNumber, Test_NXP.PWM.Param_Config.level);

    if(Test_NXP.PWM.Dutycycle_Sense == SENSE_DUTYCYCLE_INCREASE)
    {
    	Test_NXP.PWM.updatedDutycycle += 10;
    	if(Test_NXP.PWM.updatedDutycycle >= 100)
    	{
    		Test_NXP.PWM.Dutycycle_Sense = SENSE_DUTYCYCLE_DECREASE;
    	}

    }
    else if(Test_NXP.PWM.Dutycycle_Sense == SENSE_DUTYCYCLE_DECREASE)
    {
    	Test_NXP.PWM.updatedDutycycle -= 10;
    	if(Test_NXP.PWM.updatedDutycycle <= 0)
    	{
    		Test_NXP.PWM.Dutycycle_Sense = SENSE_DUTYCYCLE_INCREASE;
    	}
    }
}
