#ifndef __DSP_MSG_API_H__
#define __DSP_MSG_API_H__
#include "dsp_msg.h"
void tcl_dsp_init(void);
void tcl_dsp_sleep(int mode);
void tcl_dsp_wake_up(int mode);
void tcl_dsp_input_mix_set(int mode);
void tcl_dsp_output_mix_set(int mode);
void tcl_dsp_master_volume_set(int gain);
void tcl_dsp_channel_volume_set(int channel, int gain);
void tcl_dsp_mute_set(int state);
void tcl_dsp_unmute_set(void);
void tcl_dsp_bass_set(int bass);
void tcl_dsp_treble_set(int treble);
void tcl_dsp_channel_test_set(int channel, int gain);
void tcl_dsp_eq_set(int mode);
void tcl_dsp_drc_set(int mode);
void tcl_dsp_agl_set(int mode);
void tcl_dsp_analog_set(int gain);
#endif