set(LIBRARY_NAME ${PROJECT_NAME}-Core)

add_subdirectory(src)
if(ENABLE_TESTS)
    add_subdirectory(test)
endif()