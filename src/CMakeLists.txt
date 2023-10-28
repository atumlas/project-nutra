# configure nutra config to show version
configure_file(nutra_config.hpp.in nutra_config.hpp)

file(GLOB_RECURSE NUTRA_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE NUTRA_HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

add_nutra_executable(${PROJECT_NAME}-Game ${NUTRA_SOURCE_FILES} ${NUTRA_HEADER_FILES})

target_link_libraries(${PROJECT_NAME}-Game SDL2main SDL2-static spdlog::spdlog ${PROJECT_NAME}-Core)
target_include_directories(${PROJECT_NAME}-Game PUBLIC ${SDL_INCLUDE_DIRS})
# for including the nutra-config.hpp file
target_include_directories(${PROJECT_NAME}-Game PUBLIC ${PROJECT_BINARY_DIR}/src)