// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#include <libxi/xi.hxx>

#include <print>
#include <iostream> // cerr

#ifdef _WIN32
#  include <libminhook/minhook.h>
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
    {
      println (cerr,
               "error: unable to initialize minhook: {}",
               mh_status_to_string (s));
      return 1;
    }
#endif

    return 0;
  }
}
