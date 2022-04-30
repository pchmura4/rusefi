// this section was generated automatically by rusEFI tool ConfigDefinition.jar based on config/boards/subaru_eg33/config/gen_subaru_config.sh integration/rusefi_config.txt Sat Apr 30 17:04:55 UTC 2022
// by class com.rusefi.output.CHeaderConsumer
// begin
#pragma once
#include "rusefi_types.h"
// start of stft_cell_cfg_s
struct stft_cell_cfg_s {
	/**
	%
	 * offset 0
	 */
	int8_t maxAdd;
	/**
	%
	 * offset 1
	 */
	int8_t maxRemove;
	/**
	 * Time constant for correction while in this cell: this sets responsiveness of the closed loop correction. A value of 5.0 means it will try to make most of the correction within 5 seconds, and a value of 1.0 will try to correct within 1 second.
	sec
	 * offset 2
	 */
	scaled_channel<uint16_t, 10, 1> timeConstant;
};
static_assert(sizeof(stft_cell_cfg_s) == 4);

// start of stft_s
struct stft_s {
	/**
	 * Below this RPM, the idle region is active
	RPM
	 * offset 0
	 */
	scaled_channel<uint8_t, 1, 50> maxIdleRegionRpm;
	/**
	 * Below this engine load, the overrun region is active
	load
	 * offset 1
	 */
	uint8_t maxOverrunLoad;
	/**
	 * Above this engine load, the power region is active
	load
	 * offset 2
	 */
	uint8_t minPowerLoad;
	/**
	 * When close to correct AFR, pause correction. This can improve stability by not changing the adjustment if the error is extremely small, but is not required.
	%
	 * offset 3
	 */
	scaled_channel<uint8_t, 10, 1> deadband;
	/**
	 * Below this temperature, correction is disabled.
	C
	 * offset 4
	 */
	int8_t minClt;
	/**
	 * Below this AFR, correction is paused
	afr
	 * offset 5
	 */
	scaled_channel<uint8_t, 10, 1> minAfr;
	/**
	 * Above this AFR, correction is paused
	afr
	 * offset 6
	 */
	scaled_channel<uint8_t, 10, 1> maxAfr;
	/**
	 * Delay after starting the engine before beginning closed loop correction.
	seconds
	 * offset 7
	 */
	uint8_t startupDelay;
	/**
	 * offset 8
	 */
	stft_cell_cfg_s cellCfgs[STFT_CELL_COUNT];
};
static_assert(sizeof(stft_s) == 24);

// start of pid_s
struct pid_s {
	/**
	 * offset 0
	 */
	float pFactor;
	/**
	 * offset 4
	 */
	float iFactor;
	/**
	 * offset 8
	 */
	float dFactor;
	/**
	 * Linear addition to PID logic
	 * offset 12
	 */
	int16_t offset;
	/**
	 * PID dTime
	ms
	 * offset 14
	 */
	int16_t periodMs;
	/**
	 * Output Min Duty Cycle
	 * offset 16
	 */
	int16_t minValue;
	/**
	 * Output Max Duty Cycle
	 * offset 18
	 */
	int16_t maxValue;
};
static_assert(sizeof(pid_s) == 20);

// start of cranking_parameters_s
struct cranking_parameters_s {
	/**
	 * Base mass of the per-cylinder fuel injected during cranking. This is then modified by the multipliers for CLT, IAT, TPS ect, to give the final cranking pulse width.
	 * A reasonable starting point is 60mg per liter per cylinder.
	 * ex: 2 liter 4 cyl = 500cc/cyl, so 30mg cranking fuel.
	mg
	 * offset 0
	 */
	float baseFuel;
	/**
	 * This sets the RPM limit below which the ECU will use cranking fuel and ignition logic, typically this is around 350-450rpm. 
	 * set cranking_rpm X
	RPM
	 * offset 4
	 */
	int16_t rpm;
	/**
	 * need 4 byte alignment
	units
	 * offset 6
	 */
	uint8_t alignmentFill_at_6[2];
};
static_assert(sizeof(cranking_parameters_s) == 8);

// start of spi_pins
struct spi_pins {
	/**
	 * offset 0
	 */
	Gpio mosiPin;
	/**
	 * offset 2
	 */
	Gpio misoPin;
	/**
	 * offset 4
	 */
	Gpio sckPin;
	/**
	 * need 4 byte alignment
	units
	 * offset 6
	 */
	uint8_t alignmentFill_at_6[2];
};
static_assert(sizeof(spi_pins) == 8);

// start of gppwm_channel
struct gppwm_channel {
	/**
	 * Select a pin to use for PWM or on-off output.
	 * offset 0
	 */
	output_pin_e pin;
	/**
	 * If an error (with a sensor, etc) is detected, this value is used instead of reading from the table.
	 * This should be a safe value for whatever hardware is connected to prevent damage.
	%
	 * offset 2
	 */
	uint8_t dutyIfError;
	/**
	 * need 4 byte alignment
	units
	 * offset 3
	 */
	uint8_t alignmentFill_at_3[1];
	/**
	 * Select a frequency to run PWM at.
	 * Set this to 0hz to enable on-off mode.
	hz
	 * offset 4
	 */
	uint16_t pwmFrequency;
	/**
	 * Hysteresis: in on-off mode, turn the output on when the table value is above this duty.
	%
	 * offset 6
	 */
	uint8_t onAboveDuty;
	/**
	 * Hysteresis: in on-off mode, turn the output off when the table value is below this duty.
	%
	 * offset 7
	 */
	uint8_t offBelowDuty;
	/**
	 * Selects the load axis to use for the table.
	 * offset 8
	 */
	gppwm_channel_e loadAxis;
	/**
	unit
	 * offset 9
	 */
	uint8_t alignmentFill_map;
	/**
	load
	 * offset 10
	 */
	uint8_t loadBins[GPPWM_LOAD_COUNT];
	/**
	RPM
	 * offset 18
	 */
	scaled_channel<uint8_t, 1, 50> rpmBins[GPPWM_RPM_COUNT];
	/**
	duty
	 * offset 26
	 */
	uint8_t table[GPPWM_RPM_COUNT][GPPWM_LOAD_COUNT];
	/**
	 * need 4 byte alignment
	units
	 * offset 90
	 */
	uint8_t alignmentFill_at_90[2];
};
static_assert(sizeof(gppwm_channel) == 92);

// start of air_pressure_sensor_config_s
struct air_pressure_sensor_config_s {
	/**
	 * kPa value at low volts
	kpa
	 * offset 0
	 */
	float lowValue;
	/**
	 * kPa value at high volts
	kpa
	 * offset 4
	 */
	float highValue;
	/**
	 * offset 8
	 */
	air_pressure_sensor_type_e type;
	/**
	 * offset 12
	 */
	adc_channel_e hwChannel;
	/**
	 * need 4 byte alignment
	units
	 * offset 13
	 */
	uint8_t alignmentFill_at_13[3];
};
static_assert(sizeof(air_pressure_sensor_config_s) == 16);

/**
 * @brief MAP averaging configuration

*/
// start of MAP_sensor_config_s
struct MAP_sensor_config_s {
	/**
	 * offset 0
	 */
	float samplingAngleBins[MAP_ANGLE_SIZE];
	/**
	 * MAP averaging sampling start crank degree angle
	deg
	 * offset 32
	 */
	float samplingAngle[MAP_ANGLE_SIZE];
	/**
	 * offset 64
	 */
	float samplingWindowBins[MAP_WINDOW_SIZE];
	/**
	 * MAP averaging angle crank degree duration
	deg
	 * offset 96
	 */
	float samplingWindow[MAP_WINDOW_SIZE];
	/**
	 * offset 128
	 */
	air_pressure_sensor_config_s sensor;
};
static_assert(sizeof(MAP_sensor_config_s) == 144);

/**
 * @brief Thermistor known values

*/
// start of thermistor_conf_s
struct thermistor_conf_s {
	/**
	 * these values are in Celcius
	*C
	 * offset 0
	 */
	float tempC_1;
	/**
	*C
	 * offset 4
	 */
	float tempC_2;
	/**
	*C
	 * offset 8
	 */
	float tempC_3;
	/**
	Ohm
	 * offset 12
	 */
	float resistance_1;
	/**
	Ohm
	 * offset 16
	 */
	float resistance_2;
	/**
	Ohm
	 * offset 20
	 */
	float resistance_3;
	/**
	 * Pull-up resistor value on your board
	Ohm
	 * offset 24
	 */
	float bias_resistor;
};
static_assert(sizeof(thermistor_conf_s) == 28);

/**
 * @brief Linear sensor interpolation

*/
// start of linear_sensor_s
struct linear_sensor_s {
	/**
	 * offset 0
	 */
	adc_channel_e hwChannel;
	/**
	 * need 4 byte alignment
	units
	 * offset 1
	 */
	uint8_t alignmentFill_at_1[3];
	/**
	volts
	 * offset 4
	 */
	float v1;
	/**
	kPa
	 * offset 8
	 */
	float value1;
	/**
	volts
	 * offset 12
	 */
	float v2;
	/**
	kPa
	 * offset 16
	 */
	float value2;
};
static_assert(sizeof(linear_sensor_s) == 20);

/**
 * @brief Thermistor curve parameters

*/
// start of ThermistorConf
struct ThermistorConf {
	/**
	 * offset 0
	 */
	thermistor_conf_s config;
	/**
	 * offset 28
	 */
	adc_channel_e adcChannel;
	/**
	 * need 4 byte alignment
	units
	 * offset 29
	 */
	uint8_t alignmentFill_at_29[3];
};
static_assert(sizeof(ThermistorConf) == 32);

// start of injector_s
struct injector_s {
	/**
	 * This is your injector flow at the fuel pressure used in the vehicle. cc/min, cubic centimetre per minute
	 * By the way, g/s = 0.125997881 * (lb/hr)
	 * g/s = 0.125997881 * (cc/min)/10.5
	 * g/s = 0.0119997981 * cc/min
	cm3/min
	 * offset 0
	 */
	float flow;
	/**
	 * set_flat_injector_lag LAG
	 * set_injector_lag VOLTAGE LAG
	volts
	 * offset 4
	 */
	float battLagCorrBins[VBAT_INJECTOR_CURVE_SIZE];
	/**
	 * ms delay between injector open and close dead times
	ms
	 * offset 36
	 */
	float battLagCorr[VBAT_INJECTOR_CURVE_SIZE];
};
static_assert(sizeof(injector_s) == 68);

// start of specs_s
struct specs_s {
	/**
	 * Engine volume/capacity, in litres
	 * see also cylindersCount
	L
	 * offset 0
	 */
	float displacement;
	/**
	 * Number of cylinder the engine has.
	 * offset 4
	 */
	uint32_t cylindersCount;
	/**
	 * offset 8
	 */
	firing_order_e firingOrder;
};
static_assert(sizeof(specs_s) == 12);

/**
 * @brief Trigger wheel(s) configuration

*/
// start of trigger_config_s
struct trigger_config_s {
	/**
	 * https://github.com/rusefi/rusefi/wiki/All-Supported-Triggers
	 * set trigger_type X
	 * offset 0
	 */
	trigger_type_e type;
	/**
	offset 4 bit 0 */
	bool todoRemoveMeOneDay0 : 1 {};
	/**
	offset 4 bit 1 */
	bool todoRemoveMeOneDay1 : 1 {};
	/**
	 * This option could be used if your second trigger channel is broken
	offset 4 bit 2 */
	bool useOnlyFirstChannel : 1 {};
	/**
	offset 4 bit 3 */
	bool unusedBit_4_3 : 1 {};
	/**
	offset 4 bit 4 */
	bool unusedBit_4_4 : 1 {};
	/**
	offset 4 bit 5 */
	bool unusedBit_4_5 : 1 {};
	/**
	offset 4 bit 6 */
	bool unusedBit_4_6 : 1 {};
	/**
	offset 4 bit 7 */
	bool unusedBit_4_7 : 1 {};
	/**
	offset 4 bit 8 */
	bool unusedBit_4_8 : 1 {};
	/**
	offset 4 bit 9 */
	bool unusedBit_4_9 : 1 {};
	/**
	offset 4 bit 10 */
	bool unusedBit_4_10 : 1 {};
	/**
	offset 4 bit 11 */
	bool unusedBit_4_11 : 1 {};
	/**
	offset 4 bit 12 */
	bool unusedBit_4_12 : 1 {};
	/**
	offset 4 bit 13 */
	bool unusedBit_4_13 : 1 {};
	/**
	offset 4 bit 14 */
	bool unusedBit_4_14 : 1 {};
	/**
	offset 4 bit 15 */
	bool unusedBit_4_15 : 1 {};
	/**
	offset 4 bit 16 */
	bool unusedBit_4_16 : 1 {};
	/**
	offset 4 bit 17 */
	bool unusedBit_4_17 : 1 {};
	/**
	offset 4 bit 18 */
	bool unusedBit_4_18 : 1 {};
	/**
	offset 4 bit 19 */
	bool unusedBit_4_19 : 1 {};
	/**
	offset 4 bit 20 */
	bool unusedBit_4_20 : 1 {};
	/**
	offset 4 bit 21 */
	bool unusedBit_4_21 : 1 {};
	/**
	offset 4 bit 22 */
	bool unusedBit_4_22 : 1 {};
	/**
	offset 4 bit 23 */
	bool unusedBit_4_23 : 1 {};
	/**
	offset 4 bit 24 */
	bool unusedBit_4_24 : 1 {};
	/**
	offset 4 bit 25 */
	bool unusedBit_4_25 : 1 {};
	/**
	offset 4 bit 26 */
	bool unusedBit_4_26 : 1 {};
	/**
	offset 4 bit 27 */
	bool unusedBit_4_27 : 1 {};
	/**
	offset 4 bit 28 */
	bool unusedBit_4_28 : 1 {};
	/**
	offset 4 bit 29 */
	bool unusedBit_4_29 : 1 {};
	/**
	offset 4 bit 30 */
	bool unusedBit_4_30 : 1 {};
	/**
	offset 4 bit 31 */
	bool unusedBit_4_31 : 1 {};
	/**
	number
	 * offset 8
	 */
	int customTotalToothCount;
	/**
	number
	 * offset 12
	 */
	int customSkippedToothCount;
};
static_assert(sizeof(trigger_config_s) == 16);

// start of afr_sensor_s
struct afr_sensor_s {
	/**
	 * offset 0
	 */
	adc_channel_e hwChannel;
	/**
	 * need 4 byte alignment
	units
	 * offset 1
	 */
	uint8_t alignmentFill_at_1[3];
	/**
	volts
	 * offset 4
	 */
	float v1;
	/**
	AFR
	 * offset 8
	 */
	float value1;
	/**
	volts
	 * offset 12
	 */
	float v2;
	/**
	AFR
	 * offset 16
	 */
	float value2;
};
static_assert(sizeof(afr_sensor_s) == 20);

// start of idle_hardware_s
struct idle_hardware_s {
	/**
	Hz
	 * offset 0
	 */
	int solenoidFrequency;
	/**
	 * offset 4
	 */
	output_pin_e solenoidPin;
	/**
	 * offset 6
	 */
	Gpio stepperDirectionPin;
	/**
	 * offset 8
	 */
	Gpio stepperStepPin;
	/**
	 * offset 10
	 */
	pin_output_mode_e solenoidPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 11
	 */
	uint8_t alignmentFill_at_11[1];
};
static_assert(sizeof(idle_hardware_s) == 12);

// start of dc_io
struct dc_io {
	/**
	 * offset 0
	 */
	Gpio directionPin1;
	/**
	 * offset 2
	 */
	Gpio directionPin2;
	/**
	 * Acts as EN pin in two-wire mode
	 * offset 4
	 */
	Gpio controlPin;
	/**
	 * offset 6
	 */
	Gpio disablePin;
};
static_assert(sizeof(dc_io) == 8);

// start of vr_threshold_s
struct vr_threshold_s {
	/**
	rpm
	 * offset 0
	 */
	scaled_channel<uint8_t, 1, 50> rpmBins[6];
	/**
	volts
	 * offset 6
	 */
	scaled_channel<uint8_t, 100, 1> values[6];
	/**
	 * offset 12
	 */
	Gpio pin;
	/**
	 * need 4 byte alignment
	units
	 * offset 14
	 */
	uint8_t alignmentFill_at_14[2];
};
static_assert(sizeof(vr_threshold_s) == 16);

