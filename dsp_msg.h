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
void dsp_msg_sent(unsigned char cmd_type, unsigned int param1, unsigned int param2, unsigned int param3);
int dsp_msg_handle_thread_create(void);
void *dsp_write_pthread(void *arg);
#endif