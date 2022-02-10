#ifndef _TEST_NXP_H
#define _TEST_NXP_H

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"
#include "fsl_adc16.h"

#include "Interrupt.h"
#include "ADC.h"
#include "PWM.h"

//#include "../../Inc/Test_NXP/Interrupt.h"

typedef enum e_Test_NXP_State
{
	E_Init,
	E_Execution
}e_Test_NXP_State;

typedef struct s_Test_NXP
{
	e_Test_NXP_State State;

	s_ADC ADC;
	s_PWM PWM;

	int16_t Timer_Counter;
	bool Timer_Interrupt_Flag;
	bool Led_State;
}s_Test_NXP;

extern s_Test_NXP Test_NXP;

void Test_NXP_Main(void);
void Test_NXP_Init(void);

#endif
