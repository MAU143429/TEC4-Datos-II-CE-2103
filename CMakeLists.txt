cmake_minimum_required(VERSION 3.17)
project(TEC4_Datos_II)

set(CMAKE_CXX_STANDARD 14)

add_executable(TEC4_Datos_II main.cpp src/HashingAlgorithms/HashMD5.cpp src/HashingAlgorithms/HashMD5.h src/HashingAlgorithms/HashSHA1.cpp src/HashingAlgorithms/HashSHA1.h)