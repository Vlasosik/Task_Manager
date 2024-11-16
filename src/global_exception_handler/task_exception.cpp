#include "task_exception.h"

task_exception::task_exception(const std::string &task_name)
    : task_manager_exception("Task '" + task_name + "' doesn't exist.") {}

const char * task_exception::what() const noexcept {
    return task_manager_exception::what();
}

