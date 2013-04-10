/**
* Project: VSXu: Realtime visual programming language, music/audio visualizer, animation tool and much much more.
*
* @author Jonatan Wallmander, Vovoid Media Technologies AB Copyright (C) 2012
* @see The GNU Public License (GPL)
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef VSX_MODULE_PLUGIN_INFO_H_
#define VSX_MODULE_PLUGIN_INFO_H_

#include <vsx_platform.h>

typedef struct {
  vsx_dynamic_object_handle plugin_handle;
  int module_id;
  bool hidden_from_gui;
  vsx_module_info* module_info;

  // cached function to module's constructor/destructor
  vsx_module*(*create_new_module)( unsigned long, void* );
  void(*destroy_module)( vsx_module*, unsigned long );
} vsx_module_plugin_info;

#endif /*VSX_MODULE_PLUGIN_INFO_H_*/