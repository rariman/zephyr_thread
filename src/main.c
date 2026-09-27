#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>

#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)

static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);     

void thread_led0(void)
{
    while (1) {
        gpio_pin_toggle_dt(&led0);
        k_msleep(500);
    }
}

void thread_led1(void)
{
    while (1) {
        gpio_pin_toggle_dt(&led1);
        k_msleep(1000);
    }
}

#define STACK_SIZE 512
#define PRIORITY 5

K_THREAD_DEFINE(thread_led0_id, CONFIG_THREAD_STACK_SIZE, thread_led0, NULL, NULL, NULL, CONFIG_THREAD_PRIORITY, 0, 0);
K_THREAD_DEFINE(thread_led1_id, CONFIG_THREAD_STACK_SIZE, thread_led1, NULL, NULL, NULL, CONFIG_THREAD_PRIORITY, 0, 0);

int main(void)
{
        if (!device_is_ready(led0.port)) {
                return -ENODEV;
        }
        if (!device_is_ready(led1.port)) {
                return -ENODEV;
        }

        gpio_pin_configure_dt(&led0, GPIO_OUTPUT_INACTIVE);
        gpio_pin_configure_dt(&led1, GPIO_OUTPUT_INACTIVE);

        
        return 0;
}
