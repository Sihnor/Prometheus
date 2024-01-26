project(Sandbox)

include_directories(${WORKSPACE_PATH}/Prometheus/src)

add_executable(Sandbox src/Sandbox.cpp)

set_target_properties(Sandbox PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${WORKSPACE_PATH}/bin-int/${OUTPUT_DIR}/${PROJECT_NAME}
        RUNTIME_OUTPUT_DIRECTORY ${WORKSPACE_PATH}/bin-int/${OUTPUT_DIR}/${PROJECT_NAME}
        LIBRARY_OUTPUT_DIRECTORY ${WORKSPACE_PATH}/bin-int/${OUTPUT_DIR}/${PROJECT_NAME}
        OBJECT_OUTPUT_DIRECTORY ${WORKSPACE_PATH}/bin-int/${OUTPUT_DIR}/${PROJECT_NAME}
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${WORKSPACE_PATH}/bin-int/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME})

add_dependencies(Sandbox Prometheus)

target_link_libraries(Sandbox Prometheus)

# Copy the DLL to the executable directory

if (DEFINED PS_PLATFORM_WINDOWS)
    add_custom_command(
            TARGET Sandbox
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libPrometheusEngine.dll
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/libPrometheusEngine.dll
    )
endif ()

if (DEFINED PS_PLATFORM_LINUX)
    add_custom_command(
            TARGET Sandbox
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libPrometheusEngine.so
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/libPrometheusEngine.so
    )
endif ()
