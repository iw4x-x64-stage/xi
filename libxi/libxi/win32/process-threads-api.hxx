// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#pragma once

// Include <windows.h> without the parts we don't need and without the min
// and max macros, restoring both settings to what they were.
//
#ifndef WIN32_LEAN_AND_MEAN
#  define WIN32_LEAN_AND_MEAN
#  ifndef NOMINMAX
#    define NOMINMAX
#    include <windows.h>
#    undef NOMINMAX
#  else
#    include <windows.h>
#  endif
#  undef WIN32_LEAN_AND_MEAN
#else
#  ifndef NOMINMAX
#    define NOMINMAX
#    include <windows.h>
#    undef NOMINMAX
#  else
#    include <windows.h>
#  endif
#endif

// Hooks of the functions that <processthreadsapi.h> declares.
//
namespace xi
{
  // The ExitProcess() detour. Call the original ExitProcess() through the
  // trampoline.
  //
  void WINAPI
  exit_process (UINT code);

  // Return the location where MinHook stores the ExitProcess() trampoline
  // when it creates the hook.
  //
  void**
  exit_process_trampoline () noexcept;
}
