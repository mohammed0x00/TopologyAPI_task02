#!/bin/bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON build
cppcheck --project=build/compile_commands.json -ifoo 1>log/analysis_log 2>log/analysis_errors
