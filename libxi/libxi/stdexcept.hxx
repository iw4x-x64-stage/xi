// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#pragma once

#include <format>
#include <utility>   // forward()
#include <stdexcept>

#include <libxi/export.hxx>

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
  class LIBXI_SYMEXPORT logic_error: public std::logic_error
  {
  public:
    template <std::formattable<char>... A>
    explicit
    logic_error (std::format_string<A...> f, A&&... a)
      : std::logic_error (std::format (f, std::forward<A> (a)...)) {}

    virtual
    ~logic_error () override;
  };

  class LIBXI_SYMEXPORT invalid_argument: public std::invalid_argument
  {
  public:
    template <std::formattable<char>... A>
    explicit
    invalid_argument (std::format_string<A...> f, A&&... a)
      : std::invalid_argument (std::format (f, std::forward<A> (a)...)) {}

    virtual
    ~invalid_argument () override;
  };

  class LIBXI_SYMEXPORT domain_error: public std::domain_error
  {
  public:
    template <std::formattable<char>... A>
    explicit
    domain_error (std::format_string<A...> f, A&&... a)
      : std::domain_error (std::format (f, std::forward<A> (a)...)) {}

    virtual
    ~domain_error () override;
  };

  class LIBXI_SYMEXPORT length_error: public std::length_error
  {
  public:
    template <std::formattable<char>... A>
    explicit
    length_error (std::format_string<A...> f, A&&... a)
      : std::length_error (std::format (f, std::forward<A> (a)...)) {}

    virtual
    ~length_error () override;
  };

  class LIBXI_SYMEXPORT out_of_range: public std::out_of_range
  {
  public:
    template <std::formattable<char>... A>
    explicit
    out_of_range (std::format_string<A...> f, A&&... a)
      : std::out_of_range (std::format (f, std::forward<A> (a)...)) {}

    virtual
    ~out_of_range () override;
  };

  class LIBXI_SYMEXPORT runtime_error: public std::runtime_error
  {
  public:
    template <std::formattable<char>... A>
    explicit
    runtime_error (std::format_string<A...> f, A&&... a)
      : std::runtime_error (std::format (f, std::forward<A> (a)...)) {}

    virtual
    ~runtime_error () override;
  };

  class LIBXI_SYMEXPORT range_error: public std::range_error
  {
  public:
    template <std::formattable<char>... A>
    explicit
    range_error (std::format_string<A...> f, A&&... a)
      : std::range_error (std::format (f, std::forward<A> (a)...)) {}

    virtual
    ~range_error () override;
  };

  class LIBXI_SYMEXPORT overflow_error: public std::overflow_error
  {
  public:
    template <std::formattable<char>... A>
    explicit
    overflow_error (std::format_string<A...> f, A&&... a)
      : std::overflow_error (std::format (f, std::forward<A> (a)...)) {}

    virtual
    ~overflow_error () override;
  };

  class LIBXI_SYMEXPORT underflow_error: public std::underflow_error
  {
  public:
    template <std::formattable<char>... A>
    explicit
    underflow_error (std::format_string<A...> f, A&&... a)
      : std::underflow_error (std::format (f, std::forward<A> (a)...)) {}

    virtual
    ~underflow_error () override;
  };
}
