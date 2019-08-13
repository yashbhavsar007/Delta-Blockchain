file(GLOB HEADERS "include/delta/plugins/block_info/*.hpp")

add_library( delta_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( delta_block_info delta_app delta_chain delta_protocol fc )
target_include_directories( delta_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
