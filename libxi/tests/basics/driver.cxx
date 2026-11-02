// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#include <cstring> // strcmp()

#include <libxi/xi.hxx>
#include <libxi/version.hxx>

#undef NDEBUG
#include <cassert>

using namespace std;

// Usage: argv[0]
//
// Make sure the library links and that its binary matches the headers we
// were built with.
//
int
main ()
{
  assert (strcmp (xi::version (), LIBXI_VERSION_FULL) == 0);
}
