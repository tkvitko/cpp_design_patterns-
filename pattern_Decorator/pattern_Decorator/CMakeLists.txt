cmake_minimum_required(VERSION 3.22.0)
set(CMAKE_CXX_STANDARD 17)
project(decorator)
add_executable(decorator BoldText.cpp DecoratedText.hpp	ItalicText.hpp Link.hpp Paragraph.hpp Reversed.hpp Text.hpp BoldText.hpp DecoratedText.cpp ItalicText.cpp Link.cpp Paragraph.cpp Reversed.cpp Text.cpp main.cpp)
