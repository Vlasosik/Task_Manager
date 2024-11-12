#include "category.h"

category::category(std::string name_category) : name_category(std::move(name_category)) {
}

std::string category::get_category() const {
    return this->name_category;
}

void category::set_category(const std::string &name_category) {
    this->name_category = name_category;
}

void category::add_task_to_category(const std::string &name, std::unique_ptr<task> task) {
    category_with_task.emplace(name, std::move(task));
}

void category::show_category_tasks() const {
    for (auto& [first, second]: category_with_task) {
        std::cout << "Category: " << first << std::endl;
        second->show();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
