#ifndef __DSP_MODULE__H__
#define __DSP_MODULE__H__

typedef struct
{
    void (*power_on)(void);
    void (*power_off)(void);
    void (*init)(void);
    void (*sleep)(unsigned int);
    void (*wake_up)(unsigned int);
    void (*input_mix_set)(unsigned int);
    void (*output_mix_set)(unsigned int);
    void (*master_volume_set)(unsigned int);
    void (*channel_volume_set)(unsigned int, unsigned int);
    void (*eq_set)(unsigned int);
    void (*drc_set)(unsigned int);
    void (*agl_set)(unsigned int);
    void (*analog_gain_set)(unsigned int);
} DSP_MODULE_T;

void register_dsp_module(DSP_MODULE_T *dsp);
void unregister_dsp_module(void);
void dsp_power_on(void);
void dsp_power_off(void);
void dsp_init(void);
void dsp_sleep(unsigned int mode);
void dsp_wake_up(unsigned int mode);
void dsp_input_mix_set(unsigned int mode);
void dsp_output_mix_set(unsigned int mode);
void dsp_master_volume_set(unsigned int gain);
void dsp_channel_volume_set(unsigned int channel, unsigned int gain);
void dsp_eq_set(unsigned int mode);
void dsp_drc_set(unsigned int mode);
void dsp_agl_set(unsigned int mode);
void dsp_analog_set(unsigned int gain);
#endif