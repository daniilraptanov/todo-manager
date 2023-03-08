#ifndef TASKLIST_H
#define TASKLIST_H

#include <vector>
#include "TaskItem.h"

class TaskList {
private:
    std::vector<TaskItem> tasks;

public:
    void addTask(const TaskItem& task);
    void removeTask(int index);
    void completeTask(int index);
    std::vector<TaskItem> getTasks() const;
};

#endif
