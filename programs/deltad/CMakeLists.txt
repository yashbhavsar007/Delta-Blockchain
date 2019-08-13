add_executable( deltad main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling deltad with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( DELTA_STATIC_BUILD )
   target_link_libraries( deltad PRIVATE
      "-static-libstdc++ -static-libgcc"
      appbase
      delta_utilities
      delta_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( DELTA_STATIC_BUILD )
   target_link_libraries( deltad PRIVATE
      appbase
      delta_utilities
      delta_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( DELTA_STATIC_BUILD )

if( CLANG_TIDY_EXE )
   set_target_properties(
      deltad PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
   )
endif( CLANG_TIDY_EXE )

install( TARGETS
   deltad

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
