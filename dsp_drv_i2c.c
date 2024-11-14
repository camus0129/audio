#include "dsp_drv_i2c.h"

#define SYSFS_GPIO_EXPORT "/sys/class/gpio/export"

int gpio_export(int gpio)
{
    int fd = open(SYSFS_GPIO_EXPORT, O_WRONLY);
    if (fd < 0)
    {
        printf("fail to open sys gpio export %d\n", fd);
        return fd;
    }
    else
    {
        char gpio_port[5] = {0};
        sprintf(gpio_port, "%d", gpio);
        printf("%s\n", gpio_port);
    }
    close(fd);
}
#if 0
int main(void)
{
    gpio_export(5);
}
#endif