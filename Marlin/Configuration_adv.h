#pragma once
#define CONFIGURATION_ADV_H_VERSION 020008

#define THERMOCOUPLE_MAX_ERRORS 15

#if DISABLED(PIDTEMPCHAMBER)
  #define CHAMBER_CHECK_INTERVAL 5000   // (ms) Interval between checks in bang-bang control
#endif

#if ENABLED(THERMAL_PROTECTION_HOTENDS)
  #define THERMAL_PROTECTION_PERIOD 40        // Seconds
  #define THERMAL_PROTECTION_HYSTERESIS 4     // Degrees Celsius
  #define WATCH_TEMP_PERIOD  20               // Seconds
  #define WATCH_TEMP_INCREASE 2               // Degrees Celsius
#endif

#if ENABLED(THERMAL_PROTECTION_BED)
  #define THERMAL_PROTECTION_BED_PERIOD        20 // Seconds
  #define THERMAL_PROTECTION_BED_HYSTERESIS     2 // Degrees Celsius
  #define WATCH_BED_TEMP_PERIOD                60 // Seconds
  #define WATCH_BED_TEMP_INCREASE               2 // Degrees Celsius
#endif

#if ENABLED(THERMAL_PROTECTION_CHAMBER)
  #define THERMAL_PROTECTION_CHAMBER_PERIOD    20 // Seconds
  #define THERMAL_PROTECTION_CHAMBER_HYSTERESIS 2 // Degrees Celsius
  #define WATCH_CHAMBER_TEMP_PERIOD            60 // Seconds
  #define WATCH_CHAMBER_TEMP_INCREASE           2 // Degrees Celsius
#endif

#if ENABLED(THERMAL_PROTECTION_COOLER)
  #define THERMAL_PROTECTION_COOLER_PERIOD    10 // Seconds
  #define THERMAL_PROTECTION_COOLER_HYSTERESIS 3 // Degrees Celsius
  #define WATCH_COOLER_TEMP_PERIOD            60 // Seconds
  #define WATCH_COOLER_TEMP_INCREASE           3 // Degrees Celsius
#endif

#define AUTOTEMP
#if ENABLED(AUTOTEMP)
  #define AUTOTEMP_OLDWEIGHT    0.98
#endif

#define TEMP_SENSOR_AD595_OFFSET  0.0
#define TEMP_SENSOR_AD595_GAIN    1.0
#define TEMP_SENSOR_AD8495_OFFSET 0.0
#define TEMP_SENSOR_AD8495_GAIN   1.0

#define E0_AUTO_FAN_PIN -1
#define E1_AUTO_FAN_PIN -1
#define E2_AUTO_FAN_PIN -1
#define E3_AUTO_FAN_PIN -1
#define E4_AUTO_FAN_PIN -1
#define E5_AUTO_FAN_PIN -1
#define E6_AUTO_FAN_PIN -1
#define E7_AUTO_FAN_PIN -1
#define CHAMBER_AUTO_FAN_PIN -1
#define COOLER_AUTO_FAN_PIN -1
#define COOLER_FAN_PIN -1

#define EXTRUDER_AUTO_FAN_TEMPERATURE 50
#define EXTRUDER_AUTO_FAN_SPEED 255   // 255 == full speed
#define CHAMBER_AUTO_FAN_TEMPERATURE 30
#define CHAMBER_AUTO_FAN_SPEED 255
#define COOLER_AUTO_FAN_TEMPERATURE 18
#define COOLER_AUTO_FAN_SPEED 255

#define FANMUX0_PIN -1
#define FANMUX1_PIN -1
#define FANMUX2_PIN -1

//#define ENDSTOPS_ALWAYS_ON_DEFAULT

#define NUM_Z_STEPPER_DRIVERS 2   // (1-4) Z options change based on how many

#if NUM_Z_STEPPER_DRIVERS > 1

  #define Z_MULTI_ENDSTOPS
  #if ENABLED(Z_MULTI_ENDSTOPS)
    #define Z2_USE_ENDSTOP          _ZMAX_
    #define Z2_ENDSTOP_ADJUSTMENT   0
  #endif
#endif

