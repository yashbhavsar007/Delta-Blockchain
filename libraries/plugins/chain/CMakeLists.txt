file(GLOB HEADERS "include/delta/chain_plugin/*.hpp")
add_library( chain_plugin
             chain_plugin.cpp
             ${HEADERS} )

target_link_libraries( chain_plugin delta_chain appbase delta_utilities statsd_plugin )
target_include_directories( chain_plugin PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if( CLANG_TIDY_EXE )
   set_target_properties(
      chain_plugin PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
   )
endif( CLANG_TIDY_EXE )

install( TARGETS
   chain_plugin

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/delta/chain_plugin" )
