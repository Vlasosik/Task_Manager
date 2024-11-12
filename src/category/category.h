#ifndef CATEGORY_H
#define CATEGORY_H

#include "pch.h"
#include "../factory/factory_task.h"

class category {
    std::string name_category;
    std::unordered_multimap<std::string, std::unique_ptr<task> > category_with_task;

public:
    category() = default;

    explicit category(std::string name_category);

    [[nodiscard]] std::string get_category() const;

    void set_category(const std::string &name_category);

    void add_task_to_category(const std::string &name, std::unique_ptr<task> task);

    void show_category_tasks() const;
};


#endif //CATEGORY_H
