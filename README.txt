To build and run QTheoraFrontend on Ubuntu 9.04, execute the following commands:

$ sudo apt-get install build-essential libqt4-dev git-core ffmpeg2theora
$ git clone git://github.com/ossguy/qtheorafrontend.git
$ cd qtheorafrontend
$ ./autogen.sh
$ make
$ ./qtheorafrontend

These instructions should work with little or no modification on other Unix-like
systems. You can build QTheoraFrontend on Windows or Mac OS X by installing Qt
and ffmpeg2theora and then using the usual Qt build methods on those systems.

QTheoraFrontend currently expects the input video to be called "test.flv",
located in the current directly.  In the future, the user will be able to select
which file they wish to convert.

If having any questions about building or using QTheoraFrontend, please let me
know at denver@ossguy.com.

--
  Copyright (C) 2009  Denver Gingerich <denver@ossguy.com>

  Copying and distribution of this file, with or without modification,
  are permitted in any medium without royalty provided the copyright
  notice and this notice are preserved.
