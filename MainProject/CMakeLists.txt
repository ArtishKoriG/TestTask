add_executable (MainProject "main.cpp" "consoleLogger.h" "consoleLogger.cpp" 
"constants.h" "iLogger.h" "logger.h" "logger.cpp" "parserExceptions.h" 
"parserPoints.h" "parserPoints.cpp")

target_link_libraries(MainProject PUBLIC FinderNearestPoint)

target_include_directories(MainProject PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/FinderNearestPoint"
                          )


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MainProject PROPERTY CXX_STANDARD 20)
endif()