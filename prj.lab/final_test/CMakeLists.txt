add_library(IContainerBase2 final_test.cpp IContainerBase2.hpp )
set_property(TARGET IContainerBase2 PROPERTY CXX_STANDARD 20)
target_include_directories(IContainerBase2 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS IContainerBase2)
