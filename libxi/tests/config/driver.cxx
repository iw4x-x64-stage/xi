// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#include <print>

#include <libxi/config.hxx>

using namespace std;

// Usage: argv[0]
//
// Print the configuration to stdout, one value per line in the
// <name>: <value> form.
//
int
main ()
{
  println ("windows: {}", xi::windows);
}
