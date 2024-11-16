#include "personal_task.h"

personal_task::personal_task(std::string name, std::string description, deadline_t deadline, const PRIORITY priority,
                             const STATUS status): task(std::move(name), std::move(description),
                                                        deadline, priority, status) {
}

void personal_task::mark_as_done() {
    task::mark_as_done();
}

void personal_task::cancel_task() {
    task::cancel_task();
}

bool personal_task::is_task_completed() {
    return task::is_task_completed();
}

personal_task::~personal_task() = default;
