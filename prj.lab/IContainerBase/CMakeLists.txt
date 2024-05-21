add_library(IContainerBase final_test.cpp IContainerBase.hpp )
set_property(TARGET IContainerBase PROPERTY CXX_STANDARD 20)
target_include_directories(IContainerBase PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS IContainerBase)
