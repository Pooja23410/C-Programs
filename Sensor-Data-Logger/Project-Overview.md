# Sensor Data Logger

## Overview

A simple C-based Sensor Data Logger that simulates collecting sensor readings, validating the data, storing multiple readings, checking operating thresholds, and generating basic statistics.

The project uses user input to simulate sensor values, so it can be executed in a normal online C compiler without physical hardware.

## Sensor Parameters

The program collects:

* Temperature (°C)
* Humidity (%)
* Pressure (hPa)
* Battery Voltage (V)

## How It Works

```text
Sensor Input
     ↓
Data Validation
     ↓
Store Reading
     ↓
Threshold Check
     ↓
Status Classification
     ↓
Data Analysis
     ↓
Display Log & Statistics
```

## Status Classification

Each reading is classified as:

* **NORMAL** – All parameters are within normal limits.
* **WARNING** – At least one parameter crosses the warning limit but none reaches the critical limit.
* **CRITICAL** – At least one parameter crosses the critical limit.

If multiple conditions occur, **CRITICAL has the highest priority**, followed by WARNING and then NORMAL.

## Thresholds Used

| Parameter       | Normal       | Warning             | Critical            |
| --------------- | ------------ | ------------------- | ------------------- |
| Temperature     | ≤ 35°C       | > 35°C              | > 40°C              |
| Humidity        | ≤ 70%        | > 70%               | > 80%               |
| Pressure        | 980–1030 hPa | < 980 or > 1030 hPa | < 950 or > 1050 hPa |
| Battery Voltage | ≥ 3.5 V      | < 3.5 V             | < 3.0 V             |

### About These Thresholds

The thresholds in this project are **learning/simulation values** used to demonstrate sensor monitoring and status classification in C.

They are **not fixed industry standards** and are not intended to represent the specifications of a particular sensor, battery, or embedded product.

In a real embedded system, threshold values would depend on factors such as:

* Sensor specifications
* Hardware design
* Operating environment
* Battery characteristics
* Device requirements
* Application-specific safety limits

Therefore, the threshold values can be modified according to the requirements of a real application.

## Input Validation

The program also checks whether entered values fall within basic valid input ranges:

| Parameter       | Accepted Input Range |
| --------------- | -------------------- |
| Temperature     | -50 to 100°C         |
| Humidity        | 0 to 100%            |
| Pressure        | 800 to 1200 hPa      |
| Battery Voltage | 0 to 5 V             |

Invalid sensor data is rejected and the current reading is entered again.

## C Concepts Used

* Structures (`struct`)
* Arrays
* Functions
* Loops
* Conditional statements
* Constants
* Input validation
* Basic data analysis
* Min/Max/Average calculations

## Output

The program displays:

* Complete sensor data log
* Status of each reading
* Minimum temperature
* Maximum temperature
* Average temperature
* Average humidity
* Number of NORMAL readings
* Number of WARNING readings
* Number of CRITICAL readings

## Author

**Pooja Anbalagan**

ECE Graduate
