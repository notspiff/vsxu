/**
* Project: VSXu: Realtime modular visual programming engine.
*
* This file is part of Vovoid VSXu.
*
* @author Jonatan Wallmander, Robert Wenzel, Vovoid Media Technologies AB Copyright (C) 2003-2013
* @see The GNU Lesser General Public License (LGPL)
*
* VSXu Engine is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*
* You should have received a copy of the GNU Lesser General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/


#include "_configuration.h"
#include "vsx_param.h"
#include "vsx_module.h"

#include "module_render_basic_colored_rectangle.h"
#include "module_render_line.h"
#include "module_render_basic_textured_rectangle.h"
#include "module_render_basic_oscilloscope.h"
#include "module_render_basic_simple_colorline.h"


//******************************************************************************
//*** F A C T O R Y ************************************************************
//******************************************************************************

#ifndef _WIN32
#define __declspec(a)
#endif

extern "C" {
__declspec(dllexport) vsx_module* create_new_module(unsigned long module, void* args);
__declspec(dllexport) void destroy_module(vsx_module* m,unsigned long module);
__declspec(dllexport) unsigned long get_num_modules(vsx_engine_environment* environment);
}


vsx_module* MOD_CM(unsigned long module, void* args)
{
  VSX_UNUSED(args);
  switch (module) {
    case 0: return (vsx_module*)new module_render_basic_textured_rectangle;
    case 1: return (vsx_module*)new module_render_basic_colored_rectangle;
    case 2: return (vsx_module*)new module_render_line;
    case 3: return (vsx_module*)new module_render_basic_oscilloscope;
    case 4: return (vsx_module*)new module_render_basic_simple_colorline;
  } // switch
  return 0;
}


void MOD_DM(vsx_module* m,unsigned long module) {
  switch(module) {
    case 0: delete (module_render_basic_textured_rectangle*)m; break;
    case 1: delete (module_render_basic_colored_rectangle*)m; break;
    case 2: delete (module_render_line*)m; break;
    case 3: delete (module_render_basic_oscilloscope*)m; break;
    case 4: delete (module_render_basic_simple_colorline*)m; break;
  }
}


unsigned long MOD_NM(vsx_engine_environment* environment) {
  VSX_UNUSED(environment);
  return 5;
}  