// start of engine_configuration_s
struct engine_configuration_s {
	/**
	 * http://rusefi.com/wiki/index.php?title=Manual:Engine_Type
	 * set engine_type X
	 * offset 0
	 */
	engine_type_e engineType;
	/**
	 * Disable sensor sniffer above this rpm
	RPM
	 * offset 4
	 */
	scaled_channel<uint8_t, 1, 50> sensorSnifferRpmThreshold;
	/**
	 * set rpm_hard_limit X
	rpm
	 * offset 5
	 */
	scaled_channel<uint8_t, 1, 50> rpmHardLimit;
	/**
	 * A secondary Rev limit engaged by the driver to help launch the vehicle faster
	rpm
	 * offset 6
	 */
	scaled_channel<uint8_t, 1, 50> launchRpm;
	/**
	 * Engine sniffer would be disabled above this rpm
	 * set engineSnifferRpmThreshold X
	RPM
	 * offset 7
	 */
	scaled_channel<uint8_t, 1, 50> engineSnifferRpmThreshold;
	/**
	 * Disable multispark above this engine speed.
	rpm
	 * offset 8
	 */
	scaled_channel<uint8_t, 1, 50> multisparkMaxRpm;
	/**
	 * Above this RPM, disable AC. Set to 0 to disable check.
	rpm
	 * offset 9
	 */
	scaled_channel<uint8_t, 1, 50> maxAcRpm;
	/**
	 * Above this TPS, disable AC. Set to 0 to disable check.
	%
	 * offset 10
	 */
	uint8_t maxAcTps;
	/**
	 * Above this CLT, disable AC to prevent overheating the engine. Set to 0 to disable check.
	deg C
	 * offset 11
	 */
	uint8_t maxAcClt;
	/**
	RPM
	 * offset 12
	 */
	scaled_channel<uint8_t, 1, 50> knockNoiseRpmBins[ENGINE_NOISE_CURVE_SIZE];
	/**
	 * This parameter sets the latest that the last multispark can occur after the main ignition event. For example, if the ignition timing is 30 degrees BTDC, and this parameter is set to 45, no multispark will ever be fired after 15 degrees ATDC.
	deg
	 * offset 28
	 */
	uint8_t multisparkMaxSparkingAngle;
	/**
	 * Configures the maximum number of extra sparks to fire (does not include main spark)
	count
	 * offset 29
	 */
	uint8_t multisparkMaxExtraSparkCount;
	/**
	 * On Single Coil or Wasted Spark setups you have to lower dwell at high RPM
	RPM
	 * offset 30
	 */
	scaled_channel<uint8_t, 1, 50> sparkDwellRpmBins[DWELL_CURVE_SIZE];
	/**
	 * need 4 byte alignment
	units
	 * offset 38
	 */
	uint8_t alignmentFill_at_38[2];
	/**
	ms
	 * offset 40
	 */
	float sparkDwellValues[DWELL_CURVE_SIZE];
	/**
	 * offset 72
	 */
	injector_s injector;
	/**
	 * Does the vehicle have a turbo or supercharger?
	offset 140 bit 0 */
	bool isForcedInduction : 1 {};
	/**
	 * On Ford vehicles one of the sensors is not linear on the full range, i.e. in the specific range of the positions we effectively have only one sensor.
	offset 140 bit 1 */
	bool useFordRedundantTps : 1 {};
	/**
	offset 140 bit 2 */
	bool isVerboseAuxPid1 : 1 {};
	/**
	offset 140 bit 3 */
	bool overrideTriggerGaps : 1 {};
	/**
	 * Turn on this fan when AC is on.
	offset 140 bit 4 */
	bool enableFan1WithAc : 1 {};
	/**
	 * Turn on this fan when AC is on.
	offset 140 bit 5 */
	bool enableFan2WithAc : 1 {};
	/**
	 * Inhibit operation of this fan while the engine is not running.
	offset 140 bit 6 */
	bool disableFan1WhenStopped : 1 {};
	/**
	 * Inhibit operation of this fan while the engine is not running.
	offset 140 bit 7 */
	bool disableFan2WhenStopped : 1 {};
	/**
	 * Enable secondary spark outputs that fire after the primary (rotaries, twin plug engines).
	offset 140 bit 8 */
	bool enableTrailingSparks : 1 {};
	/**
	 * enable cj125verbose/disable cj125verbose
	offset 140 bit 9 */
	bool isCJ125Verbose : 1 {};
	/**
	 * Is your UA CJ125 output wired to MCU via resistor divider? Ua can go over 3.3v but only at lambda >3, i.e very lean AFR above 44.1
	 * When exposed to free air and 17x gain, Ua will be 4.17 volt
	offset 140 bit 10 */
	bool cj125isUaDivided : 1 {};
	/**
	offset 140 bit 11 */
	bool cj125isLsu49 : 1 {};
	/**
	 * TLE7209 uses two-wire mode. TLE9201 and VNH2SP30 do NOT use two wire mode.
	offset 140 bit 12 */
	bool etb_use_two_wires : 1 {};
	/**
	 * Subaru/BMW style where default valve position is somewhere in the middle. First solenoid opens it more while second can close it more than default position.
	offset 140 bit 13 */
	bool isDoubleSolenoidIdle : 1 {};
	/**
	offset 140 bit 14 */
	bool useEeprom : 1 {};
	/**
	 * Is your UR CJ125 output wired to MCU via resistor divider?
	 * Looks like 3v range should be enough, divider generally not needed.
	offset 140 bit 15 */
	bool cj125isUrDivided : 1 {};
	/**
	 * Switch between Industrial and Cic PID implementation
	offset 140 bit 16 */
	bool useCicPidForIdle : 1 {};
	/**
	offset 140 bit 17 */
	bool useTLE8888_cranking_hack : 1 {};
	/**
	offset 140 bit 18 */
	bool useInstantRpmForIdle : 1 {};
	/**
	 * This uses separate ignition timing and VE tables not only for idle conditions, also during the postcranking-to-idle taper transition (See also afterCrankingIACtaperDuration).
	offset 140 bit 19 */
	bool useSeparateIdleTablesForCrankingTaper : 1 {};
	/**
	offset 140 bit 20 */
	bool launchControlEnabled : 1 {};
	/**
	offset 140 bit 21 */
	bool rollingLaunchEnabled : 1 {};
	/**
	offset 140 bit 22 */
	bool antiLagEnabled : 1 {};
	/**
	 * For cranking either use the specified fixed base fuel mass, or use the normal running math (VE table).
	offset 140 bit 23 */
	bool useRunningMathForCranking : 1 {};
	/**
	 * Shall we display real life signal or just the part consumed by trigger decoder.
	 * Applies to both trigger and cam/vvt input.
	 * 
	 * enable logic_level_trigger
	offset 140 bit 24 */
	bool displayLogicLevelsInEngineSniffer : 1 {};
	/**
	offset 140 bit 25 */
	bool useTLE8888_stepper : 1 {};
	/**
	 * If enabled, the MAP estimate table will be used if the MAP sensor fails to estimate manifold pressure based on RPM and TPS.
	offset 140 bit 26 */
	bool enableMapEstimationTableFallback : 1 {};
	/**
	offset 140 bit 27 */
	bool usescriptTableForCanSniffingFiltering : 1 {};
	/**
	 * Print incoming and outgoing first bus CAN messages in rusEFI console
	offset 140 bit 28 */
	bool verboseCan : 1 {};
	/**
	 * Experimental setting that will cause a misfire
	 * DO NOT ENABLE.
	offset 140 bit 29 */
	bool artificialTestMisfire : 1 {};
	/**
	offset 140 bit 30 */
	bool issue_294_31 : 1 {};
	/**
	offset 140 bit 31 */
	bool unusedBit_47_31 : 1 {};
	/**
	 * Closed throttle, 1 volt = 200 units.
	 * See also tps1_1AdcChannel
	 * set tps_min X
	ADC
	 * offset 144
	 */
	int16_t tpsMin;
	/**
	 * Full throttle.
	 * See also tps1_1AdcChannel
	 * set tps_max X
	ADC
	 * offset 146
	 */
	int16_t tpsMax;
	/**
	 * TPS error detection: what throttle % is unrealistically low?
	 * Also used for accelerator pedal error detection if so equiped.
	%
	 * offset 148
	 */
	int16_t tpsErrorDetectionTooLow;
	/**
	 * TPS error detection: what throttle % is unrealistically high?
	 * Also used for accelerator pedal error detection if so equiped.
	%
	 * offset 150
	 */
	int16_t tpsErrorDetectionTooHigh;
	/**
	 * offset 152
	 */
	cranking_parameters_s cranking;
	/**
	 * Dwell duration while cranking
	ms
	 * offset 160
	 */
	float ignitionDwellForCrankingMs;
	/**
	 * Once engine speed passes this value, start reducing ETB angle.
	rpm
	 * offset 164
	 */
	uint16_t etbRevLimitStart;
	/**
	 * This far above 'Soft limiter start', fully close the throttle. At the bottom of the range, throttle control is normal. At the top of the range, the throttle is fully closed.
	rpm
	 * offset 166
	 */
	uint16_t etbRevLimitRange;
	/**
	 * @see isMapAveragingEnabled
	 * offset 168
	 */
	MAP_sensor_config_s map;
	/**
	 * todo: merge with channel settings, use full-scale Thermistor here!
	 * offset 312
	 */
	ThermistorConf clt;
	/**
	 * offset 344
	 */
	ThermistorConf iat;
	/**
	deg
	 * offset 376
	 */
	int launchTimingRetard;
	/**
	 * value '6' for 8MHz hw osc
	 * read hip9011 datasheet for details
	 * todo split into two bit fields
	integer
	 * offset 380
	 */
	int hip9011PrescalerAndSDO;
	/**
	 * We calculate knock band based of cylinderBore
	 *  Use this to override - kHz knock band override
	kHz
	 * offset 384
	 */
	float knockBandCustom;
	/**
	 * offset 388
	 */
	specs_s specs;
	/**
	 * Cylinder diameter in mm.
	mm
	 * offset 400
	 */
	float cylinderBore;
	/**
	 * This setting controls which fuel quantity control algorithm is used.
	 * Alpha-N means drive by TPS commonly only used for NA engines
	 * Speed Density requires MAP sensor and is the default choice for may installs
	 * MAF air charge is a cylinder filling based method that uses a mass air flow sensor.
	 * offset 404
	 */
	engine_load_mode_e fuelAlgorithm;
	/**
	 * This is the injection strategy during engine start. See Fuel/Injection settings for more detail. It is suggested to use "Simultaneous".
	 * offset 408
	 */
	injection_mode_e crankingInjectionMode;
	/**
	 * This is where the fuel injection type is defined: "Simultaneous" means all injectors will fire together at once. "Sequential" fires the injectors on a per cylinder basis, which requires individually wired injectors. "Batched" will fire the injectors in groups. If your injectors are individually wired you will also need to enable "Two wire batch emulation". 
	 * set injection_mode X
	 * See also twoWireBatchInjection
	 * offset 412
	 */
	injection_mode_e injectionMode;
	/**
	 * this is about deciding when the injector starts it's squirt
	 * See also injectionPhase map
	 * todo: do we need even need this since we have the map anyway?
	deg
	 * offset 416
	 */
	angle_t extraInjectionOffset;
	/**
	 * Ignition advance angle used during engine cranking, 5-10 degrees will work as a base setting for most engines.
	 * There is tapering towards running timing advance
	 * set cranking_timing_angle X
	deg
	 * offset 420
	 */
	angle_t crankingTimingAngle;
	/**
	 * Single coil = distributor
	 * Individual coils = one coil per cylinder (COP, coil-near-plug), requires sequential mode
	 * Wasted spark = Fires pairs of cylinders together, either one coil per pair of cylinders or one coil per cylinder
	 * Two distributors = A pair of distributors, found on some BMW, Toyota and other engines
	 * set ignition_mode X
	 * offset 424
	 */
	ignition_mode_e ignitionMode;
	/**
	 * How many consecutive gap rations have to match expected ranges for sync to happen
	count
	 * offset 428
	 */
	int8_t gapTrackingLengthOverride;
	/**
	 * Above this speed, disable closed loop idle control. Set to 0 to disable (allow closed loop idle at any speed).
	kph
	 * offset 429
	 */
	uint8_t maxIdleVss;
	/**
	 * Expected oil pressure after starting the engine. If oil pressure does not reach this level within 5 seconds of engine start, fuel will be cut. Set to 0 to disable and always allow starting.
	kPa
	 * offset 430
	 */
	uint16_t minOilPressureAfterStart;
	/**
	 * Dynamic uses the timing map to decide the ignition timing, Static timing fixes the timing to the value set below (only use for checking static timing with a timing light).
	 * offset 432
	 */
	timing_mode_e timingMode;
	/**
	 * This value is the ignition timing used when in 'fixed timing' mode, i.e. constant timing
	 * This mode is useful when adjusting distributor location.
	RPM
	 * offset 436
	 */
	angle_t fixedModeTiming;
	/**
	 * Angle between Top Dead Center (TDC) and the first trigger event.
	 * Positive value in case of synchnization point before TDC and negative in case of synchnization point after TDC
	 * .Knowing this angle allows us to control timing and other angles in reference to TDC.
	 * set global_trigger_offset_angle X
	deg btdc
	 * offset 440
	 */
	angle_t globalTriggerAngleOffset;
	/**
	 * Ratio/coefficient of input voltage dividers on your PCB. For example, use '2' if your board divides 5v into 2.5v. Use '1.66' if your board divides 5v into 3v.
	coef
	 * offset 444
	 */
	float analogInputDividerCoefficient;
	/**
	 * This is the ratio of the resistors for the battery voltage, measure the voltage at the battery and then adjust this number until the gauge matches the reading.
	coef
	 * offset 448
	 */
	float vbattDividerCoeff;
	/**
	 * Cooling fan turn-on temperature threshold, in Celsius
	deg C
	 * offset 452
	 */
	float fanOnTemperature;
	/**
	 * Cooling fan turn-off temperature threshold, in Celsius
	deg C
	 * offset 456
	 */
	float fanOffTemperature;
	/**
	 * Number of revolutions per kilometer for the wheels your vehicle speed sensor is connected to. Use an online calculator to determine this based on your tire size.
	revs/km
	 * offset 460
	 */
	float driveWheelRevPerKm;
	/**
	 * set can_mode X
	 * offset 464
	 */
	can_nbc_e canNbcType;
	/**
	 * CANbus thread period in ms
	ms
	 * offset 468
	 */
	int canSleepPeriodMs;
	/**
	 * offset 472
	 */
	display_mode_e displayMode;
	/**
	index
	 * offset 476
	 */
	int byFirmwareVersion;
	/**
	index
	 * offset 480
	 */
	int HD44780width;
	/**
	index
	 * offset 484
	 */
	int HD44780height;
	/**
	 * First throttle body, first sensor. See also pedalPositionAdcChannel
	 * offset 488
	 */
	adc_channel_e tps1_1AdcChannel;
	/**
	 * This is the processor input pin that the battery voltage circuit is connected to, if you are unsure of what pin to use, check the schematic that corresponds to your PCB.
	 * offset 489
	 */
	adc_channel_e vbattAdcChannel;
	/**
	 * This is the processor pin that your fuel level sensor in connected to. This is a non standard input so will need to be user defined.
	 * offset 490
	 */
	adc_channel_e fuelLevelSensor;
	/**
	 * Second throttle body position sensor, single channel so far
	 * set_analog_input_pin tps2 X
	 * offset 491
	 */
	adc_channel_e tps2_1AdcChannel;
	/**
	 * 0.1 is a good default value
	x
	 * offset 492
	 */
	float idle_derivativeFilterLoss;
	/**
	 * just a temporary solution
	angle
	 * offset 496
	 */
	int trailingSparkAngle;
	/**
	 * offset 500
	 */
	trigger_config_s trigger;
	/**
	 * offset 516
	 */
	spi_device_e hip9011SpiDevice;
	/**
	 * Single value to be used in event of a failed MAP sensor 
	 * This value is only used for speed density fueling calculations.
	kPa
	 * offset 517
	 */
	uint8_t failedMapFallback;
	/**
	 * Duty cycle to use in case of a sensor failure. This duty cycle should produce the minimum possible amount of boost.
	%
	 * offset 518
	 */
	uint8_t boostControlSafeDutyCycle;
	/**
	 * offset 519
	 */
	adc_channel_e mafAdcChannel;
	/**
	 * set global_fuel_correction X
	coef
	 * offset 520
	 */
	float globalFuelCorrection;
	/**
	volts
	 * offset 524
	 */
	float adcVcc;
	/**
	Deg
	 * offset 528
	 */
	float mapCamDetectionAnglePosition;
	/**
	 * Camshaft input could be used either just for engine phase detection if your trigger shape does not include cam sensor as 'primary' channel, or it could be used for Variable Valve timing on one of the camshafts.
	 * offset 532
	 */
	brain_input_pin_e camInputs[CAM_INPUTS_COUNT];
	/**
	 * offset 540
	 */
	uint8_t camInputsPadding[CAM_INPUTS_COUNT_padding];
	/**
	 * offset 540
	 */
	afr_sensor_s afr;
	/**
	 * Electronic throttle pedal position first channel
	 * See throttlePedalPositionSecondAdcChannel for second channel
	 * See also tps1_1AdcChannel
	 * set_analog_input_pin pps X
	 * See throttlePedalUpVoltage and throttlePedalWOTVoltage
	 * offset 560
	 */
	adc_channel_e throttlePedalPositionAdcChannel;
	/**
	 * need 4 byte alignment
	units
	 * offset 561
	 */
	uint8_t alignmentFill_at_561[1];
	/**
	 * offset 562
	 */
	Gpio tle6240_cs;
	/**
	 * offset 564
	 */
	pin_output_mode_e tle6240_csPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 565
	 */
	uint8_t alignmentFill_at_565[1];
	/**
	 * Throttle Pedal not pressed switch - used on some older vehicles like early Mazda Miata
	 * offset 566
	 */
	switch_input_pin_e throttlePedalUpPin;
	/**
	 * @see hasBaroSensor
	 * offset 568
	 */
	air_pressure_sensor_config_s baroSensor;
	/**
	 * offset 584
	 */
	idle_hardware_s idle;
	/**
	 * Value between 0 and 100 used in Manual mode
	%
	 * offset 596
	 */
	float manIdlePosition;
	/**
	 * Ignition timing to remove when a knock event occurs.
	%
	 * offset 600
	 */
	scaled_channel<uint8_t, 10, 1> knockRetardAggression;
	/**
	 * After a knock event, reapply timing at this rate.
	deg/s
	 * offset 601
	 */
	scaled_channel<uint8_t, 10, 1> knockRetardReapplyRate;
	/**
	 * Maximum amount of knock retard.
	deg
	 * offset 602
	 */
	uint8_t knockRetardMaximum;
	/**
	 * Set this so your vehicle speed signal is responsive, but not noisy. Larger value give smoother but slower response.
	 * offset 603
	 */
	uint8_t vssFilterReciprocal;
	/**
	 * Number of turns of your vehicle speed sensor per turn of the wheels. For example if your sensor is on the transmission output, enter your axle/differential ratio. If you are using a hub-mounted sensor, enter a value of 1.0.
	ratio
	 * offset 604
	 */
	scaled_channel<uint16_t, 1000, 1> vssGearRatio;
	/**
	 * Number of pulses output per revolution of the shaft where your VSS is mounted. For example, GM applications of the T56 output 17 pulses per revolution of the transmission output shaft.
	count
	 * offset 606
	 */
	uint8_t vssToothCount;
	/**
	 * need 4 byte alignment
	units
	 * offset 607
	 */
	uint8_t alignmentFill_at_607[1];
	/**
	 * offset 608
	 */
	Gpio l9779_cs;
	/**
	 * need 4 byte alignment
	units
	 * offset 610
	 */
	uint8_t alignmentFill_at_610[2];
	/**
	 * Same RPM is used for two ways of producing simulated RPM. See also triggerSimulatorPins (with wires)
	 * See also directSelfStimulation (no wires, bypassing input hardware)
	 * rpm X
	 * TODO: rename to triggerSimulatorRpm
	Rpm
	 * offset 612
	 */
	int triggerSimulatorFrequency;
	/**
	 * offset 616
	 */
	output_pin_e injectionPins[MAX_CYLINDER_COUNT];
	/**
	 * offset 640
	 */
	output_pin_e ignitionPins[MAX_CYLINDER_COUNT];
	/**
	 * offset 664
	 */
	pin_output_mode_e injectionPinMode;
	/**
	 * offset 665
	 */
	pin_output_mode_e ignitionPinMode;
	/**
	 * offset 666
	 */
	Gpio HD44780_rs;
	/**
	 * offset 668
	 */
	Gpio HD44780_e;
	/**
	 * offset 670
	 */
	Gpio HD44780_db4;
	/**
	 * offset 672
	 */
	Gpio HD44780_db5;
	/**
	 * offset 674
	 */
	Gpio HD44780_db6;
	/**
	 * offset 676
	 */
	Gpio HD44780_db7;
	/**
	 * offset 678
	 */
	Gpio gps_rx_pin;
	/**
	 * offset 680
	 */
	Gpio gps_tx_pin;
	/**
	 * offset 682
	 */
	output_pin_e fuelPumpPin;
	/**
	 * offset 684
	 */
	pin_output_mode_e fuelPumpPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 685
	 */
	uint8_t alignmentFill_at_685[1];
	/**
	 * Check engine light, also malfunction indicator light. Always blinks once on boot.
	 * offset 686
	 */
	output_pin_e malfunctionIndicatorPin;
	/**
	 * offset 688
	 */
	pin_output_mode_e malfunctionIndicatorPinMode;
	/**
	 * offset 689
	 */
	pin_output_mode_e fanPinMode;
	/**
	 * offset 690
	 */
	output_pin_e fanPin;
	/**
	 * Some cars have a switch to indicate that clutch pedal is all the way down
	 * offset 692
	 */
	switch_input_pin_e clutchDownPin;
	/**
	 * offset 694
	 */
	output_pin_e alternatorControlPin;
	/**
	 * offset 696
	 */
	pin_output_mode_e alternatorControlPinMode;
	/**
	 * offset 697
	 */
	pin_input_mode_e clutchDownPinMode;
	/**
	 * offset 698
	 */
	Gpio digitalPotentiometerChipSelect[DIGIPOT_COUNT];
	/**
	 * offset 706
	 */
	pin_output_mode_e electronicThrottlePin1Mode;
	/**
	 * need 4 byte alignment
	units
	 * offset 707
	 */
	uint8_t alignmentFill_at_707[1];
	/**
	 * set_cj125_heater_pin XXX
	 * offset 708
	 */
	Gpio wboHeaterPin;
	/**
	 * set_cj125_cs_pin XXX
	 * offset 710
	 */
	Gpio cj125CsPin;
	/**
	 * offset 712
	 */
	spi_device_e max31855spiDevice;
	/**
	 * need 4 byte alignment
	units
	 * offset 713
	 */
	uint8_t alignmentFill_at_713[1];
	/**
	 * offset 714
	 */
	Gpio debugTriggerSync;
	/**
	 * Digital Potentiometer is used by stock ECU stimulation code
	 * offset 716
	 */
	spi_device_e digitalPotentiometerSpiDevice;
	/**
	 * need 4 byte alignment
	units
	 * offset 717
	 */
	uint8_t alignmentFill_at_717[1];
	/**
	 * offset 718
	 */
	Gpio mc33972_cs;
	/**
	 * offset 720
	 */
	pin_output_mode_e mc33972_csPinMode;
	/**
	 * Useful in Research&Development phase
	 * offset 721
	 */
	adc_channel_e auxFastSensor1_adcChannel;
	/**
	 * First throttle body, second sensor.
	 * offset 722
	 */
	adc_channel_e tps1_2AdcChannel;
	/**
	 * Second throttle body, second sensor.
	 * offset 723
	 */
	adc_channel_e tps2_2AdcChannel;
	/**
	 * Electronic throttle pedal position input
	 * Second channel
	 * See also tps1_1AdcChannel
	 * See throttlePedalSecondaryUpVoltage and throttlePedalSecondaryWOTVoltage
	 * offset 724
	 */
	adc_channel_e throttlePedalPositionSecondAdcChannel;
	/**
	%
	 * offset 725
	 */
	uint8_t fuelLevelValues[FUEL_LEVEL_TABLE_COUNT];
	/**
	 * need 4 byte alignment
	units
	 * offset 733
	 */
	uint8_t alignmentFill_at_733[3];
	/**
	 * AFR, WBO, EGO - whatever you like to call it
	 * offset 736
	 */
	ego_sensor_e afr_type;
	/**
	 * 0.1 is a good default value
	x
	 * offset 740
	 */
	float idle_antiwindupFreq;
	/**
	 * offset 744
	 */
	brain_input_pin_e triggerInputPins[TRIGGER_INPUT_PIN_COUNT];
	/**
	 * offset 750
	 */
	pin_output_mode_e hip9011CsPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 751
	 */
	uint8_t alignmentFill_at_751[1];
	/**
	 * offset 752
	 */
	output_pin_e tachOutputPin;
	/**
	 * offset 754
	 */
	pin_output_mode_e tachOutputPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 755
	 */
	uint8_t alignmentFill_at_755[1];
	/**
	 * offset 756
	 */
	output_pin_e mainRelayPin;
	/**
	 * offset 758
	 */
	Gpio sdCardCsPin;
	/**
	 * set_can_tx_pin X
	 * offset 760
	 */
	Gpio canTxPin;
	/**
	 * set_can_rx_pin X
	 * offset 762
	 */
	Gpio canRxPin;
	/**
	 * offset 764
	 */
	pin_input_mode_e throttlePedalUpPinMode;
	/**
	 * Additional idle % while A/C is active
	%
	 * offset 765
	 */
	uint8_t acIdleExtraOffset;
	/**
	 * Ratio between the wheels and your transmission output.
	ratio
	 * offset 766
	 */
	scaled_channel<uint16_t, 100, 1> finalGearRatio;
	/**
	 * offset 768
	 */
	brain_input_pin_e tcuInputSpeedSensorPin;
	/**
	 * offset 770
	 */
	uint8_t tcuInputSpeedSensorTeeth;
	/**
	 * need 4 byte alignment
	units
	 * offset 771
	 */
	uint8_t alignmentFill_at_771[1];
	/**
	 * Voltage when the wastegate is closed.
	 * You probably don't have one of these!
	mv
	 * offset 772
	 */
	uint16_t wastegatePositionMin;
	/**
	 * Voltage when the wastegate is fully open.
	 * You probably don't have one of these!
	 * 1 volt = 1000 units
	mv
	 * offset 774
	 */
	uint16_t wastegatePositionMax;
	/**
	 * Voltage when the idle valve is closed.
	 * You probably don't have one of these!
	mv
	 * offset 776
	 */
	uint16_t idlePositionMin;
	/**
	 * Voltage when the idle valve is open.
	 * You probably don't have one of these!
	 * 1 volt = 1000 units
	mv
	 * offset 778
	 */
	uint16_t idlePositionMax;
	/**
	 * Secondary TTL channel baud rate
	BPs
	 * offset 780
	 */
	uint32_t tunerStudioSerialSpeed;
	/**
	 * Just for reference really, not taken into account by any logic at this point
	CR
	 * offset 784
	 */
	float compressionRatio;
	/**
	 * Each rusEFI piece can provide synthetic trigger signal for external ECU. Sometimes these wires are routed back into trigger inputs of the same rusEFI board.
	 * See also directSelfStimulation which is different.
	 * offset 788
	 */
	Gpio triggerSimulatorPins[TRIGGER_SIMULATOR_PIN_COUNT];
	/**
	 * offset 794
	 */
	pin_output_mode_e triggerSimulatorPinModes[TRIGGER_SIMULATOR_PIN_COUNT];
	/**
	 * need 4 byte alignment
	units
	 * offset 797
	 */
	uint8_t alignmentFill_at_797[1];
	/**
	 * Narrow band o2 heater, not used for CJ125. 'ON' if engine is running, 'OFF' if stopped or cranking. See wboHeaterPin
	 * offset 798
	 */
	output_pin_e o2heaterPin;
	/**
	 * offset 800
	 */
	pin_output_mode_e o2heaterPinModeTodO;
	/**
	 * need 4 byte alignment
	units
	 * offset 801
	 */
	uint8_t alignmentFill_at_801[3];
	/**
	offset 804 bit 0 */
	bool is_enabled_spi_1 : 1 {};
	/**
	offset 804 bit 1 */
	bool is_enabled_spi_2 : 1 {};
	/**
	offset 804 bit 2 */
	bool is_enabled_spi_3 : 1 {};
	/**
	 * enable sd/disable sd
	offset 804 bit 3 */
	bool isSdCardEnabled : 1 {};
	/**
	 * Use 11 bit (standard) or 29 bit (extended) IDs for rusEFI verbose CAN format.
	offset 804 bit 4 */
	bool rusefiVerbose29b : 1 {};
	/**
	offset 804 bit 5 */
	bool isEngineControlEnabled : 1 {};
	/**
	offset 804 bit 6 */
	bool isHip9011Enabled : 1 {};
	/**
	offset 804 bit 7 */
	bool isVerboseAlternator : 1 {};
	/**
	offset 804 bit 8 */
	bool useSerialPort : 1 {};
	/**
	 * This setting should only be used if you have a stepper motor idle valve and a stepper motor driver installed.
	offset 804 bit 9 */
	bool useStepperIdle : 1 {};
	/**
	offset 804 bit 10 */
	bool enabledStep1Limiter : 1 {};
	/**
	offset 804 bit 11 */
	bool useTpicAdvancedMode : 1 {};
	/**
	offset 804 bit 12 */
	bool useLcdScreen : 1 {};
	/**
	offset 804 bit 13 */
	bool verboseTLE8888 : 1 {};
	/**
	 * CAN broadcast using custom rusEFI protocol
	 * enable can_broadcast/disable can_broadcast
	offset 804 bit 14 */
	bool enableVerboseCanTx : 1 {};
	/**
	 * This will cause the alternator to be operated in a basic on or off mode, this is the simplest alternator control.
	offset 804 bit 15 */
	bool onOffAlternatorLogic : 1 {};
	/**
	 * enable cj125/disable cj125
	offset 804 bit 16 */
	bool isCJ125Enabled : 1 {};
	/**
	 * Use rise or fall signal front
	 * get vvtCamSensorUseRise
	offset 804 bit 17 */
	bool vvtCamSensorUseRise : 1 {};
	/**
	 * Useful for individual intakes
	offset 804 bit 18 */
	bool measureMapOnlyInOneCylinder : 1 {};
	/**
	offset 804 bit 19 */
	bool stepperForceParkingEveryRestart : 1 {};
	/**
	 * If enabled, try to fire the engine before a full engine cycle has been completed using RPM estimated from the last 90 degrees of engine rotation. As soon as the trigger syncs plus 90 degrees rotation, fuel and ignition events will occur. If disabled, worst case may require up to 4 full crank rotations before any events are scheduled.
	offset 804 bit 20 */
	bool isFasterEngineSpinUpEnabled : 1 {};
	/**
	 * This setting disables fuel injection while the engine is in overrun, this is useful as a fuel saving measure and to prevent back firing.
	offset 804 bit 21 */
	bool coastingFuelCutEnabled : 1 {};
	/**
	 * This setting allows the ECU to open the IAC during overrun conditions to help reduce engine breaking, this can be helpful for large engines in light weight cars. Used in Auto-PID Idle mode.
	offset 804 bit 22 */
	bool useIacTableForCoasting : 1 {};
	/**
	offset 804 bit 23 */
	bool useNoiselessTriggerDecoder : 1 {};
	/**
	offset 804 bit 24 */
	bool useIdleTimingPidControl : 1 {};
	/**
	 * Allows disabling the ETB when the engine is stopped. You may not like the power draw or PWM noise from the motor, so this lets you turn it off until it's necessary.
	offset 804 bit 25 */
	bool disableEtbWhenEngineStopped : 1 {};
	/**
	offset 804 bit 26 */
	bool is_enabled_spi_4 : 1 {};
	/**
	 * Disable the electronic throttle motor and DC idle motor for testing.
	 * This mode is for testing ETB/DC idle position sensors, etc without actually driving the throttle.
	offset 804 bit 27 */
	bool pauseEtbControl : 1 {};
	/**
	offset 804 bit 28 */
	bool alignEngineSnifferAtTDC : 1 {};
	/**
	 * This setting allows the ETB to act as the idle air control valve and move to regulate the airflow at idle.
	offset 804 bit 29 */
	bool useETBforIdleControl : 1 {};
	/**
	offset 804 bit 30 */
	bool idleIncrementalPidCic : 1 {};
	/**
	 * AEM X-Series or rusEFI Wideband
	offset 804 bit 31 */
	bool enableAemXSeries : 1 {};
	/**
	 * offset 808
	 */
	brain_input_pin_e logicAnalyzerPins[LOGIC_ANALYZER_CHANNEL_COUNT];
	/**
	 * offset 816
	 */
	pin_output_mode_e mainRelayPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 817
	 */
	uint8_t alignmentFill_at_817[1];
	/**
	 * offset 818
	 */
	Gpio hip9011CsPin;
	/**
	 * offset 820
	 */
	Gpio hip9011IntHoldPin;
	/**
	 * offset 822
	 */
	pin_output_mode_e hip9011IntHoldPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 823
	 */
	uint8_t alignmentFill_at_823[1];
	/**
	 * offset 824
	 */
	uint32_t verboseCanBaseAddress;
	/**
	v
	 * offset 828
	 */
	uint8_t mc33_hvolt;
	/**
	 * Minimum MAP before closed loop boost is enabled. Use to prevent misbehavior upon entering boost.
	kPa
	 * offset 829
	 */
	uint8_t minimumBoostClosedLoopMap;
	/**
	 * Optional Radiator Fan used with A/C
	 * offset 830
	 */
	output_pin_e acFanPin;
	/**
	 * offset 832
	 */
	pin_output_mode_e acFanPinMode;
	/**
	 * offset 833
	 */
	spi_device_e l9779spiDevice;
	/**
	volts
	 * offset 834
	 */
	scaled_channel<uint8_t, 10, 1> dwellVoltageCorrVoltBins[DWELL_CURVE_SIZE];
	/**
	 * offset 842
	 */
	imu_type_e imuType;
	/**
	multiplier
	 * offset 843
	 */
	scaled_channel<uint8_t, 50, 1> dwellVoltageCorrValues[DWELL_CURVE_SIZE];
	/**
	 * need 4 byte alignment
	units
	 * offset 851
	 */
	uint8_t alignmentFill_at_851[1];
	/**
	kg
	 * offset 852
	 */
	uint16_t vehicleWeight;
	/**
	 * How far above idle speed do we consider idling?
	 * For example, if target = 800, this param = 200, then anything below 1000 RPM is considered idle.
	RPM
	 * offset 854
	 */
	int16_t idlePidRpmUpperLimit;
	/**
	 * Apply nonlinearity correction below a pulse of this duration. Pulses longer than this duration will receive no adjustment.
	ms
	 * offset 856
	 */
	scaled_channel<uint16_t, 1000, 1> applyNonlinearBelowPulse;
	/**
	 * offset 858
	 */
	Gpio lps25BaroSensorScl;
	/**
	 * offset 860
	 */
	Gpio lps25BaroSensorSda;
	/**
	 * offset 862
	 */
	brain_input_pin_e vehicleSpeedSensorInputPin;
	/**
	 * Some vehicles have a switch to indicate that clutch pedal is all the way up
	 * offset 864
	 */
	switch_input_pin_e clutchUpPin;
	/**
	 * offset 866
	 */
	InjectorNonlinearMode injectorNonlinearMode;
	/**
	 * offset 867
	 */
	pin_input_mode_e clutchUpPinMode;
	/**
	 * offset 868
	 */
	Gpio max31855_cs[EGT_CHANNEL_COUNT];
	/**
	 * Continental/GM flex fuel sensor, 50-150hz type
	 * offset 884
	 */
	brain_input_pin_e flexSensorPin;
	/**
	 * offset 886
	 */
	Gpio test557pin;
	/**
	 * offset 888
	 */
	pin_output_mode_e stepperDirectionPinMode;
	/**
	 * offset 889
	 */
	spi_device_e mc33972spiDevice;
	/**
	 * Stoichiometric ratio for your secondary fuel. This value is used when the Flex Fuel sensor indicates E100, typically 9.0
	:1
	 * offset 890
	 */
	scaled_channel<uint8_t, 10, 1> stoichRatioSecondary;
	/**
	 * Maximum allowed ETB position. Some throttles go past fully open, so this allows you to limit it to fully open.
	%
	 * offset 891
	 */
	uint8_t etbMaximumPosition;
	/**
	 * SD card logging period, in milliseconds
	ms
	 * offset 892
	 */
	int16_t sdCardPeriodMs;
	/**
	 * offset 894
	 */
	adc_channel_e idlePositionSensor;
	/**
	 * need 4 byte alignment
	units
	 * offset 895
	 */
	uint8_t alignmentFill_at_895[1];
	/**
	 * offset 896
	 */
	Gpio debugMapAveraging;
	/**
	 * offset 898
	 */
	output_pin_e starterRelayDisablePin;
	/**
	 * On some vehicles we can disable starter once engine is already running
	 * offset 900
	 */
	pin_output_mode_e starterRelayDisablePinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 901
	 */
	uint8_t alignmentFill_at_901[1];
	/**
	 * Some Subaru and some Mazda use double-solenoid idle air valve
	 * offset 902
	 */
	output_pin_e secondSolenoidPin;
	/**
	 * See also starterControlPin
	 * offset 904
	 */
	switch_input_pin_e startStopButtonPin;
	/**
	 * need 4 byte alignment
	units
	 * offset 906
	 */
	uint8_t alignmentFill_at_906[2];
	/**
	 * This many MAP samples are used to estimate the current MAP. This many samples are considered, and the minimum taken. Recommended value is 1 for single-throttle engines, and your number of cylinders for individual throttle bodies.
	count
	 * offset 908
	 */
	int mapMinBufferLength;
	/**
	 * Below this throttle position, the engine is considered idling. If you have an electronic throttle, this checks accelerator pedal position instead of throttle position, and should be set to 1-2%.
	%
	 * offset 912
	 */
	int16_t idlePidDeactivationTpsThreshold;
	/**
	%
	 * offset 914
	 */
	int16_t stepperParkingExtraSteps;
	/**
	ADC
	 * offset 916
	 */
	uint16_t tps1SecondaryMin;
	/**
	ADC
	 * offset 918
	 */
	uint16_t tps1SecondaryMax;
	/**
	rpm
	 * offset 920
	 */
	int16_t antiLagRpmTreshold;
	/**
	 * Maximum time to crank starter when start/stop button is pressed
	Seconds
	 * offset 922
	 */
	uint16_t startCrankingDuration;
	/**
	 * This pin is used for debugging - snap a logic analyzer on it and see if it's ever high
	 * offset 924
	 */
	Gpio triggerErrorPin;
	/**
	 * offset 926
	 */
	pin_output_mode_e triggerErrorPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 927
	 */
	uint8_t alignmentFill_at_927[1];
	/**
	 * offset 928
	 */
	output_pin_e acRelayPin;
	/**
	 * offset 930
	 */
	pin_output_mode_e acRelayPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 931
	 */
	uint8_t alignmentFill_at_931[1];
	/**
	 * offset 932
	 */
	script_setting_t scriptSetting[SCRIPT_SETTING_COUNT];
	/**
	 * offset 964
	 */
	Gpio spi1mosiPin;
	/**
	 * offset 966
	 */
	Gpio spi1misoPin;
	/**
	 * offset 968
	 */
	Gpio spi1sckPin;
	/**
	 * offset 970
	 */
	Gpio spi2mosiPin;
	/**
	 * offset 972
	 */
	Gpio spi2misoPin;
	/**
	 * offset 974
	 */
	Gpio spi2sckPin;
	/**
	 * offset 976
	 */
	Gpio spi3mosiPin;
	/**
	 * offset 978
	 */
	Gpio spi3misoPin;
	/**
	 * offset 980
	 */
	Gpio spi3sckPin;
	/**
	 * Saab Combustion Detection Module knock signal input pin
	 * also known as Saab Ion Sensing Module
	 * offset 982
	 */
	Gpio cdmInputPin;
	/**
	 * offset 984
	 */
	Gpio joystickCenterPin;
	/**
	 * offset 986
	 */
	Gpio joystickAPin;
	/**
	 * offset 988
	 */
	Gpio joystickBPin;
	/**
	 * offset 990
	 */
	Gpio joystickCPin;
	/**
	 * offset 992
	 */
	Gpio joystickDPin;
	/**
	 * offset 994
	 */
	uart_device_e consoleUartDevice;
	/**
	 * need 4 byte alignment
	units
	 * offset 995
	 */
	uint8_t alignmentFill_at_995[1];
	/**
	 * rusEFI console Sensor Sniffer mode
	 * offset 996
	 */
	sensor_chart_e sensorChartMode;
	/**
	 * offset 1000
	 */
	maf_sensor_type_e mafSensorType;
	/**
	offset 1004 bit 0 */
	bool clutchUpPinInverted : 1 {};
	/**
	offset 1004 bit 1 */
	bool clutchDownPinInverted : 1 {};
	/**
	 * If enabled we use two H-bridges to drive stepper idle air valve
	offset 1004 bit 2 */
	bool useHbridgesToDriveIdleStepper : 1 {};
	/**
	offset 1004 bit 3 */
	bool multisparkEnable : 1 {};
	/**
	offset 1004 bit 4 */
	bool enableLaunchRetard : 1 {};
	/**
	offset 1004 bit 5 */
	bool unfinishedenableLaunchBoost : 1 {};
	/**
	offset 1004 bit 6 */
	bool unfinishedlaunchDisableBySpeed : 1 {};
	/**
	 * Read VSS from OEM CAN bus according to selected CAN vehicle configuration.
	offset 1004 bit 7 */
	bool enableCanVss : 1 {};
	/**
	offset 1004 bit 8 */
	bool enableInnovateLC2 : 1 {};
	/**
	offset 1004 bit 9 */
	bool showHumanReadableWarning : 1 {};
	/**
	 * If enabled, adjust at a constant rate instead of a rate proportional to the current lambda error. This mode may be easier to tune, and more tolerant of sensor noise. Use of this mode is required if you have a narrowband O2 sensor.
	offset 1004 bit 10 */
	bool stftIgnoreErrorMagnitude : 1 {};
	/**
	offset 1004 bit 11 */
	bool tempBooleanForVerySpecialCases : 1 {};
	/**
	offset 1004 bit 12 */
	bool enableSoftwareKnock : 1 {};
	/**
	 * enable vvt_details
	offset 1004 bit 13 */
	bool verboseVVTDecoding : 1 {};
	/**
	 * get invertCamVVTSignal
	offset 1004 bit 14 */
	bool invertCamVVTSignal : 1 {};
	/**
	 * This property is useful if using rusEFI as TCM or BCM only
	 * enable consumeObdSensors
	offset 1004 bit 15 */
	bool consumeObdSensors : 1 {};
	/**
	offset 1004 bit 16 */
	bool knockBankCyl1 : 1 {};
	/**
	offset 1004 bit 17 */
	bool knockBankCyl2 : 1 {};
	/**
	offset 1004 bit 18 */
	bool knockBankCyl3 : 1 {};
	/**
	offset 1004 bit 19 */
	bool knockBankCyl4 : 1 {};
	/**
	offset 1004 bit 20 */
	bool knockBankCyl5 : 1 {};
	/**
	offset 1004 bit 21 */
	bool knockBankCyl6 : 1 {};
	/**
	offset 1004 bit 22 */
	bool knockBankCyl7 : 1 {};
	/**
	offset 1004 bit 23 */
	bool knockBankCyl8 : 1 {};
	/**
	offset 1004 bit 24 */
	bool knockBankCyl9 : 1 {};
	/**
	offset 1004 bit 25 */
	bool knockBankCyl10 : 1 {};
	/**
	offset 1004 bit 26 */
	bool knockBankCyl11 : 1 {};
	/**
	offset 1004 bit 27 */
	bool knockBankCyl12 : 1 {};
	/**
	offset 1004 bit 28 */
	bool tcuEnabled : 1 {};
	/**
	offset 1004 bit 29 */
	bool canBroadcastUseChannelTwo : 1 {};
	/**
	 * If enabled we use four Push-Pull outputs to directly drive stepper idle air valve coilss
	offset 1004 bit 30 */
	bool useRawOutputToDriveIdleStepper : 1 {};
	/**
	 * Print incoming and outgoing second bus CAN messages in rusEFI console
	offset 1004 bit 31 */
	bool verboseCan2 : 1 {};
	/**
	 * offset 1008
	 */
	dc_io etbIo[ETB_COUNT];
	/**
	 * Wastegate control Solenoid
	 * offset 1024
	 */
	output_pin_e boostControlPin;
	/**
	 * offset 1026
	 */
	pin_output_mode_e boostControlPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 1027
	 */
	uint8_t alignmentFill_at_1027[1];
	/**
	 * offset 1028
	 */
	switch_input_pin_e antiLagActivatePin;
	/**
	 * offset 1030
	 */
	switch_input_pin_e launchActivatePin;
	/**
	 * offset 1032
	 */
	pid_s boostPid;
	/**
	 * offset 1052
	 */
	boostType_e boostType;
	/**
	Hz
	 * offset 1056
	 */
	int boostPwmFrequency;
	/**
	 * offset 1060
	 */
	launchActivationMode_e launchActivationMode;
	/**
	 * offset 1064
	 */
	antiLagActivationMode_e antiLagActivationMode;
	/**
	 * Disabled above this speed
	Kph
	 * offset 1068
	 */
	int launchSpeedThreshold;
	/**
	 * Range from Launch Rpm for Timing Retard to activate
	RPM
	 * offset 1072
	 */
	int launchTimingRpmRange;
	/**
	 * Extra Fuel Added
	%
	 * offset 1076
	 */
	int launchFuelAdded;
	/**
	 * Duty Cycle for the Boost Solenoid
	%
	 * offset 1080
	 */
	int launchBoostDuty;
	/**
	 * RPM Range for Hard Cut
	rpm
	 * offset 1084
	 */
	int hardCutRpmRange;
	/**
	rpm
	 * offset 1088
	 */
	int launchAdvanceRpmRange;
	/**
	rpm
	 * offset 1092
	 */
	int launchTpsTreshold;
	/**
	rpm
	 * offset 1096
	 */
	float launchActivateDelay;
	/**
	 * offset 1100
	 */
	stft_s stft;
	/**
	 * offset 1124
	 */
	dc_io stepperDcIo[DC_PER_STEPPER];
	/**
	 * For example, BMW, GM or Chevrolet
	 * REQUIRED for rusEFI Online
	 * offset 1140
	 */
	vehicle_info_t engineMake;
	/**
	 * For example, LS1 or NB2
	 * REQUIRED for rusEFI Online
	 * offset 1172
	 */
	vehicle_info_t engineCode;
	/**
	 * For example, Hunchback or Orange Miata
	 * Vehicle name has to be unique between your vehicles.
	 * REQUIRED for rusEFI Online
	 * offset 1204
	 */
	vehicle_info_t vehicleName;
	/**
	 * offset 1236
	 */
	output_pin_e tcu_solenoid[TCU_SOLENOID_COUNT];
	/**
	 * offset 1248
	 */
	etb_function_e etbFunctions[ETB_COUNT];
	/**
	 * offset 1250
	 */
	spi_device_e drv8860spiDevice;
	/**
	 * need 4 byte alignment
	units
	 * offset 1251
	 */
	uint8_t alignmentFill_at_1251[1];
	/**
	 * offset 1252
	 */
	Gpio drv8860_cs;
	/**
	 * offset 1254
	 */
	pin_output_mode_e drv8860_csPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 1255
	 */
	uint8_t alignmentFill_at_1255[1];
	/**
	 * offset 1256
	 */
	Gpio drv8860_miso;
	/**
	volt
	 * offset 1258
	 */
	scaled_channel<uint16_t, 1000, 1> fuelLevelBins[FUEL_LEVEL_TABLE_COUNT];
	/**
	 * offset 1274
	 */
	output_pin_e luaOutputPins[LUA_PWM_COUNT];
	/**
	 * need 4 byte alignment
	units
	 * offset 1290
	 */
	uint8_t alignmentFill_at_1290[2];
	/**
	 * Angle between cam sensor and VVT zero position
	 * set vvt_offset X
	value
	 * offset 1292
	 */
	float vvtOffsets[CAM_INPUTS_COUNT];
	/**
	 * offset 1308
	 */
	float vvtOffsetsPadding[CAM_INPUTS_COUNT_padding];
	/**
	 * offset 1308
	 */
	vr_threshold_s vrThreshold[VR_THRESHOLD_COUNT];
	/**
	 * offset 1340
	 */
	gppwm_note_t gpPwmNote[GPPWM_CHANNELS];
	/**
	ADC
	 * offset 1404
	 */
	uint16_t tps2SecondaryMin;
	/**
	ADC
	 * offset 1406
	 */
	uint16_t tps2SecondaryMax;
	/**
	offset 1408 bit 0 */
	bool disablePrimaryUart : 1 {};
	/**
	 * Enables lambda sensor closed loop feedback for fuelling.
	offset 1408 bit 1 */
	bool fuelClosedLoopCorrectionEnabled : 1 {};
	/**
	 * Print details into rusEFI console
	 * enable verbose_idle
	offset 1408 bit 2 */
	bool isVerboseIAC : 1 {};
	/**
	offset 1408 bit 3 */
	bool boardUseTachPullUp : 1 {};
	/**
	offset 1408 bit 4 */
	bool boardUseTempPullUp : 1 {};
	/**
	 * This options enables data for 'engine sniffer' tab in console, which comes at some CPU price
	offset 1408 bit 5 */
	bool isEngineChartEnabled : 1 {};
	/**
	 * Sometimes we have a performance issue while printing error
	offset 1408 bit 6 */
	bool silentTriggerError : 1 {};
	/**
	offset 1408 bit 7 */
	bool useLinearCltSensor : 1 {};
	/**
	 * enable can_read/disable can_read
	offset 1408 bit 8 */
	bool canReadEnabled : 1 {};
	/**
	 * enable can_write/disable can_write
	offset 1408 bit 9 */
	bool canWriteEnabled : 1 {};
	/**
	offset 1408 bit 10 */
	bool useLinearIatSensor : 1 {};
	/**
	offset 1408 bit 11 */
	bool boardUse2stepPullDown : 1 {};
	/**
	 * Treat milliseconds value as duty cycle value, i.e. 0.5ms would become 50%
	offset 1408 bit 12 */
	bool tachPulseDurationAsDutyCycle : 1 {};
	/**
	 * This enables smart alternator control and activates the extra alternator settings.
	offset 1408 bit 13 */
	bool isAlternatorControlEnabled : 1 {};
	/**
	 * This setting flips the signal from the primary engine speed sensor.
	offset 1408 bit 14 */
	bool invertPrimaryTriggerSignal : 1 {};
	/**
	 * This setting flips the signal from the secondary engine speed sensor.
	offset 1408 bit 15 */
	bool invertSecondaryTriggerSignal : 1 {};
	/**
	offset 1408 bit 16 */
	bool cutFuelOnHardLimit : 1 {};
	/**
	offset 1408 bit 17 */
	bool cutSparkOnHardLimit : 1 {};
	/**
	offset 1408 bit 18 */
	bool launchFuelCutEnable : 1 {};
	/**
	 * This is the Cut Mode normally used
	offset 1408 bit 19 */
	bool launchSparkCutEnable : 1 {};
	/**
	offset 1408 bit 20 */
	bool boardUseCrankPullUp : 1 {};
	/**
	offset 1408 bit 21 */
	bool boardUseCamPullDown : 1 {};
	/**
	offset 1408 bit 22 */
	bool boardUseCamVrPullUp : 1 {};
	/**
	offset 1408 bit 23 */
	bool boardUseD2PullDown : 1 {};
	/**
	offset 1408 bit 24 */
	bool boardUseD3PullDown : 1 {};
	/**
	offset 1408 bit 25 */
	bool boardUseD4PullDown : 1 {};
	/**
	offset 1408 bit 26 */
	bool boardUseD5PullDown : 1 {};
	/**
	 * Sometimes we just have to shut the engine down. Use carefully!
	offset 1408 bit 27 */
	bool useFSIO5ForCriticalIssueEngineStop : 1 {};
	/**
	 * Sometimes we have to miss injection on purpose to attract driver's attention
	offset 1408 bit 28 */
	bool useFSIO4ForSeriousEngineWarning : 1 {};
	/**
	offset 1408 bit 29 */
	bool launchActivateInverted : 1 {};
	/**
	offset 1408 bit 30 */
	bool twoStroke : 1 {};
	/**
	 * Where is your primary skipped wheel located?
	offset 1408 bit 31 */
	bool skippedWheelOnCam : 1 {};
	/**
	 * offset 1412
	 */
	adc_channel_e hipOutputChannel;
	/**
	 * need 4 byte alignment
	units
	 * offset 1413
	 */
	uint8_t alignmentFill_at_1413[1];
	/**
	 * A/C button input
	 * offset 1414
	 */
	switch_input_pin_e acSwitch;
	/**
	 * offset 1416
	 */
	adc_channel_e vRefAdcChannel;
	/**
	 * Expected neutral position
	%
	 * offset 1417
	 */
	uint8_t etbNeutralPosition;
	/**
	 * need 4 byte alignment
	units
	 * offset 1418
	 */
	uint8_t alignmentFill_at_1418[2];
	/**
	 * See also idleRpmPid
	 * offset 1420
	 */
	idle_mode_e idleMode;
	/**
	 * Enable fuel injection - This is default off for new projects as a safety feature, set to "true" to enable fuel injection and further injector settings.
	offset 1424 bit 0 */
	bool isInjectionEnabled : 1 {};
	/**
	 * Enable ignition - This is default off for new projects as a safety feature, set to "true" to enable ignition and further ignition settings.
	offset 1424 bit 1 */
	bool isIgnitionEnabled : 1 {};
	/**
	 * When enabled if TPS is held above 95% no fuel is injected while cranking to clear excess fuel from the cylinders.
	offset 1424 bit 2 */
	bool isCylinderCleanupEnabled : 1 {};
	/**
	 * Should we use tables to vary tau/beta based on CLT/MAP, or just with fixed values?
	offset 1424 bit 3 */
	bool complexWallModel : 1 {};
	/**
	offset 1424 bit 4 */
	bool alwaysInstantRpm : 1 {};
	/**
	offset 1424 bit 5 */
	bool isMapAveragingEnabled : 1 {};
	/**
	 * If enabled, use separate temperature multiplier table for cranking idle position.
	 * If disabled, use normal running multiplier table applied to the cranking base position.
	offset 1424 bit 6 */
	bool overrideCrankingIacSetting : 1 {};
	/**
	 * This activates a separate ignition timing table for idle conditions, this can help idle stability by using ignition retard and advance either side of the desired idle speed. Extra retard at low idle speeds will prevent stalling and extra advance at high idle speeds can help reduce engine power and slow the idle speed.
	offset 1424 bit 7 */
	bool useSeparateAdvanceForIdle : 1 {};
	/**
	offset 1424 bit 8 */
	bool isWaveAnalyzerEnabled : 1 {};
	/**
	 * This activates a separate fuel table for Idle, this allows fine tuning of the idle fuelling.
	offset 1424 bit 9 */
	bool useSeparateVeForIdle : 1 {};
	/**
	 * enable trigger_details
	offset 1424 bit 10 */
	bool verboseTriggerSynchDetails : 1 {};
	/**
	 * Usually if we have no trigger events that means engine is stopped
	 * Unless we are troubleshooting and spinning the engine by hand - this case a longer
	 * delay is needed
	offset 1424 bit 11 */
	bool isManualSpinningMode : 1 {};
	/**
	 * This is needed if your coils are individually wired and you wish to use batch injection.
	 * enable two_wire_batch_injection
	offset 1424 bit 12 */
	bool twoWireBatchInjection : 1 {};
	/**
	 * VR sensors are only precise on rising front
	 * enable trigger_only_front
	offset 1424 bit 13 */
	bool useOnlyRisingEdgeForTrigger : 1 {};
	/**
	 * This is needed if your coils are individually wired (COP) and you wish to use batch ignition (Wasted Spark).
	offset 1424 bit 14 */
	bool twoWireBatchIgnition : 1 {};
	/**
	offset 1424 bit 15 */
	bool useFixedBaroCorrFromMap : 1 {};
	/**
	 * In Constant mode, timing is automatically tapered to running as RPM increases.
	 * In Table mode, the "Cranking ignition advance" table is used directly.
	offset 1424 bit 16 */
	bool useSeparateAdvanceForCranking : 1 {};
	/**
	 * This enables the various ignition corrections during cranking (IAT, CLT, FSIO and PID idle).
	 * You probably don't need this.
	offset 1424 bit 17 */
	bool useAdvanceCorrectionsForCranking : 1 {};
	/**
	 * Enable a second cranking table to use for E100 flex fuel, interpolating between the two based on flex fuel sensor.
	offset 1424 bit 18 */
	bool flexCranking : 1 {};
	/**
	 * This flag allows to use a special 'PID Multiplier' table (0.0-1.0) to compensate for nonlinear nature of IAC-RPM controller
	offset 1424 bit 19 */
	bool useIacPidMultTable : 1 {};
	/**
	offset 1424 bit 20 */
	bool isBoostControlEnabled : 1 {};
	/**
	 * Interpolates the Ignition Retard from 0 to 100% within the RPM Range
	offset 1424 bit 21 */
	bool launchSmoothRetard : 1 {};
	/**
	offset 1424 bit 22 */
	bool unused1476b20 : 1 {};
	/**
	offset 1424 bit 23 */
	bool unused1476b8 : 1 {};
	/**
	offset 1424 bit 24 */
	bool unused_1484_bit_24 : 1 {};
	/**
	offset 1424 bit 25 */
	bool unused_1484_bit_25 : 1 {};
	/**
	offset 1424 bit 26 */
	bool unused_1484_bit_26 : 1 {};
	/**
	offset 1424 bit 27 */
	bool unused_1484_bit_27 : 1 {};
	/**
	offset 1424 bit 28 */
	bool unused_1484_bit_28 : 1 {};
	/**
	offset 1424 bit 29 */
	bool unused_1484_bit_29 : 1 {};
	/**
	offset 1424 bit 30 */
	bool unused_1484_bit_30 : 1 {};
	/**
	offset 1424 bit 31 */
	bool unused_1484_bit_31 : 1 {};
	/**
	count
	 * offset 1428
	 */
	uint32_t engineChartSize;
	/**
	mult
	 * offset 1432
	 */
	float turboSpeedSensorMultiplier;
	/**
	 * offset 1436
	 */
	Gpio camInputsDebug[CAM_INPUTS_COUNT];
	/**
	 * offset 1444
	 */
	uint8_t camInputsDebugPadding[CAM_INPUTS_COUNT_padding];
	/**
	 * Extra idle target speed when A/C is enabled. Some cars need the extra speed to keep the AC efficient while idling.
	RPM
	 * offset 1444
	 */
	int16_t acIdleRpmBump;
	/**
	 * set warningPeriod X
	seconds
	 * offset 1446
	 */
	int16_t warningPeriod;
	/**
	angle
	 * offset 1448
	 */
	float knockDetectionWindowStart;
	/**
	angle
	 * offset 1452
	 */
	float knockDetectionWindowEnd;
	/**
	ms
	 * offset 1456
	 */
	float idleStepperReactionTime;
	/**
	count
	 * offset 1460
	 */
	int idleStepperTotalSteps;
	/**
	 * TODO: finish this #413
	sec
	 * offset 1464
	 */
	float noAccelAfterHardLimitPeriodSecs;
	/**
	 * At what trigger index should some MAP-related math be executed? This is a performance trick to reduce load on synchronization trigger callback.
	index
	 * offset 1468
	 */
	int mapAveragingSchedulingAtIndex;
	/**
	kPa
	 * offset 1472
	 */
	float baroCorrPressureBins[BARO_CORR_SIZE];
	/**
	RPM
	 * offset 1488
	 */
	float baroCorrRpmBins[BARO_CORR_SIZE];
	/**
	ratio
	 * offset 1504
	 */
	float baroCorrTable[BARO_CORR_SIZE][BARO_CORR_SIZE];
	/**
	 * Cranking fuel correction coefficient based on TPS
	Ratio
	 * offset 1568
	 */
	float crankingTpsCoef[CRANKING_CURVE_SIZE];
	/**
	%
	 * offset 1600
	 */
	float crankingTpsBins[CRANKING_CURVE_SIZE];
	/**
	 * Duration in ms or duty cycle depending on selected mode
	 * offset 1632
	 */
	float tachPulseDuractionMs;
	/**
	 * Length of time the deposited wall fuel takes to dissipate after the start of acceleration.
	Seconds
	 * offset 1636
	 */
	float wwaeTau;
	/**
	 * offset 1640
	 */
	pid_s alternatorControl;
	/**
	 * offset 1660
	 */
	pid_s etb;
	/**
	 * offset 1680
	 */
	Gpio triggerInputDebugPins[TRIGGER_INPUT_PIN_COUNT];
	/**
	 * offset 1686
	 */
	brain_input_pin_e turboSpeedSensorInputPin;
	/**
	 * Closed throttle#2. todo: extract these two fields into a structure
	 * See also tps2_1AdcChannel
	 * set tps2_min X
	ADC
	 * offset 1688
	 */
	int16_t tps2Min;
	/**
	 * Full throttle#2. tpsMax value as 10 bit ADC value. Not Voltage!
	 * See also tps1_1AdcChannel
	 * set tps2_max X
	ADC
	 * offset 1690
	 */
	int16_t tps2Max;
	/**
	 * See also startStopButtonPin
	 * offset 1692
	 */
	output_pin_e starterControlPin;
	/**
	 * offset 1694
	 */
	pin_input_mode_e startStopButtonMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 1695
	 */
	uint8_t alignmentFill_at_1695[1];
	/**
	 * offset 1696
	 */
	Gpio mc33816_flag0;
	/**
	Pulse
	 * offset 1698
	 */
	uint8_t tachPulsePerRev;
	/**
	 * need 4 byte alignment
	units
	 * offset 1699
	 */
	uint8_t alignmentFill_at_1699[1];
	/**
	 * kPa value which is too low to be true
	kPa
	 * offset 1700
	 */
	float mapErrorDetectionTooLow;
	/**
	 * kPa value which is too high to be true
	kPa
	 * offset 1704
	 */
	float mapErrorDetectionTooHigh;
	/**
	 * How long to wait for the spark to fire before recharging the coil for another spark.
	ms
	 * offset 1708
	 */
	scaled_channel<uint16_t, 1000, 1> multisparkSparkDuration;
	/**
	 * This sets the dwell time for subsequent sparks. The main spark's dwell is set by the dwell table.
	ms
	 * offset 1710
	 */
	scaled_channel<uint16_t, 1000, 1> multisparkDwell;
	/**
	 * See cltIdleRpmBins
	 * offset 1712
	 */
	pid_s idleRpmPid;
	/**
	 * 0 = No fuel settling on port walls 1 = All the fuel settling on port walls setting this to 0 disables the wall wetting enrichment.
	Fraction
	 * offset 1732
	 */
	float wwaeBeta;
	/**
	 * blue LED on many rusEFI boards.
	 * Blue Communication LED which is expected to blink at 50% duty cycle during normal board operation.
	 * If USB communication cable is connected Blue LED starts to blink faster.
	 * offset 1736
	 */
	Gpio communicationLedPin;
	/**
	 * Green LED on many rusEFI boards.
	 * Off if engine is stopped, blinks if engine is cranking, solid if engine is running.
	 * offset 1738
	 */
	Gpio runningLedPin;
	/**
	 * See also EFI_CONSOLE_RX_BRAIN_PIN
	 * offset 1740
	 */
	Gpio binarySerialTxPin;
	/**
	 * offset 1742
	 */
	Gpio binarySerialRxPin;
	/**
	 * offset 1744
	 */
	Gpio auxValves[AUX_DIGITAL_VALVE_COUNT];
	/**
	 * offset 1748
	 */
	switch_input_pin_e tcuUpshiftButtonPin;
	/**
	 * offset 1750
	 */
	switch_input_pin_e tcuDownshiftButtonPin;
	/**
	voltage
	 * offset 1752
	 */
	float throttlePedalUpVoltage;
	/**
	 * Pedal in the floor
	voltage
	 * offset 1756
	 */
	float throttlePedalWOTVoltage;
	/**
	 * on ECU start turn fuel pump on to build fuel pressure
	seconds
	 * offset 1760
	 */
	int16_t startUpFuelPumpDuration;
	/**
	 * If the RPM closer to target than this value, disable closed loop idle correction to prevent oscillation
	RPM
	 * offset 1762
	 */
	int16_t idlePidRpmDeadZone;
	/**
	 * CLT-based target RPM for automatic idle controller
	C
	 * offset 1764
	 */
	float cltIdleRpmBins[CLT_CURVE_SIZE];
	/**
	 * See idleRpmPid
	RPM
	 * offset 1828
	 */
	scaled_channel<uint8_t, 1, 50> cltIdleRpm[CLT_CURVE_SIZE];
	/**
	 * This is the target battery voltage the alternator PID control will attempt to maintain
	Volts
	 * offset 1844
	 */
	float targetVBatt;
	/**
	 * Turns off alternator output above specified TPS, enabling this reduced parasitic drag on the engine at full load.
	%
	 * offset 1848
	 */
	float alternatorOffAboveTps;
	/**
	 * This is the duration in cycles that the IAC will take to reach its normal idle position, it can be used to hold the idle higher for a few seconds after cranking to improve startup.
	cycles
	 * offset 1852
	 */
	int16_t afterCrankingIACtaperDuration;
	/**
	 * Extra IAC, in percent between 0 and 100, tapered between zero and idle deactivation TPS value
	percent
	 * offset 1854
	 */
	int16_t iacByTpsTaper;
	/**
	 * Auxiliary sensor serial, not to be confused with secondary calibration serial
	 * set_aux_tx_pin X
	 * offset 1856
	 */
	Gpio auxSerialTxPin;
	/**
	 * offset 1858
	 */
	Gpio warningLedPin;
	/**
	 * Auxiliary sensor serial, not to be confused with secondary calibration serial
	 * set_aux_rx_pin X
	 * offset 1860
	 */
	Gpio auxSerialRxPin;
	/**
	 * offset 1862
	 */
	Gpio LIS302DLCsPin;
	/**
	 * How long to look back for TPS-based acceleration enrichment. Increasing this time will trigger enrichment for longer when a throttle position change occurs.
	sec
	 * offset 1864
	 */
	scaled_channel<uint8_t, 20, 1> tpsAccelLookback;
	/**
	 * Below this speed, disable DFCO. Use this to prevent jerkiness from fuel enable/disable in low gears.
	kph
	 * offset 1865
	 */
	uint8_t coastingFuelCutVssLow;
	/**
	 * Above this speed, allow DFCO. Use this to prevent jerkiness from fuel enable/disable in low gears.
	kph
	 * offset 1866
	 */
	uint8_t coastingFuelCutVssHigh;
	/**
	 * Pause closed loop fueling after deceleration fuel cut occurs. Set this to a little longer than however long is required for normal fueling behavior to resume after fuel cut.
	sec
	 * offset 1867
	 */
	scaled_channel<uint8_t, 10, 1> noFuelTrimAfterDfcoTime;
	/**
	 * Maximum change delta of TPS percentage over the 'length'. Actual TPS change has to be above this value in order for TPS/TPS acceleration to kick in.
	roc
	 * offset 1868
	 */
	float tpsAccelEnrichmentThreshold;
	/**
	 * offset 1872
	 */
	brain_input_pin_e auxSpeedSensorInputPin[2];
	/**
	 * offset 1876
	 */
	uint8_t totalGearsCount;
	/**
	 * Sets what part of injection's is controlled by the injection phase table.
	 * offset 1877
	 */
	InjectionTimingMode injectionTimingMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 1878
	 */
	uint8_t alignmentFill_at_1878[2];
	/**
	 * Band rate for primary TTL
	BPs
	 * offset 1880
	 */
	uint32_t uartConsoleSerialSpeed;
	/**
	 * For decel we simply multiply delta of TPS and tFor decel we do not use table?!
	roc
	 * offset 1884
	 */
	float tpsDecelEnleanmentThreshold;
	/**
	 * Magic multiplier, we multiply delta of TPS and get fuel squirt duration
	coeff
	 * offset 1888
	 */
	float tpsDecelEnleanmentMultiplier;
	/**
	 * ExpAverage alpha coefficient
	coeff
	 * offset 1892
	 */
	float slowAdcAlpha;
	/**
	 * See http://rusefi.com/s/debugmode
	 * 
	 * set debug_mode X
	 * offset 1896
	 */
	debug_mode_e debugMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 1897
	 */
	uint8_t alignmentFill_at_1897[3];
	/**
	BPs
	 * offset 1900
	 */
	uint32_t auxSerialSpeed;
	/**
	voltage
	 * offset 1904
	 */
	float throttlePedalSecondaryUpVoltage;
	/**
	 * Pedal in the floor
	voltage
	 * offset 1908
	 */
	float throttlePedalSecondaryWOTVoltage;
	/**
	 * set can_baudrate
	 * offset 1912
	 */
	can_baudrate_e canBaudRate;
	/**
	 * Override the Y axis (load) value used for the VE table.
	 * Advanced users only: If you aren't sure you need this, you probably don't need this.
	 * offset 1913
	 */
	ve_override_e veOverrideMode;
	/**
	 * offset 1914
	 */
	can_baudrate_e can2BaudRate;
	/**
	 * Override the Y axis (load) value used for the AFR table.
	 * Advanced users only: If you aren't sure you need this, you probably don't need this.
	 * offset 1915
	 */
	load_override_e afrOverrideMode;
	/**
	A
	 * offset 1916
	 */
	scaled_channel<uint8_t, 10, 1> mc33_hpfp_i_peak;
	/**
	A
	 * offset 1917
	 */
	scaled_channel<uint8_t, 10, 1> mc33_hpfp_i_hold;
	/**
	 * How long to deactivate power when hold current is reached before applying power again
	us
	 * offset 1918
	 */
	uint8_t mc33_hpfp_i_hold_off;
	/**
	 * Maximum amount of time the solenoid can be active before assuming a programming error
	ms
	 * offset 1919
	 */
	uint8_t mc33_hpfp_max_hold;
	/**
	 * Enable if DC-motor driver (H-bridge) inverts the signals (eg. RZ7899 on Hellen boards)
	offset 1920 bit 0 */
	bool stepperDcInvertedPins : 1 {};
	/**
	offset 1920 bit 1 */
	bool unused1740b0 : 1 {};
	/**
	offset 1920 bit 2 */
	bool unused1740b1 : 1 {};
	/**
	offset 1920 bit 3 */
	bool unused1740b2 : 1 {};
	/**
	offset 1920 bit 4 */
	bool unused1127 : 1 {};
	/**
	offset 1920 bit 5 */
	bool unused1128 : 1 {};
	/**
	offset 1920 bit 6 */
	bool unused1129 : 1 {};
	/**
	offset 1920 bit 7 */
	bool unused1130 : 1 {};
	/**
	offset 1920 bit 8 */
	bool unusedBit_538_8 : 1 {};
	/**
	offset 1920 bit 9 */
	bool unusedBit_538_9 : 1 {};
	/**
	offset 1920 bit 10 */
	bool unusedBit_538_10 : 1 {};
	/**
	offset 1920 bit 11 */
	bool unusedBit_538_11 : 1 {};
	/**
	offset 1920 bit 12 */
	bool unusedBit_538_12 : 1 {};
	/**
	offset 1920 bit 13 */
	bool unusedBit_538_13 : 1 {};
	/**
	offset 1920 bit 14 */
	bool unusedBit_538_14 : 1 {};
	/**
	offset 1920 bit 15 */
	bool unusedBit_538_15 : 1 {};
	/**
	offset 1920 bit 16 */
	bool unusedBit_538_16 : 1 {};
	/**
	offset 1920 bit 17 */
	bool unusedBit_538_17 : 1 {};
	/**
	offset 1920 bit 18 */
	bool unusedBit_538_18 : 1 {};
	/**
	offset 1920 bit 19 */
	bool unusedBit_538_19 : 1 {};
	/**
	offset 1920 bit 20 */
	bool unusedBit_538_20 : 1 {};
	/**
	offset 1920 bit 21 */
	bool unusedBit_538_21 : 1 {};
	/**
	offset 1920 bit 22 */
	bool unusedBit_538_22 : 1 {};
	/**
	offset 1920 bit 23 */
	bool unusedBit_538_23 : 1 {};
	/**
	offset 1920 bit 24 */
	bool unusedBit_538_24 : 1 {};
	/**
	offset 1920 bit 25 */
	bool unusedBit_538_25 : 1 {};
	/**
	offset 1920 bit 26 */
	bool unusedBit_538_26 : 1 {};
	/**
	offset 1920 bit 27 */
	bool unusedBit_538_27 : 1 {};
	/**
	offset 1920 bit 28 */
	bool unusedBit_538_28 : 1 {};
	/**
	offset 1920 bit 29 */
	bool unusedBit_538_29 : 1 {};
	/**
	offset 1920 bit 30 */
	bool unusedBit_538_30 : 1 {};
	/**
	offset 1920 bit 31 */
	bool unusedBit_538_31 : 1 {};
	/**
	ms
	 * offset 1924
	 */
	scaled_channel<uint8_t, 1, 5> benchTestOffTime;
	/**
	count
	 * offset 1925
	 */
	uint8_t benchTestCount;
	/**
	ms
	 * offset 1926
	 */
	scaled_channel<uint8_t, 1, 5> benchTestOnTime;
	/**
	 * offset 1927
	 */
	pin_input_mode_e launchActivatePinMode;
	/**
	 * set_can2_tx_pin X
	 * offset 1928
	 */
	Gpio can2TxPin;
	/**
	 * set_can2_rx_pin X
	 * offset 1930
	 */
	Gpio can2RxPin;
	/**
	 * offset 1932
	 */
	pin_output_mode_e starterControlPinMode;
	/**
	 * offset 1933
	 */
	adc_channel_e wastegatePositionSensor;
	/**
	 * Override the Y axis (load) value used for the ignition table.
	 * Advanced users only: If you aren't sure you need this, you probably don't need this.
	 * offset 1934
	 */
	load_override_e ignOverrideMode;
	/**
	 * Select which fuel pressure sensor measures the pressure of the fuel at your injectors.
	 * offset 1935
	 */
	injector_pressure_type_e injectorPressureType;
	/**
	 * offset 1936
	 */
	output_pin_e hpfpValvePin;
	/**
	 * offset 1938
	 */
	pin_output_mode_e hpfpValvePinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 1939
	 */
	uint8_t alignmentFill_at_1939[1];
	/**
	 * MAP value above which fuel is cut in case of overboost.
	 * Set to 0 to disable overboost cut.
	kPa (absolute)
	 * offset 1940
	 */
	float boostCutPressure;
	/**
	kg/h
	 * offset 1944
	 */
	scaled_channel<uint8_t, 1, 5> tchargeBins[16];
	/**
	ratio
	 * offset 1960
	 */
	scaled_channel<uint8_t, 100, 1> tchargeValues[16];
	/**
	 * Fixed timing, useful for TDC testing
	deg
	 * offset 1976
	 */
	float fixedTiming;
	/**
	 * MAP voltage for low point
	v
	 * offset 1980
	 */
	float mapLowValueVoltage;
	/**
	 * MAP voltage for low point
	v
	 * offset 1984
	 */
	float mapHighValueVoltage;
	/**
	 * EGO value correction
	value
	 * offset 1988
	 */
	float egoValueShift;
	/**
	 * offset 1992
	 */
	output_pin_e vvtPins[CAM_INPUTS_COUNT];
	/**
	 * offset 2000
	 */
	spi_device_e cj125SpiDevice;
	/**
	 * offset 2001
	 */
	pin_output_mode_e cj125CsPinMode;
	/**
	 * offset 2002
	 */
	pin_output_mode_e sdCardCsPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 2003
	 */
	uint8_t alignmentFill_at_2003[1];
	/**
	 * This is the IAC position during cranking, some engines start better if given more air during cranking to improve cylinder filling.
	percent
	 * offset 2004
	 */
	int crankingIACposition;
	/**
	 * offset 2008
	 */
	float tChargeMinRpmMinTps;
	/**
	 * offset 2012
	 */
	float tChargeMinRpmMaxTps;
	/**
	 * offset 2016
	 */
	float tChargeMaxRpmMinTps;
	/**
	 * offset 2020
	 */
	float tChargeMaxRpmMaxTps;
	/**
	 * offset 2024
	 */
	pwm_freq_t vvtOutputFrequency[CAMS_PER_BANK];
	/**
	 * Additional idle % when fan #1 is active
	%
	 * offset 2028
	 */
	uint8_t fan1ExtraIdle;
	/**
	 * need 4 byte alignment
	units
	 * offset 2029
	 */
	uint8_t alignmentFill_at_2029[3];
	/**
	Hz
	 * offset 2032
	 */
	int alternatorPwmFrequency;
	/**
	 * Narrow Band WBO Approximation
	V
	 * offset 2036
	 */
	float narrowToWideOxygenBins[NARROW_BAND_WIDE_BAND_CONVERSION_SIZE];
	/**
	ratio
	 * offset 2068
	 */
	float narrowToWideOxygen[NARROW_BAND_WIDE_BAND_CONVERSION_SIZE];
	/**
	 * set vvt_mode X
	 * offset 2100
	 */
	vvt_mode_e vvtMode[CAMS_PER_BANK];
	/**
	 * offset 2102
	 */
	uint8_t vvtModePadding[CAMS_PER_BANK_padding];
	/**
	 * Additional idle % when fan #2 is active
	%
	 * offset 2102
	 */
	uint8_t fan2ExtraIdle;
	/**
	 * Delay to allow fuel pressure to build before firing the priming pulse.
	sec
	 * offset 2103
	 */
	scaled_channel<uint8_t, 100, 1> primingDelay;
	/**
	 * offset 2104
	 */
	adc_channel_e auxAnalogInputs[AUX_ANALOG_INPUT_COUNT];
	/**
	 * offset 2112
	 */
	output_pin_e trailingCoilPins[MAX_CYLINDER_COUNT];
	/**
	 * CLT-based timing correction
	C
	 * offset 2136
	 */
	float cltTimingBins[CLT_TIMING_CURVE_SIZE];
	/**
	degree
	 * offset 2168
	 */
	float cltTimingExtra[CLT_TIMING_CURVE_SIZE];
	/**
	 * offset 2200
	 */
	tle8888_mode_e tle8888mode;
	/**
	 * offset 2201
	 */
	pin_output_mode_e LIS302DLCsPinMode;
	/**
	 * None = I have a MAP-referenced fuel pressure regulator
	 * Fixed rail pressure = I have an atmosphere-referenced fuel pressure regulator (returnless, typically)
	 * Sensed rail pressure = I have a fuel pressure sensor
	 * offset 2202
	 */
	injector_compensation_mode_e injectorCompensationMode;
	/**
	 * offset 2203
	 */
	pin_output_mode_e fan2PinMode;
	/**
	 * This is the pressure at which your injector flow is known.
	 * For example if your injectors flow 400cc/min at 3.5 bar, enter 350kpa here.
	kPa
	 * offset 2204
	 */
	float fuelReferencePressure;
	/**
	 * Fuel multiplier (enrichment) immediately after engine start
	mult
	 * offset 2208
	 */
	float postCrankingFactor;
	/**
	 * Time over which to taper out after start enrichment
	seconds
	 * offset 2212
	 */
	float postCrankingDurationSec;
	/**
	 * offset 2216
	 */
	ThermistorConf auxTempSensor1;
	/**
	 * offset 2248
	 */
	ThermistorConf auxTempSensor2;
	/**
	Deg
	 * offset 2280
	 */
	int16_t knockSamplingDuration;
	/**
	Hz
	 * offset 2282
	 */
	int16_t etbFreq;
	/**
	 * offset 2284
	 */
	pid_s etbWastegatePid;
	/**
	 * For micro-stepping, make sure that PWM frequency (etbFreq) is high enough
	 * offset 2304
	 */
	stepper_num_micro_steps_e stepperNumMicroSteps;
	/**
	 * Use to limit the current when the stepper motor is idle, not moving (100% = no limit)
	%
	 * offset 2305
	 */
	uint8_t stepperMinDutyCycle;
	/**
	 * Use to limit the max.current through the stepper motor (100% = no limit)
	%
	 * offset 2306
	 */
	uint8_t stepperMaxDutyCycle;
	/**
	 * offset 2307
	 */
	spi_device_e sdCardSpiDevice;
	/**
	 * per-cylinder timing correction
	deg
	 * offset 2308
	 */
	angle_t timing_offset_cylinder[MAX_CYLINDER_COUNT];
	/**
	seconds
	 * offset 2356
	 */
	float idlePidActivationTime;
	/**
	 * offset 2360
	 */
	pin_mode_e spi1SckMode;
	/**
	 * Modes count be used for 3v<>5v integration using pull-ups/pull-downs etc.
	 * offset 2361
	 */
	pin_mode_e spi1MosiMode;
	/**
	 * offset 2362
	 */
	pin_mode_e spi1MisoMode;
	/**
	 * offset 2363
	 */
	pin_mode_e spi2SckMode;
	/**
	 * offset 2364
	 */
	pin_mode_e spi2MosiMode;
	/**
	 * offset 2365
	 */
	pin_mode_e spi2MisoMode;
	/**
	 * offset 2366
	 */
	pin_mode_e spi3SckMode;
	/**
	 * offset 2367
	 */
	pin_mode_e spi3MosiMode;
	/**
	 * offset 2368
	 */
	pin_mode_e spi3MisoMode;
	/**
	 * offset 2369
	 */
	pin_output_mode_e stepperEnablePinMode;
	/**
	 * ResetB
	 * offset 2370
	 */
	Gpio mc33816_rstb;
	/**
	 * offset 2372
	 */
	Gpio mc33816_driven;
	/**
	 * Brake pedal switch
	 * offset 2374
	 */
	switch_input_pin_e brakePedalPin;
	/**
	 * lambda input
	 * offset 2376
	 */
	adc_channel_e cj125ua;
	/**
	 * heater input
	 * offset 2377
	 */
	adc_channel_e cj125ur;
	/**
	 * offset 2378
	 */
	pin_input_mode_e brakePedalPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 2379
	 */
	uint8_t alignmentFill_at_2379[1];
	/**
	 * offset 2380
	 */
	pid_s auxPid[CAMS_PER_BANK];
	/**
	 * offset 2420
	 */
	float injectorCorrectionPolynomial[8];
	/**
	C
	 * offset 2452
	 */
	int8_t primeBins[8];
	/**
	 * offset 2460
	 */
	linear_sensor_s oilPressure;
	/**
	 * offset 2480
	 */
	spi_device_e accelerometerSpiDevice;
	/**
	 * need 4 byte alignment
	units
	 * offset 2481
	 */
	uint8_t alignmentFill_at_2481[1];
	/**
	 * offset 2482
	 */
	output_pin_e fan2Pin;
	/**
	 * Cooling fan turn-on temperature threshold, in Celsius
	deg C
	 * offset 2484
	 */
	uint8_t fan2OnTemperature;
	/**
	 * Cooling fan turn-off temperature threshold, in Celsius
	deg C
	 * offset 2485
	 */
	uint8_t fan2OffTemperature;
	/**
	 * need 4 byte alignment
	units
	 * offset 2486
	 */
	uint8_t alignmentFill_at_2486[2];
	/**
	x
	 * offset 2488
	 */
	float scriptCurve1Bins[SCRIPT_CURVE_16];
	/**
	y
	 * offset 2552
	 */
	float scriptCurve1[SCRIPT_CURVE_16];
	/**
	x
	 * offset 2616
	 */
	float scriptCurve2Bins[SCRIPT_CURVE_16];
	/**
	y
	 * offset 2680
	 */
	float scriptCurve2[SCRIPT_CURVE_16];
	/**
	x
	 * offset 2744
	 */
	float scriptCurve3Bins[SCRIPT_CURVE_8];
	/**
	y
	 * offset 2776
	 */
	float scriptCurve3[SCRIPT_CURVE_8];
	/**
	x
	 * offset 2808
	 */
	float scriptCurve4Bins[SCRIPT_CURVE_8];
	/**
	y
	 * offset 2840
	 */
	float scriptCurve4[SCRIPT_CURVE_8];
	/**
	 * offset 2872
	 */
	Gpio stepperEnablePin;
	/**
	 * offset 2874
	 */
	Gpio tle8888_cs;
	/**
	 * offset 2876
	 */
	pin_output_mode_e tle8888_csPinMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 2877
	 */
	uint8_t alignmentFill_at_2877[1];
	/**
	 * offset 2878
	 */
	Gpio mc33816_cs;
	/**
	 * Optional timing advance table for Cranking (see useSeparateAdvanceForCranking)
	RPM
	 * offset 2880
	 */
	float crankingAdvanceBins[CRANKING_ADVANCE_CURVE_SIZE];
	/**
	 * Optional timing advance table for Cranking (see useSeparateAdvanceForCranking)
	deg
	 * offset 2896
	 */
	float crankingAdvance[CRANKING_ADVANCE_CURVE_SIZE];
	/**
	 * todo: more comments
	 * offset 2912
	 */
	Gpio servoOutputPins[SERVO_COUNT];
	/**
	 * This sets the RPM above which fuel cut is active.
	rpm
	 * offset 2928
	 */
	int16_t coastingFuelCutRpmHigh;
	/**
	 * This sets the RPM below which fuel cut is deactivated, this prevents jerking or issues transitioning to idle
	rpm
	 * offset 2930
	 */
	int16_t coastingFuelCutRpmLow;
	/**
	 * Throttle position below which fuel cut is active. With an electronic throttle enabled, this checks against pedal position.
	%
	 * offset 2932
	 */
	int16_t coastingFuelCutTps;
	/**
	 * Fuel cutoff is disabled when the engine is cold.
	C
	 * offset 2934
	 */
	int16_t coastingFuelCutClt;
	/**
	 * Increases PID reaction for RPM<target by adding extra percent to PID-error
	%
	 * offset 2936
	 */
	int16_t pidExtraForLowRpm;
	/**
	 * MAP value above which fuel injection is re-enabled.
	kPa
	 * offset 2938
	 */
	int16_t coastingFuelCutMap;
	/**
	 * CLT-based idle position for coasting (used in Auto-PID Idle mode)
	C
	 * offset 2940
	 */
	float iacCoastingBins[CLT_CURVE_SIZE];
	/**
	 * CLT-based idle position for coasting (used in Auto-PID Idle mode)
	%
	 * offset 3004
	 */
	float iacCoasting[CLT_CURVE_SIZE];
	/**
	 * offset 3068
	 */
	linear_sensor_s highPressureFuel;
	/**
	 * offset 3088
	 */
	linear_sensor_s lowPressureFuel;
	/**
	 * CLT-based target RPM for hard limit depending on CLT like on Lexus LFA
	C
	 * offset 3108
	 */
	int8_t cltRevLimitRpmBins[CLT_LIMITER_CURVE_SIZE];
	/**
	 * See idleRpmPid
	 * offset 3112
	 */
	uint16_t cltRevLimitRpm[CLT_LIMITER_CURVE_SIZE];
	/**
	 * offset 3120
	 */
	gppwm_note_t scriptCurveName[SCRIPT_CURVE_COUNT];
	/**
	x
	 * offset 3216
	 */
	float scriptCurve5Bins[SCRIPT_CURVE_8];
	/**
	y
	 * offset 3248
	 */
	float scriptCurve5[SCRIPT_CURVE_8];
	/**
	x
	 * offset 3280
	 */
	float scriptCurve6Bins[SCRIPT_CURVE_8];
	/**
	y
	 * offset 3312
	 */
	float scriptCurve6[SCRIPT_CURVE_8];
	/**
	 * offset 3344
	 */
	gppwm_note_t scriptTableName[SCRIPT_TABLE_COUNT];
	/**
	 * offset 3408
	 */
	gppwm_note_t scriptSettingName[SCRIPT_SETTING_COUNT];
	/**
	 * Heat transfer coefficient at zero flow.
	 * 0 means the air charge is fully heated to the same temperature as CLT.
	 * 1 means the air charge gains no heat, and enters the cylinder at the temperature measured by IAT.
	 * offset 3536
	 */
	float tChargeAirCoefMin;
	/**
	 * Heat transfer coefficient at high flow, as defined by "max air flow".
	 * 0 means the air charge is fully heated to the same temperature as CLT.
	 * 1 means the air charge gains no heat, and enters the cylinder at the temperature measured by IAT.
	 * offset 3540
	 */
	float tChargeAirCoefMax;
	/**
	 * High flow point for heat transfer estimation.
	 * Set this to perhaps 50-75% of your maximum airflow at wide open throttle.
	kg/h
	 * offset 3544
	 */
	float tChargeAirFlowMax;
	/**
	 * Maximum allowed rate of increase allowed for the estimated charge temperature
	deg/sec
	 * offset 3548
	 */
	float tChargeAirIncrLimit;
	/**
	 * Maximum allowed rate of decrease allowed for the estimated charge temperature
	deg/sec
	 * offset 3552
	 */
	float tChargeAirDecrLimit;
	/**
	 * offset 3556
	 */
	tChargeMode_e tChargeMode;
	/**
	 * target TPS value, 0 to 100%
	 * TODO: use int8 data date once we template interpolation method
	target TPS position
	 * offset 3560
	 */
	float etbBiasBins[ETB_BIAS_CURVE_LENGTH];
	/**
	 * PWM bias, 0 to 100%
	ETB duty cycle bias
	 * offset 3592
	 */
	float etbBiasValues[ETB_BIAS_CURVE_LENGTH];
	/**
	 * offset 3624
	 */
	float hip9011Gain;
	/**
	 * iTerm min value
	 * offset 3628
	 */
	int16_t etb_iTermMin;
	/**
	 * iTerm max value
	 * offset 3630
	 */
	int16_t etb_iTermMax;
	/**
	 * See useIdleTimingPidControl
	 * offset 3632
	 */
	pid_s idleTimingPid;
	/**
	 * If the RPM closer to target than this value, disable timing correction to prevent oscillation
	RPM
	 * offset 3652
	 */
	int16_t idleTimingPidDeadZone;
	/**
	 * A delay in cycles between fuel-enrich. portions
	cycles
	 * offset 3654
	 */
	int16_t tpsAccelFractionPeriod;
	/**
	 * A fraction divisor: 1 or less = entire portion at once, or split into diminishing fractions
	coef
	 * offset 3656
	 */
	float tpsAccelFractionDivisor;
	/**
	 * offset 3660
	 */
	spi_device_e tle8888spiDevice;
	/**
	 * offset 3661
	 */
	spi_device_e mc33816spiDevice;
	/**
	 * iTerm min value
	 * offset 3662
	 */
	int16_t idlerpmpid_iTermMin;
	/**
	 * offset 3664
	 */
	spi_device_e tle6240spiDevice;
	/**
	 * Stoichiometric ratio for your primary fuel. When Flex Fuel is enabled, this value is used when the Flex Fuel sensor indicates E0.
	 * E0 = 14.7
	 * E10 = 14.1
	 * E85 = 9.9
	 * E100 = 9.0
	:1
	 * offset 3665
	 */
	scaled_channel<uint8_t, 10, 1> stoichRatioPrimary;
	/**
	 * iTerm max value
	 * offset 3666
	 */
	int16_t idlerpmpid_iTermMax;
	/**
	 * This sets the range of the idle control on the ETB. At 100% idle position, the value specified here sets the base ETB position.
	%
	 * offset 3668
	 */
	float etbIdleThrottleRange;
	/**
	 * Select which fuel correction bank this cylinder belongs to. Group cylinders that share the same O2 sensor
	 * offset 3672
	 */
	uint8_t cylinderBankSelect[MAX_CYLINDER_COUNT];
	/**
	mg
	 * offset 3684
	 */
	scaled_channel<uint8_t, 1, 5> primeValues[8];
	/**
	 * Trigger comparator center point voltage
	V
	 * offset 3692
	 */
	uint8_t triggerCompCenterVolt;
	/**
	 * Trigger comparator hysteresis voltage (Min)
	V
	 * offset 3693
	 */
	uint8_t triggerCompHystMin;
	/**
	 * Trigger comparator hysteresis voltage (Max)
	V
	 * offset 3694
	 */
	uint8_t triggerCompHystMax;
	/**
	 * VR-sensor saturation RPM
	RPM
	 * offset 3695
	 */
	scaled_channel<uint8_t, 1, 50> triggerCompSensorSatRpm;
	/**
	 * offset 3696
	 */
	pid_s idleRpmPid2;
	/**
	%
	 * offset 3716
	 */
	uint8_t iacPidMultTable[IAC_PID_MULT_SIZE][IAC_PID_MULT_SIZE];
	/**
	Load
	 * offset 3780
	 */
	uint8_t iacPidMultLoadBins[IAC_PID_MULT_SIZE];
	/**
	RPM
	 * offset 3788
	 */
	scaled_channel<uint8_t, 1, 50> iacPidMultRpmBins[IAC_PID_MULT_SIZE];
	/**
	 * set can_vss X
	 * offset 3796
	 */
	can_vss_nbc_e canVssNbcType;
	/**
	 * offset 3800
	 */
	gppwm_channel gppwm[GPPWM_CHANNELS];
	/**
	mA
	 * offset 4168
	 */
	uint16_t mc33_i_boost;
	/**
	mA
	 * offset 4170
	 */
	uint16_t mc33_i_peak;
	/**
	mA
	 * offset 4172
	 */
	uint16_t mc33_i_hold;
	/**
	us
	 * offset 4174
	 */
	uint16_t mc33_t_max_boost;
	/**
	us
	 * offset 4176
	 */
	uint16_t mc33_t_peak_off;
	/**
	us
	 * offset 4178
	 */
	uint16_t mc33_t_peak_tot;
	/**
	us
	 * offset 4180
	 */
	uint16_t mc33_t_bypass;
	/**
	us
	 * offset 4182
	 */
	uint16_t mc33_t_hold_off;
	/**
	us
	 * offset 4184
	 */
	uint16_t mc33_t_hold_tot;
	/**
	 * offset 4186
	 */
	pin_input_mode_e tcuUpshiftButtonPinMode;
	/**
	 * offset 4187
	 */
	pin_input_mode_e tcuDownshiftButtonPinMode;
	/**
	 * offset 4188
	 */
	pin_input_mode_e acSwitchMode;
	/**
	 * offset 4189
	 */
	pin_output_mode_e tcu_solenoid_mode[TCU_SOLENOID_COUNT];
	/**
	 * Knock sensor output knock detection threshold depending on current RPM.
	dB
	 * offset 4195
	 */
	scaled_channel<int8_t, 2, 1> knockBaseNoise[ENGINE_NOISE_CURVE_SIZE];
	/**
	 * need 4 byte alignment
	units
	 * offset 4211
	 */
	uint8_t alignmentFill_at_4211[1];
	/**
	from
	 * offset 4212
	 */
	float triggerGapOverrideFrom[GAP_TRACKING_LENGTH];
	/**
	 * offset 4284
	 */
	int8_t unused4080[12];
	/**
	to
	 * offset 4296
	 */
	float triggerGapOverrideTo[GAP_TRACKING_LENGTH];
	/**
	lobes/cam
	 * offset 4368
	 */
	uint8_t hpfpCamLobes;
	/**
	 * offset 4369
	 */
	hpfp_cam_e hpfpCam;
	/**
	 * Crank angle ATDC of first lobe peak
	deg
	 * offset 4370
	 */
	uint8_t hpfpPeakPos;
	/**
	 * If the requested activation time is below this angle, don't bother running the pump
	deg
	 * offset 4371
	 */
	uint8_t hpfpMinAngle;
	/**
	 * Size of the pump chamber in cc. Typical Bosch HDP5 has a 9.0mm diameter, typical BMW N* stroke is 4.4mm.
	cc
	 * offset 4372
	 */
	scaled_channel<uint16_t, 1000, 1> hpfpPumpVolume;
	/**
	 * How long to keep the valve activated (in order to allow the pump to build pressure and keep the valve open on its own)
	deg
	 * offset 4374
	 */
	uint8_t hpfpActivationAngle;
	/**
	 * offset 4375
	 */
	uint8_t issFilterReciprocal;
	/**
	%/kPa
	 * offset 4376
	 */
	scaled_channel<uint16_t, 1000, 1> hpfpPidP;
	/**
	%/kPa/lobe
	 * offset 4378
	 */
	scaled_channel<uint16_t, 100000, 1> hpfpPidI;
	/**
	 * The fastest rate the target pressure can be reduced by. This is because HPFP have no way to bleed off pressure other than injecting fuel.
	kPa/s
	 * offset 4380
	 */
	uint16_t hpfpTargetDecay;
	/**
	%
	 * offset 4382
	 */
	scaled_channel<uint8_t, 2, 1> hpfpLobeProfileQuantityBins[HPFP_LOBE_PROFILE_SIZE];
	/**
	deg
	 * offset 4398
	 */
	scaled_channel<uint8_t, 2, 1> hpfpLobeProfileAngle[HPFP_LOBE_PROFILE_SIZE];
	/**
	volts
	 * offset 4414
	 */
	uint8_t hpfpDeadtimeVoltsBins[HPFP_DEADTIME_SIZE];
	/**
	ms
	 * offset 4422
	 */
	scaled_channel<uint16_t, 1000, 1> hpfpDeadtimeMS[HPFP_DEADTIME_SIZE];
	/**
	kPa
	 * offset 4438
	 */
	uint16_t hpfpTarget[HPFP_TARGET_SIZE][HPFP_TARGET_SIZE];
	/**
	load
	 * offset 4638
	 */
	scaled_channel<uint16_t, 10, 1> hpfpTargetLoadBins[HPFP_TARGET_SIZE];
	/**
	RPM
	 * offset 4658
	 */
	scaled_channel<uint8_t, 1, 50> hpfpTargetRpmBins[HPFP_TARGET_SIZE];
	/**
	%
	 * offset 4668
	 */
	int8_t hpfpCompensation[HPFP_COMPENSATION_SIZE][HPFP_COMPENSATION_SIZE];
	/**
	cc/lobe
	 * offset 4768
	 */
	scaled_channel<uint16_t, 1000, 1> hpfpCompensationLoadBins[HPFP_COMPENSATION_SIZE];
	/**
	RPM
	 * offset 4788
	 */
	scaled_channel<uint8_t, 1, 50> hpfpCompensationRpmBins[HPFP_COMPENSATION_SIZE];
	/**
	 * offset 4798
	 */
	output_pin_e stepper_raw_output[4];
	/**
	ratio
	 * offset 4806
	 */
	scaled_channel<uint16_t, 100, 1> gearRatio[GEARS_COUNT];
	/**
	 * We need to give engine time to build oil pressure without diverting it to VVT
	ms
	 * offset 4822
	 */
	uint16_t vvtActivationDelayMs;
	/**
	deg C
	 * offset 4824
	 */
	int8_t wwCltBins[WWAE_TABLE_SIZE];
	/**
	 * offset 4832
	 */
	scaled_channel<uint8_t, 100, 1> wwTauCltValues[WWAE_TABLE_SIZE];
	/**
	 * offset 4840
	 */
	scaled_channel<uint8_t, 100, 1> wwBetaCltValues[WWAE_TABLE_SIZE];
	/**
	kPa
	 * offset 4848
	 */
	int8_t wwMapBins[WWAE_TABLE_SIZE];
	/**
	 * offset 4856
	 */
	scaled_channel<uint8_t, 100, 1> wwTauMapValues[WWAE_TABLE_SIZE];
	/**
	 * offset 4864
	 */
	scaled_channel<uint8_t, 100, 1> wwBetaMapValues[WWAE_TABLE_SIZE];
	/**
	Nm
	 * offset 4872
	 */
	scaled_channel<uint8_t, 1, 10> torqueTable[TORQUE_CURVE_SIZE][TORQUE_CURVE_SIZE];
	/**
	RPM
	 * offset 4908
	 */
	uint16_t torqueRpmBins[TORQUE_CURVE_SIZE];
	/**
	Load
	 * offset 4920
	 */
	uint16_t torqueLoadBins[TORQUE_CURVE_SIZE];
	/**
	 * offset 4932
	 */
	GearControllerMode gearControllerMode;
	/**
	 * offset 4933
	 */
	TransmissionControllerMode transmissionControllerMode;
	/**
	 * need 4 byte alignment
	units
	 * offset 4934
	 */
	uint8_t alignmentFill_at_4934[2];
	/**
	 * offset 4936
	 */
	linear_sensor_s auxLinear1;
	/**
	 * offset 4956
	 */
	linear_sensor_s auxLinear2;
	/**
	 * offset 4976
	 */
	output_pin_e tcu_tcc_onoff_solenoid;
	/**
	 * offset 4978
	 */
	pin_output_mode_e tcu_tcc_onoff_solenoid_mode;
	/**
	 * need 4 byte alignment
	units
	 * offset 4979
	 */
	uint8_t alignmentFill_at_4979[1];
	/**
	 * offset 4980
	 */
	output_pin_e tcu_tcc_pwm_solenoid;
	/**
	 * offset 4982
	 */
	pin_output_mode_e tcu_tcc_pwm_solenoid_mode;
	/**
	 * need 4 byte alignment
	units
	 * offset 4983
	 */
	uint8_t alignmentFill_at_4983[1];
	/**
	 * offset 4984
	 */
	pwm_freq_t tcu_tcc_pwm_solenoid_freq;
	/**
	 * offset 4986
	 */
	output_pin_e tcu_pc_solenoid_pin;
	/**
	 * offset 4988
	 */
	pin_output_mode_e tcu_pc_solenoid_pin_mode;
	/**
	 * need 4 byte alignment
	units
	 * offset 4989
	 */
	uint8_t alignmentFill_at_4989[1];
	/**
	 * offset 4990
	 */
	pwm_freq_t tcu_pc_solenoid_freq;
	/**
	 * offset 4992
	 */
	output_pin_e tcu_32_solenoid_pin;
	/**
	 * offset 4994
	 */
	pin_output_mode_e tcu_32_solenoid_pin_mode;
	/**
	 * need 4 byte alignment
	units
	 * offset 4995
	 */
	uint8_t alignmentFill_at_4995[1];
	/**
	 * offset 4996
	 */
	pwm_freq_t tcu_32_solenoid_freq;
	/**
	units
	 * offset 4998
	 */
	uint8_t mainUnusedEnd[250];
};
static_assert(sizeof(engine_configuration_s) == 5248);

