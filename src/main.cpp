#include <Arduino.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

#include "bl.h"

void setup()
{
  //Fix for crash on network initialization
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
  bl_init();
}

void loop()
{
  bl_process();
}
