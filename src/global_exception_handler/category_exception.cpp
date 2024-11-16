#include "category_exception.h"

category_exception::category_exception(const std::string& category_name)
    : task_manager_exception("Category '" + category_name + "' doesn't exist.") {}

const char * category_exception::what() const noexcept {
    return task_manager_exception::what();
}

