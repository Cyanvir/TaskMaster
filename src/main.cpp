#include <iostream>
#include "TaskManager.h" // 现在只需要引入管家

int main() {
    // 实例化一个管家对象
    TaskManager manager;
    
    std::cout << "=== TaskMaster v1.0 ===" << std::endl;

    // 假装用户在输入命令
    manager.addTask("Review Linear Algebra"); // 复习线代
    manager.addTask("Write C++ Project");     // 写C++
    manager.addTask("Sleep");                 // 睡觉

    // 显示列表
    manager.showAllTasks();

    return 0;
}