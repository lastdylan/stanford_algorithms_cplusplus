cmake_minimum_required(VERSION 3.12.3)
project(cpp_algos)

set(MAINFOLDER ${PROJECT_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH "${MAINFOLDER}/bin")
set (LIBRARY_OUTPUT_PATH "${MAINFOLDER}/lib")
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

file(GLOB LIB_SOURCES "src/*.cpp")
file(GLOB LIB_HEADERS "include/*.hpp")
file(GLOB APP_SOURCES src/*.cxx)
file(GLOB APP_HEADERS include/*.h)

add_library(algoscpp ${LIB_SOURCES} ${LIB_HEADERS})

foreach( sourcefile ${APP_SOURCES} )
    get_filename_component(appname ${sourcefile} NAME_WE)
    add_executable(${appname} ${sourcefile} ${APP_HEADERS})
    target_link_libraries( ${appname} algoscpp )
endforeach( sourcefile ${APP_SOURCES} )
