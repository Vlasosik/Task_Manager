#include "task_manager.h"

#include "../factory/task.h"
#include "../global_exception_handler/category_exception.h"
#include "../global_exception_handler/task_exception.h"
#include "../observer/task_notifier.h"

std::unique_ptr<task_manager> task_manager::singleton_task_manager = nullptr;

task_manager *task_manager::get_instance() {
    if (singleton_task_manager == nullptr) {
        singleton_task_manager.reset(new task_manager());
    }
    return singleton_task_manager.get();
}

std::unordered_map<category, std::vector<std::shared_ptr<task> > >::iterator
task_manager::get_iterator(const category &category) {
    return task_manager_configure.find(category);
}

void task_manager::add_new_task_in_category(const category &category, std::shared_ptr<task> task) {
    if (const auto it = task_manager_configure.find(category); it != task_manager_configure.end()) {
        it->second.push_back(task);
    } else {
        task_manager_configure.emplace(category, std::vector{std::move(task)});
    }
}


void task_manager::update_task(const category &category, const std::shared_ptr<task> &task) {
    if (const auto pair = get_iterator(category); pair != task_manager_configure.end()) {
        for (const auto &current: pair->second) {
            current->set_name(task->get_name());
            current->set_description(task->get_description());
            current->set_priority(task->get_priority());
            current->set_status(task->get_status());
        }
        task_notifier.notify();
    } else {
        throw category_exception(category.get_category());
    }
}

void task_manager::remove_task(const category &category, const std::shared_ptr<task> &task) {
    if (const auto pair = get_iterator(category); pair != task_manager_configure.end()) {
        for (const auto &current: pair->second) {
            if (current->get_name() == task->get_name()) {
                task_manager_configure.erase(pair->first);
            }
        }
    } else {
        throw task_exception(task->get_name());
    }
}

void task_manager::sort_by_priority() {
    for (auto &[category, tasks]: task_manager_configure) {
        std::sort(tasks.begin(), tasks.end(), [](const std::shared_ptr<task> &a, const std::shared_ptr<task> &b) {
            return a->get_priority() < b->get_priority();
        });
    }
}

std::vector<std::shared_ptr<task> > task_manager::filter_by_priority(const PRIORITY priority) {
    std::vector<std::shared_ptr<task> > filtered_tasks;
    for (auto &[categories, tasks]: task_manager_configure) {
        for (const auto &task: tasks) {
            if (task->get_priority() == priority) {
                filtered_tasks.push_back(task);
            }
        }
    }
    return filtered_tasks;
}

std::vector<std::shared_ptr<task> > task_manager::filter_by_status(const STATUS status) {
    std::vector<std::shared_ptr<task> > filtered_tasks;
    for (auto &[categories, tasks]: task_manager_configure) {
        for (const auto &task: tasks) {
            if (task->get_status() == status) {
                filtered_tasks.push_back(task);
            }
        }
    }
    return filtered_tasks;
}

std::optional<category> task_manager::filter_by_category(const category &other_category) {
    for (auto &[categories, tasks]: task_manager_configure) {
        if (categories.get_category() == other_category.get_category()) {
            return categories;
        }
    }
    return std::nullopt;
}

std::vector<std::shared_ptr<task> > task_manager::filter_by_nearest_deadline() {
    std::vector<std::shared_ptr<task> > filtered_tasks;
    auto now = std::chrono::system_clock::now();
    for (const auto &[first, second]: task_manager_configure) {
        for (const auto &task: second) {
            if (auto deadline = task->get_deadline(); deadline > now) {
                filtered_tasks.push_back(task);
            }
        }
    }
    std::sort(filtered_tasks.begin(), filtered_tasks.end(),
              [now](const auto &task1, const auto &task2) {
                  const auto deadline1 = task1->get_deadline();
                  const auto deadline2 = task2->get_deadline();
                  return deadline1 - now < deadline2 - now;
              });
    return filtered_tasks;
}

std::unordered_multimap<category, std::vector<std::shared_ptr<task> > > task_manager::get_competed_task() {
    std::unordered_multimap<category, std::vector<std::shared_ptr<task> > > competed_task;
    for (auto &[category, tasks]: task_manager_configure) {
        for (const auto &task: tasks) {
            if (task->get_status() == STATUS::DONE) {
                competed_task.emplace(category, tasks);
            }
        }
    }
    return competed_task;
}

std::unordered_multimap<category, std::vector<std::shared_ptr<task> > > task_manager::get_category_and_tasks() {
    std::unordered_multimap<category, std::vector<std::shared_ptr<task> > > return_tasks;
    for (auto &[category, tasks]: task_manager_configure) {
        for (const auto &task: tasks) {
            return_tasks.emplace(category, tasks);
        }
    }
    return return_tasks;
}

void task_manager::show_all_tasks_with_category() const {
    for (const auto &[first, second]: task_manager_configure) {
        std::cout << "Category: " << first.get_category() << "\n";
        std::cout << "Task info: " << "\n";
        for (const auto &task: second) {
            task->show();
        }
        std::cout << "===========================\n";
    }
}
