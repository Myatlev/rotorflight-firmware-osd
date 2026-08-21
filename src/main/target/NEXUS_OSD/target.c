/*
 * RadioMaster Nexus OSD — timer map from RDMS-NEXUS_F7.config
 */

#include <stdint.h>

#include "platform.h"
#include "drivers/io.h"
#include "drivers/dma.h"
#include "drivers/timer.h"
#include "drivers/timer_def.h"

const timerHardware_t timerHardware[USABLE_TIMER_CHANNEL_COUNT] = {
    DEF_TIM(TIM9,  CH2, PA3,  TIM_USE_PPM,   0, 0), // SBUS / PPM on UART2 RX pin
    DEF_TIM(TIM4,  CH1, PB6,  TIM_USE_MOTOR, 0, 0), // M1 (main)
    DEF_TIM(TIM3,  CH1, PB4,  TIM_USE_SERVO, 0, 0), // S1
    DEF_TIM(TIM3,  CH2, PB5,  TIM_USE_SERVO, 0, 0), // S2
    DEF_TIM(TIM3,  CH3, PB0,  TIM_USE_SERVO, 0, 0), // S3
    DEF_TIM(TIM2,  CH2, PB3,  TIM_USE_SERVO, 0, 0), // S4 / tail
    DEF_TIM(TIM5,  CH3, PA2,  TIM_USE_FREQ,  0, 0), // RPM frequency input
};
