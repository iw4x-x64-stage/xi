// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#include <libxi/stdexcept.hxx>

namespace xi
{
  // The destructors are defined here, so that each vtable is emitted in this
  // translation unit only (which matters for the DLL export).
  //
  logic_error::
  ~logic_error ()
  {
  }

  invalid_argument::
  ~invalid_argument ()
  {
  }

  domain_error::
  ~domain_error ()
  {
  }

  length_error::
  ~length_error ()
  {
  }

  out_of_range::
  ~out_of_range ()
  {
  }

  runtime_error::
  ~runtime_error ()
  {
  }

  range_error::
  ~range_error ()
  {
  }

  overflow_error::
  ~overflow_error ()
  {
  }

  underflow_error::
  ~underflow_error ()
  {
  }
}
