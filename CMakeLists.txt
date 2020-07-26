cmake_minimum_required(VERSION 3.16)
project(RaceTracer)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

include_directories(Tuple)
include_directories(Vector)
include_directories(Point)
include_directories(Color)
include_directories(Canvas)
include_directories(Matrix)
include_directories(Ray)
include_directories(Sphere)
include_directories(Intersection)
include_directories(Light)
include_directories(Material)

add_executable(RaceTracer
        main.cpp
        "Tuple/Tuple.cpp" Test/Test.cpp Vector/Vector.cpp Vector/Vector.h Point/Point.cpp Point/Point.h Color/Color.cpp Color/Color.h Canvas/Canvas.cpp Canvas/Canvas.h Matrix/Matrix.cpp Matrix/Matrix.h Matrix/MatrixTransform.cpp Test/Test2.cpp Ray/Ray.cpp Ray/Ray.h Sphere/Sphere.cpp Sphere/Sphere.h Intersection/Intersection.cpp Intersection/Intersection.h Light/Light.cpp Light/Light.h Material/Material.cpp Material/Material.h)

target_link_libraries(RaceTracer gtest gtest_main)