// start of cyl_trim_s
struct cyl_trim_s {
	/**
	 * offset 0
	 */
	scaled_channel<int8_t, 5, 1> table[TRIM_SIZE][TRIM_SIZE];
};
static_assert(sizeof(cyl_trim_s) == 16);

// start of persistent_config_s
struct persistent_config_s {
	/**
	 * offset 0
	 */
	engine_configuration_s engineConfiguration;
	/**
	 * offset 5248
	 */
	error_message_t warning_message;
	/**
	C
	 * offset 5368
	 */
	float afterstartCoolantBins[AFTERSTART_HOLD_CURVE_SIZE];
	/**
	Seconds
	 * offset 5400
	 */
	float afterstartHoldTime[AFTERSTART_HOLD_CURVE_SIZE];
	/**
	%
	 * offset 5432
	 */
	float afterstartEnrich[AFTERSTART_ENRICH_CURVE_SIZE];
	/**
	Seconds
	 * offset 5464
	 */
	float afterstartDecayTime[AFTERSTART_DECAY_CURVE_SIZE];
	/**
	 * offset 5496
	 */
	scaled_channel<uint8_t, 2, 1> boostTableOpenLoop[BOOST_RPM_COUNT][BOOST_LOAD_COUNT];
	/**
	RPM
	 * offset 5560
	 */
	scaled_channel<uint8_t, 1, 50> boostRpmBins[BOOST_RPM_COUNT];
	/**
	 * offset 5568
	 */
	scaled_channel<uint8_t, 1, 2> boostTableClosedLoop[BOOST_RPM_COUNT][BOOST_LOAD_COUNT];
	/**
	%
	 * offset 5632
	 */
	scaled_channel<uint8_t, 1, 1> boostTpsBins[BOOST_LOAD_COUNT];
	/**
	%
	 * offset 5640
	 */
	uint8_t pedalToTpsTable[PEDAL_TO_TPS_SIZE][PEDAL_TO_TPS_SIZE];
	/**
	%
	 * offset 5704
	 */
	uint8_t pedalToTpsPedalBins[PEDAL_TO_TPS_SIZE];
	/**
	RPM
	 * offset 5712
	 */
	scaled_channel<uint8_t, 1, 50> pedalToTpsRpmBins[PEDAL_TO_TPS_SIZE];
	/**
	 * CLT-based cranking position multiplier for simple manual idle controller
	C
	 * offset 5720
	 */
	float cltCrankingCorrBins[CLT_CRANKING_CURVE_SIZE];
	/**
	 * CLT-based cranking position multiplier for simple manual idle controller
	%
	 * offset 5752
	 */
	float cltCrankingCorr[CLT_CRANKING_CURVE_SIZE];
	/**
	 * Optional timing advance table for Idle (see useSeparateAdvanceForIdle)
	RPM
	 * offset 5784
	 */
	scaled_channel<uint8_t, 1, 50> idleAdvanceBins[IDLE_ADVANCE_CURVE_SIZE];
	/**
	 * Optional timing advance table for Idle (see useSeparateAdvanceForIdle)
	deg
	 * offset 5792
	 */
	float idleAdvance[IDLE_ADVANCE_CURVE_SIZE];
	/**
	RPM
	 * offset 5824
	 */
	scaled_channel<uint8_t, 1, 10> idleVeRpmBins[IDLE_VE_SIZE];
	/**
	load
	 * offset 5828
	 */
	scaled_channel<uint8_t, 1, 1> idleVeLoadBins[IDLE_VE_SIZE];
	/**
	%
	 * offset 5832
	 */
	scaled_channel<uint16_t, 10, 1> idleVeTable[IDLE_VE_SIZE][IDLE_VE_SIZE];
	/**
	 * offset 5864
	 */
	lua_script_t luaScript;
	/**
	C
	 * offset 13864
	 */
	float cltFuelCorrBins[CLT_CURVE_SIZE];
	/**
	ratio
	 * offset 13928
	 */
	float cltFuelCorr[CLT_CURVE_SIZE];
	/**
	C
	 * offset 13992
	 */
	float iatFuelCorrBins[IAT_CURVE_SIZE];
	/**
	ratio
	 * offset 14056
	 */
	float iatFuelCorr[IAT_CURVE_SIZE];
	/**
	ratio
	 * offset 14120
	 */
	float crankingFuelCoef[CRANKING_CURVE_SIZE];
	/**
	C
	 * offset 14152
	 */
	float crankingFuelBins[CRANKING_CURVE_SIZE];
	/**
	ratio
	 * offset 14184
	 */
	float crankingCycleCoef[CRANKING_CURVE_SIZE];
	/**
	counter
	 * offset 14216
	 */
	float crankingCycleBins[CRANKING_CURVE_SIZE];
	/**
	 * CLT-based idle position multiplier for simple manual idle controller
	C
	 * offset 14248
	 */
	float cltIdleCorrBins[CLT_CURVE_SIZE];
	/**
	 * CLT-based idle position multiplier for simple manual idle controller
	ratio
	 * offset 14312
	 */
	float cltIdleCorr[CLT_CURVE_SIZE];
	/**
	 * Also known as MAF transfer function.
	 * kg/hour value.
	 * By the way 2.081989116 kg/h = 1 ft3/m
	kg/hour
	 * offset 14376
	 */
	float mafDecoding[MAF_DECODING_COUNT];
	/**
	V
	 * offset 15400
	 */
	float mafDecodingBins[MAF_DECODING_COUNT];
	/**
	deg
	 * offset 16424
	 */
	scaled_channel<int16_t, 10, 1> ignitionIatCorrTable[IGN_RPM_COUNT][IGN_LOAD_COUNT];
	/**
	Temperature
	 * offset 16936
	 */
	float ignitionIatCorrLoadBins[IGN_LOAD_COUNT];
	/**
	RPM
	 * offset 17000
	 */
	uint16_t ignitionIatCorrRpmBins[IGN_RPM_COUNT];
	/**
	deg
	 * offset 17032
	 */
	int16_t injectionPhase[IGN_RPM_COUNT][IGN_LOAD_COUNT];
	/**
	Load
	 * offset 17544
	 */
	uint16_t injPhaseLoadBins[FUEL_LOAD_COUNT];
	/**
	RPM
	 * offset 17576
	 */
	uint16_t injPhaseRpmBins[FUEL_RPM_COUNT];
	/**
	onoff
	 * offset 17608
	 */
	uint8_t tcuSolenoidTable[TCU_SOLENOID_COUNT][TCU_GEAR_COUNT];
	/**
	kPa
	 * offset 17668
	 */
	scaled_channel<uint16_t, 100, 1> mapEstimateTable[FUEL_RPM_COUNT][FUEL_LOAD_COUNT];
	/**
	% TPS
	 * offset 18180
	 */
	scaled_channel<uint16_t, 100, 1> mapEstimateTpsBins[FUEL_LOAD_COUNT];
	/**
	RPM
	 * offset 18212
	 */
	uint16_t mapEstimateRpmBins[FUEL_RPM_COUNT];
	/**
	value
	 * offset 18244
	 */
	uint8_t vvtTable1[SCRIPT_TABLE_8][SCRIPT_TABLE_8];
	/**
	L
	 * offset 18308
	 */
	uint16_t vvtTable1LoadBins[SCRIPT_TABLE_8];
	/**
	RPM
	 * offset 18324
	 */
	uint16_t vvtTable1RpmBins[SCRIPT_TABLE_8];
	/**
	value
	 * offset 18340
	 */
	uint8_t vvtTable2[SCRIPT_TABLE_8][SCRIPT_TABLE_8];
	/**
	L
	 * offset 18404
	 */
	uint16_t vvtTable2LoadBins[SCRIPT_TABLE_8];
	/**
	RPM
	 * offset 18420
	 */
	uint16_t vvtTable2RpmBins[SCRIPT_TABLE_8];
	/**
	deg
	 * offset 18436
	 */
	scaled_channel<int16_t, 10, 1> ignitionTable[IGN_RPM_COUNT][IGN_LOAD_COUNT];
	/**
	Load
	 * offset 18948
	 */
	uint16_t ignitionLoadBins[IGN_LOAD_COUNT];
	/**
	RPM
	 * offset 18980
	 */
	uint16_t ignitionRpmBins[IGN_RPM_COUNT];
	/**
	%
	 * offset 19012
	 */
	scaled_channel<uint16_t, 10, 1> veTable[FUEL_RPM_COUNT][FUEL_LOAD_COUNT];
	/**
	kPa
	 * offset 19524
	 */
	uint16_t veLoadBins[FUEL_LOAD_COUNT];
	/**
	RPM
	 * offset 19556
	 */
	uint16_t veRpmBins[FUEL_RPM_COUNT];
	/**
	lambda
	 * offset 19588
	 */
	scaled_channel<uint8_t, 147, 1> lambdaTable[FUEL_RPM_COUNT][FUEL_LOAD_COUNT];
	/**
	 * offset 19844
	 */
	uint16_t lambdaLoadBins[FUEL_LOAD_COUNT];
	/**
	RPM
	 * offset 19876
	 */
	uint16_t lambdaRpmBins[FUEL_RPM_COUNT];
	/**
	value
	 * offset 19908
	 */
	float tpsTpsAccelTable[TPS_TPS_ACCEL_TABLE][TPS_TPS_ACCEL_TABLE];
	/**
	from
	 * offset 20164
	 */
	float tpsTpsAccelFromRpmBins[TPS_TPS_ACCEL_TABLE];
	/**
	to
	 * offset 20196
	 */
	float tpsTpsAccelToRpmBins[TPS_TPS_ACCEL_TABLE];
	/**
	value
	 * offset 20228
	 */
	float scriptTable1[SCRIPT_TABLE_8][SCRIPT_TABLE_8];
	/**
	L
	 * offset 20484
	 */
	uint16_t scriptTable1LoadBins[SCRIPT_TABLE_8];
	/**
	RPM
	 * offset 20500
	 */
	uint16_t scriptTable1RpmBins[SCRIPT_TABLE_8];
	/**
	value
	 * offset 20516
	 */
	uint8_t scriptTable2[SCRIPT_TABLE_8][SCRIPT_TABLE_8];
	/**
	L
	 * offset 20580
	 */
	uint16_t scriptTable2LoadBins[SCRIPT_TABLE_8];
	/**
	RPM
	 * offset 20596
	 */
	uint16_t scriptTable2RpmBins[SCRIPT_TABLE_8];
	/**
	value
	 * offset 20612
	 */
	uint8_t scriptTable3[SCRIPT_TABLE_8][SCRIPT_TABLE_8];
	/**
	L
	 * offset 20676
	 */
	uint16_t scriptTable3LoadBins[SCRIPT_TABLE_8];
	/**
	RPM
	 * offset 20692
	 */
	uint16_t scriptTable3RpmBins[SCRIPT_TABLE_8];
	/**
	value
	 * offset 20708
	 */
	uint8_t scriptTable4[SCRIPT_TABLE_8][SCRIPT_TABLE_8];
	/**
	L
	 * offset 20772
	 */
	uint16_t scriptTable4LoadBins[SCRIPT_TABLE_8];
	/**
	RPM
	 * offset 20788
	 */
	uint16_t scriptTable4RpmBins[SCRIPT_TABLE_8];
	/**
	 * offset 20804
	 */
	uint16_t ignTrimLoadBins[TRIM_SIZE];
	/**
	rpm
	 * offset 20812
	 */
	uint16_t ignTrimRpmBins[TRIM_SIZE];
	/**
	 * offset 20820
	 */
	cyl_trim_s ignTrims[12];
	/**
	 * offset 21012
	 */
	uint16_t fuelTrimLoadBins[TRIM_SIZE];
	/**
	rpm
	 * offset 21020
	 */
	uint16_t fuelTrimRpmBins[TRIM_SIZE];
	/**
	 * offset 21028
	 */
	cyl_trim_s fuelTrims[12];
	/**
	ratio
	 * offset 21220
	 */
	scaled_channel<uint16_t, 100, 1> crankingFuelCoefE100[CRANKING_CURVE_SIZE];
	/**
	Airmass
	 * offset 21236
	 */
	uint8_t tcu_pcAirmassBins[8];
	/**
	%
	 * offset 21244
	 */
	uint8_t tcu_pcValsR[8];
	/**
	%
	 * offset 21252
	 */
	uint8_t tcu_pcValsN[8];
	/**
	%
	 * offset 21260
	 */
	uint8_t tcu_pcVals1[8];
	/**
	%
	 * offset 21268
	 */
	uint8_t tcu_pcVals2[8];
	/**
	%
	 * offset 21276
	 */
	uint8_t tcu_pcVals3[8];
	/**
	%
	 * offset 21284
	 */
	uint8_t tcu_pcVals4[8];
	/**
	%
	 * offset 21292
	 */
	uint8_t tcu_pcVals12[8];
	/**
	%
	 * offset 21300
	 */
	uint8_t tcu_pcVals23[8];
	/**
	%
	 * offset 21308
	 */
	uint8_t tcu_pcVals34[8];
	/**
	%
	 * offset 21316
	 */
	uint8_t tcu_pcVals21[8];
	/**
	%
	 * offset 21324
	 */
	uint8_t tcu_pcVals32[8];
	/**
	%
	 * offset 21332
	 */
	uint8_t tcu_pcVals43[8];
	/**
	TPS
	 * offset 21340
	 */
	uint8_t tcu_tccTpsBins[8];
	/**
	MPH
	 * offset 21348
	 */
	uint8_t tcu_tccLockSpeed[8];
	/**
	MPH
	 * offset 21356
	 */
	uint8_t tcu_tccUnlockSpeed[8];
	/**
	KPH
	 * offset 21364
	 */
	uint8_t tcu_32SpeedBins[8];
	/**
	%
	 * offset 21372
	 */
	uint8_t tcu_32Vals[8];
};
static_assert(sizeof(persistent_config_s) == 21380);

// end
// this section was generated automatically by rusEFI tool ConfigDefinition.jar based on config/boards/subaru_eg33/config/gen_subaru_config.sh integration/rusefi_config.txt Sat Apr 30 17:04:55 UTC 2022
