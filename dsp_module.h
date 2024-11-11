#ifndef __DSP_MODULE__H__
#define __DSP_MODULE__H__

typedef struct
{
    void (*power_on)(void);
    void (*power_off)(void);
    void (*init)(void);
    void (*sleep)(int);
    void (*wake_up)(int);
    void (*input_mix_set)(int);
    void (*output_mix_set)(int);
    void (*master_volume_set)(int);
    void (*channel_volume_set)(int, int);
    void (*mute_set)(int);
    void (*unmute_set)(void);
    void (*bass_set)(int);
    void (*treble_set)(int);
    void (*channel_test)(int, int);
    void (*eq_set)(int);
    void (*drc_set)(int);
    void (*agl_set)(int);
    void (*analog_gain_set)(int);
} DSP_MODULE_T;

void register_dsp_module(DSP_MODULE_T *dsp);
void unregister_dsp_module(void);
void dsp_power_on(void);
void dsp_power_off(void);
void dsp_init(void);
void dsp_sleep(int mode);
void dsp_wake_up(int mode);
void dsp_input_mix_set(int mode);
void dsp_output_mix_set(int mode);
void dsp_master_volume_set(int gain);
void dsp_channel_volume_set(int channel, int gain);
void dsp_eq_set(int mode);
void dsp_drc_set(int mode);
void dsp_agl_set(int mode);
void dsp_analog_set(int gain);
#endif