file(GLOB HEADERS "include/delta/plugins/account_history_rocksdb/*.hpp")

add_library( account_history_rocksdb_plugin
             account_history_rocksdb_plugin.cpp
           )

target_link_libraries( account_history_rocksdb_plugin
   chain_plugin delta_chain delta_protocol json_rpc_plugin rocksdb
   )

target_include_directories( account_history_rocksdb_plugin
   PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/rocksdb/include"
   )

install( TARGETS
   account_history_rocksdb_plugin

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
