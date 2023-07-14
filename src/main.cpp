
#ifndef UNICODE
	#undef _UNICODE
#else
	#ifndef _UNICODE
		#define _UNICODE
	#endif
#endif

#include "main.h"
#include <windows.h>
#include <math.h>
#include "bass.h"
#include <string>

HINSTANCE dll_handle;

/* BASS DLL FUNCTIONS */
typedef BOOL(CALLBACK * FUNCTION_BASS_INIT)(int device, DWORD freq, DWORD flags, HWND win, GUID * clsid);
FUNCTION_BASS_INIT BASS_init;

typedef DWORD(CALLBACK * FUNCTION_BASS_LOAD)(BOOL mem, void * file, QWORD offset, QWORD length, DWORD flags);
FUNCTION_BASS_LOAD BASS_load;

typedef BOOL(CALLBACK * FUNCTION_BASS_PLAY)(DWORD handle, BOOL restart);
FUNCTION_BASS_PLAY BASS_play;

typedef BOOL(CALLBACK * FUNCTION_BASS_PAUSE)(DWORD handle);
FUNCTION_BASS_PAUSE BASS_pause;

typedef BOOL(CALLBACK * FUNCTION_BASS_STOP)(DWORD handle);
FUNCTION_BASS_STOP BASS_stop;

typedef BOOL(CALLBACK * FUNCTION_BASS_FLAGS)(DWORD handle, DWORD flags, DWORD mask);
FUNCTION_BASS_FLAGS BASS_flags;

typedef BOOL(CALLBACK * FUNCTION_BASS_SET_ATTRIBUTE)(DWORD handle, DWORD attrib, float value);
FUNCTION_BASS_SET_ATTRIBUTE BASS_set_attribute;

typedef BOOL(CALLBACK * FUNCTION_BASS_GET_ATTRIBUTE)(DWORD handle, DWORD attrib, float * value);
FUNCTION_BASS_GET_ATTRIBUTE BASS_get_attribute;

typedef int(CALLBACK * FUNCTION_BASS_ERROR_GET_CODE)();
FUNCTION_BASS_ERROR_GET_CODE BASS_error_get_code;

typedef float(CALLBACK * FUNCTION_BASS_GET_CPU)();
FUNCTION_BASS_GET_CPU BASS_get_cpu;

typedef BOOL(CALLBACK * FUNCTION_BASS_CLOSE)();
FUNCTION_BASS_CLOSE BASS_close;

typedef BOOL(CALLBACK * FUNCTION_BASS_FREE)(DWORD handle);
FUNCTION_BASS_FREE BASS_free;

typedef BOOL(CALLBACK * FUNCTION_BASS_SET_CONFIG)(DWORD option, DWORD value);
FUNCTION_BASS_SET_CONFIG BASS_set_config;

typedef DWORD(CALLBACK * FUNCTION_BASS_GET_CONFIG)(DWORD option);
FUNCTION_BASS_GET_CONFIG BASS_get_config;

typedef float(CALLBACK * FUNCTION_BASS_GET_MVOLUME)();
FUNCTION_BASS_GET_MVOLUME BASS_get_mvolume;

typedef BOOL(CALLBACK * FUNCTION_BASS_SET_MVOLUME)(float volume);
FUNCTION_BASS_SET_MVOLUME BASS_set_mvolume;

typedef BOOL(CALLBACK * FUNCTION_BASS_SET_DEVICE)(DWORD device);
FUNCTION_BASS_SET_DEVICE BASS_set_device;

typedef DWORD(CALLBACK * FUNCTION_BASS_GET_DEVICE)();
FUNCTION_BASS_GET_DEVICE BASS_get_device;

typedef BOOL(CALLBACK * FUNCTION_BASS_SLIDE)(DWORD handle, DWORD attrib, float value, DWORD time);
FUNCTION_BASS_SLIDE BASS_slide;

typedef BOOL(CALLBACK * FUNCTION_BASS_IS_SLIDING)(DWORD handle, DWORD attrib);
FUNCTION_BASS_IS_SLIDING BASS_is_sliding;

