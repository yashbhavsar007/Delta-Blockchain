file(GLOB HEADERS "include/delta/delayed_node/*.hpp")

add_library( delta_delayed_node
             delayed_node_plugin.cpp
           )

target_link_libraries( delta_delayed_node delta_chain delta_protocol delta_app )
target_include_directories( delta_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   delta_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
