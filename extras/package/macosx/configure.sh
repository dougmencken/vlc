#!/bin/sh

CFLAGS=${CFLAGS}
LDFLAGS=${LDFLAGS}

case "${ARCH}" in
    ppc*)
        CFLAGS="${CFLAGS} -m32"
        LDFLAGS="${LDFLAGS} -m32"
        ;;
    x86_64*)
        CFLAGS="${CFLAGS} -m64 -march=core2 -mtune=core2"
        LDFLAGS="${LDFLAGS} -m64"
        ;;
    *x86*)
        CFLAGS="${CFLAGS} -m32 -march=prescott -mtune=generic"
        LDFLAGS="${LDFLAGS} -m32"
        ;;
esac

##--enable-macosx
##--enable-minimal-macosx
OPTIONS="
        --prefix=`pwd`/vlc_install_dir
        --disable-macosx
        --enable-qt
        --enable-merge-ffmpeg
        --enable-osx-notifications
        --enable-faad
        --enable-flac
        --enable-theora
        --enable-shout
        --enable-ncurses
        --enable-twolame
        --enable-realrtsp
        --enable-libass
        --enable-macosx-eyetv
        --enable-macosx-qtkit
        --enable-macosx-avfoundation
        --disable-skins2
        --disable-xcb
        --disable-caca
        --disable-sdl
        --disable-macosx-dialog-provider
        --with-macosx-version-min=10.5
"

export CFLAGS
export LDFLAGS

sh "$(dirname $0)"/../../../configure ${OPTIONS} $*
