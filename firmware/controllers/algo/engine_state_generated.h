// this section was generated automatically by rusEFI tool ConfigDefinition.jar based on (unknown script) controllers/algo/engine_state.txt Fri May 05 01:46:17 UTC 2023
// by class com.rusefi.output.CHeaderConsumer
// begin
#pragma once
#include "rusefi_types.h"
// start of LuaAdjustments
struct LuaAdjustments {
	/**
	 * Lua: Fuel add
	g
	 * offset 0
	 */
	float fuelAdd = (float)0;
	/**
	 * Lua: Fuel mult
	 * offset 4
	 */
	float fuelMult = (float)0;
	/**
	offset 8 bit 0 */
	bool clutchUpState : 1 {};
	/**
	offset 8 bit 1 */
	bool brakePedalState : 1 {};
	/**
	offset 8 bit 2 */
	bool acRequestState : 1 {};
	/**
	offset 8 bit 3 */
	bool luaDisableEtb : 1 {};
	/**
	offset 8 bit 4 */
	bool luaIgnCut : 1 {};
	/**
	offset 8 bit 5 */
	bool unusedBit_7_5 : 1 {};
	/**
	offset 8 bit 6 */
	bool unusedBit_7_6 : 1 {};
	/**
	offset 8 bit 7 */
	bool unusedBit_7_7 : 1 {};
	/**
	offset 8 bit 8 */
	bool unusedBit_7_8 : 1 {};
	/**
	offset 8 bit 9 */
	bool unusedBit_7_9 : 1 {};
	/**
	offset 8 bit 10 */
	bool unusedBit_7_10 : 1 {};
	/**
	offset 8 bit 11 */
	bool unusedBit_7_11 : 1 {};
	/**
	offset 8 bit 12 */
	bool unusedBit_7_12 : 1 {};
	/**
	offset 8 bit 13 */
	bool unusedBit_7_13 : 1 {};
	/**
	offset 8 bit 14 */
	bool unusedBit_7_14 : 1 {};
	/**
	offset 8 bit 15 */
	bool unusedBit_7_15 : 1 {};
	/**
	offset 8 bit 16 */
	bool unusedBit_7_16 : 1 {};
	/**
	offset 8 bit 17 */
	bool unusedBit_7_17 : 1 {};
	/**
	offset 8 bit 18 */
	bool unusedBit_7_18 : 1 {};
	/**
	offset 8 bit 19 */
	bool unusedBit_7_19 : 1 {};
	/**
	offset 8 bit 20 */
	bool unusedBit_7_20 : 1 {};
	/**
	offset 8 bit 21 */
	bool unusedBit_7_21 : 1 {};
	/**
	offset 8 bit 22 */
	bool unusedBit_7_22 : 1 {};
	/**
	offset 8 bit 23 */
	bool unusedBit_7_23 : 1 {};
	/**
	offset 8 bit 24 */
	bool unusedBit_7_24 : 1 {};
	/**
	offset 8 bit 25 */
	bool unusedBit_7_25 : 1 {};
	/**
	offset 8 bit 26 */
	bool unusedBit_7_26 : 1 {};
	/**
	offset 8 bit 27 */
	bool unusedBit_7_27 : 1 {};
	/**
	offset 8 bit 28 */
	bool unusedBit_7_28 : 1 {};
	/**
	offset 8 bit 29 */
	bool unusedBit_7_29 : 1 {};
	/**
	offset 8 bit 30 */
	bool unusedBit_7_30 : 1 {};
	/**
	offset 8 bit 31 */
	bool unusedBit_7_31 : 1 {};
};
static_assert(sizeof(LuaAdjustments) == 12);

// start of speed_density_s
struct speed_density_s {
	/**
	 * Charge temperature estimate
	deg C
	 * offset 0
	 */
	scaled_channel<int16_t, 100, 1> tCharge = (int16_t)0;
	/**
	 * need 4 byte alignment
	units
	 * offset 2
	 */
	uint8_t alignmentFill_at_2[2];
	/**
	 * Charge temperature estimate K
	 * offset 4
	 */
	float tChargeK = (float)0;
};
static_assert(sizeof(speed_density_s) == 8);

// start of cranking_fuel_s
struct cranking_fuel_s {
	/**
	 * Fuel: base duration
	 * Duration of injection, in ms. During cranking we do not account for injector flow, so if you change injectors you would need to change settings.
	 * Deprecated. Please use '1'.
	 * TODO: maybe account for injector flow?
	 * offset 0
	 */
	floatms_t baseFuel = (floatms_t)0;
	/**
	 * Cranking: CLT coefficient
	 * offset 4
	 */
	float coolantTemperatureCoefficient = (float)0;
	/**
	 * offset 8
	 */
	float tpsCoefficient = (float)0;
	/**
	 * offset 12
	 */
	float durationCoefficient = (float)0;
	/**
	 * Fuel: Actual injection
	 * duration based on all coefficients.
	 * offset 16
	 */
	floatms_t fuel = (floatms_t)0;
};
static_assert(sizeof(cranking_fuel_s) == 20);

