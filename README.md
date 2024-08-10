# Fingerpad

## Introduction

The Fingerpad is a unique musical instrument created by transforming an ordinary glove into an interactive device using LDR sensors, Arduino, and SuperCollider. Each fingertip of the glove, including the thumb, is equipped with an LDR sensor to control different sound frequencies and amplitudes. This project explores the interaction between humans and hardware in a musical context.

## Device Overview

### Glove Configuration

- **Sensors**: LDR sensors are affixed to each fingertip and the thumb.
- **Frequency Assignment**:
  - **Index Finger**: 440 Hz
  - **Middle Finger**: 600 Hz
  - **Ring Finger**: 720 Hz
  - **Little Finger**: 990 Hz
- **Pitch Control**: The intensity of light on the thumb affects the pitch of the frequencies assigned to each fingertip.
- **Amplitude Control**: The light intensity on each fingertip determines the amplitude of the associated frequency.

## Circuit and Arduino Code

### Circuit

- **Components**: LDR and a 10k Ohm resistor connected in series.
- **Operation**: The Arduino reads the voltage at the junction between the LDR and the resistor. The LDR’s resistance decreases with increased light intensity, resulting in a higher voltage that the Arduino converts into a digital reading.

### Arduino Code

- **Setup**: Configures analog pins (A1 to A5) for LDR inputs.
- **Output**: Sends readings in the format `ldr1xldr2xldr3xldr4xldr5xa` to the serial monitor, which are then read by SuperCollider.

## SuperCollider Processing

### Functionality

1. **Frequency Control**: Each finger’s LDR controls a different sine wave frequency. The thumb LDR adjusts the pitch of these frequencies.
2. **Amplitude Control**: The intensity of light on each LDR determines the amplitude of the associated frequency.
3. **Pitch Manipulation**: Thumb LDR affects the pitch if the light intensity exceeds a threshold (400 units). If below, all fingers play the same note.
4. **Data Handling**: SuperCollider reads LDR data from the serial monitor and processes it to control the sound synthesis.

### SuperCollider Code Explanation

- **Frequency and Amplitude**: Sets up sine wave frequencies for each finger and adjusts amplitude based on light intensity.
- **Pitch Adjustment**: Modulates pitch based on thumb LDR readings.

## Gesture Synthesis

### Gesture 1

- Uses a specific `SynthDef` for gesture recognition, derived from a tutorial with minor modifications.

### Gesture 2

- Employs simple pink noise synthesis for gesture recognition.

### Working

- The gestures are detected and processed, triggering corresponding sounds. If the gesture condition is not met, the sound is terminated.

## Arduino and SuperCollider Integration

- **Data Formatting**: Arduino prints LDR readings in a specific format (`ldr1xldr2xldr3xldr4xldr5xa`), which SuperCollider parses to get individual LDR values.
- **Gesture Processing**: SuperCollider uses these readings to control synth parameters and recognize gestures.

## Installation and Usage

1. **Hardware Setup**: Connect LDR sensors to the glove and interface with Arduino.
2. **Arduino Code**: Upload the Arduino code to the board.
3. **SuperCollider**: Set up SuperCollider to read data from the Arduino and process it for sound synthesis.


