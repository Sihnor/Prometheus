project(Prometheus)

file(GLOB_RECURSE PS_SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/src/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

include_directories(${PROJECT_SOURCE_DIR}/src/Prometheus/Core)

add_library(Prometheus SHARED ${PS_SOURCE_FILES})
set_property(TARGET Prometheus PROPERTY OUTPUT_NAME "PrometheusEngine")

set_target_properties(Prometheus PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${WORKSPACE_PATH}/bin/${OUTPUT_DIR}/${PROJECT_NAME}
        RUNTIME_OUTPUT_DIRECTORY ${WORKSPACE_PATH}/bin/${OUTPUT_DIR}/${PROJECT_NAME}
        LIBRARY_OUTPUT_DIRECTORY ${WORKSPACE_PATH}/bin/${OUTPUT_DIR}/${PROJECT_NAME}
        OBJECT_OUTPUT_DIRECTORY ${WORKSPACE_PATH}/bin/${OUTPUT_DIR}/${PROJECT_NAME}
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${WORKSPACE_PATH}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME} CACHE STRING "PrometheusDll Output Dir")

# Definiere PS_BUILD_DLL, um anzuzeigen, dass die Bibliothek als DLL erstellt wird
target_compile_definitions(Prometheus PRIVATE PS_BUILD_DLL)