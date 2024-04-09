add_library(DoubleListQueue DoubleListQueue.cpp DoubleListQueue.hpp )
set_property(TARGET DoubleListQueue PROPERTY CXX_STANDARD 20)
target_include_directories(DoubleListQueue PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS DoubleListQueue)
