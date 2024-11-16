#ifndef FACTORY_TASK_H
#define FACTORY_TASK_H

#include "task.h"

enum class TaskType {
    PERSONAL = 1, HIGH_PRIORITY_TASK, LONG_TERM_TASK
};

class factory_task {
public:
    static std::shared_ptr<task> get_factory_task(TaskType task_type, const std::string &name,
                                                  const std::string &description,
                                                  deadline_t deadline,
                                                  PRIORITY priority, STATUS status);
};


#endif //FACTORY_TASK_H
