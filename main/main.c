#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN 2  // GPIO pin for the LED

void blink_task(void *pvParameter) {
    printf("Blink Task Running on Core: %d\n", xPortGetCoreID());

    while (1) {
        gpio_set_level(LED_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(1000));

        gpio_set_level(LED_PIN, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void print_task(void *pvParameter) {
    printf("Print Task Running on Core: %d\n", xPortGetCoreID());

    while (1) {
        printf("Hello from Core %d!\n", xPortGetCoreID());
        vTaskDelay(pdMS_TO_TICKS(2000));  // Print every 2 seconds
    }
}

void app_main(void) {
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    // Run blink_task on Core 1
    xTaskCreatePinnedToCore(blink_task, "Blink Task", 2048, NULL, 1, NULL, 1);

    // Run print_task on Core 0
    xTaskCreatePinnedToCore(print_task, "Print Task", 2048, NULL, 1, NULL, 0);
}
