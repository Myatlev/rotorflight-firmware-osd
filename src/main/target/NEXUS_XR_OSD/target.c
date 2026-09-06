/*
 * RadioMaster Nexus-XR OSD — timer map from RDMS-NEXUS_XR.config
 */

#include <stdint.h>

#include "platform.h"
#include "drivers/io.h"
#include "drivers/dma.h"
#include "drivers/timer.h"
#include "drivers/timer_def.h"

const timerHardware_t timerHardware[USABLE_TIMER_CHANNEL_COUNT] = {
    DEF_TIM(TIM9,  CH2, PA3,  TIM_USE_PPM,   0, 0), // SBUS / PPM on UART2 RX pin
    DEF_TIM(TIM1,  CH2, PA9,  TIM_USE_MOTOR, 0, 0), // M1 (main)   DMA2 S6 C0
    DEF_TIM(TIM3,  CH1, PB4,  TIM_USE_SERVO, 0, 0), // S1
    DEF_TIM(TIM3,  CH2, PB5,  TIM_USE_SERVO, 0, 0), // S2
    DEF_TIM(TIM3,  CH3, PB0,  TIM_USE_SERVO, 0, 0), // S3
    DEF_TIM(TIM2,  CH1, PA15, TIM_USE_SERVO, 0, 0), // S4 / tail  (alt. M2)
    DEF_TIM(TIM5,  CH3, PA2,  TIM_USE_FREQ,  0, 0), // RPM frequency input
    DEF_TIM(TIM11, CH1, PB9,  TIM_USE_ANY,   0, 0), // gyro CLKIN (ICM42688P)
    DEF_TIM(TIM3,  CH4, PB1,  TIM_USE_ANY,   0, 0), // spare pad
};
