#CMakeLists file for server

cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Debug)

#set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -Wshadow")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -march=native -O2 -L/usr/local/lib -lclan22GL -lclan22Display -lpng -ljpeg -lfreetype -lz -lfontconfig -lX11 -lclan22Core -lclan22CSSLayout -lpthread")

set(HDRS 
      )
 
set(SRCS
      main.cpp
)

add_executable(App ${HDRS} ${SRCS})
target_link_libraries(App ${ClanLib_LIBRARIES})