//#define SENSORLESS_BACKOFF_MM  { 2, 2 }     // (mm) Backoff from endstops before sensorless homing

#define HOMING_BUMP_MM      { 5, 5, 2 }       // (mm) Backoff from endstops after first bump
#define HOMING_BUMP_DIVISOR { 2, 2, 4 }       // Re-Bump Speed Divisor (Divides the Homing Feedrate)

//#define HOMING_BACKOFF_POST_MM { 2, 2, 2 }  // (mm) Backoff from endstops after homing

#define QUICK_HOME                          // If G28 contains XY do a diagonal move first
//#define HOME_Y_BEFORE_X                     // If G28 contains XY home Y before X
//#define HOME_Z_FIRST                        // Home Z first. Requires a Z-MIN endstop (not a probe).
//#define CODEPENDENT_XY_HOMING               // If X/Y can't home without homing Y/X first

#define AXIS_RELATIVE_MODES { false, false, false, false }

#define INVERT_X_STEP_PIN false
#define INVERT_Y_STEP_PIN false
#define INVERT_Z_STEP_PIN false
#define INVERT_E_STEP_PIN false

#define DEFAULT_STEPPER_DEACTIVE_TIME 120
#define DISABLE_INACTIVE_X true
#define DISABLE_INACTIVE_Y true
#define DISABLE_INACTIVE_Z true  // Set 'false' if the nozzle could fall onto your printed part!
#define DISABLE_INACTIVE_E true

#define DEFAULT_MINIMUMFEEDRATE       0.0     // (mm/s) Minimum feedrate. Set with M205 S.
#define DEFAULT_MINTRAVELFEEDRATE     0.0     // (mm/s) Minimum travel feedrate. Set with M205 T.

#define DEFAULT_MINSEGMENTTIME        20000   // (µs) Set with M205 B.

#define SLOWDOWN
#if ENABLED(SLOWDOWN)
  #define SLOWDOWN_DIVISOR 2
#endif

#define MINIMUM_PLANNER_SPEED 0.05 // (mm/s)

#define MICROSTEP_MODES { 16, 16, 16, 16, 16, 16 } // [1,2,4,8,16]

#if EITHER(IS_ULTIPANEL, EXTENSIBLE_UI)
  #define MANUAL_FEEDRATE { 50*60, 50*60, 4*60, 2*60 } // (mm/min) Feedrates for manual moves along X, Y, Z, E from panel
  #define FINE_MANUAL_MOVE 0.025    // (mm) Smallest manual move (< 0.1mm) applying to Z on most machines
  #if IS_ULTIPANEL
    #define MANUAL_E_MOVES_RELATIVE // Display extruder move distance rather than "position"
    #define ULTIPANEL_FEEDMULTIPLY  // Encoder sets the feedrate multiplier on the Status Screen
  #endif
#endif

#define ENCODER_RATE_MULTIPLIER
#if ENABLED(ENCODER_RATE_MULTIPLIER)
  #define ENCODER_10X_STEPS_PER_SEC   30  // (steps/s) Encoder rate for 10x speed
  #define ENCODER_100X_STEPS_PER_SEC  80  // (steps/s) Encoder rate for 100x speed
#endif

#if HAS_LCD_MENU
  #define LCD_INFO_MENU
#endif

#if HAS_DISPLAY
  #define LCD_TIMEOUT_TO_STATUS 15000
  #if ENABLED(SHOW_BOOTSCREEN)
    #define BOOTSCREEN_TIMEOUT 2000      // (ms) Total Duration to display the boot screen(s)
    #if EITHER(HAS_MARLINUI_U8GLIB, TFT_COLOR_UI)
      #define BOOT_MARLIN_LOGO_SMALL     // Show a smaller Marlin logo on the Boot Screen (saving lots of flash)
    #endif
  #endif

  #define STATUS_MESSAGE_SCROLLING
#endif

#if EITHER(SDSUPPORT, LCD_SET_PROGRESS_MANUALLY) && ANY(HAS_MARLINUI_U8GLIB, HAS_MARLINUI_HD44780, IS_TFTGLCD_PANEL, EXTENSIBLE_UI)
  #define SHOW_REMAINING_TIME       // Display estimated time to completion
  #if ENABLED(SHOW_REMAINING_TIME)
    #define ROTATE_PROGRESS_DISPLAY // Display (P)rogress, (E)lapsed, and (R)emaining time
  #endif
