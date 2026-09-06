/*
 * RadioMaster Nexus-XR — MSP DisplayPort OSD variant (DJI O4 Pro).
 * Pinout matches rotorflight-targets RDMS-NEXUS_XR.config (board_design F7C5).
 * NOT the original Nexus (RDMS-NEXUS_F7 / NEXUS_OSD): XR has a different pin map
 * (gyro EXTI/CLK, I2C3 baro, UART1 pins, UART5 for the built-in ELRS RX, ADC).
 */

#pragma once

#define TARGET_BOARD_IDENTIFIER "NXRO"
#define USBD_PRODUCT_STRING     "Nexus-XR OSD"

#define LED0_PIN                PC10
#define LED1_PIN                PC11

#define ENABLE_DSHOT_DMAR       DSHOT_DMAR_ON

// *************** Gyro & ACC **********************
#define USE_SPI
#define USE_SPI_DEVICE_1

#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PA7

#define GYRO_1_CS_PIN           PA4
#define GYRO_1_ACC_CS_PIN       PB2
#define GYRO_1_SPI_INSTANCE     SPI1
#define GYRO_1_EXTI_PIN         PB8
#define GYRO_1_CLKIN_PIN        PB9     // TIM11 CH1 → ICM42688P CLKIN (32 kHz)

#define USE_GYRO
#define USE_ACC
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P
#define GYRO_1_ALIGN            CW180_DEG

// *************** Baro (SPL06-001, DPS310-compatible) on I2C3 ***
#define USE_I2C
#define USE_I2C_DEVICE_3
#define I2C_DEVICE              (I2CDEV_3)
#define I2C3_SCL                PA8
#define I2C3_SDA                PC9
#define BARO_I2C_INSTANCE       (I2CDEV_3)

#define USE_BARO
#define USE_BARO_DPS310
#define DEFAULT_BARO_DPS310     // required: pg/barometer.c selects the I2C bus only via DEFAULT_BARO_*

// *************** Blackbox flash (W25N02KV 256 MB) ***
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            PB13
#define SPI2_MISO_PIN           PB14
#define SPI2_MOSI_PIN           PB15

#define USE_FLASHFS
#define USE_FLASH_W25N01G       // driver covers W25N01G / W25N02KV
#define FLASH_CS_PIN            PB12
#define FLASH_SPI_INSTANCE      SPI2

// *************** UART **************************
#define USE_VCP

#define USE_UART1               // "S.BUS" port
#define UART1_RX_PIN            PB7
#define UART1_TX_PIN            PB6

#define USE_UART2               // "Telemetry" port (RX only; PA2 is the RPM/FREQ input)
#define UART2_RX_PIN            PA3

#define USE_UART3               // Port-C
#define UART3_RX_PIN            PB10
#define UART3_TX_PIN            PB11

#define USE_UART4               // Port-A
#define UART4_RX_PIN            PA0
#define UART4_TX_PIN            PA1

#define USE_UART5               // built-in ELRS receiver (CRSF)
#define UART5_RX_PIN            PD2
#define UART5_TX_PIN            PC12

#define USE_UART6               // Port-B (DJI O4 MSP DisplayPort by convention)
#define UART6_RX_PIN            PC6
#define UART6_TX_PIN            PC7

#define SERIAL_PORT_COUNT       7

#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_CRSF
#define SERIALRX_UART           SERIAL_PORT_UART5

// *************** ADC (battery / BEC / bus voltage) ***
#define USE_ADC
#define ADC_INSTANCE            ADC1
#define ADC1_DMA_OPT            0

#define VBAT_ADC_PIN            PC0
#define VBEC_ADC_PIN            PC1
#define VBUS_ADC_PIN            PC2
#define CURRENT_METER_ADC_PIN   NONE
#define RSSI_ADC_PIN            NONE

// calibration from RDMS-NEXUS_XR.config
#define VBAT_SCALE_DEFAULT      2532
#define VBAT_DIVIDER_DEFAULT    102
#define VBEC_SCALE_DEFAULT      1216
#define VBEC_DIVIDER_DEFAULT    196
#define VBUS_SCALE_DEFAULT      850
#define VBUS_DIVIDER_DEFAULT    274

#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_NONE

// *************** PINIO ***************************
#define PINIO1_PIN              PC8
#define PINIO1_CONFIG           (PINIO_CONFIG_MODE_OUT_PP | PINIO_CONFIG_OUT_INVERTED)  // 129 in stock config

#define USE_FREQ_SENSOR

#define DEFAULT_FEATURES        (FEATURE_OSD | FEATURE_TELEMETRY | FEATURE_DYN_NOTCH)

#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         0xffff
#define TARGET_IO_PORTD         0xffff
#define TARGET_IO_PORTE         0xffff
#define TARGET_IO_PORTF         0xffff

#define USABLE_TIMER_CHANNEL_COUNT 9
#define USED_TIMERS             (TIM_N(1) | TIM_N(2) | TIM_N(3) | TIM_N(5) | TIM_N(9) | TIM_N(11))

// ---------------------------------------------------------------------------
// Flash budget: MSP OSD only; no analog OSD / MAG. Same trim as NEXUS_OSD, EXCEPT
// features that change MSP reply shapes (board info, flight stats, vario, names):
// the configurator parses fixed-size payloads and hangs on an empty MSP_FLIGHT_STATS.
// Applied after target/common_pre.h.
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
#undef USE_GYRO_DLPF_EXPERIMENTAL
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
