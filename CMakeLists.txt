cmake_minimum_required(VERSION 3.19)
project(csvParser)

set(CMAKE_CXX_STANDARD 11)

add_executable(csvParser main.cpp CsvWriter.cpp CsvWriter.h CsvReader.cpp CsvReader.h)