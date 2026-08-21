/*
 * RadioMaster Nexus — MSP DisplayPort OSD variant (DJI O4 Pro MVP).
 * Pinout matches rotorflight-targets RDMS-NEXUS_F7.config.
 * Stock unified NEXUS_F7 (STM32F7X2) is unchanged; develop OSD only on this target.
 */

#pragma once

#define TARGET_BOARD_IDENTIFIER "NXOS"
#define USBD_PRODUCT_STRING     "Nexus OSD"

#define LED0_PIN                PC14
#define LED1_PIN                PC15

#define ENABLE_DSHOT_DMAR       DSHOT_DMAR_ON

// *************** Gyro & ACC **********************
#define USE_SPI
#define USE_SPI_DEVICE_1

#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PA7

#define GYRO_1_CS_PIN           PA4
#define GYRO_1_SPI_INSTANCE     SPI1
#define GYRO_1_EXTI_PIN         PA15

#define USE_GYRO
#define USE_ACC
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P
#define GYRO_1_ALIGN            CW90_DEG

// *************** Baro **************************
#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C_DEVICE              (I2CDEV_1)
#define I2C1_SCL                PB8
#define I2C1_SDA                PB9
#define BARO_I2C_INSTANCE       (I2CDEV_1)

#define USE_BARO
#define USE_BARO_DPS310

// *************** Blackbox flash ******************
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            PB13
#define SPI2_MISO_PIN           PB14
#define SPI2_MOSI_PIN           PB15

#define USE_FLASHFS
#define USE_FLASH_W25N01G
#define FLASH_CS_PIN            PB12
#define FLASH_SPI_INSTANCE      SPI2

// *************** UART **************************
#define USE_VCP

#define USE_UART1
#define UART1_RX_PIN            PA10
#define UART1_TX_PIN            PA9

#define USE_UART2
#define UART2_RX_PIN            PA3

#define USE_UART3
#define UART3_RX_PIN            PB10
#define UART3_TX_PIN            PB11

#define USE_UART4
#define UART4_RX_PIN            PA0
#define UART4_TX_PIN            PA1

#define USE_UART6
#define UART6_RX_PIN            PC6
#define UART6_TX_PIN            PC7

#define SERIAL_PORT_COUNT       6

#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_CRSF
#define SERIALRX_UART           SERIAL_PORT_UART4

// *************** ADC (BEC / external bus voltage) ***
#define USE_ADC
#define ADC_INSTANCE            ADC1
#define ADC1_DMA_OPT            0

#define VBAT_ADC_PIN            NONE
#define CURRENT_METER_ADC_PIN   NONE
#define RSSI_ADC_PIN            NONE

#define USE_FREQ_SENSOR

#define DEFAULT_FEATURES        (FEATURE_OSD | FEATURE_TELEMETRY | FEATURE_DYN_NOTCH)
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_NONE
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_NONE

#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         0xffff
#define TARGET_IO_PORTD         0xffff
#define TARGET_IO_PORTE         0xffff
#define TARGET_IO_PORTF         0xffff

#define USABLE_TIMER_CHANNEL_COUNT 7
#define USED_TIMERS             (TIM_N(2) | TIM_N(3) | TIM_N(4) | TIM_N(5) | TIM_N(9))

// ---------------------------------------------------------------------------
// MVP flash budget: MSP OSD; no analog OSD / MAG. GPS + ESC sensor + 4way/forward
// programming kept. Applied after target/common_pre.h.
// ---------------------------------------------------------------------------
#undef USE_MAG
#undef USE_MAG_DATA_READY_SIGNAL
#undef USE_MAG_HMC5883
#undef USE_MAG_SPI_HMC5883
#undef USE_MAG_QMC5883
#undef USE_MAG_LIS3MDL
#undef USE_MAG_AK8963
#undef USE_MAG_SPI_AK8963
#undef USE_MAG_AK8975
#undef USE_MAG_MPU925X_AK8963
#undef USE_MAX7456
#undef USE_FRSKYOSD
#undef USE_CANVAS
#undef USE_RANGEFINDER
#undef USE_RANGEFINDER_HCSR04
#undef USE_RANGEFINDER_TF
#undef USE_CAMERA_CONTROL
#undef USE_RCDEVICE
#undef USE_SDCARD
#undef USE_SDCARD_SPI
#undef USE_SDCARD_SDIO
#undef USE_DASHBOARD
#undef USE_MULTI_GYRO
#undef USE_VTX_COMMON
#undef USE_VTX_CONTROL
#undef USE_VTX_SMARTAUDIO
#undef USE_VTX_TRAMP
#undef USE_VTX_TABLE
#undef USE_LED_STRIP
#undef USE_OSD_STICK_OVERLAY
#undef USE_PERSISTENT_STATS
#undef USE_TELEMETRY_MAVLINK
#undef USE_TELEMETRY_JETIEXBUS
#undef USE_TELEMETRY_HOTT
#undef USE_TELEMETRY_LTM
#undef USE_SERIALRX_JETIEXBUS
#undef USE_HOTT_TEXTMODE
#undef USE_FLASH_M25P16
#undef USE_FLASH_W25Q128FV
#undef USE_FLASH_W25M
#undef USE_FLASH_W25M512
#undef USE_FLASH_W25M02G
#undef USE_FLASH_TOOLS
#undef USE_PROFILE_NAMES
#undef USE_CUSTOM_BOX_NAMES
#undef USE_VARIO
#undef USE_GYRO_DLPF_EXPERIMENTAL
#undef USE_SENSOR_NAMES
#undef USE_SIGNATURE
#undef USE_BOARD_INFO
#undef USE_EXTENDED_CMS_MENUS
#undef USE_CMS_FAILSAFE_MENU
#undef USE_SPEKTRUM_BIND
#undef USE_SPEKTRUM_BIND_PLUG
#undef USE_SPEKTRUM_REAL_RSSI
#undef USE_SPEKTRUM_FAKE_RSSI
#undef USE_SPEKTRUM_RSSI_PERCENT_CONVERSION
#undef USE_SPEKTRUM_VTX_CONTROL
#undef USE_SPEKTRUM_VTX_TELEMETRY
#undef USE_SPEKTRUM_CMS_TELEMETRY
