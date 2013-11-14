crt-detector
============

C++ library for detecting Visual C++ runtimes on Windows XP and later.

## Usage
crt-detector allows you to detect both the availability of Visual C++ runtimes installed onto the end-user's computer _and_ any VC++ runtimes that are available in the current working directory.

If you want to check for the availability of Visual C++ 2008 SP1 with an image compiled for x86, you can look for it globally first:

````
	//Is Visual C++ 2008 SP1 runtime for x86 installed?
	if(IsVC2008SP1Installed_x86()){ ... }
````

And then you can check for it in the current working directory if necessary:

````
	//Are the Visual C++ 2008 SP1 DLLs for x86 available in my current directory?
	if(IsVC2008AvailableLocally_x86()()){ ... }
````

That's all there is to it! Please view `VCDetector.h` to see the full set of available methods.

## Source Files
The only two files that you need to integrate this detection functionality into your apps are:

* __VCDetector.h__ and
* __VCDetector.cpp__.

It is worth noting, however, that `stdafx.h` contains the list of all of the Win32 API dependencies that this code takes.

## Linking Dependencies
In order to compile this project or any others that depend on you must link the add the following assemblies to the `Linker --> Additional Input`
options for all of your build configurations.

* __msi.lib__ used for querying the MsiProductAvailable APIs.
* __shlwapi.lib__ used for file path manipulation.
* __dbghelp.lib__ used for inspecting the images of locally-available DLLs.

## License
Licensed under Apache 2.0 - see the License file for details.

## Contributions
We accept pull requests - include descriptions of your changes and please follow our comment style inside `VCDetector.cpp`.

----
Copyright 2013-2014 [MarkedUp Inc][0].
Check out [MarkedUp Analytics for Windows Desktop Applications][1]!

 [0]: https://markedup.com/ "MarkedUp Analytics"
 [1]: https://markedup.com/ "MarkedUp Anayltics for Win32 Applications"