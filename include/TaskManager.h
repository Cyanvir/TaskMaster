#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <iostream>
#include "Task.h"  // 必须引入 Task，因为我们要管理它

class TaskManager {
private:
    // 【考核核心点】组合关系：TaskManager 拥有(Has-a) 一组 Task
    std::vector<Task> tasks; 

public:
    // 添加任务
    void addTask(const std::string& title);

    // 显示所有任务
    void showAllTasks() const;
    bool markTaskCompleted(int index);
    // 修改指定任务的标题
    bool editTaskTitle(int index, const std::string& newTitle);
    int getTaskCount() const;
};

#endif