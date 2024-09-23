# Добавьте источник в исполняемый файл этого проекта.
add_library(FinderNearestPoint  "segmentLine.h" "finderDistToSegment.h" "finderDistToSegment.cpp"
"vector.h" "vector.cpp" "coordinates.h" "coordinates.cpp")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FinderNearestPoint PROPERTY CXX_STANDARD 20)
endif()
