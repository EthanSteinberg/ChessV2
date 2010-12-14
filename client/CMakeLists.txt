#CMakeLists file for server

cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Debug)

set(LIBS  "-L/usr/local/lib -lclan22GL -lclan22Display -lpng -ljpeg -lfreetype -lz -lfontconfig -lX11 -lclan22Core -lclan22CSSLayout -lpthread")
#set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -Wshadow")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -march=native -std=c++0x  ${LIBS}")

set(HDRS 
      )
 
set(SRCS
      src/main.cpp
)


add_executable(ChessClient ${HDRS} ${SRCS})
target_link_libraries(ChessClient ChessCli ChessGui)


add_subdirectory(src)
