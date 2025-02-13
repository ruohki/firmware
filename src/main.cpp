#include <Arduino.h>

#if WAVESHARE_BOARD
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#endif

#include "bl.h"

void setup()
{
  #if WAVESHARE_BOARD
  //Fix for crash on network initialization
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
  #endif
  bl_init();
}

void loop()
{
  bl_process();
}
