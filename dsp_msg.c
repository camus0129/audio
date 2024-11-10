
#include <pthread.h>
#include "dsp_msg.h"
key_t dsp_msg_key;
int msgid;
void *dsp_write_pthread(void *arg)
{
    while (1)
    {
        static DSP_MSG_T rcv_msg;
        memset(&rcv_msg, 0, sizeof(rcv_msg));
        int ret = msgrcv(msgid, &rcv_msg, sizeof(DSP_MSG_T) - sizeof(long), 0, 0);
        if (-1 == ret)
        {
            printf("rcv dsp msg error\n");
        }
        else
        {
            printf("rcv_msg = %d %d,%d\n", rcv_msg.param1, rcv_msg.param2, rcv_msg.param3);
        }
        sleep(1);
    }
}
int dsp_msg_handle_thread_create(void)
{
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
    }
    return 0;
}
void dsp_msg_sent(unsigned char cmd_type, unsigned int param1, unsigned int param2, unsigned int param3)
{
    static DSP_MSG_T test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    test_msg.mtype = 1;
    test_msg.cmd_type = cmd_type;
    test_msg.param1 = param1;
    test_msg.param2 = param2;
    test_msg.param3 = param3;
    int ret = msgsnd(msgid, &test_msg, sizeof(DSP_MSG_T) - sizeof(long), IPC_NOWAIT);
    if (-1 == ret)
    {
        printf("dsp msg sent fail\n");
    }
}