file(GLOB HEADERS "include/delta/private_message/*.hpp")

add_library( delta_private_message
             private_message_plugin.cpp
           )

target_link_libraries( delta_private_message delta_chain delta_protocol delta_app )
target_include_directories( delta_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   delta_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
