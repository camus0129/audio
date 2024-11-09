#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
void *dsp_write_pthread(void *arg)
{
    while (1)
    {
        sleep(1);
        printf("dsp_write_pthread\n");
    }
}


int main(void)
{
    pthread_t dsp_write_pid;
    int res = pthread_create(&dsp_write_pid, NULL, dsp_write_pthread, NULL);
    printf("test\n");
    while (1)
    {
    }
    return 0;
}
