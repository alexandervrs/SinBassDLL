#define sinBassDefine
/* SIN BASS DLL | VERSION 1.3.1 */
/* using bass.dll version 2.4.7.1 */

/* initialize the DLL, call this script before you use any functions from the DLL */

//DLL Path
var_sin_bass_dll = working_directory + "\sin-bass.dll";

//Declare functions available
global.var_sin_bass_init = external_define(var_sin_bass_dll, "sin_bass_init", dll_cdecl, ty_real, 2, ty_string, ty_real);
global.var_sin_bass_get_master_volume = external_define(var_sin_bass_dll, "sin_bass_get_master_volume", dll_cdecl, ty_real, 0);
global.var_sin_bass_set_master_volume = external_define(var_sin_bass_dll, "sin_bass_set_master_volume", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_set_global_volume = external_define(var_sin_bass_dll, "sin_bass_set_global_volume", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_get_global_volume = external_define(var_sin_bass_dll, "sin_bass_get_global_volume", dll_cdecl, ty_real, 0);
global.var_sin_bass_error_get_code = external_define(var_sin_bass_dll, "sin_bass_error_get_code", dll_cdecl, ty_real, 0);
global.var_sin_bass_get_device = external_define(var_sin_bass_dll, "sin_bass_get_device", dll_cdecl, ty_real, 0);
global.var_sin_bass_set_device = external_define(var_sin_bass_dll, "sin_bass_set_device", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_get_cpu = external_define(var_sin_bass_dll, "sin_bass_get_cpu", dll_cdecl, ty_real, 0);
global.var_sin_bass_close = external_define(var_sin_bass_dll, "sin_bass_close", dll_cdecl, ty_real, 0);

global.var_sin_bass_stream_load = external_define(var_sin_bass_dll, "sin_bass_stream_load", dll_cdecl, ty_real, 1, ty_string);
global.var_sin_bass_stream_play = external_define(var_sin_bass_dll, "sin_bass_stream_play", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_pause = external_define(var_sin_bass_dll, "sin_bass_stream_pause", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_resume = external_define(var_sin_bass_dll, "sin_bass_stream_resume", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_loop = external_define(var_sin_bass_dll, "sin_bass_stream_loop", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_set_loop = external_define(var_sin_bass_dll, "sin_bass_stream_set_loop", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.var_sin_bass_stream_get_loop = external_define(var_sin_bass_dll, "sin_bass_stream_get_loop", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_stop = external_define(var_sin_bass_dll, "sin_bass_stream_stop", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_set_volume = external_define(var_sin_bass_dll, "sin_bass_stream_set_volume", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.var_sin_bass_stream_get_volume = external_define(var_sin_bass_dll, "sin_bass_stream_get_volume", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_set_pitch = external_define(var_sin_bass_dll, "sin_bass_stream_set_pitch", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.var_sin_bass_stream_set_pan = external_define(var_sin_bass_dll, "sin_bass_stream_set_pan", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.var_sin_bass_stream_fade_volume = external_define(var_sin_bass_dll, "sin_bass_stream_fade_volume", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.var_sin_bass_stream_fade_pan = external_define(var_sin_bass_dll, "sin_bass_stream_fade_pan", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.var_sin_bass_stream_fade_pitch = external_define(var_sin_bass_dll, "sin_bass_stream_fade_pitch", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.var_sin_bass_stream_is_playing = external_define(var_sin_bass_dll, "sin_bass_stream_is_playing", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_is_paused = external_define(var_sin_bass_dll, "sin_bass_stream_is_paused", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_is_stopped = external_define(var_sin_bass_dll, "sin_bass_stream_is_stopped", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_volume_is_fading = external_define(var_sin_bass_dll, "sin_bass_stream_volume_is_fading", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_pitch_is_fading = external_define(var_sin_bass_dll, "sin_bass_stream_pitch_is_fading", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_pan_is_fading = external_define(var_sin_bass_dll, "sin_bass_stream_pan_is_fading", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_set_position_bytes = external_define(var_sin_bass_dll, "sin_bass_stream_set_position_bytes", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.var_sin_bass_stream_get_position_bytes = external_define(var_sin_bass_dll, "sin_bass_stream_get_position_bytes", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_get_position_seconds = external_define(var_sin_bass_dll, "sin_bass_stream_get_position_seconds", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_get_length_bytes = external_define(var_sin_bass_dll, "sin_bass_stream_get_length_bytes", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_get_length_seconds = external_define(var_sin_bass_dll, "sin_bass_stream_get_length_seconds", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_get_pitch = external_define(var_sin_bass_dll, "sin_bass_stream_get_pitch", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_get_pan = external_define(var_sin_bass_dll, "sin_bass_stream_get_pan", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_stream_free = external_define(var_sin_bass_dll, "sin_bass_stream_free", dll_cdecl, ty_real, 1, ty_real);

global.var_sin_bass_sample_load = external_define(var_sin_bass_dll, "sin_bass_sample_load", dll_cdecl, ty_real, 1, ty_string);
global.var_sin_bass_sample_play = external_define(var_sin_bass_dll, "sin_bass_sample_play", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_sample_stop = external_define(var_sin_bass_dll, "sin_bass_sample_stop", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_sample_free = external_define(var_sin_bass_dll, "sin_bass_sample_free", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_sample_set_volume = external_define(var_sin_bass_dll, "sin_bass_sample_set_volume", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.var_sin_bass_sample_set_pitch = external_define(var_sin_bass_dll, "sin_bass_sample_set_pitch", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.var_sin_bass_sample_set_pan = external_define(var_sin_bass_dll, "sin_bass_sample_set_pan", dll_cdecl, ty_real, 2, ty_real, ty_real);
global.var_sin_bass_sample_get_volume = external_define(var_sin_bass_dll, "sin_bass_sample_get_volume", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_sample_get_pitch = external_define(var_sin_bass_dll, "sin_bass_sample_get_pitch", dll_cdecl, ty_real, 1, ty_real);
global.var_sin_bass_sample_get_pan = external_define(var_sin_bass_dll, "sin_bass_sample_get_pan", dll_cdecl, ty_real, 1, ty_real);

#define sinBassInit
/*

Initializes the sound system

returns 1 on success, 0 on failure, -1 when then the bass.dll could not be found or not specified

*/

return external_call(global.var_sin_bass_init,argument0,window_handle());

#define sinBassClose
/*

Closes the sound system and cleans up memory (call on game end)

returns 1 on success, 0 on failure, -1 on bass.dll unload error

*/

return external_call(global.var_sin_bass_close);

#define sinBassGetDevice
/*

Returns the current audio device

returns device number on success, -1 on failure

*/

return external_call(global.var_sin_bass_get_device);

#define sinBassSetDevice
/*

Sets the device to use

returns 0 = no sound, 1 = first real output device

*/

return external_call(global.var_sin_bass_set_device,argument0);

#define sinBassGetCPU
/*

Returns the CPU Usage from bass.dll

returns the usage percent

*/

return external_call(global.var_sin_bass_get_cpu);

#define sinBassGetGlobalVolume
/*

Returns the volume of a all sounds (range: 0(mute) - 10000(full))

returns volume on success, -1 on failure

*/

return external_call(global.var_sin_bass_get_global_volume);

#define sinBassSetGlobalVolume
/*

Sets the volume for all sounds (range: 0(mute) - 10000(full))

returns volume on success, -1 on failure

*/

return external_call(global.var_sin_bass_set_global_volume,argument0);

#define sinBassGetMasterVolume
/*

Returns the volume of the system (range: 0(mute) - 1(full))

returns volume on success, -1 on failure

*/

return external_call(global.var_sin_bass_get_master_volume);

#define sinBassSetMasterVolume
/*

Sets the volume of the system (range: 0(mute) - 1(full))

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_set_master_volume,argument0);

#define sinBassErrorGetCode
/*

Returns the last error code from bass.dll

returns the error code:

0 BASS_OK (no error)
1 BASS_ERROR_MEM  
2 BASS_ERROR_FILEOPEN  
3 BASS_ERROR_DRIVER  
4 BASS_ERROR_BUFLOST  
5 BASS_ERROR_HANDLE  
6 BASS_ERROR_FORMAT  
7 BASS_ERROR_POSITION  
8 BASS_ERROR_INIT  
9 BASS_ERROR_START  
14 BASS_ERROR_ALREADY  
18 BASS_ERROR_NOCHAN  
19 BASS_ERROR_ILLTYPE  
20 BASS_ERROR_ILLPARAM  
21 BASS_ERROR_NO3D  
22 BASS_ERROR_NOEAX  
23 BASS_ERROR_DEVICE  
24 BASS_ERROR_NOPLAY  
25 BASS_ERROR_FREQ  
27 BASS_ERROR_NOTFILE  
29 BASS_ERROR_NOHW  
31 BASS_ERROR_EMPTY  
32 BASS_ERROR_NONET  
33 BASS_ERROR_CREATE  
34 BASS_ERROR_NOFX  
37 BASS_ERROR_NOTAVAIL  
38 BASS_ERROR_DECODE  
39 BASS_ERROR_DX  
40 BASS_ERROR_TIMEOUT  
41 BASS_ERROR_FILEFORM  
42 BASS_ERROR_SPEAKER  
43 BASS_ERROR_VERSION  
44 BASS_ERROR_CODEC  
45 BASS_ERROR_ENDED  
-1 BASS_ERROR_UNKNOWN  

*/

return external_call(global.var_sin_bass_error_get_code);

#define sinBassStreamLoad
/*

Loads an OGG/MP3/MP2/MP1/WAV/AIFF file into memory as a stream and returns an ID to refer to, 

You should load a sound with this way if you are going to use it as a music track

returns a numeric ID on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_load,argument0);

#define sinBassStreamPlay
/*

Plays a stream sound

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_play,argument0);

#define sinBassStreamLoop
/*

Plays a sound stream looping

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_loop,argument0);

#define sinBassStreamStop
/*

Stops a sound stream

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_stop,argument0);

#define sinBassStreamPause
/*

Pauses a sound stream

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_pause,argument0);

#define sinBassStreamResume
/*

Resumes a paused sound stream

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_resume,argument0);

#define sinBassStreamFree
/*

Unloads a sound stream from memory, use it when you no longer need the sound

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_free,argument0);

#define sinBassStreamSetLoop
/*

Sets the loop of a sound stream

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_set_loop,argument0,argument1);

#define sinBassStreamGetLoop
/*

Returns if a sound stream is looping / has loop on or off

returns 1 if loop on, 0 for off

*/

return external_call(global.var_sin_bass_stream_get_loop,argument0);

#define sinBassStreamSetVolume
/*

Sets the volume of a sound stream (range: 0(mute) - 1(full))

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_set_volume,argument0,argument1);

#define sinBassStreamGetVolume
/*

Returns the volume of a sound stream (range: 0(mute) - 1(full))

returns volume on success, -1 on failure

*/

return external_call(global.var_sin_bass_stream_get_volume,argument0);

#define sinBassStreamSetPitch
/*

Sets the pitch (frequency) of a sound stream (range: 0(mute) - 100000(full))

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_set_pitch,argument0,argument1);

#define sinBassStreamGetPitch
/*

Returns the pitch (frequency) of a sound stream (range: 0(mute) - 100000(full))

returns pitch on success, -1 on failure

*/

return external_call(global.var_sin_bass_stream_get_pitch,argument0);

#define sinBassStreamSetPan
/*

Sets the pan of a sound stream (range: -1(mute) - 1(full))

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_set_pan,argument0,argument1);

#define sinBassStreamGetPan
/*

Returns the pan of a sound stream (range: -1(mute) - 1(full))

returns pitch on success, -2 on failure

*/

return external_call(global.var_sin_bass_stream_get_pan,argument0);

#define sinBassStreamFadeVolume
/*

Fades the volume (range: 0(mute) - 1(full)) to a specified amount over time (milliseconds)

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_fade_volume,argument0,argument1,argument2);

#define sinBassStreamFadePitch
/*

Fades the pitch(frequency) (range: 0(mute) - 100000(full)) to a specified amount over time (milliseconds)

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_fade_pitch,argument0,argument1,argument2);

#define sinBassStreamFadePan
/*

Fades the panning (range: -1(mute) - 1(full)) to a specified amount over time (milliseconds)

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_fade_pan,argument0,argument1,argument2);

#define sinBassStreamVolumeIsFading
/*

Returns if the volume is currently fading

returns 1 if yes, 0 if not

*/

return external_call(global.var_sin_bass_stream_volume_is_fading,argument0);

#define sinBassStreamPitchIsFading
/*

Returns if the pitch (frequency) is currently fading

returns 1 if yes, 0 if not

*/

return external_call(global.var_sin_bass_stream_pitch_is_fading,argument0);

#define sinBassStreamPanIsFading
/*

Returns if the pan is currently fading

returns 1 if yes, 0 if not

*/

return external_call(global.var_sin_bass_stream_pan_is_fading,argument0);

#define sinBassStreamSetPositionBytes
/*

Sets the position of a sound stream in bytes

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_stream_set_position_bytes,argument0,argument1);

#define sinBassStreamGetPositionBytes
/*

Gets the position of a sound stream (in bytes)

returns the position on success, -1 on failure

*/

return external_call(global.var_sin_bass_stream_get_position_bytes,argument0);

#define sinBassStreamGetPositionSeconds
/*

Gets the position of a sound stream (in seconds)

returns the position on success, -1 on failure

*/

return external_call(global.var_sin_bass_stream_get_position_seconds,argument0);

#define sinBassStreamGetLengthBytes
/*

Gets the total length of a sound stream (in bytes)

returns the length on success, -1 on failure

*/

return external_call(global.var_sin_bass_stream_get_length_bytes,argument0);

#define sinBassStreamGetLengthSeconds
/*

Gets the total length of a sound stream (in seconds)

returns the length on success, -1 on failure

*/

return external_call(global.var_sin_bass_stream_get_length_seconds,argument0);

#define sinBassStreamIsPlaying
/*

Returns if the sound stream is playing

returns 1 if playing, 0 if not

*/

return external_call(global.var_sin_bass_stream_is_playing,argument0);

#define sinBassStreamIsPaused
/*

Returns if the sound stream is paused

returns 1 if paused, 0 if not

*/

return external_call(global.var_sin_bass_stream_is_paused,argument0);

#define sinBassStreamIsStopped
/*

Returns if the sound stream is stopped

returns 1 if stopped, 0 if not

*/

return external_call(global.var_sin_bass_stream_is_stopped,argument0);

#define sinBassSampleLoad
/*

Loads an OGG/MP3/MP2/MP1/WAV/AIFF file into memory as a sample and returns an ID to refer to, 

You must load a sound with this way if you are going to use it as a sound effect

returns a numeric ID on success, 0 on failure

*/

return external_call(global.var_sin_bass_sample_load,argument0);

#define sinBassSamplePlay
/*

Plays a sample sound

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_sample_play,argument0);

#define sinBassSampleStop
/*

Stops all playing instances of a sample sound

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_sample_stop,argument0);

#define sinBassSampleFree
/*

Unloads a sample sound from memory, use it when you no longer need the sound

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_sample_free,argument0);

#define sinBassSampleSetVolume
/*

Sets the volume of a sample sound (range: 0(mute) - 1(full))

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_sample_set_volume,argument0,argument1);

#define sinBassSampleGetVolume
/*

Gets the volume of a sample sound (range: 0(mute) - 1(full))

returns volume on success, -1 on failure

*/

return external_call(global.var_sin_bass_sample_get_volume,argument0);

#define sinBassSampleSetPitch
/*

Sets the sample pitch (frequency) of a sound (range: 0(mute) - 100000(full))

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_sample_set_pitch,argument0,argument1);

#define sinBassSampleGetPitch
/*

Gets the sample pitch (frequency) of a sound (range: 0(mute) - 100000(full))

returns pitch on success, -1 on failure

*/

return external_call(global.var_sin_bass_sample_get_pitch,argument0);

#define sinBassSampleSetPan
/*

Sets the pan of a sample sound (range: -1(mute) - 1(full))

returns 1 on success, 0 on failure

*/

return external_call(global.var_sin_bass_sample_set_pan,argument0,argument1);

#define sinBassSampleGetPan
/*

Retrieves the pan of a sample sound (range: -1(mute) - 1(full))

returns pan on success, -1 on failure

*/

return external_call(global.var_sin_bass_sample_get_pan,argument0);

