# CMakeList.txt : CMake project for Rupture, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Rupture WIN32 "Rupture.cc")

add_subdirectory(external/glm)

target_include_directories(Rupture PRIVATE include)

target_link_libraries(Rupture PRIVATE glm::glm)

target_compile_definitions(Rupture PRIVATE 
	PROJECT_NAME="${PROJECT_NAME}"
	$<$<CONFIG:Debug>:RUPTURE_DEBUG>
)

target_sources(Rupture PRIVATE
  src/Graphics/GL/Texture2D.cc
  src/Graphics/GL/ShaderProgram.cc
  src/Utils/Logger.cc
)

add_custom_command(TARGET Rupture POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/Rupture/assets"
        "$<TARGET_FILE_DIR:Rupture>/assets"	
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Rupture PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
