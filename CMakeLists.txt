cmake_minimum_required(VERSION 3.20)
project(Galilee VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Force x64 platform for MSVC
set(CMAKE_GENERATOR_PLATFORM x64 CACHE STRING "Platform architecture" FORCE)

# Explicitly define all valid configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;GL_DEBUG;GL_DIST;GL_RELEASE" CACHE STRING "Available configurations" FORCE)

# Define source and header file search
file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.h")

# Define output directories
set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/Binaries/${CMAKE_BUILD_TYPE}/x64/${PROJECT_NAME}")
set(INTERMEDIATE_DIR "${CMAKE_SOURCE_DIR}/Intermediates/${CMAKE_BUILD_TYPE}/x64/${PROJECT_NAME}")

# Add executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Set output directories
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}
)

# Define preprocessor definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE
    GL_PLATFORM_WINDOWS
    GL_PLATFORM_LINUX
)

# Fix missing linker flag variables for configurations
set(CMAKE_EXE_LINKER_FLAGS_GL_DEBUG "")
set(CMAKE_EXE_LINKER_FLAGS_GL_DIST "")
set(CMAKE_EXE_LINKER_FLAGS_GL_RELEASE "")

# Explicitly ensure Debug|x64 is recognized in MSBuild
foreach(CONFIG Debug GL_DEBUG GL_DIST GL_RELEASE)
    string(TOUPPER ${CONFIG} CONFIG_UPPER)
    set_property(DIRECTORY PROPERTY CMAKE_CONFIGURE_DEPENDS "${INTERMEDIATE_DIR}")
endforeach()