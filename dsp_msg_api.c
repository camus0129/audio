#include "dsp_msg_api.h"

void tcl_dsp_init(void)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_INIT, 0, 0, 0);
}
void tcl_dsp_sleep(int mode)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_SLEEP, mode, 0, 0);
}
void tcl_dsp_wake_up(int mode)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_WAKP_UP, mode, 0, 0);
}
void tcl_dsp_input_mix_set(int mode)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_INPUT_MIX_SET, mode, 0, 0);
}
void tcl_dsp_output_mix_set(int mode)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_OUTPUT_MIX_SET, mode, 0, 0);
}

void tcl_dsp_master_volume_set(int gain)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_MASTER_VOLUME_SET, gain, 0, 0);
}

void tcl_dsp_channel_volume_set(int channel, int gain)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_CHANNEL_VOLUME_SET, channel, gain, 0);
}

void tcl_dsp_mute_set(int state)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_MUTE_SET, state, 0, 0);
}

void tcl_dsp_unmute_set(void)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_UNMUTE_SET, 0, 0, 0);
}

void tcl_dsp_bass_set(int bass)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_BASS_SET, bass, 0, 0);
}

void tcl_dsp_treble_set(int treble)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_TREBLE_SET, treble, 0, 0);
}

void tcl_dsp_channel_test_set(int channel, int gain)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_CHANNEL_TEST_SET, channel, gain, 0);
}

void tcl_dsp_eq_set(int mode)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_EQ_SET, mode, 0, 0);
}

void tcl_dsp_drc_set(int mode)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_DRC_SET, mode, 0, 0);
}

void tcl_dsp_agl_set(int mode)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_AGL_SET, mode, 0, 0);
}

void tcl_dsp_analog_set(int gain)
{
    printf("%s\n", __func__);
    dsp_msg_send(DSP_CMD_ANALOG_GAIN_SET, gain, 0, 0);
}