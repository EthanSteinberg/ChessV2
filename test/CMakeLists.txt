#CMakeLists file for server

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -march=native -std=c++0x")
set(HDRS 
      )
 
set(SRCS
      main.cpp
)

add_executable(Test ${HDRS} ${SRCS})
target_link_libraries(Test ${PANTHEIOS_LIBRARIES})

