#!/bin/bash
cmake -S . -B build 1>log/build_log 2>log/build_errors
cmake --build build 1>>log/build_log 2>>log/build_errors
