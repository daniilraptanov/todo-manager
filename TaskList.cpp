#include "TaskList.h"

void TaskList::addTask(const TaskItem& task) {
    tasks.push_back(task);
}

void TaskList::removeTask(int index) {
    tasks.erase(tasks.begin() + index);
}

void TaskList::completeTask(int index) {
    tasks[index].setCompleted(true);
}

std::vector<TaskItem> TaskList::getTasks() const {
    return tasks;
}
