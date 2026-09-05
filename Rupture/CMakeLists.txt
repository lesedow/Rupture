# CMakeList.txt : CMake project for Rupture, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Rupture WIN32 "Rupture.cc")

target_include_directories(Rupture PRIVATE include)
target_compile_definitions(Rupture PRIVATE __PROJECT_NAME__="${PROJECT_NAME}")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Rupture PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
