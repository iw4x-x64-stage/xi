// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#include <print>
#include <iostream>  // cerr
#include <stdexcept> // runtime_error

#include <libxi/xi.hxx>

using namespace std;

// Usage: argv[0] [<argument>...]
//
// Run xi::main() with the driver's command line and exit with its status.
// If it throws, then print the error to stderr and exit with status 1.
//
int
main (int argc, char* argv[])
{
  try
  {
    return xi::main (argc, argv);
  }
  catch (const runtime_error& e)
  {
    println (cerr, "error: {}", e.what ());
    return 1;
  }
}
