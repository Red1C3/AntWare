#!/bin/bash

meson setup builddir
ninja -Cbuilddir && ./builddir/antware
