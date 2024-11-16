#ifndef __DSP_DRV_I2C_H__
#define __DSP_DRV_I2C_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
int gpio_export(int gpio);
int gpio_set_direction(int gpio, int direction);
int gpio_set_value(int gpio, int value);
#endif