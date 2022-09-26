cmake_minimum_required(VERSION 3.2)

project(GameEngine LANGUAGES CXX)

file(GLOB engine_sources source/*.cpp)

add_library(${PROJECT_NAME} ${engine_sources})

add_subdirectory(external/SDL2)
add_subdirectory(external/SDL2_image)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        SDL2
        SDL2_image
    PRIVATE
        
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        SDL2
        SDL2_image

    PRIVATE

)