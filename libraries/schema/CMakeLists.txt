file(GLOB HEADERS "include/delta/schema/*.hpp")
add_library( delta_schema schema.cpp ${HEADERS} )
target_link_libraries( delta_schema fc )
target_include_directories( delta_schema PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   delta_schema

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/delta/schema" )
