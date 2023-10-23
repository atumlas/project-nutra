# Creates a library target called `name` from the given source files.
macro(add_nutra_library name)
  if(BUILD_SHARED_LIBS)
    set(LIBTYPE SHARED)
  else()
    set(LIBTYPE STATIC)
  endif()
  add_library(${name} ${LIBTYPE} ${ARGN})
    install(TARGETS ${name}
      COMPONENT ${name}
      LIBRARY DESTINATION lib
      ARCHIVE DESTINATION lib
      RUNTIME DESTINATION bin)
endmacro()

# Creates an executable target called `name` from the given source files.
macro(add_nutra_executable name)
  add_executable(${name} ${ARGN} )
        install(TARGETS ${name}
        COMPONENT ${name}
        RUNTIME DESTINATION bin)
endmacro()