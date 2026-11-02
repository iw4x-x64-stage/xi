// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#include <libxi/win32/process-threads-api.hxx>

namespace xi
{
  namespace
  {
    void (WINAPI* exit_process_original) (UINT) (nullptr);
  }

  void WINAPI
  exit_process (UINT code)
  {
    exit_process_original (code);
  }

  void**
  exit_process_trampoline () noexcept
  {
    return reinterpret_cast<void**> (&exit_process_original);
  }
}
