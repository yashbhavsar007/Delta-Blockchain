file(GLOB HEADERS "include/delta/plugins/raw_block/*.hpp")

add_library( delta_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( delta_raw_block delta_app delta_chain delta_protocol fc )
target_include_directories( delta_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
