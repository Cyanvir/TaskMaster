cmake_minimum_required(VERSION 3.10)
project(TaskMaster)

set(CMAKE_CXX_STANDARD 17)

# 告诉 CMake 头文件在哪里
include_directories(include)

# ==========================================
# 1. 主程序 (TaskApp)
# ==========================================
# 只包含 main.cpp (真正的入口)
add_executable(TaskApp 
    src/main.cpp 
    src/Task.cpp 
    src/TaskManager.cpp
)

# ==========================================
# 2. 测试程序 (TaskTests) 
# ==========================================
# 这里的入口是 src/test_main.cpp
add_executable(TaskTests 
    src/test_main.cpp 
    src/Task.cpp 
    src/TaskManager.cpp
)