#include "TaskItem.h"

TaskItem::TaskItem(const std::string& name, bool completed) : name(name), completed(completed) {}

std::string TaskItem::getName() const {
    return name;
}

bool TaskItem::isCompleted() const {
    return completed;
}

void TaskItem::setName(const std::string& name) {
    this->name = name;
}

void TaskItem::setCompleted(bool completed) {
    this->completed = completed;
}
