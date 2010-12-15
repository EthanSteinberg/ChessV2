#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      src/main.cpp
)


add_executable(Test ${HDRS} ${SRCS})
target_link_libraries(Test Pantheios)

