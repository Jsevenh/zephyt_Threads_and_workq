#ifndef SYS_DEPS_H

#define SYS_DEPS_H
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include<zephyr/sys/printk.h>
#include<zephyr/sys/util.h>
#include<string.h>


// get data from the device tree
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);
static const struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET(DT_ALIAS(led), gpios);



#endif