#include<stdio.h>
#include"driver/gpio.h"
#include"freertos/FreeRTOS.h"
#include "esp_log.h"
#include "freertos/task.h"

#define LED_PIN 2

void app_main()
{
  ESP_LOGI("LOG","Pin 2 used as LED:Default on board");
  gpio_set_direction(LED_PIN,GPIO_MODE_OUTPUT);
  uint32_t Led_status = 0; //false state
  while(1)
  {
    Led_status =!Led_status;
    gpio_set_level(LED_PIN,Led_status);
    vTaskDelay(10* portTICK_PERIOD_MS);
    ESP_LOGI("LOG","LED Toggles %d",(!Led_status));
  }
}