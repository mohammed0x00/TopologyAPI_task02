cmake_minimum_required(VERSION 3.14)
project(TopologyAPI)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/4348d4efedad427b5232cafb618a93deeea15044.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set ( PROJECT_LINK_LIBS ${CMAKE_CURRENT_BINARY_DIR}/src/libTopologyAPI.a )

add_subdirectory(src)

enable_testing()

include_directories(src/include)

add_executable(Device_test test/Device_test.cpp)
add_executable(Resistor_test test/Resistor_test.cpp)
add_executable(Nmos_test test/Nmos_test.cpp)
add_executable(Topology_test test/Topology_test.cpp)
add_executable(API_test test/API_test.cpp)



add_dependencies(Device_test TopologyAPI)
add_dependencies(Resistor_test TopologyAPI)
add_dependencies(Nmos_test TopologyAPI)
add_dependencies(Topology_test TopologyAPI)
add_dependencies(API_test TopologyAPI)


target_link_libraries(
  Device_test
  gtest_main
)

target_link_libraries(
  Resistor_test
  gtest_main
)

target_link_libraries(
  Nmos_test
  gtest_main
)

target_link_libraries(
  Topology_test
  gtest_main
)

target_link_libraries(
  API_test
  gtest_main
  ${PROJECT_LINK_LIBS}
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test/InitializeTestFile.json
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test/compareTestFile.json
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

include(GoogleTest)
gtest_discover_tests(Device_test Resistor_test Nmos_test Topology_test API_test)
