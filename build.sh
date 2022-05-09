#!/bin/bash
cmake -S . -B build
cd build
cmake --build . && ./API_test