// start of engine_state_s
struct engine_state_s {
	/**
	 * offset 0
	 */
	LuaAdjustments lua;
	/**
	 * offset 12
	 */
	speed_density_s sd;
	/**
	 * offset 20
	 */
	float engineCycleDurationMs = (float)0;
	/**
	 * offset 24
	 */
	float minRpmKcurrentTPS = (float)0;
	/**
	 * offset 28
	 */
	uint32_t currentTpsAdc = (uint32_t)0;
	/**
	 * offset 32
	 */
	float tpsVoltageMCU = (float)0;
	/**
	 * offset 36
	 */
	float tpsVoltageBoard = (float)0;
	/**
	 * offset 40
	 */
	float currentBaroCorrectedVE = (float)0;
	/**
	 * offset 44
	 */
	float injectorFlowCorrection = (float)0;
	/**
	 * @@GAUGE_NAME_FUEL_BARO_CORR@@
	 * offset 48
	 */
	float baroCorrection = (float)0;
	/**
	 * offset 52
	 */
	cranking_fuel_s crankingFuel;
	/**
	 * Detected Board ID
	id
	 * offset 72
	 */
	int16_t hellenBoardId = (int16_t)0;
	/**
	 * need 4 byte alignment
	units
	 * offset 74
	 */
	uint8_t alignmentFill_at_74[2];
	/**
	 * @@INDICATOR_NAME_CLUTCH_UP@@
	offset 76 bit 0 */
	bool clutchUpState : 1 {};
	/**
	 * @@INDICATOR_NAME_CLUTCH_DOWN@@
	offset 76 bit 1 */
	bool clutchDownState : 1 {};
	/**
	 * @@INDICATOR_NAME_BRAKE_DOWN@@
	offset 76 bit 2 */
	bool brakePedalState : 1 {};
	/**
	offset 76 bit 3 */
	bool startStopState : 1 {};
	/**
	offset 76 bit 4 */
	bool unusedBit_17_4 : 1 {};
	/**
	offset 76 bit 5 */
	bool unusedBit_17_5 : 1 {};
	/**
	offset 76 bit 6 */
	bool unusedBit_17_6 : 1 {};
	/**
	offset 76 bit 7 */
	bool unusedBit_17_7 : 1 {};
	/**
	offset 76 bit 8 */
	bool unusedBit_17_8 : 1 {};
	/**
	offset 76 bit 9 */
	bool unusedBit_17_9 : 1 {};
	/**
	offset 76 bit 10 */
	bool unusedBit_17_10 : 1 {};
	/**
	offset 76 bit 11 */
	bool unusedBit_17_11 : 1 {};
	/**
	offset 76 bit 12 */
	bool unusedBit_17_12 : 1 {};
	/**
	offset 76 bit 13 */
	bool unusedBit_17_13 : 1 {};
	/**
	offset 76 bit 14 */
	bool unusedBit_17_14 : 1 {};
	/**
	offset 76 bit 15 */
	bool unusedBit_17_15 : 1 {};
	/**
	offset 76 bit 16 */
	bool unusedBit_17_16 : 1 {};
	/**
	offset 76 bit 17 */
	bool unusedBit_17_17 : 1 {};
	/**
	offset 76 bit 18 */
	bool unusedBit_17_18 : 1 {};
	/**
	offset 76 bit 19 */
	bool unusedBit_17_19 : 1 {};
	/**
	offset 76 bit 20 */
	bool unusedBit_17_20 : 1 {};
	/**
	offset 76 bit 21 */
	bool unusedBit_17_21 : 1 {};
	/**
	offset 76 bit 22 */
	bool unusedBit_17_22 : 1 {};
	/**
	offset 76 bit 23 */
	bool unusedBit_17_23 : 1 {};
	/**
	offset 76 bit 24 */
	bool unusedBit_17_24 : 1 {};
	/**
	offset 76 bit 25 */
	bool unusedBit_17_25 : 1 {};
	/**
	offset 76 bit 26 */
	bool unusedBit_17_26 : 1 {};
	/**
	offset 76 bit 27 */
	bool unusedBit_17_27 : 1 {};
	/**
	offset 76 bit 28 */
	bool unusedBit_17_28 : 1 {};
	/**
	offset 76 bit 29 */
	bool unusedBit_17_29 : 1 {};
	/**
	offset 76 bit 30 */
	bool unusedBit_17_30 : 1 {};
	/**
	offset 76 bit 31 */
	bool unusedBit_17_31 : 1 {};
	/**
	 * offset 80
	 */
	uint32_t startStopStateToggleCounter = (uint32_t)0;
	/**
	 * offset 84
	 */
	float egtValue1 = (float)0;
	/**
	 * offset 88
	 */
	float egtValue2 = (float)0;
	/**
	 * User-defined RPM hard limit
	rpm
	 * offset 92
	 */
	int16_t desiredRpmLimit = (int16_t)0;
	/**
	 * need 4 byte alignment
	units
	 * offset 94
	 */
	uint8_t alignmentFill_at_94[2];
	/**
	 * offset 96
	 */
	uint32_t fuelInjectionCounter = (uint32_t)0;
	/**
	 * offset 100
	 */
	uint32_t sparkCounter = (uint32_t)0;
	/**
	 * @@GAUGE_NAME_FUEL_LOAD@@
	 * offset 104
	 */
	float fuelingLoad = (float)0;
	/**
	 * @@GAUGE_NAME_IGNITION_LOAD@@
	 * offset 108
	 */
	float ignitionLoad = (float)0;
	/**
	%
	 * offset 112
	 */
	scaled_channel<uint16_t, 100, 1> veTableYAxis = (uint16_t)0;
	/**
	 * need 4 byte alignment
	units
	 * offset 114
	 */
	uint8_t alignmentFill_at_114[2];
};
static_assert(sizeof(engine_state_s) == 116);

// end
// this section was generated automatically by rusEFI tool ConfigDefinition.jar based on (unknown script) controllers/algo/engine_state.txt Fri May 05 01:46:17 UTC 2023
