# CMakeList.txt: проект CMake для Wrapper; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("Wrapper")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Wrapper   "main.cpp" "Wrapper/wrapper.hpp"  "Engine/engine.h" "Engine/engine.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
