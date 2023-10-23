add_github_dependency(SDL libsdl-org/SDL release-2.28.3)

file(GLOB_RECURSE NUTRA_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE NUTRA_HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

add_nutra_executable(${PROJECT_NAME} ${NUTRA_SOURCE_FILES} ${NUTRA_HEADER_FILES} )

target_link_libraries(${PROJECT_NAME} SDL2-static SDL2main)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL_INCLUDE_DIRS})