cmake_minimum_required(VERSION 3.29)
project(task_manager)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(task_manager main.cpp
        include/pch.h
        src/factory/task_interface.h
        src/factory/task.h
        src/factory/task.cpp
        src/factory/personal_task.cpp
        src/factory/personal_task.h
        src/factory/high_priority_task.cpp
        src/factory/high_priority_task.h
        src/factory/long_term_task.cpp
        src/factory/long_term_task.h
        src/factory/factory_task.cpp
        src/factory/factory_task.h
        src/category/category.cpp
        src/category/category.h
        src/task_manager/task_manager.cpp
        src/task_manager/task_manager.h
)

target_include_directories(task_manager PRIVATE include)

target_precompile_headers(task_manager PRIVATE include/pch.h)

