#!/bin/bash

set -e

VERSION=2.6.3

wget -O gperftools-"$VERSION".tar.gz https://github.com/gperftools/gperftools/releases/download/gperftools-"$VERSION"/gperftools-"$VERSION".tar.gz
tar xf gperftools-"$VERSION".tar.gz
cd gperftools-"$VERSION"

wget -O a.patch https://raw.githubusercontent.com/leoh0/pt/master/a.patch
patch -p0 < a.patch

LDFLAGS="-lpthread" ./configure --prefix="$THIRDPARTY_BUILD" --enable-shared=no --enable-frame-pointers --disable-libunwind
make V=1 install
