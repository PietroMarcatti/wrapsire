cmake_minimum_required(VERSION 3.0.0)
project(engine++ VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "-no-pie")

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/src
    
    ${PROJECT_SOURCE_DIR}/include/src/gen1
    ${PROJECT_SOURCE_DIR}/include/src/gen1/data
    ${PROJECT_SOURCE_DIR}/include/src/gen1/samples
)

add_library(engine-wrapper INTERFACE)
target_include_directories(engine-wrapper INTERFACE include)

set(WRAPSIRE_SOURCES
    examples/basicuse.cpp
)

add_executable(basicuse ${WRAPSIRE_SOURCES})
target_link_libraries(basicuse INTERFACE engine-wrapper PUBLIC ${PROJECT_SOURCE_DIR}/lib/pkmn.lib)

add_executable(randomagent examples/randomagent.cpp)
target_link_libraries(randomagent INTERFACE engine-wrapper PUBLIC ${PROJECT_SOURCE_DIR}/lib/pkmn.lib)

# TEST

set(TEST_SOURCES
    tests/test.cpp
)

INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}/tests
)

add_executable(engine-test ${TEST_SOURCES})

target_link_libraries(engine-test 
    PUBLIC ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} 
    INTERFACE engine-wrapper 
    PUBLIC ${PROJECT_SOURCE_DIR}/lib/pkmn.lib
)