// Copyright (c) the IW4x authors (see the AUTHORS file).
// SPDX-License-Identifier: GPL-3.0-only WITH AdditionRef-IW4x-Exception-1.1

#include <print>
#include <iterator>    // end()
#include <concepts>    // derived_from
#include <algorithm>   // ranges::find()
#include <stdexcept>
#include <exception>
#include <string_view>

#include <libxi/stdexcept.hxx>

#undef NDEBUG
#include <cassert>

using namespace std;

namespace
{
  // Throw X with the type name and 42 formatted into its description,
  // catch it as its standard counterpart S, and print the description.
  //
  template <derived_from<exception> S, derived_from<S> X>
  void
  test (string_view n)
  {
    try
    {
      throw X ("{}: {}", n, 42);
    }
    catch (const S& e)
    {
      println ("{}", e.what ());
    }
  }

  struct test_entry
  {
    string_view name;
    void (*function) (string_view);
  };

  const test_entry tests[]
  {
    {"logic_error",      &test<logic_error,      xi::logic_error>},
    {"invalid_argument", &test<invalid_argument, xi::invalid_argument>},
    {"domain_error",     &test<domain_error,     xi::domain_error>},
    {"length_error",     &test<length_error,     xi::length_error>},
    {"out_of_range",     &test<out_of_range,     xi::out_of_range>},
    {"runtime_error",    &test<runtime_error,    xi::runtime_error>},
    {"range_error",      &test<range_error,      xi::range_error>},
    {"overflow_error",   &test<overflow_error,   xi::overflow_error>},
    {"underflow_error",  &test<underflow_error,  xi::underflow_error>}
  };
}

// Usage: argv[0] <type>
//
// Throw the xi exception type with the type name and 42 formatted into its
// description in the '{}: {}' form, catch it as the standard type that it
// derives from, and print the description to stdout.
//
int
main (int argc, char* argv[])
{
  assert (argc == 2);

  const string_view n (argv[1]);
  const auto i (ranges::find (tests, n, &test_entry::name));

  assert (i != end (tests));
  i->function (n);
}
