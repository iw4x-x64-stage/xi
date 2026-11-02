// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#include <string>

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

#include <libminhook/minhook.h>

#include <libxi/xi.hxx>

#undef NDEBUG
#include <cassert>

using namespace std;

// Usage: argv[0] <code>
//
// Run xi::main(), make sure it hooked ExitProcess(), and end the process
// with ExitProcess (<code>).
//
int
main (int argc, char* argv[])
{
  assert (argc == 2);
  assert (xi::main (argc, argv) == 0);

  // Enabling the hook of the function that kernel32 exports fails if it
  // is already enabled.
  //
  const FARPROC f (GetProcAddress (GetModuleHandleW (L"kernel32"),
                                   "ExitProcess"));

  assert (f != nullptr);
  assert (mh_enable_hook (reinterpret_cast<void*> (f)) == MH_ERROR_ENABLED);

  ExitProcess (static_cast<UINT> (stoul (argv[1])));
}
