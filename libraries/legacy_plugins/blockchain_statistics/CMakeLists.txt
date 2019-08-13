file(GLOB HEADERS "include/delta/blockchain_statistics/*.hpp")

add_library( delta_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( delta_blockchain_statistics delta_chain delta_protocol delta_app )
target_include_directories( delta_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   delta_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)