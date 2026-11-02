// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#pragma once

#if defined(LIBXI_STATIC)
#  define LIBXI_SYMEXPORT
#elif defined(LIBXI_STATIC_BUILD)
#  define LIBXI_SYMEXPORT
#elif defined(LIBXI_SHARED)
#  ifdef _WIN32
#    define LIBXI_SYMEXPORT __declspec (dllimport)
#  else
#    define LIBXI_SYMEXPORT
#  endif
#elif defined(LIBXI_SHARED_BUILD)
#  ifdef _WIN32
#    define LIBXI_SYMEXPORT __declspec (dllexport)
#  else
#    define LIBXI_SYMEXPORT
#  endif
#else
// If none of the above macros are defined, then we assume we are being used
// by some third-party build system that cannot/doesn't signal the library
// type being linked.
//
#  error define LIBXI_STATIC or LIBXI_SHARED preprocessor macro to signal libxi library type being linked
#endif
