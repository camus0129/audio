#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dsp_msg.h"
#include <pthread.h>

key_t dsp_msg_key;
int msgid;

int main(void)
{
    printf("tcl audio init start2\n");
#if 0
    int res = dsp_msg_handle_thread_create();
    if (res < 0)
    {
        printf("thread create eror\n");
    }
#endif
    pthread_t dsp_write_pid;
    // get ipc msg key
    dsp_msg_key = ftok(DSP_MSG_KEY, 20);
    // get ipc msg id
    msgid = msgget(dsp_msg_key, 0666 | IPC_CREAT);
    if (-1 == msgid)
    {
        printf("create dsp ipc msg error\n");
        return -1;
    }
    else
    {
        // create a thread to receive msg from main process
        int res = pthread_create(&dsp_write_pid, NULL, dsp_write_pthread, NULL);
        if (res < 0)
        {
            printf("create dsp msg handle thread fail\n");
            return res;
        }
        while (1)
        {
            static unsigned int i = 0;
            static DSP_MSG_T test_msg;
            memset(&test_msg, 0, sizeof(test_msg));
            test_msg.mtype = 1;
            test_msg.cmd_type = 1;
            test_msg.param1 = i;
            test_msg.param2 = i;
            test_msg.param3 = i;
            int ret = msgsnd(msgid, &test_msg, sizeof(DSP_MSG_T) - sizeof(long), IPC_NOWAIT);
            if (-1 == ret)
            {
                printf("dsp msg sent fail\n");
            }
            i++;
            sleep(1);
        }
    }
    return 0;
}
