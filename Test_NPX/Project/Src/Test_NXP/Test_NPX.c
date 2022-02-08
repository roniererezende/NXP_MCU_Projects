#include <../Project/Inc/Test_NXP/Test_NXP.h>

s_Test_NXP Test_NXP;

void Test_NXP_Main(void)
{
	switch(Test_NXP.State)
	{
		case E_Init:
		    BOARD_InitBootPins();
		    BOARD_InitBootClocks();
		    BOARD_InitBootPeripherals();
		#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
		    /* Init FSL debug console. */
		    BOARD_InitDebugConsole();
		#endif
		    LPTMR_StartTimer(LPTMR0);
			Test_NXP.State = E_Execution;
			printf("Initialization Performed\n");
		break;

		case E_Execution:
			if(Test_NXP.Timer_Interrupt_Flag != false)
			{
				if(GPIO_PinRead(BOARD_BLUE_LED_GPIO, BOARD_BLUE_LED_PIN) == false)
				{
					GPIO_PinWrite(BOARD_BLUE_LED_GPIO, BOARD_BLUE_LED_PIN, true);
				}
				else
				{
					GPIO_PinWrite(BOARD_BLUE_LED_GPIO, BOARD_BLUE_LED_PIN, false);
				}
				GPIO_PortToggle(BOARD_WHITE_LED_GPIO, 1 << BOARD_WHITE_LED_PIN);
				GPIO_PortToggle(BOARD_RED_LED_GPIO, BOARD_RED_LED_PIN_MASK);
				Test_NXP.Timer_Interrupt_Flag = false;
			}

			if(GPIO_PinRead(BOARD_KEY_GPIO, BOARD_KEY_PIN) != false)
			{
				GPIO_PinWrite(BOARD_GREEN_LED_GPIO, BOARD_GREEN_LED_PIN, false);
			}
			else
			{
				GPIO_PinWrite(BOARD_GREEN_LED_GPIO, BOARD_GREEN_LED_PIN, true);
			}
			printf("Performing Execution\n");
		break;
	}
}
