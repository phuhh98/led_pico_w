#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define GPIO_ON 1
#define GPIO_OFF 0

int main()
{
    // initialized chosen serial port
    stdio_init_all();

    const uint LED_PIN = 0;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    if (cyw43_arch_init())
    {
        return -1;
    }

    while (true)
    {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, GPIO_ON);
        gpio_put(LED_PIN, 1);
        printf("Blink!\r\n");
        sleep_ms(1000);
        printf("ping\n");
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, GPIO_OFF);
        gpio_put(LED_PIN, 0);
        printf("pong\n");
        sleep_ms(1000);
    }
}