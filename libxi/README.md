# libxi - Internal foundation library for IW4x projects.

The `libxi` library is the foundation that the IW4x projects build on. It
holds the facilities these projects share, so that each one is written and
tested once.

## Usage

To start using `libxi` in your project, add the following `depends` value to
your `manifest`, adjusting the version constraint as appropriate:

```
depends: libxi ^0.1.0
```

Then import the library in your `buildfile`:

```
import libs = libxi%lib{xi}
```