typedef DWORD(CALLBACK * FUNCTION_BASS_IS_ACTIVE)(DWORD device);
FUNCTION_BASS_IS_ACTIVE BASS_is_active;

typedef DWORD(CALLBACK * FUNCTION_BASS_SET_POSITION)(DWORD handle, QWORD pos, DWORD mode);
FUNCTION_BASS_SET_POSITION BASS_set_position;

typedef QWORD(CALLBACK * FUNCTION_BASS_GET_POSITION)(DWORD handle, DWORD mode);
FUNCTION_BASS_GET_POSITION BASS_get_position;

typedef QWORD(CALLBACK * FUNCTION_BASS_GET_LENGTH)(DWORD handle, DWORD mode);
FUNCTION_BASS_GET_LENGTH BASS_get_length;

typedef DWORD(CALLBACK * FUNCTION_BASS_LOAD_SAMPLE)(BOOL mem, void * file, QWORD offset, DWORD length, DWORD max, DWORD flags);
FUNCTION_BASS_LOAD_SAMPLE BASS_load_sample;

typedef DWORD(CALLBACK * FUNCTION_BASS_SAMPLE_GET_CHANNEL)(DWORD handle, BOOL onlynew);
FUNCTION_BASS_SAMPLE_GET_CHANNEL BASS_sample_get_channel;

typedef BOOL(CALLBACK * FUNCTION_BASS_SAMPLE_STOP)(DWORD handle);
FUNCTION_BASS_SAMPLE_STOP BASS_sample_stop;

typedef BOOL(CALLBACK * FUNCTION_BASS_SAMPLE_FREE)(DWORD handle);
FUNCTION_BASS_SAMPLE_FREE BASS_sample_free;

typedef BOOL(CALLBACK * FUNCTION_BASS_SAMPLE_SET_INFO)(DWORD handle, BASS_SAMPLE * info);
FUNCTION_BASS_SAMPLE_SET_INFO BASS_sample_set_info;

typedef BOOL(CALLBACK * FUNCTION_BASS_SAMPLE_GET_INFO)(DWORD handle, BASS_SAMPLE * info);
FUNCTION_BASS_SAMPLE_GET_INFO BASS_sample_get_info;

typedef double(CALLBACK * FUNCTION_BASS_BYTES2SECONDS)(DWORD handle, QWORD pos);
FUNCTION_BASS_BYTES2SECONDS BASS_bytes2seconds;

typedef QWORD(CALLBACK * FUNCTION_BASS_SECONDS2BYTES)(DWORD handle, double pos);
FUNCTION_BASS_SECONDS2BYTES BASS_seconds2bytes;
/* end of BASS DLL FUNCTIONS */

