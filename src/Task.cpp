// src/Task.cpp
#include "Task.h"

// 构造函数实现
Task::Task(std::string t) {
    this->title = t;
    this->isCompleted = false; // 默认任务是未完成的
}

// 标记任务为完成
void Task::markCompleted() {
    this->isCompleted = true;
}

// 获取任务状态
bool Task::isDone() const {
    return this->isCompleted;
}

// 获取任务标题
std::string Task::getTitle() const {
    return this->title;
}