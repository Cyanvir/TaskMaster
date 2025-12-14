// src/test_main.cpp
#include <iostream>
#include <cassert> // C++ 标准断言库
#include "Task.h"
#include "TaskManager.h"

// 辅助函数：打印绿色的通过信息
void printPass(const std::string& testName) {
    std::cout << "[PASS] " << testName << std::endl;
}

void testTaskClass() {
    // 1. 测试创建任务
    Task t("Study C++");
    assert(t.getTitle() == "Study C++"); // 如果不相等，程序会直接报错终止
    assert(t.isDone() == false);
    
    // 2. 测试修改任务
    t.setTitle("Study English");
    assert(t.getTitle() == "Study English");

    // 3. 测试标记完成
    t.markCompleted();
    assert(t.isDone() == true);

    printPass("Task Class Logic");
}

void testTaskManager() {
    TaskManager manager;
    
    // 1. 测试一开始是空的
    assert(manager.getTaskCount() == 0);

    // 2. 测试添加任务
    manager.addTask("Test Task 1");
    assert(manager.getTaskCount() == 1);

    // 3. 测试修改任务
    // 注意：我们代码逻辑里 index 从 1 开始，数组从 0 开始
    // 我们没法直接断言 vector 内部，但我们可以确保 edit 函数返回 true
    bool editResult = manager.editTaskTitle(1, "Edited Task");
    assert(editResult == true);

    // 4. 测试错误处理 (修改不存在的任务)
    bool badEdit = manager.editTaskTitle(99, "Wrong");
    assert(badEdit == false);

    printPass("TaskManager Logic");
}

int main() {
    std::cout << "Running Unit Tests..." << std::endl;
    
    testTaskClass();
    testTaskManager();

    std::cout << "\nAll Unit Tests Passed! Great job!" << std::endl;
    return 0;
}