add_github_dependency(SDL libsdl-org/SDL release-2.28.3)

add_nutra_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} SDL2-static SDL2main)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL_INCLUDE_DIRS})