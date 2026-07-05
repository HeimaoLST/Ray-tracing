cmake_minimum_required(VERSION 3.15)
project(RayTracingC)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(raytracing
  src/main.cpp
)

target_include_directories(raytracing PRIVATE include)
