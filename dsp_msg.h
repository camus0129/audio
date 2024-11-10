#ifndef __DSP_MSG_H__
#define __DSP_MSG_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define DSP_MSG_KEY "tcl_audio"

typedef struct
{
    long mtype;
    unsigned char cmd_type;
    unsigned int param1;
    unsigned int param2;
    unsigned int param3;
} DSP_MSG_T;

enum DSP_CMD_TYPE_E
{
    DSP_CMD_INIT = 0,
    DSP_CMD_SLEEP,
    DSP_CMD_WAKP_UP,
    DSP_CMD_INPUT_MIX_SET,
    DSP_CMD_OUTPUT_MIX_SET,
    DSP_CMD_MASTER_VOLUME_SET, // 5
    DSP_CMD_CHANNEL_VOLUME_SET,
    DSP_CMD_EQ_SET,
    DSP_CMD_DRC_SET,
    DSP_CMD_AGL_SET,
    DSP_CMD_ANALOG_GAIN_SET,
};

void dsp_msg_send(unsigned char cmd_type, unsigned int param1, unsigned int param2, unsigned int param3);
int dsp_msg_handle_thread_create(void);
void *dsp_write_pthread(void *arg);

#endif