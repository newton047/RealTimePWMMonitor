# PWM Monitor Prototype

A PWM signal monitoring system with ADC feedback for the STM32F401 microcontroller.

## Project Overview

This embedded systems project implements a PWM monitoring system that:
- Monitors PWM signals via ADC feedback
- Compares ADC readings against threshold values
- Controls LED indicators based on voltage levels
- Provides UART debug output for monitoring
- Supports user input for configuration

**Target Hardware:** STM32F401RET6 (ARM Cortex-M4, 84 MHz)

## Hardware Configuration

### GPIO Pinout
| Function | Port | Pin | Alternate Function |
|----------|------|-----|-------------------|
| PWM Input | PA | 1 | TIM2_CH2 (AF1) |
| ADC Feedback | PA | 0 | ADC1_IN0 |
| Status LED | PA | 5 | GPIO Output |
| UART TX | PA | 2 | USART2_TX (AF7) |
| UART RX | PA | 3 | USART2_RX (AF7) |
| User Button | PC | 13 | GPIO Input |

### Peripherals Used
- **TIM2:** PWM input capture on channel 2 (100 kHz monitoring)
- **ADC1:** Single-channel conversion on PA0 (12-bit, max sampling time)
- **USART2:** Serial debug output at 9600 baud
- **SysTick:** 1 ms tick for callback scheduling

## Software Architecture

### Module Structure

```
SelfTestMode/
├── Motor/              - PWM input monitoring (TIM2)
├── ADCFeedback/        - ADC input processing
│   ├── filter.c/h     - Exponential moving average filter
│   └── LUT.c/h        - Threshold lookup table
├── UserLed/            - Status indicator LED
├── UserInputButton/    - Configuration button input
├── TimeBase/           - SysTick timer & callback scheduler
├── DebugPort/          - UART debug output
└── self_test.c/h      - Diagnostic mode (placeholder)
```

### Core Functionality

#### Main Application (main.c)
- **Initialization:** Sets up all peripherals in sequence
- **Periodic Callbacks:** Registered with 1ms SysTick timer
  - **100ms:** `ADCReadHandler()` - Read and filter ADC value
  - **200ms:** `UserButtonHandler()` - Check button for configuration
  - **1000ms:** `SecondIncrementer()` - Send debug data via UART
  - **1000ms:** `ErrorCheckerHandler()` - Validate ADC reading against thresholds

#### PWM Monitoring (Motor/)
- Monitors PWM signals on PA1 via TIM2
- Supports threshold-based monitoring
- PWM frequency: 100 kHz monitoring capability
- Clock configuration: 2 MHz base, /1 prescaler

#### ADC Processing (ADCFeedback/)
- **ADC Configuration:**
  - 12-bit resolution
  - Maximum sampling time for accuracy
  - Single-channel sequence
  - Blocking read (waits for conversion)
- **Signal Processing:**
  - Raw ADC → Voltage conversion (3.3V / 4096 counts)
  - Exponential moving average filter (α = 0.5)
- **Threshold Validation:**
  - Lookup table maps settings → expected voltage ranges
  - Tolerance: ±0.2V from threshold values
  - Sets status flag and LED based on readings

#### Monitoring Loop
```
PWM Input (PA1)
    ↓
ADC Reading → Raw Count → Convert to Voltage → Filter
    ↓
Compare (Filtered ADC vs Threshold ± 0.2V)
    ↓
Status Flag + LED control
```

#### Timing System (TimeBase/)
- **SysTick Configuration:**
  - 1 kHz tick (1 ms period)
  - Interrupt-driven callback execution
- **Callback Scheduler:**
  - Supports up to 10 concurrent callbacks
  - Each callback has independent interval
  - Executed in SysTick interrupt context
- **Callback Registration:**
  ```c
  TimeBaseRegisterCallback(interval_ms, callback_function)
  ```

#### Debug Output (DebugPort/)
- **UART Configuration:**
  - USART2 on PA2 (TX) / PA3 (RX)
  - 9600 baud
  - 1 stop bit, no parity
- **Output Format (every 1 second):**
  ```
  <seconds> : ADC Voltage <mV> Setting <0-10> Threshold <mV> Status <0/1>
  ```

## Build & Compilation

### Prerequisites
- STM32CubeIDE or equivalent ARM Cortex-M4 compiler
- CMSIS device headers (STM32F4xx)
- Standard C library with floating-point support

