add_library(iStack iStack.cpp iStackBase.hpp )
set_property(TARGET iStack PROPERTY CXX_STANDARD 20)
target_include_directories(iStack PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS iStack)