#endif

#if ENABLED(SDSUPPORT)
  #define SD_PROCEDURE_DEPTH 1              // Increase if you need more nested M32 calls
  #define SD_FINISHED_STEPPERRELEASE true   // Disable steppers when SD Print is finished
  #define SD_FINISHED_RELEASECOMMAND "M84"  // Use "M84XYE" to keep Z enabled so your bed stays in place
  #define SDCARD_RATHERRECENTFIRST
  #define SD_MENU_CONFIRM_START             // Confirm the selected SD file before printing
  #define BROWSE_MEDIA_ON_INSERT          // Open the file browser when media is inserted
  #define EVENT_GCODE_SD_ABORT "G28XY"      // G-code to run on SD Abort Print (e.g., "G28XY" or "G27")
  #define SCROLL_LONG_FILENAMES
#endif

#if HAS_MARLINUI_U8GLIB
  #define XYZ_HOLLOW_FRAME
  #define MENU_HOLLOW_FRAME
  #define STATUS_HOTEND_INVERTED      // Show solid nozzle bitmaps when heating (Requires STATUS_HOTEND_ANIM)
  #define STATUS_HOTEND_ANIM          // Use a second bitmap to indicate hotend heating
  #define STATUS_BED_ANIM             // Use a second bitmap to indicate bed heating
  #define STATUS_CHAMBER_ANIM         // Use a second bitmap to indicate chamber heating
  #define BOOT_MARLIN_LOGO_ANIMATED // Animated Marlin logo. Costs ~‭3260 (or ~940) bytes of PROGMEM.
  #define MARLIN_BRICKOUT
  #define MARLIN_INVADERS
  #define MARLIN_SNAKE
#endif

#define BABYSTEPPING
#if ENABLED(BABYSTEPPING)
  #define BABYSTEP_ALWAYS_AVAILABLE       // Allow babystepping at all times (not just during movement).
  #define BABYSTEP_INVERT_Z false           // Change if Z babysteps should go the other way
  #define BABYSTEP_MULTIPLICATOR_Z  1       // (steps or mm) Steps or millimeter distance for each Z babystep
  #define BABYSTEP_MULTIPLICATOR_XY 1       // (steps or mm) Steps or millimeter distance for each XY babystep
  #define BABYSTEP_DISPLAY_TOTAL          // Display total babysteps since last G28
#endif

#define LIN_ADVANCE
#if ENABLED(LIN_ADVANCE)
  #define LIN_ADVANCE_K 1.05    // Unit: mm compression per 1mm/s extruder speed
  #define EXPERIMENTAL_SCURVE // Enable this option to permit S-Curve Acceleration
#endif

#define ARC_SUPPORT                 // Disable this feature to save ~3226 bytes
#if ENABLED(ARC_SUPPORT)
  #define MM_PER_ARC_SEGMENT      1 // (mm) Length (or minimum length) of each arc segment
  #define MIN_ARC_SEGMENTS       24 // Minimum number of segments in a complete circle
  #define N_ARC_CORRECTION       25 // Number of interpolated segments between corrections
#endif

#define MIN_STEPS_PER_SEGMENT 6

#if ENABLED(SDSUPPORT)
  #define BLOCK_BUFFER_SIZE 16
#endif

#define MAX_CMD_SIZE 96
#define BUFSIZE 4

#define TX_BUFFER_SIZE 0

#define SERIAL_OVERRUN_PROTECTION

