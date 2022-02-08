
#include <../Project/Inc/Test_NXP/Test_NXP.h>

/* LPTMR0_IRQn interrupt handler */
void Timer_Interrupt(void) {
  uint32_t intStatus;
  /* Reading all interrupt flags of status register */
  intStatus = LPTMR_GetStatusFlags(LPTMR0_PERIPHERAL);
  LPTMR_ClearStatusFlags(LPTMR0_PERIPHERAL, intStatus);

  /* Place your code here */
  Test_NXP.Timer_Interrupt_Flag = true;

  /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
     Store immediate overlapping exception return operation might vector to incorrect interrupt. */
  #if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}
