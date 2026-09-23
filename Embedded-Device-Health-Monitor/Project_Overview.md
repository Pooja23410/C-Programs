# Embedded Device Health Monitor

A C-based software project that monitors the health of multiple embedded devices using parameters such as **temperature, voltage, current, memory, CPU usage, and battery level**.

The program checks each parameter against predefined limits and assigns a **NORMAL, WARNING, or CRITICAL** status.

## Features

* Monitor up to **10 devices**
* Store device data using `struct`
* Check multiple health parameters
* Individual status for each parameter
* Calculate overall device status
* Display a final report for all devices
* Runs on any standard **online C compiler**

## Health Limits

| Parameter   | Normal   | Warning              | Critical         |
| ----------- | -------- | -------------------- | ---------------- |
| Temperature | ≤ 70°C   | > 70°C               | > 85°C           |
| Voltage     | 3.3–5.0V | 3.0–3.3V or 5.0–5.5V | < 3.0V or > 5.5V |
| Current     | ≤ 2.0A   | > 2.0A               | > 3.0A           |
| Memory      | ≤ 70%    | > 70%                | > 85%            |
| CPU Usage   | ≤ 70%    | > 70%                | > 85%            |
| Battery     | ≥ 50%    | < 50%                | < 20%            |

**Note:**
These limits are simplified values used only for learning, demonstration, and software simulation. 
They are not intended to represent actual hardware-specific or industry-standard operating limits. Real embedded systems require thresholds based on the specific device, component datasheets, and system requirements.

## Technologies

* C Programming
* Structures
* Functions
* Arrays
* Conditional Statements
* Loops
* Input/Output

## How It Works

**Input Device Data → Check Parameters → Assign Status → Calculate Overall Status → Display Final Report**

### Author
**Pooja Anbalagan**

ECE Graduate
