/*
 * Copyright (C) 2007 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * Modified by Joakim Plate <elupus@ecce.se>  to be stand alone from libavutil
 */

#ifndef HTS_SHA1_H
#define HTS_SHA1_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

extern const int hts_sha1_size;

struct HTSSHA1;

void hts_sha1_init(struct HTSSHA1* context);
void hts_sha1_update(struct HTSSHA1* context, const uint8_t* data, unsigned int len);
void hts_sha1_final(struct HTSSHA1* context, uint8_t digest[20]);

#ifdef __cplusplus
}
#endif

#endif /* HTS_SHA1_H */
