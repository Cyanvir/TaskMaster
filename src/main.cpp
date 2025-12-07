// src/main.cpp
#include <iostream>
#include "Task.h" // 引入需要使用的类

int main() {
    // 1. 创建一个任务对象
    Task myTask("Finish Linear Algebra Exam");

    // 2. 打印它的初始状态
    std::cout << "Task: " << myTask.getTitle() << std::endl;
    std::cout << "Status: " << (myTask.isDone() ? "Done" : "Pending") << std::endl;

    // 3. 完成它！
    myTask.markCompleted();
    std::cout << "--- Updated Status ---" << std::endl;
    std::cout << "Status: " << (myTask.isDone() ? "Done" : "Pending") << std::endl;

    return 0;
}