#include "factory_task.h"

#include "high_priority_task.h"
#include "long_term_task.h"
#include "personal_task.h"

std::shared_ptr<task> factory_task::get_factory_task(const TaskType task_type, const std::string &name,
                                                     const std::string &description, const deadline_t deadline,
                                                     const PRIORITY priority, const STATUS status) {
    switch (task_type) {
        case TaskType::PERSONAL:
            return std::make_shared<personal_task>(name, description, deadline, priority, status);
        case TaskType::HIGH_PRIORITY_TASK:
            return std::make_shared<high_priority_task>(name, description, deadline, priority, status);
        case TaskType::LONG_TERM_TASK:
            return std::make_shared<long_term_task>(name, description, deadline, priority, status);
        default:
            return nullptr;
    }
}
