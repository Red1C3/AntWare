#!/bin/bash

meson setup build
ninja -Cbuild && ./build/antware