#define ADVANCED_PAUSE_FEATURE
#if ENABLED(ADVANCED_PAUSE_FEATURE)
  #define PAUSE_PARK_RETRACT_FEEDRATE         60 
  #define PAUSE_PARK_RETRACT_LENGTH            2 
  #define FILAMENT_CHANGE_UNLOAD_FEEDRATE     10 
  #define FILAMENT_CHANGE_UNLOAD_ACCEL        25 
  #define FILAMENT_CHANGE_UNLOAD_LENGTH      100 
  #define FILAMENT_CHANGE_SLOW_LOAD_FEEDRATE   6 
  #define FILAMENT_CHANGE_SLOW_LOAD_LENGTH     0 
  #define FILAMENT_CHANGE_FAST_LOAD_FEEDRATE   6 
  #define FILAMENT_CHANGE_FAST_LOAD_ACCEL     25 
  #define FILAMENT_CHANGE_FAST_LOAD_LENGTH     0 
  #define ADVANCED_PAUSE_PURGE_FEEDRATE        3 
  #define ADVANCED_PAUSE_PURGE_LENGTH         50 
  #define ADVANCED_PAUSE_RESUME_PRIME          0 
  #define FILAMENT_UNLOAD_PURGE_RETRACT       13 
  #define FILAMENT_UNLOAD_PURGE_DELAY       5000 
  #define FILAMENT_UNLOAD_PURGE_LENGTH         8 
  #define FILAMENT_UNLOAD_PURGE_FEEDRATE      25 
  #define PAUSE_PARK_NOZZLE_TIMEOUT           45 
  #define FILAMENT_CHANGE_ALERT_BEEPS         10 
  #define PAUSE_PARK_NO_STEPPER_TIMEOUT          
#endif

#if HAS_TRINAMIC_CONFIG
  #define HOLD_MULTIPLIER    0.5  // Scales down the holding current from run current
  #define INTERPOLATE      true

  #if AXIS_IS_TMC(X)
    #define X_CURRENT       850        // (mA) RMS current. Multiply by 1.414 for peak current.
    #define X_CURRENT_HOME  X_CURRENT  // (mA) RMS current for sensorless homing
    #define X_MICROSTEPS     16        // 0..256
    #define X_RSENSE          0.11
    #define X_CHAIN_POS      -1        // -1..0: Not chained. 1: MCU MOSI connected. 2: Next in chain, ...
  #endif

  #if AXIS_IS_TMC(Y)
    #define Y_CURRENT       850
    #define Y_CURRENT_HOME  Y_CURRENT
    #define Y_MICROSTEPS     16
    #define Y_RSENSE          0.11
    #define Y_CHAIN_POS      -1
  #endif

  #if AXIS_IS_TMC(Z)
    #define Z_CURRENT       850
    #define Z_CURRENT_HOME  Z_CURRENT
    #define Z_MICROSTEPS     16
    #define Z_RSENSE          0.11
    #define Z_CHAIN_POS      -1
  #endif

  #if AXIS_IS_TMC(Z2)
    #define Z2_CURRENT      850
    #define Z2_CURRENT_HOME Z2_CURRENT
    #define Z2_MICROSTEPS    Z_MICROSTEPS
    #define Z2_RSENSE         0.11
    #define Z2_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC(E0)
    #define E0_CURRENT      650
    #define E0_MICROSTEPS    16
    #define E0_RSENSE         0.11
    #define E0_CHAIN_POS     -1
  #endif

  #define STEALTHCHOP_XY
  #define STEALTHCHOP_Z
  #define STEALTHCHOP_E

  #define CHOPPER_TIMING CHOPPER_DEFAULT_12V

  #define X_HYBRID_THRESHOLD     120
  #define Y_HYBRID_THRESHOLD     120
  #define Z_HYBRID_THRESHOLD       3
  #define Z2_HYBRID_THRESHOLD      3
  #define E0_HYBRID_THRESHOLD     30

  #define SENSORLESS_HOMING

  #if EITHER(SENSORLESS_HOMING, SENSORLESS_PROBING)
    #define X_STALL_SENSITIVITY  105
    #define Y_STALL_SENSITIVITY  100
  #endif

  #define TMC_HOME_PHASE { 896, 896, 896 }

  #define SQUARE_WAVE_STEPPING

  #define TMC_DEBUG

  #define TMC_ADV() {  }

#endif

#define AUTO_REPORT_TEMPERATURES

#define EXTENDED_CAPABILITIES_REPORT

#define PROPORTIONAL_FONT_RATIO 1.0

#define FASTER_GCODE_PARSER

#if ENABLED(PRINTCOUNTER)
  #define SERVICE_WARNING_BUZZES  3
#endif