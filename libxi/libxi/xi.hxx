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
}
