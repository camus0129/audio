#include "dsp_drv_gpio.h"

#define SYSFS_GPIO_EXPORT "/sys/class/gpio/export"

int gpio_is_exported(int gpio)
{
    int res = 0;
    char gpio_param[40] = {0};
    snprintf(gpio_param, sizeof(gpio_param), "/sys/class/gpio/gpio%d/direction", gpio);
    if (access(gpio_param, F_OK) == 0)
    {
        res = 1;
    }
    return res;
}
int gpio_export(int gpio)
{
    if (gpio_is_exported(gpio))
    {
        printf("gpio %d has already exported\n", gpio);
        return 0;
    }
    else
    {
        int res = 0;
        int fd = open(SYSFS_GPIO_EXPORT, O_WRONLY);
        if (fd < 0)
        {
            printf("open /sys/class/gpio/export fail\n");
            return -1;
        }
        else
        {
            char gpio_port[5] = {0};
            snprintf(gpio_port, sizeof(gpio_port), "%d", gpio);
            res = write(fd, gpio_port, sizeof(gpio_port));
            if (res < 0)
            {
                printf("export gpio %d fail\n", gpio);
                return res;
            }
            printf("export gpio %s sucessfully\n", gpio_port);
        }
        close(fd);
        return res;
    }
}
int gpio_set_direction(int gpio, int direction)
{
    int res = 0;
    char gpio_param[40] = {0};
    snprintf(gpio_param, sizeof(gpio_param), "/sys/class/gpio/gpio%d/direction", gpio);
    int fd = open(gpio_param, O_WRONLY);
    if (fd < 0)
    {
        printf("fail to open sys gpio %d direction \n", gpio);
        return -1;
    }
    else
    {
        if (direction) // out
        {
            res = write(fd, "out", 4);
        }
        else
        {
            res = write(fd, "in", 3);
        }
        if (res < 0)
        {
            printf("fail to set sys gpio direction %d\n", direction);
            return -1;
        }
        else
        {
            printf("set gpio %d direction %d\n", gpio, direction);
        }
        close(fd);
        return res;
    }
}
int gpio_set_value(int gpio, int value)
{
    int res = 0;
    char gpio_param[40] = {0};
    snprintf(gpio_param, sizeof(gpio_param), "/sys/class/gpio/gpio%d/value", gpio);
    int fd = open(gpio_param, O_WRONLY);
    if (fd < 0)
    {
        printf("fail to open sys gpio %d value \n", gpio);
        return -1;
    }
    else
    {
        if (value) // out
        {
            res = write(fd, "1", 2);
        }
        else
        {
            res = write(fd, "0", 2);
        }
        if (res < 0)
        {
            printf("set sys gpio value %d fail\n", value);
            return -1;
        }
        else
        {
            printf("set gpio %d value %d ok\n", gpio, value);
        }
        close(fd);
        return res;
    }
}
#if 0 // for api test
int main(void)
{
    gpio_export(514);
    gpio_set_direction(514, 1);
    gpio_set_value(514, 0);
}
#endif