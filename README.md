crt-detector
============

C++ library for detecting Visual C++ runtimes on Windows XP and later.

## Source Files
The only two files that you need to integrate this detection functionality into your apps are:

* __VCDetector.h__ and
* __VCDetector.cpp__.

It is worth noting, however, that `stdafx.h` contains the list of all of the Win32 API dependencies that this code takes.

## Linking Dependencies
In order to compile this project or any others that depend on you must link the add the following two assemblies to the `Linker --> Additional Input`
options for all of your build configurations.

* __msi.lib__
* __shlwapi.lib__

## License
Licensed under Apache 2.0 - see the License file for details.

## Contributions
We accept pull requests - include descriptions of your changes and please follow our comment style inside `VCDetector.cpp`.

Copyright 2013-2014 MarkedUp Inc.
