#include "Gameboard.h"

/**
 * Setup NVIC, GCLK, and WDT.
 * This function is called once when the Arduino is initialized.
 */
void setupWatchdogTimer() {
  // Clear and enable WDT
  NVIC_DisableIRQ(WDT_IRQn);
  NVIC_ClearPendingIRQ(WDT_IRQn);
  NVIC_SetPriority(WDT_IRQn, 0);
  NVIC_EnableIRQ(WDT_IRQn);

  // Configure and enable WDT GCLK:
  GCLK->GENDIV.reg = GCLK_GENDIV_DIV(4) | GCLK_GENDIV_ID(5);
  while (GCLK->STATUS.bit.SYNCBUSY);
  // set GCLK->GENCTRL.reg and GCLK->CLKCTRL.reg
  GCLK->GENCTRL.reg = GCLK_GENCTRL_DIVSEL | GCLK_GENCTRL_GENEN | GCLK_GENCTRL_SRC(3) | GCLK_GENCTRL_ID(5);
  while (GCLK->STATUS.bit.SYNCBUSY);
  GCLK->CLKCTRL.reg = GCLK_CLKCTRL_GEN(5) | GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_ID(3);
  while (GCLK->STATUS.bit.SYNCBUSY);

  // Configure WDT:
  WDT->CONFIG.reg = WDT_CONFIG_PER(9);
  WDT->EWCTRL.reg = 8;

  Serial.println("WDT setup complete");
}

/**
 * Enables the WDT, which will reboot the Arduino if it is not reset periodically.
 * Called when the game/song starts.
 */
void enableWatchdogTimer() {
  WDT->CTRL.bit.ENABLE = 1;
  while (WDT->STATUS.bit.SYNCBUSY);
  WDT->INTENSET.bit.EW = 1;

  Serial.println("WDT enabled");
}

/**
 * Disables the WDT, which will prevent the Arduino from rebooting.
 * Called when the game/song ends.
 */
void disableWatchdogTimer() {
  WDT->CTRL.bit.ENABLE = 0;
  WDT->INTENCLR.bit.EW = 0;

  Serial.println("WDT disabled");
}

/**
 * Resets the WDT, which prevents the Arduino from rebooting.
 * Called periodically during the game/song on each beat.
 */
void resetWatchdogTimer() {
  WDT->CLEAR.reg = 0xA5;
  // Serial.println("WDT reset");
}

/**
 * WDT interrupt handler. Called when the WDT is about to reset the Arduino.
 */
void WDT_Handler() {
  WDT->INTFLAG.reg = WDT_INTFLAG_EW;
  Serial.println("WDT Interrupt (WDT reset imminent)");
}
