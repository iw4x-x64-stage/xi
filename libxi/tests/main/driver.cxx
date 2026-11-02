// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#include <libxi/xi.hxx>

// Usage: argv[0] [<argument>...]
//
// Run xi::main() with the driver's command line and exit with its status.
//
int
main (int argc, char* argv[])
{
  return xi::main (argc, argv);
}
