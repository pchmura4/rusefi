/*
 * efifeatures.h
 *
 * @date Mar 7, 2014
 * @author Andrey Belomutskiy, (c) 2012-2020
 */

#pragma once

// see SIM_SD1_PORT and SIM_SD2_PORT
#define TS_PRIMARY_UxART_PORT SD1
#define EFI_TS_PRIMARY_IS_SERIAL TRUE
#define TS_SECONDARY_UxART_PORT SD2
#define EFI_TS_SECONDARY_IS_SERIAL TRUE

#define EFI_ENABLE_ASSERTS TRUE
#define EFI_LAUNCH_CONTROL TRUE

#define EFI_TS_TUNNEL_CAN TRUE

#define EFI_TCU FALSE

#define EFI_ENGINE_EMULATOR TRUE

/**
 * todo: we *plan* an (integration) test
 */
#define EFI_CAN_GPIO TRUE

#define EFI_ANTILAG_SYSTEM TRUE

#define ENABLE_PERF_TRACE FALSE

#define EFI_PRINTF_FUEL_DETAILS FALSE

#define HW_CHECK_MODE FALSE

#define SC_BUFFER_SIZE 4000

#define EFI_ACTIVE_CONFIGURATION_IN_FLASH FALSE

#define EFI_BOOST_CONTROL TRUE

#define EFI_CANBUS_SLAVE FALSE

#define EFI_BOSCH_YAW FALSE

#define EFI_AUX_SERIAL FALSE

#define EFI_CLOCK_LOCKS FALSE

#define TS_UART_MODE FALSE

#define EFI_USB_SERIAL FALSE

#define EFI_CDM_INTEGRATION FALSE

#ifndef EFI_SHAFT_POSITION_INPUT
#define EFI_SHAFT_POSITION_INPUT TRUE
#endif

#define EFI_MC33816 FALSE
if !defined(EFI_HPFP) && EFI_SHAFT_POSITION_INPUT
#define EFI_HPFP TRUE
#endif

#define EFI_BLUETOOTH_SETUP FALSE

#define EFI_GPIO_HARDWARE FALSE

#define BOARD_TLE6240_COUNT         0
#define BOARD_MC33972_COUNT			0
#define BOARD_TLE8888_COUNT 	0

#define EFI_TEXT_LOGGING TRUE

#define EFI_MEMS FALSE

#if !defined(EFI_TOOTH_LOGGER) && EFI_SHAFT_POSITION_INPUT
#define EFI_TOOTH_LOGGER TRUE
#endif

#define EFI_USE_UART_DMA FALSE

if !defined(EFI_MAP_AVERAGING) && EFI_SHAFT_POSITION_INPUT
#define EFI_MAP_AVERAGING TRUE
#endif

#define EFI_ALTERNATOR_CONTROL TRUE

#define EFI_ENGINE_AUDI_AAN FALSE
#define EFI_ENGINE_SNOW_BLOWER FALSE

/**
 * simulator works via self-stimulation which works via trigger emulation
 */
#define EFI_EMULATE_POSITION_SENSORS TRUE

#define EFI_SIGNAL_EXECUTOR_SLEEP TRUE
#define EFI_INTERNAL_ADC FALSE
#define EFI_EGT FALSE

#define EFI_UART_ECHO_TEST_MODE FALSE

#define EFI_ENGINE_CONTROL TRUE
#define EFI_IDLE_CONTROL TRUE

#define EFI_IDLE_PID_CIC TRUE
#define EFI_MAIN_RELAY_CONTROL FALSE
#define EFI_HIP_9011 TRUE
#define EFI_CJ125 TRUE

#define EFI_CAN_SUPPORT TRUE

#define EFI_WIDEBAND_FIRMWARE_UPDATE TRUE
#define EFI_MAX_31855 FALSE

#define EFI_ELECTRONIC_THROTTLE_BODY TRUE
#define EFI_VVT_PID TRUE

#ifndef HAL_TRIGGER_USE_PAL
#define HAL_TRIGGER_USE_PAL FALSE
#endif /* HAL_TRIGGER_USE_PAL */

#ifndef HAL_TRIGGER_USE_ADC
#define HAL_TRIGGER_USE_ADC FALSE
#endif /* HAL_TRIGGER_USE_ADC */

#define EFI_UART_GPS FALSE
#define EFI_HAS_RESET FALSE
#define EXTREME_TERM_LOGGING FALSE
#define DEBUG_FUEL FALSE
#define DEBUG_WAVE FALSE

#define EFI_DEFAILED_LOGGING FALSE
#if !defined(EFI_ENGINE_SNIFFER) && EFI_SHAFT_POSITION_INPUT
#define EFI_ENGINE_SNIFFER TRUE
#endif

#define FUEL_MATH_EXTREME_LOGGING FALSE
#define EFI_ANALOG_SENSORS TRUE
#define EFI_INTERNAL_FLASH TRUE
#define EFI_STORAGE_INT_FLASH TRUE
#define EFI_FLASH_WRITE_THREAD TRUE
#define EFI_STORAGE_EXT_SNOR FALSE
#define EFI_RTC FALSE
#define EFI_MALFUNCTION_INDICATOR FALSE
#define EFI_LOGIC_ANALYZER FALSE
#define EFI_PWM_TESTER FALSE
#define TRIGGER_EXTREME_LOGGING FALSE
#define SPARK_EXTREME_LOGGING FALSE
#define DEBUG_PWM FALSE
#define EFI_SIGNAL_EXECUTOR_ONE_TIMER FALSE
#define EFI_TUNER_STUDIO_VERBOSE FALSE
#define EFI_FILE_LOGGING TRUE
#define EFI_WARNING_LED FALSE
#define EFI_VEHICLE_SPEED TRUE
#define EFI_TCU FALSE

#define EFI_SENSOR_CHART TRUE
#define EFI_HISTOGRAMS FALSE

#define EFI_TUNER_STUDIO TRUE

#define EFI_BOARD_TEST FALSE

#define EFI_LUA TRUE
#define LUA_USER_HEAP 100000
