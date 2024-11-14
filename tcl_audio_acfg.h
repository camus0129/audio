#ifndef __TCL_AUDIO_ACFG_H__
#define __TCL_AUDIO_ACFG_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define VOL_MIN 0
#define VOL_MAX 100
#define VOL_DEFAULT 50

int tcl_audio_get_volume(void);
void tcl_audio_set_volume(int volume);
int tcl_audio_get_mute(void);
void tcl_audio_set_mute(int mute);
int tcl_audio_get_sound_mode(void);
void tcl_audio_set_sound_mode(int mode);
int tcl_audio_get_bass(void);
void tcl_audio_set_bass(int bass);
int tcl_audio_get_treble(void);
void tcl_audio_set_treble(int treble);
int tcl_audio_get_night_mode(void);
void tcl_audio_set_night_mode(int night_mdoe);
int tcl_audio_get_system_mode(void);
void tcl_audio_set_system_mode(int mode);
int tcl_audio_get_voice_enhance_mode(void);
void tcl_audio_set_voice_enhance_mode(int mode);
int tcl_audio_get_surround_enhance_mode(void);
void tcl_audio_set_surround_enhance_mode(int mode);
int tcl_audio_get_ai_sonic_mode(void);
void tcl_audio_set_ai_sonic_mode(int mode);
#endif