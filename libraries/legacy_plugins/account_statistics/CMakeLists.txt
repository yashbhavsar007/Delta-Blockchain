file(GLOB HEADERS "include/delta/account_statistics/*.hpp")

add_library( delta_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( delta_account_statistics delta_chain delta_protocol delta_app )
target_include_directories( delta_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   delta_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)