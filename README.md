# Blink and Core Demonstration Example

(See the `README.md` file in the upper-level 'examples' directory for more information about examples.)

This example demonstrates how to blink an LED using the GPIO driver while concurrently printing messages from a different task running on another core of the ESP32.

## Supported Targets

| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C5 | ESP32-C6 | ESP32-C61 | ESP32-H2 | ESP32-P4 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | --------- | -------- | -------- | -------- | -------- |

## Description

This example includes two tasks:
1. A **blinking task** that toggles an LED connected to a GPIO pin on and off every second.
2. A **printing task** that runs on another core and prints a message ("Hello from Core 0!") every 2 seconds.

The example demonstrates multi-core programming on ESP32 using the FreeRTOS API.

## How to Use Example

Before project configuration and build, be sure to set the correct chip target using:

```sh
idf.py set-target <chip_name>
```

### Hardware Required

* A development board with a regular LED on-board (e.g., ESP32-DevKitC, ESP32-S3-DevKitC, etc.)
* A USB cable for power supply and programming

See [Development Boards](https://www.espressif.com/en/products/devkits) for more information.

### Configure the Project

Open the project configuration menu (`idf.py menuconfig`).

- Set the GPIO number used for the LED in your source file. The default is `GPIO2`.

### Build and Flash

Run the following command to build, flash, and monitor the project:

```sh
idf.py -p PORT flash monitor
```

(To exit the serial monitor, type `Ctrl-]`.)

For full steps to configure and use ESP-IDF to build projects, see the [Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html).

## Example Output

After flashing the project, you will see two tasks running:
1. The **blinking task** toggling the LED every second.
2. The **printing task** outputting messages like the following:

```text
Blink Task Running on Core: 1
Print Task Running on Core: 0
Hello from Core 0!
Hello from Core 0!
Hello from Core 0!
```

### Troubleshooting

* If the LED isn't blinking, ensure the correct GPIO pin is selected in the code for your board.
* If messages are not visible on the monitor, verify the serial connection and ensure the correct port is specified in the `idf.py -p PORT` command.

For any technical queries, please open an [issue](https://github.com/espressif/esp-idf/issues) on GitHub. We will get back to you soon.
