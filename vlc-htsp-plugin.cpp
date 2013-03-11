/*****************************************************************************
 * Copyright (C) 2012
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include <vlc_common.h>
#include <vlc_plugin.h>
#include <vlc_demux.h>
#include <vlc_access.h>
#include <vlc_services_discovery.h>

#include "discovery.h"
#include "access.h"
#include "helper.h"

VLC_SD_PROBE_HELPER( "htsp", "Tvheadend HTSP", SD_CAT_LAN )

vlc_module_begin ()
    set_shortname( "HTSP Protocol" )
    set_description( "TVHeadend HTSP Protocol" )
    set_capability( "access_demux", 0 )
    set_category( CAT_INPUT )
    set_subcategory( SUBCAT_INPUT_ACCESS )
    set_callbacks( OpenHTSP, CloseHTSP )
    add_shortcut( "hts", "htsp" )

    add_submodule()
    set_shortname( "HTSP Protocol Discovery" )
    set_description( "TVHeadend HTSP Protocol Discovery" )
    set_category( CAT_PLAYLIST )
    set_subcategory ( SUBCAT_PLAYLIST_SD )
    add_integer_with_range( CFG_PREFIX"port", 9982, 1, 65536, "HTSP Server Port", "The port of the HTSP server to connect to", false )
    add_string( CFG_PREFIX"host", "localhost", "HTSP Server Address", "The IP/Hostname of the HTSP server to connect to", false )
    add_string( CFG_PREFIX"user", "", "HTSP Username", "The username for authentication with HTSP Server", false )
    add_password( CFG_PREFIX"pass", "", "HTSP Password", "The password for authentication with HTSP Server", false )
    set_capability ( "services_discovery", 0 )
    set_callbacks ( OpenSD, CloseSD )
    add_shortcut( "hts", "htsp" )

    VLC_SD_PROBE_SUBMODULE
vlc_module_end ()

const char *const cfg_options[] =
{
    "port",
    "host",
    "user",
    "pass",
    NULL
};
