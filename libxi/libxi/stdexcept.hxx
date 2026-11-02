// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#pragma once

#include <format>
#include <utility>   // forward()
#include <concepts>  // derived_from
#include <exception>
#include <stdexcept>

// The standard exception types (see <stdexcept>) with constructors that
// take the description as a format string and its arguments, for example:
//
// throw invalid_argument ("invalid port {}", p);
//
// Each type derives from its standard counterpart, so it is caught as such.
// Note that the description is a format string, so to pass one that is
// computed at run time, use "{}" with the description as its argument.
//
namespace xi
{
  template <std::derived_from<std::exception> E>
  class basic_error: public E
  {
  public:
    template <std::formattable<char>... A>
    explicit
    basic_error (std::format_string<A...> f, A&&... a)
      : E (std::format (f, std::forward<A> (a)...)) {}
  };

  using logic_error      = basic_error<std::logic_error>;
  using invalid_argument = basic_error<std::invalid_argument>;
  using domain_error     = basic_error<std::domain_error>;
  using length_error     = basic_error<std::length_error>;
  using out_of_range     = basic_error<std::out_of_range>;
  using runtime_error    = basic_error<std::runtime_error>;
  using range_error      = basic_error<std::range_error>;
  using overflow_error   = basic_error<std::overflow_error>;
  using underflow_error  = basic_error<std::underflow_error>;
}
