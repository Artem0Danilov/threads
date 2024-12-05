cmake_minimum_required(VERSION 3.10)

# Название проекта и версия
project(DeviceProject VERSION 1.0)

# Указываем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем директории для заголовочных файлов
include_directories(include)  # Добавьте эту строку для указания директории include

# Указываем, что нужно компилировать
add_executable(main main.cpp src/Device.cpp)

# Для многопоточности добавляем флаг pthread
target_link_libraries(main pthread)
