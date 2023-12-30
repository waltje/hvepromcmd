

		High-Voltage EPROM Programmer/Reader

		    Command-Line Client Program


	       Matthew Millman <inaxeon@hotmail.com>
	      Fred N. van Kempen <waltje@varcem.com>


These are the (updated) sources for Matt's client program for his
very useful programmer/reader for old, high-voltage EPROM devices
such as the 1702A, 2708 and MCS-48 series, and derivatives.


LICENSE

This program is open-source software, issued under the GNU Public
License, version 2.0 or higher.  See COPYING.txt for more details.


BUILDING

To build for Windows:

  1.  For Visual Studio, go to the "plat/win" directory and open
      the HvEpromCmd.sln solution file. Select the proper platform
      and configuration, and build the project. Note that x86 and
      x64 platforms are supported, as well as ARM (Windows 8.x,
      Windows RT) and ARM64 (Windows 10, Windows 11.)

  2.  For users of MinGW(-w64), open a command prompt for that
      toolset, and build the program with

	make -f plat/win/makefile.mingw [ARCH=xxx]

      where 'xxx' is the desired platform; either x86 or x64 at
      the time of this writing.  It defaults to x86.

  3.  For users of the TinyC compiler (which is really useful!),
      open a command prompt for that compiler, and build with

	make -f plat/win/makefile.tcc [ARCH=xxx]

      where 'xxx' is the desired platform; either x86 or x64 at
      the time of this writing.  It defaults to x86.


To build for Linux and similar *x-based systems with GCC:

  make -f plat/unix/makefile.gcc [ARCH=xxx]

where 'xxx' is the desired platform; either x86 or x64 at
the time of this writing.  It defaults to x64.


To build for macOS (version 11 and up) with the Xcode development system:

  make -f plat/mac/makefile.mac [ARCH=xxx]

where 'xxx' is the desired platform; either x64 or arm at
the time of this writing.  It defaults to x64.


VERSION

Since the original files were not versioned at all, numbering was
started at 2.0 for this derived work.


Last Updated: December 2023
Fred N. van Kempen, <waltje@varcem.com>
