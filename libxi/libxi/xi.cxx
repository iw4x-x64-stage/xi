// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#include <libxi/xi.hxx>

#include <libxi/version.hxx>

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
    return 0;
  }
}
