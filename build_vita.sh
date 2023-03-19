#!/bin/bash

mkdir builddir
cd builddir
cmake .. -DNOSOUND=ON
make -j4
cd ..
