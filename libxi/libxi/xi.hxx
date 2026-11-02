// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#pragma once

#include <libxi/export.hxx>

namespace xi
{
  // Return the version of the library binary, that is, the value of
  // LIBXI_VERSION_FULL when the library was built.
  //
  // Note that the caller sees LIBXI_VERSION_FULL as it was when the caller
  // was built, so comparing the two detects a library binary from another
  // build of the package.
  //
  LIBXI_SYMEXPORT const char*
  version () noexcept;

  // Run the program with the command line arguments as passed to the C++
  // main() function and return its exit status.
  //
  // Throw std::runtime_error if unable to set up the process, for example,
  // to hook one of its functions.
  //
  LIBXI_SYMEXPORT int
  main (int argc, char* argv[]);
}
