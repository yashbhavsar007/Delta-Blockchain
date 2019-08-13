file(GLOB HEADERS "include/delta/plugins/auth_util/*.hpp")

add_library( delta_auth_util
             ${HEADERS}
             auth_util_plugin.cpp
             auth_util_api.cpp
           )

target_link_libraries( delta_auth_util delta_app delta_chain delta_protocol fc )
target_include_directories( delta_auth_util
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
