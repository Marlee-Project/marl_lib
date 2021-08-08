cmake_minimum_required(VERSION 3.17)
project(marl_lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(MARL_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(MARL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

find_package(SDL2 QUIET)
# find_package(SDL2_ttf)
message(STATUS ${SDL2_VERSION})
IF(${SDL2_FOUND})
  message(STATUS "FOUND SDL")
  message(STATUS "DIR: " ${SDL2_LIBRARIES})
  message(STATUS "INCLUDE: " ${SDL2_INCLUDE_DIRS})
  # include_directories(${SDL2_INCLUDE_DIRS})
  # link_libraries(${SDL2_LIBRARIES})
	link_libraries(SDL2::SDL2 SDL2_ttf SDL2_image)
else()
  message(STATUS "Did not find SDL2")
  message(STATUS "Please install it, or wait until this process automation is implemented")
  message(SEND_ERROR "DID NOT FIND SDL2")
ENDIF()
include_directories( 
  ${MARL_SRC_DIR}
  ${MARL_INCLUDE_DIR}
)

add_subdirectory(sandbox)

SET(MARL_LIB_FILES ${MARL_INCLUDE_DIR}/marl_lib.h ${MARL_INCLUDE_DIR}/marl_window.h ${MARL_SRC_DIR}/visual/marl_window.c ${MARL_INCLUDE_DIR}/marl_list.h ${MARL_SRC_DIR}/util/marl_list.c ${MARL_INCLUDE_DIR}/marl_string.h ${MARL_SRC_DIR}/util/marl_string.c ${MARL_INCLUDE_DIR}/marl_sdl.h ${MARL_INCLUDE_DIR}/marl_terminal.h ${MARL_SRC_DIR}/util/marl_terminal.c)
add_library(marl_lib ${MARL_LIB_FILES})
