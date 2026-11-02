// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#include <libxi/xi.hxx>

#include <format>    // format()
#include <stdexcept> // runtime_error

#ifdef _WIN32
#  include <libminhook/minhook.h>

#  include <libxi/win32/process-threads-api.hxx>
#endif

#include <libxi/version.hxx>

using namespace std;

namespace xi
{
  const char*
  version () noexcept
  {
    return LIBXI_VERSION_FULL;
  }

  int
  main (int, char*[])
  {
#ifdef _WIN32
    // Initialize MinHook before anything gets a chance to create a hook.
    //
    if (mh_status s = mh_initialize (); s != MH_OK)
      throw runtime_error (format ("unable to initialize minhook: {}",
                                   mh_status_to_string (s)));

    // Hook the ExitProcess() that kernel32 exports, so that every call
    // reaches the detour, whichever import or address it goes through.
    //
    {
      void* d (reinterpret_cast<void*> (&exit_process));
      void* t (nullptr);

      mh_status s (mh_create_hook_api_ex (L"kernel32", "ExitProcess",
                                          d, exit_process_trampoline (), &t));

      if (s == MH_OK)
        s = mh_enable_hook (t);

      if (s != MH_OK)
        throw runtime_error (format ("unable to hook ExitProcess: {}",
                                     mh_status_to_string (s)));
    }
#endif

    return 0;
  }
}
