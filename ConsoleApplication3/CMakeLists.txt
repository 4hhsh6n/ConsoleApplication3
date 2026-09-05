cmake_minimum_required(VERSION 3.10)   # минимальная версия CMake
project(ConsoleApplication3)           # имя проекта совпадает с именем вашего решения

# Устанавливаем стандарт C++ (вы используете C++11/14/17 – укажем 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем исполняемый файл из одного исходника
add_executable(ConsoleApplication3 ConsoleApplication3.cpp)