set(SOURCE_PATH )

file(GLOB_RECURSE TEST_SOURCES *.cpp *.hpp)

# Builds tests
add_executable(${LIBRARY_NAME}-Tests ${TEST_SOURCES})

target_include_directories(${LIBRARY_NAME}-Tests PUBLIC ../src ${SDL_INCLUDE_DIRS})

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#Links googletest and googlemock to the test executable
target_link_libraries(${LIBRARY_NAME}-Tests GTest::gtest_main ${LIBRARY_NAME})

include(GoogleTest)

gtest_discover_tests(${LIBRARY_NAME}-Tests)
