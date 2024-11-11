
#include <pthread.h>
#include "dsp_msg.h"
#include "dsp_module.h"

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
            printf("rcv_msg: cmd_type = %d,param1= %d, param2 = %d,param3 = %d\n", rcv_msg.cmd_type, rcv_msg.param1, rcv_msg.param2, rcv_msg.param3);
            switch (rcv_msg.cmd_type)
            {
            case DSP_CMD_INIT:
            {
                printf("dsp init set cmd\n");
                // dsp_init();
                break;
            }
            case DSP_CMD_SLEEP:
            {
                printf("dsp sleep set cmd\n");
                break;
            }
            case DSP_CMD_WAKP_UP:
            {
                printf("dsp wakeup set cmd\n");
                break;
            }
            case DSP_CMD_INPUT_MIX_SET:
            {
                printf("dsp input mix set cmd\n");
                break;
            }
            case DSP_CMD_OUTPUT_MIX_SET:
            {
                printf("dsp output mix set cmd\n");
                break;
            }
            case DSP_CMD_MASTER_VOLUME_SET:
            {
                printf("dsp master vol set cmd\n");
                break;
            }
            case DSP_CMD_CHANNEL_VOLUME_SET:
            {
                printf("dsp channel vol set cmd\n");
                break;
            }
            case DSP_CMD_MUTE_SET:
            {
                printf("dsp mute set cmd\n");
                break;
            }
            case DSP_CMD_UNMUTE_SET:
            {
                printf("dsp unmute set cmd\n");
                break;
            }
            case DSP_CMD_BASS_SET:
            {
                printf("dsp bass set cmd\n");
                break;
            }
            case DSP_CMD_TREBLE_SET:
            {
                printf("dsp treble set cmd\n");
                break;
            }
            case DSP_CMD_EQ_SET:
            {
                printf("dsp eq set cmd\n");
                break;
            }
            case DSP_CMD_DRC_SET:
            {
                printf("dsp drc set cmd\n");
                break;
            }
            case DSP_CMD_AGL_SET:
            {
                printf("dsp agl set cmd\n");
                break;
            }
            case DSP_CMD_ANALOG_GAIN_SET:
            {
                printf("dsp analog gain set cmd\n");
                break;
            }
            default:
            {
                printf("unknown cmd type = %d\n", rcv_msg.cmd_type);
                break;
            }
            }
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
void dsp_msg_send(unsigned char cmd_type, int param1, int param2, int param3)
{
    static DSP_MSG_T test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    test_msg.mtype = 1; // fixed mtype = 1
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
