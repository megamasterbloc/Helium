/*
 * This file is part of the micropython-ulab project,
 *
 * https://github.com/v923z/micropython-ulab
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019-2021 Zoltán Vörös
 *               2020 Scott Shawcroft for Adafruit Industries
 *               2020 Taku Fukada
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <py/runtime.h>
#include <py/builtin.h>
#include <py/binary.h>
#include <py/obj.h>
#include <py/objarray.h>

#include "fft.h"

//| """Frequency-domain functions"""
//|


//| def fft(r: ulab.ndarray, c: Optional[ulab.ndarray] = None) -> Tuple[ulab.ndarray, ulab.ndarray]:
//|     """
//|     :param ulab.ndarray r: A 1-dimension array of values whose size is a power of 2
//|     :param ulab.ndarray c: An optional 1-dimension array of values whose size is a power of 2, giving the complex part of the value
//|     :return tuple (r, c): The real and complex parts of the FFT
//|
//|     Perform a Fast Fourier Transform from the time domain into the frequency domain
//|
//|     See also ~ulab.extras.spectrum, which computes the magnitude of the fft,
//|     rather than separately returning its real and imaginary parts."""
//|     ...
//|
static mp_obj_t fft_fft(size_t n_args, const mp_obj_t *args) {
    if(n_args == 2) {
        return fft_fft_ifft_spectrogram(n_args, args[0], args[1], FFT_FFT);
    } else {
        return fft_fft_ifft_spectrogram(n_args, args[0], mp_const_none, FFT_FFT);
    }
}

MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(fft_fft_obj, 1, 2, fft_fft);

//| def ifft(r: ulab.ndarray, c: Optional[ulab.ndarray] = None) -> Tuple[ulab.ndarray, ulab.ndarray]:
//|     """
//|     :param ulab.ndarray r: A 1-dimension array of values whose size is a power of 2
//|     :param ulab.ndarray c: An optional 1-dimension array of values whose size is a power of 2, giving the complex part of the value
//|     :return tuple (r, c): The real and complex parts of the inverse FFT
//|
//|     Perform an Inverse Fast Fourier Transform from the frequeny domain into the time domain"""
//|     ...
//|

static mp_obj_t fft_ifft(size_t n_args, const mp_obj_t *args) {
    if(n_args == 2) {
        return fft_fft_ifft_spectrogram(n_args, args[0], args[1], FFT_IFFT);
    } else {
        return fft_fft_ifft_spectrogram(n_args, args[0], mp_const_none, FFT_IFFT);
    }
}

MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(fft_ifft_obj, 1, 2, fft_ifft);

STATIC const mp_rom_map_elem_t ulab_fft_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_fft) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_fft), (mp_obj_t)&fft_fft_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_ifft), (mp_obj_t)&fft_ifft_obj },
};

STATIC MP_DEFINE_CONST_DICT(mp_module_ulab_fft_globals, ulab_fft_globals_table);

mp_obj_module_t ulab_fft_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_ulab_fft_globals,
};
