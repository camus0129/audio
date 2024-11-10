#ifndef __DSP_MODULE__H__
#define __DSP_MODULE__H__
typedef struct
{
    void (*power_on)(void);
    void (*power_off)(void);
    void (*dsp_init)(void);
    void (*dsp_input_mix)(unsigned int);
    void (*dsp_out_mix)(unsigned int);
    void (*dsp_volume_set)(unsigned int);
    void (*dsp_eq_set)(unsigned int);
    void (*dsp_drc_set)(unsigned int);
    void (*dsp_agl_set)(unsigned int);
    void (*dsp_analog_gain)(unsigned int);
} DSP_MODULE_T;

#endif