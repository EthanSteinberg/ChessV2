#CMakeLists file for server

cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Debug)

set(LIBS  "-L/usr/local/lib -lclan22GL -lclan22Display -lpng -ljpeg -lfreetype -lz -lfontconfig -lX11 -lclan22Core -lclan22CSSLayout -lpthread")
#set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -Wshadow")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -march=native -std=c++0x  ${LIBS}")

set(HDRS 
      src/chessClientGui.h
      )
 
set(SRCS
      src/chessClientGui.cpp
      src/main.cpp
)


add_library(ChessCli STATIC src/chessClient.h src/chessClient.cpp)

add_library(ChessComponent STATIC src/chessComponent.h src/chessComponent.cpp)
target_link_libraries(ChessComponent ${ClanLib_LIBRARIES} ChessCli)


add_executable(ChessGui ${HDRS} ${SRCS})
target_link_libraries(ChessGui ${ClanLib_LIBRARIES} ChessComponent ChessCli)

