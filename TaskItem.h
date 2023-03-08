#ifndef TASKITEM_H
#define TASKITEM_H

#include <string>

class TaskItem {
private:
    std::string name;
    bool completed;

public:
    TaskItem(const std::string& name, bool completed = false);
    std::string getName() const;
    bool isCompleted() const;
    void setName(const std::string& name);
    void setCompleted(bool completed);
};

#endif