### Build Configuration
```
Project: PWM_Monitor_Proto
MCU: STM32F401RET6
Optimization: -O2 (recommended)
Floating Point: Hard FPU (default)
```

### Compiler Flags
- Warnings enabled (`-Wall -Wextra`)
- Standard: C99 or later
- FPU enabled (ARM hard float ABI)

## Running the Application

### Power-Up Sequence
1. System clocks initialize
2. GPIO peripherals configured
3. PWM monitoring and ADC enabled
4. First ADC reading taken
5. SysTick callbacks begin executing
6. System monitors PWM input continuously

### User Interaction
- **Button Press (PC13, active-low):** Cycles monitoring settings 0→1→...→10→0
- **Status Condition:** LED on PA5 indicates when ADC reading meets criteria
- **Debug Output:** UART sends status every second

### Expected Operation
```
Power On
  ↓
Initialize all modules
  ↓
Monitoring setting = 0
  ↓
Monitor ADC feedback (100ms interval)
  ↓
Check button for setting change (200ms interval)
  ↓
Report status via UART (1000ms interval)
  ↓
Validate feedback against thresholds (1000ms interval)
  ↓
Loop continuously...
```

## Electrical Specifications

### Power Supply
- Operating voltage: 3.3V
- MCU current: ~50 mA typical
- External circuits: Dependent on PWM source and LED ratings

### PWM Input
- Frequency range: DC to 100 kHz monitoring capability
- Input impedance: ~50 Ω (GPIO)
- Voltage range: 0-3.3V (5V tolerant GPIO)

### ADC Feedback
- Input range: 0-3.3V
- Impedance: High (>100 kΩ input resistance)
- Sampling: Maximum time configured
- Accuracy: ±1 LSB (±0.8 mV typical)

### Debug UART
- Voltage levels: 3.3V LVTTL
- Baud rate: 9600 8N1
- Requires USB-to-serial adapter for PC connection

## Known Issues & Limitations

1. **Array Bounds:** No explicit bounds checking on threshold LUT access
   - Assume setting always in valid range (0-10)
   - Add validation if external inputs possible

2. **Self-Test Module:** Currently unimplemented
   - Contains placeholder functions only
   - TODO: Add GPIO, ADC, PWM, and UART diagnostic tests

3. **Status Recovery:** Status flag is set but not automatically cleared
   - System continues operation with flag set
   - Flag clears when ADC reading returns to valid range

4. **Button Debouncing:** No debounce filtering implemented
   - Single read at 200ms interval
   - Add debounce if mechanical switch has bounce

5. **SysTick Callback Limit:** Maximum 10 concurrent callbacks
   - Returns -1 if limit exceeded
   - Increase CALLBACK_NODE array if more callbacks needed

## Code Quality & Documentation

- **Comments:** Comprehensive documentation for all modules
- **Style:** Consistent formatting and variable naming
- **Doxygen:** Function documentation in Doxygen format (`/** ... */`)
- **Error Handling:** Basic error handling for callback registration

## Testing Recommendations

1. **ADC Verification:**
   - Connect PWM signal to PA0
   - Verify filtered ADC output matches input ±0.2V

2. **PWM Monitoring:**
   - Monitor TIM2 input capture on PA1
   - Verify PWM signal detection and processing

3. **UART Testing:**
   - Connect USB-to-serial adapter to PA2/PA3
   - Verify 9600 baud output format

4. **Button Testing:**
   - Press PC13 to ground
   - Verify setting increments and response

5. **Status Detection:**
   - Vary PWM input voltage
   - Verify status flag sets and LED turns on/off

## Debugging Tips

- **UART Output:** Monitor serial output for real-time system state
- **LED Indicator:** Visual feedback for status conditions
- **PWM Measurement:** Use oscilloscope to verify input signal
- **ADC Monitoring:** Log raw ADC and filtered values via UART

## Future Enhancements

1. Implement self-test mode with GPIO/ADC/PWM verification
2. Add configurable threshold table via UART commands
3. Implement duty cycle measurement and reporting
4. Add frequency measurement capabilities
5. Support for multiple PWM input channels
6. Add soft-start monitoring with configurable ramp rates
7. Implement data logging to external memory

## References

- STM32F401 Reference Manual
- ARM Cortex-M4 Programming Guide
- STM32 HAL Library Documentation
- CMSIS Core Documentation

## License

Copyright (c) 2026. All rights reserved.

---

**Last Updated:** March 2026  
**Version:** 1.0  
**Status:** Functional with placeholder self-test module
