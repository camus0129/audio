#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dsp_module.h"

DSP_MODULE_T *dsp_module;

void register_dsp_module(DSP_MODULE_T *dsp)
{
    if (dsp)
    {
        dsp_module = dsp;
    }
}

void unregister_dsp_module(void)
{
    dsp_module = NULL;
}

void dsp_power_on(void)
{
    dsp_module->power_on();
}

void dsp_power_off(void)
{
    dsp_module->power_off();
}

void dsp_init(void)
{
    dsp_module->init();
}

void dsp_sleep(int mode)
{
    dsp_module->sleep(mode);
}

void dsp_wake_up(int mode)
{
    dsp_module->wake_up(mode);
}

void dsp_input_mix_set(int mode)
{
    dsp_module->input_mix_set(mode);
}

void dsp_output_mix_set(int mode)
{
    dsp_module->output_mix_set(mode);
}

void dsp_master_volume_set(int gain)
{
    dsp_module->master_volume_set(gain);
}

void dsp_channel_volume_set(int channel, int gain)
{
    dsp_module->channel_volume_set(channel, gain);
}

void dsp_mute_set(int state)
{
    dsp_module->mute_set(state);
}

void dsp_unmute_set(void)
{
    dsp_module->unmute_set();
}

void dsp_bass_set(int bass)
{
    dsp_module->bass_set(bass);
}

void dsp_treble_set(int treble)
{
    dsp_module->treble_set(treble);
}

void dsp_channel_test_set(int channel, int gain)
{
    dsp_module->channel_test(channel, gain);
}

void dsp_eq_set(int mode)
{
    dsp_module->eq_set(mode);
}

void dsp_drc_set(int mode)
{
    dsp_module->drc_set(mode);
}

void dsp_agl_set(int mode)
{
    dsp_module->agl_set(mode);
}

void dsp_analog_set(int gain)
{
    dsp_module->analog_gain_set(gain);
}