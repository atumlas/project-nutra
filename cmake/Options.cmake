# Defines an option and prints its value
macro(nutra_option name description default_value)
    if (NOT "${ARGN}" STREQUAL "")
        message(SEND_ERROR "nutra_option takes only a three argument.  Offending args: ${ARGN}")
    endif()    
    option(${name} ${description} ${default_value})
    message(STATUS "\t${name} ${${name}}")
endmacro()