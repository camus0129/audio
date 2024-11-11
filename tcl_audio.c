#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dsp_msg_api.h"

int main(void)
{
    printf("tcl audio init start\n");
    int res = dsp_msg_handle_thread_create();
    if (res < 0)
    {
        printf("thread create eror\n");
    }
    else
    {
        while (1)
        {
            static unsigned int i = 0;
            tcl_dsp_init();
            i++;
            sleep(1);
        }
    }
    return 0;
}
