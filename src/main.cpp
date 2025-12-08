// src/main.cpp
#include <iostream>
#include <string>
#include <limits> // 用于清理输入缓存
#include "TaskManager.h"

// 显示菜单的辅助函数
void showMenu() {
    std::cout << "\n==========================" << std::endl;
    std::cout << "   TaskMaster 2026 CLI" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "1. Add New Task " << std::endl;
    std::cout << "2. Show All Tasks " << std::endl;
    std::cout << "3. Mark Task as Done" << std::endl;
    std::cout << "4. Edit Task Title" << std::endl;
    std::cout << "0. Exit " << std::endl;
    std::cout << "Please select: ";
}

int main() {
    TaskManager manager;
    int choice;
    std::string tempTitle;

    // 【核心逻辑】无限循环
    // 只要用户不输入 0，程序就永远不结束
    while (true) {
        showMenu();
        
        // 获取用户输入的数字
        if (!(std::cin >> choice)) {
            // 防止用户输入字母导致死循环的保护措施
            std::cout << "Invalid input! Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // 【坑点修复】清除输入缓冲区里的 "回车键"
        // 如果不写这行，后面的 getline 会直接读到一个空行
        std::cin.ignore(); 

        if (choice == 0) {
            std::cout << "Goodbye! Good luck with your exams!" << std::endl;
            break; // 打破循环，退出程序
        }
        else if (choice == 1) {
            std::cout << "Enter task title: ";
            // 使用 getline 允许输入的任务名带空格 (比如 "Go to sleep")
            std::getline(std::cin, tempTitle);
            
            if (!tempTitle.empty()) {
                manager.addTask(tempTitle);
            }
        }
        else if (choice == 2) {
            manager.showAllTasks();
        }
        else if (choice == 3) {
            int taskID;
            std::cout << "Enter task ID to complete: ";
            // 检查输入是不是数字
            if (std::cin >> taskID) {
                manager.markTaskCompleted(taskID);
            } else {
                std::cout << "Invalid input! Please enter a number." << std::endl;
                // 清理一下输入缓存，防止死循环
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else if (choice == 4) {
            int taskID;
            std::cout << "Enter task ID to edit: ";

            if (std::cin >> taskID) {
                // 清理缓冲区里的回车符！
                // 如果不加这行，下面的 getline 会直接读到空字符串
                std::cin.ignore(); 

                std::cout << "Enter new title: ";
                std::string newTitle;
                std::getline(std::cin, newTitle);

                if (!newTitle.empty()) {
                    manager.editTaskTitle(taskID, newTitle);
                } else {
                    std::cout << "Error: Title cannot be empty!" << std::endl;
                }
            } else {
                std::cout << "Invalid input! Please enter a number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else {
            std::cout << "Unknown option, please try again." << std::endl;
        }
    }

    return 0;
}