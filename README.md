# TopologyAPI_task02

## Overview
API to read a json file, parse it and represent it in classes

## Features
- Support add/remove topology operations.
- Support query devices using netlist node ID.
- Implemented in C++.
- Use CMake build tool.

## Documentation
[TopologyAPI Documentation] is generated using [Doxygen].

## General Info.
- C++ language.
- [jsoncpp library]
- [Google-Test]
- [CMake]
- [Cppcheck]

## Why C++ ?
- The main advantage in my opinion is that C++, compared to other object-oriented languages, is faster.
- C++ is pretty much compatible with C.
- Scalability refers to the ability of a program to scale. It means that the C++ program is capable of running on a small scale as well as a large scale of data.
- C++ gives the programmer the provision of total control over memory management.(eg. comparing with Java)
- Since C++ is closely associated with C, C++ allows low-level manipulation of data at a certain level.
- In some cases other languages that run on a run-time environment - that can be considered as portable languages - may be non-portable.

## Build
Build process is done using CMake build tool.
See log files: [Build Log], [Build Errors].
![build screenshot](https://github.com/mohammed0x00/TopologyAPI_task02/blob/main/screenshots/build.png)
See [CMakeLists.txt].

## Test
Test process is done using Google-Test library.
See log files: [Test Log], [Test Errors].
> Currently, only API tests are available. Other units will be tested soon.

![test screenshot](https://github.com/mohammed0x00/TopologyAPI_task02/blob/main/screenshots/test.png)

## Code analysis
Code analysis process is done using Cppcheck tool.
See log files: [Analysis Log], [Analysis Errors].
![analusis screenshot](https://github.com/mohammed0x00/TopologyAPI_task02/blob/main/screenshots/analysis.png)

[jsoncpp library]: <https://github.com/open-source-parsers/jsoncpp>
[Google-Test]: <https://github.com/google/googletest>
[CMake]: <https://cmake.org/>
[TopologyAPI Documentation]: <https://mohammed0x00.github.io/TopologyAPI_task02/>
[Doxygen]: <https://www.doxygen.nl/>
[Build Log]:<https://github.com/mohammed0x00/TopologyAPI_task02/blob/main/log/build_log>
[Build Errors]:<https://github.com/mohammed0x00/TopologyAPI_task02/blob/main/log/build_errors>
[Test Log]:<https://github.com/mohammed0x00/TopologyAPI_task02/blob/main/log/test_log>
[Test Errors]:<https://github.com/mohammed0x00/TopologyAPI_task02/blob/main/log/test_errors>
[Analysis Log]:<https://github.com/mohammed0x00/TopologyAPI_task02/blob/main/log/analysis_log>
[Analysis Errors]:<https://github.com/mohammed0x00/TopologyAPI_task02/blob/main/log/analysis_errors>
[Cppcheck]:<https://cppcheck.sourceforge.io/>
[CMakeLists.txt]:<https://github.com/mohammed0x00/TopologyAPI_task02/blob/main/CMakeLists.txt>
