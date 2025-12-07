#include "TaskManager.h"

void TaskManager::addTask(const std::string& title) {
    // 1. 创建一个新任务
    Task newTask(title);
    
    // 2. 把它放进 vector 列表里
    tasks.push_back(newTask);
    
    std::cout << "Task added: " << title << std::endl;
}

void TaskManager::showAllTasks() const {
    std::cout << "\n--- To-Do List ---" << std::endl;
    
    if (tasks.empty()) {
        std::cout << "No tasks yet!" << std::endl;
        return;
    }

    // 遍历列表打印状态
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". [" 
                  << (tasks[i].isDone() ? "X" : " ") << "] " 
                  << tasks[i].getTitle() << std::endl;
    }
    std::cout << "------------------\n" << std::endl;
}