std::wstring string_to_wstring(std::string stringName)
{
    int len;
    int slength = (int)stringName.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, stringName.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, stringName.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

export double sin_bass_init(LPCSTR dllfile, double window_handle) {

    dll_handle = LoadLibrary(string_to_wstring(dllfile).c_str());

    if (!dll_handle) {
        return -1;
    }

    BASS_init = (FUNCTION_BASS_INIT) GetProcAddress(dll_handle, "BASS_Init");
    BASS_load = (FUNCTION_BASS_LOAD) GetProcAddress(dll_handle, "BASS_StreamCreateFile");
    BASS_play = (FUNCTION_BASS_PLAY) GetProcAddress(dll_handle, "BASS_ChannelPlay");
    BASS_pause = (FUNCTION_BASS_PAUSE) GetProcAddress(dll_handle, "BASS_ChannelPause");
    BASS_stop = (FUNCTION_BASS_STOP) GetProcAddress(dll_handle, "BASS_ChannelStop");
    BASS_flags = (FUNCTION_BASS_FLAGS) GetProcAddress(dll_handle, "BASS_ChannelFlags");
    BASS_set_attribute = (FUNCTION_BASS_SET_ATTRIBUTE) GetProcAddress(dll_handle, "BASS_ChannelSetAttribute");
    BASS_get_attribute = (FUNCTION_BASS_GET_ATTRIBUTE) GetProcAddress(dll_handle, "BASS_ChannelGetAttribute");
    BASS_error_get_code = (FUNCTION_BASS_ERROR_GET_CODE) GetProcAddress(dll_handle, "BASS_ErrorGetCode");
    BASS_get_cpu = (FUNCTION_BASS_GET_CPU) GetProcAddress(dll_handle, "BASS_GetCPU");
    BASS_close = (FUNCTION_BASS_CLOSE) GetProcAddress(dll_handle, "BASS_Free");
    BASS_free = (FUNCTION_BASS_FREE) GetProcAddress(dll_handle, "BASS_StreamFree");
    BASS_get_mvolume = (FUNCTION_BASS_GET_MVOLUME) GetProcAddress(dll_handle, "BASS_GetVolume");
    BASS_set_mvolume = (FUNCTION_BASS_SET_MVOLUME) GetProcAddress(dll_handle, "BASS_SetVolume");
    BASS_set_config = (FUNCTION_BASS_SET_CONFIG) GetProcAddress(dll_handle, "BASS_SetConfig");
    BASS_get_config = (FUNCTION_BASS_GET_CONFIG) GetProcAddress(dll_handle, "BASS_GetConfig");
    BASS_set_device = (FUNCTION_BASS_SET_DEVICE) GetProcAddress(dll_handle, "BASS_SetDevice");
    BASS_get_device = (FUNCTION_BASS_GET_DEVICE) GetProcAddress(dll_handle, "BASS_GetDevice");
    BASS_slide = (FUNCTION_BASS_SLIDE) GetProcAddress(dll_handle, "BASS_ChannelSlideAttribute");
    BASS_is_sliding = (FUNCTION_BASS_IS_SLIDING) GetProcAddress(dll_handle, "BASS_ChannelIsSliding");
    BASS_is_active = (FUNCTION_BASS_IS_ACTIVE) GetProcAddress(dll_handle, "BASS_ChannelIsActive");
    BASS_set_position = (FUNCTION_BASS_SET_POSITION) GetProcAddress(dll_handle, "BASS_ChannelSetPosition");
    BASS_get_position = (FUNCTION_BASS_GET_POSITION) GetProcAddress(dll_handle, "BASS_ChannelGetPosition");
    BASS_get_length = (FUNCTION_BASS_GET_LENGTH) GetProcAddress(dll_handle, "BASS_ChannelGetLength");
    BASS_load_sample = (FUNCTION_BASS_LOAD_SAMPLE) GetProcAddress(dll_handle, "BASS_SampleLoad");
    BASS_sample_get_channel = (FUNCTION_BASS_SAMPLE_GET_CHANNEL) GetProcAddress(dll_handle, "BASS_SampleGetChannel");
    BASS_sample_stop = (FUNCTION_BASS_SAMPLE_STOP) GetProcAddress(dll_handle, "BASS_SampleStop");
    BASS_sample_free = (FUNCTION_BASS_SAMPLE_FREE) GetProcAddress(dll_handle, "BASS_SampleFree");
    BASS_sample_set_info = (FUNCTION_BASS_SAMPLE_SET_INFO) GetProcAddress(dll_handle, "BASS_SampleSetInfo");
    BASS_sample_get_info = (FUNCTION_BASS_SAMPLE_GET_INFO) GetProcAddress(dll_handle, "BASS_SampleGetInfo");
    BASS_bytes2seconds = (FUNCTION_BASS_BYTES2SECONDS) GetProcAddress(dll_handle, "BASS_ChannelBytes2Seconds");
    BASS_seconds2bytes = (FUNCTION_BASS_SECONDS2BYTES) GetProcAddress(dll_handle, "BASS_ChannelSeconds2Bytes");

    if (!BASS_init) {
        FreeLibrary(dll_handle);
        return -1;
    }

    if (BASS_init(-1, 44100, 0, (HWND)(int) window_handle, NULL)) {
        return 1;
    } else {
        return 0;
    }

}

/* STREAMS */
export double sin_bass_stream_load(LPSTR file) {
    return BASS_load(FALSE, file, 0, 0, 0);
}

export double sin_bass_stream_free(double filehandle) {
    if (BASS_free((DWORD) filehandle)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_play(double filehandle) {
    if (BASS_play((DWORD) filehandle, TRUE)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_loop(double filehandle) {

    if (BASS_flags((DWORD) filehandle, BASS_SAMPLE_LOOP, BASS_SAMPLE_LOOP)) {
        if (BASS_play((DWORD) filehandle, TRUE)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return -1;
    }
}

export double sin_bass_stream_set_loop(double filehandle, double attrflag) {
    if (attrflag == 1) {
        if (BASS_flags((DWORD) filehandle, BASS_SAMPLE_LOOP, BASS_SAMPLE_LOOP)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (BASS_flags((DWORD) filehandle, 0, BASS_SAMPLE_LOOP)) {
            return 1;
        } else {
            return 0;
        }
    }
}

export double sin_bass_stream_get_loop(double filehandle) {
    if (BASS_flags((DWORD) filehandle, BASS_SAMPLE_LOOP, 0)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_set_device(double device) {

    if (BASS_set_device((DWORD) device)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_get_device() {

    return (double) BASS_get_device();
}

export double sin_bass_set_global_volume(double amount) {

    if (BASS_set_config(BASS_CONFIG_GVOL_STREAM, (DWORD) amount)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_get_global_volume() {
    return (double) BASS_get_config(BASS_CONFIG_GVOL_STREAM);
}

export double sin_bass_get_master_volume() {
    return (double) BASS_get_mvolume();
}

export double sin_bass_set_master_volume(double amount) {
    if (BASS_set_mvolume((float) amount)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_get_volume(double filehandle) {
    float value;
    if (BASS_get_attribute((DWORD) filehandle, BASS_ATTRIB_VOL, & value)) {
        return (double) value;
    } else {
        return -1;
    }
}

export double sin_bass_stream_get_pitch(double filehandle) {
    float value;
    if (BASS_get_attribute((DWORD) filehandle, BASS_ATTRIB_FREQ, & value)) {
        return (double) value;
    } else {
        return -2;
    }
}

export double sin_bass_stream_get_pan(double filehandle) {
    float value;
    if (BASS_get_attribute((DWORD) filehandle, BASS_ATTRIB_PAN, & value)) {
        return (double) value;
    } else {
        return -1;
    }
}

export double sin_bass_stream_set_volume(double filehandle, double amount) {

    if (BASS_set_attribute((DWORD) filehandle, BASS_ATTRIB_VOL, (float) amount)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_set_pitch(double filehandle, double amount) {
    if (BASS_set_attribute((DWORD) filehandle, BASS_ATTRIB_FREQ, (float) amount)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_set_pan(double filehandle, double amount) {

    if (BASS_set_attribute((DWORD) filehandle, BASS_ATTRIB_PAN, (float) amount)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_resume(double filehandle) {
    if (BASS_play((DWORD) filehandle, FALSE)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_pause(double filehandle) {
    if (BASS_pause((DWORD) filehandle)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_stop(double filehandle) {
    if (BASS_stop((DWORD) filehandle)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_error_get_code() {
    return (double) BASS_error_get_code();
}

export double sin_bass_get_cpu() {
    return (double) BASS_get_cpu();
}

export double sin_bass_close() {
    if (!BASS_close()) {
        return 0;
    }
    if (!FreeLibrary(dll_handle)) {
        return -1;
    }

    return 1;
}

export double sin_bass_stream_fade_volume(double filehandle, double amount, double time) {
    if (BASS_slide((DWORD) filehandle, BASS_ATTRIB_VOL, (float) amount, (DWORD) time)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_fade_pan(double filehandle, double amount, double time) {
    if (BASS_slide((DWORD) filehandle, BASS_ATTRIB_PAN, (float) amount, (DWORD) time)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_fade_pitch(double filehandle, double amount, double time) {
    if (BASS_slide((DWORD) filehandle, BASS_ATTRIB_FREQ, (float) amount, (DWORD) time)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_is_playing(double filehandle) {
    if (BASS_is_active((DWORD) filehandle) == BASS_ACTIVE_PLAYING) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_is_paused(double filehandle) {
    if (BASS_is_active((DWORD) filehandle) == BASS_ACTIVE_PAUSED) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_is_stopped(double filehandle) {
    if (BASS_is_active((DWORD) filehandle) == BASS_ACTIVE_STOPPED) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_volume_is_fading(double filehandle) {
    if (BASS_is_sliding((DWORD) filehandle, BASS_ATTRIB_VOL)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_pitch_is_fading(double filehandle) {
    if (BASS_is_sliding((DWORD) filehandle, BASS_ATTRIB_FREQ)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_pan_is_fading(double filehandle) {
    if (BASS_is_sliding((DWORD) filehandle, BASS_ATTRIB_PAN)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_set_position_seconds(double filehandle, double pos) {
    double spos;
    spos = floor(BASS_seconds2bytes((DWORD) filehandle, pos));
    if (BASS_set_position((DWORD) filehandle, (QWORD) spos, BASS_POS_BYTE)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_set_position_bytes(double filehandle, double pos) {
    if (BASS_set_position((DWORD) filehandle, (QWORD) pos, BASS_POS_BYTE)) {
        return 1;
    } else {
        return 0;
    }
}

export double sin_bass_stream_get_position_seconds(double filehandle) {

    DWORD pos;
    pos = BASS_get_position((DWORD) filehandle, BASS_POS_BYTE);
    return floor(BASS_bytes2seconds((DWORD) filehandle, pos));
}

export double sin_bass_stream_get_position_bytes(double filehandle) {
    return BASS_get_position((DWORD) filehandle, BASS_POS_BYTE);
}

export double sin_bass_stream_get_length_bytes(double filehandle) {
    return (double) BASS_get_length((DWORD) filehandle, BASS_POS_BYTE);
}

export double sin_bass_stream_get_length_seconds(double filehandle) {
    DWORD pos;
    pos = BASS_get_length((DWORD) filehandle, BASS_POS_BYTE);
    return floor(BASS_bytes2seconds((DWORD) filehandle, pos));
}

/* SAMPLES */

export double sin_bass_sample_load(LPSTR file) {
    return BASS_load_sample(FALSE, file, 0, 0, 65534, 0);
}

export double sin_bass_sample_play(double filehandle) {
    DWORD chan;
    chan = BASS_sample_get_channel((DWORD) filehandle, FALSE);
    return BASS_play(chan, FALSE);
}

export double sin_bass_sample_stop(double filehandle) {
    return BASS_sample_stop((DWORD) filehandle);
}

export double sin_bass_sample_free(double filehandle) {
    return BASS_sample_free((DWORD) filehandle);
}

export double sin_bass_sample_set_volume(double filehandle, double amount) {
    BASS_SAMPLE info;
    BASS_sample_get_info((DWORD) filehandle, & info);

    info.volume = (float) amount;
    return BASS_sample_set_info((DWORD) filehandle, & info);
}

export double sin_bass_sample_get_volume(double filehandle) {
    BASS_SAMPLE info;
    if (BASS_sample_get_info((DWORD) filehandle, & info)) {
        return (double) info.volume;
    } else {
        return -1;
    }
}

export double sin_bass_sample_set_pitch(double filehandle, double amount) {
    BASS_SAMPLE info;
    BASS_sample_get_info((DWORD) filehandle, & info);

    info.freq = (DWORD) amount;
    return BASS_sample_set_info((DWORD) filehandle, & info);
}

export double sin_bass_sample_get_pitch(double filehandle) {
    BASS_SAMPLE info;
    if (BASS_sample_get_info((DWORD) filehandle, & info)) {
        return (double) info.freq;
    } else {
        return -1;
    }
}

export double sin_bass_sample_set_pan(double filehandle, double amount) {
    BASS_SAMPLE info;
    BASS_sample_get_info((DWORD) filehandle, & info);

    info.pan = (float) amount;
    return BASS_sample_set_info((DWORD) filehandle, & info);
}

export double sin_bass_sample_get_pan(double filehandle) {
    BASS_SAMPLE info;
    if (BASS_sample_get_info((DWORD) filehandle, & info)) {
        return (double) info.pan;
    } else {
        return -1;
    }

}