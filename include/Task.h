// include/Task.h
#ifndef TASK_H
#define TASK_H

#include <string>

// 考核点：类定义
class Task {
private:
    // 考核点：封装 (Private 成员变量)
    // 只有类自己能改这些数据，外部必须通过方法来访问
    std::string title;
    bool isCompleted;

public:
    // 构造函数：创建一个新任务
    Task(std::string t);

    // 考核点：Public 成员函数
    void markCompleted();
    bool isDone() const;
    std::string getTitle() const;
};

#endif // TASK_H