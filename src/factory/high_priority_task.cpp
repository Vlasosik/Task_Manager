#include "high_priority_task.h"


high_priority_task::high_priority_task(std::string name, std::string description, const PRIORITY priority,
                                       const STATUS status): task(std::move(name), std::move(description),
                                                                  priority, status) {
}

void high_priority_task::mark_as_done() {
    task::mark_as_done();
}

void high_priority_task::cancel_task() {
    task::cancel_task();
}

bool high_priority_task::is_task_completed() {
    return task::is_task_completed();
}

high_priority_task::~high_priority_task() = default;
