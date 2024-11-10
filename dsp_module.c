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

void dsp_sleep(unsigned int mode)
{
    dsp_module->sleep(mode);
}

void dsp_wake_up(unsigned int mode)
{
    dsp_module->wake_up(mode);
}

void dsp_input_mix_set(unsigned int mode)
{
    dsp_module->input_mix_set(mode);
}

void dsp_output_mix_set(unsigned int mode)
{
    dsp_module->output_mix_set(mode);
}

void dsp_master_volume_set(unsigned int gain)
{
    dsp_module->master_volume_set(gain);
}

void dsp_channel_volume_set(unsigned int gain)
{
    dsp_module->channel_volume_set(gain);
}

void dsp_eq_set(unsigned int mode)
{
    dsp_module->eq_set(mode);
}

void dsp_drc_set(unsigned int mode)
{
    dsp_module->drc_set(mode);
}

void dsp_agl_set(unsigned int mode)
{
    dsp_module->agl_set(mode);
}

void dsp_analog_set(unsigned int gain)
{
    dsp_module->analog_gain_set(gain);
}