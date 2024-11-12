#include "long_term_task.h"

long_term_task::long_term_task(std::string name, std::string description, const PRIORITY priority, const STATUS status)
    : task(std::move(name), std::move(description), priority, status) {
}

void long_term_task::mark_as_done() {
    task::mark_as_done();
}

void long_term_task::cancel_task() {
    task::cancel_task();
}

bool long_term_task::is_task_completed() {
    return task::is_task_completed();
}

long_term_task::~long_term_task() = default;
