cmake_minimum_required(VERSION 3.12)
PROJECT(base LANGUAGES CXX)

AUX_SOURCE_DIRECTORY(./ SRC_LIST1)
AUX_SOURCE_DIRECTORY(./pb/protocol SRC_LIST2)

configure_file(version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/version.h @ONLY)

find_package(jsoncpp CONFIG REQUIRED)
get_target_property(jsoncpp_INCLUDE_DIR jsoncpp_lib INTERFACE_INCLUDE_DIRECTORIES)

add_library(base STATIC ${SRC_LIST1} ${SRC_LIST2})
target_compile_features(base PRIVATE cxx_std_11)
target_compile_definitions(base PRIVATE -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DAC_HAS_INFO
  -DAC_HAS_WARNING -DAC_HAS_ERROR -DAC_HAS_CRITICAL -DTIXML_USE_STL
  -DAC_HAS_DEBUG -DLINUX_DAEMON)
target_include_directories(base PRIVATE pb/protocol ${jsoncpp_INCLUDE_DIR} ${jsoncpp_INCLUDE_DIR}/jsoncpp)
