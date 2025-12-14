# TaskMaster CLI Tool

## 1. 项目简介 (Introduction)
TaskMaster 是一个基于 C++ 开发的命令行待办事项管理工具 (CLI To-Do List Manager)。
本项目旨在实践 C++ 面向对象编程 (OOP) 思想，并遵循标准的工程化构建流程。

主要特点：
- **工程化构建**：使用 CMake 进行项目管理，脱离 IDE 依赖。
- **模块化设计**：严格遵循头文件 (.h) 与源文件 (.cpp) 分离的原则。
- **面向对象**：体现了封装 (Encapsulation) 和组合 (Composition) 关系。

## 2. 主要功能 (Features)
- [x] **添加任务 (Add)**：支持输入自定义任务标题，具有输入缓冲清理机制。
- [x] **查看列表 (List)**：动态显示当前所有任务及其完成状态。
- [x] **标记完成 (Complete)**：通过任务 ID 快速标记任务状态，支持 ID 合法性校验。
- [x] **修改任务 (Edit)**：支持对已存在的任务标题进行编辑，包含 "Fail-fast" 验证逻辑。
- [x] **全英文界面 (English UI)**：适配各类终端环境 (PowerShell/CMD/Bash)，避免编码乱码问题。

## 3. 项目目录结构 (Directory Structure)
```text
TaskMaster/
├── CMakeLists.txt      # CMake 构建脚本 (核心工程文件)
├── README.md           # 项目说明文档
├── .gitignore          # Git 忽略规则 (忽略 build/ 等临时文件)
├── pig_test.html       # 尝试GitHub配置网页，[https://cyanvir.github.io/TaskMaster/pig_test.html]网页链接
├── include/            # 头文件目录 (声明)
│   ├── Task.h          # Task 类：封装单个任务属性
│   └── TaskManager.h   # TaskManager 类：管理任务列表
└── src/                # 源文件目录 (实现)
    ├── main.cpp        # 程序入口：负责 CLI 交互与输入验证
    ├── Task.cpp        # Task 类逻辑实现
    └── TaskManager.cpp # TaskManager 类逻辑实现
```

## 4. 构建与运行方式 (Build & Run)
本项目依赖 CMake 和 C++ 编译器 (如 MinGW/GCC)。请按照以下步骤运行：

# 4.1 构建项目
```text
# 1. 创建构建目录 (Out-of-source build)
mkdir build
cd build

# 2. 生成 Makefile
# 如果是 Windows MinGW 环境：
cmake -G "MinGW Makefiles" ..
# 如果是 Mac/Linux 环境：
# cmake ..

# 3. 编译可执行文件
cmake --build .
```

# 4.2 运行程序
编译成功后，在 build 目录下运行：
```text
# Windows
./TaskApp.exe

# Mac/Linux
# ./TaskApp
```
## 5. 设计思路 (Design Philosophy)
本项目严格按照考核要求的工程化标准开发：

- **组合模式 (Composition)**：TaskManager 类内部维护一个 std::vector<Task>，负责数据的生命周期管理。

- **输入健壮性**：在 main.cpp 中实现了完善的 cin 错误处理和缓冲区清理，防止非法输入导致程序死循环。

- **Git 规范**：开发过程包含 chore, feat, fix, docs 等多种类型的提交，记录了完整的开发演进过程。

## Note: 
除了本项目外，我正在开发一个更复杂的 C++ 课程设计项目：中国象棋 (Chinese Chess)。 
欢迎访问我的另一个仓库查看：[https://github.com/Cyanvir/ChineseChess-CPP]