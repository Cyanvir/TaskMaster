# 1. 规定 CMake 的最低版本 (标准写法)
cmake_minimum_required(VERSION 3.10)

# 2. 定义项目名称
project(TaskMaster)

# 3. 设置 C++ 标准为 C++11 或 C++14 (保证兼容性)
set(CMAKE_CXX_STANDARD 14)

# 4. 告诉编译器头文件在哪里 (重要！不然以后找不到 .h 文件)
include_directories(include)

# 5. 自动查找 src 目录下所有的 .cpp 文件，存到 SOURCES 变量里
#    这样就不用每加一个文件都改一次 CMakeLists 了
file(GLOB SOURCES "src/*.cpp")

# 6. 生成可执行文件
#    名字叫 TaskApp，由 SOURCES 里的文件编译而来
add_executable(TaskApp ${SOURCES})