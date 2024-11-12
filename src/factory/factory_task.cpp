#include "factory_task.h"

#include "high_priority_task.h"
#include "long_term_task.h"
#include "personal_task.h"

std::unique_ptr<task> factory_task::get_factory_task(const TaskType task_type, const std::string &name,
                                                     const std::string &description,
                                                     const PRIORITY priority, const STATUS status) {
    switch (task_type) {
        case TaskType::PERSONAL:
            return std::make_unique<personal_task>(name, description, priority, status);
        case TaskType::HIGH_PRIORITY_TASK:
            return std::make_unique<high_priority_task>(name, description, priority, status);
        case TaskType::LONG_TERM_TASK:
            return std::make_unique<long_term_task>(name, description, priority, status);
        default:
            return nullptr;
    }
}
