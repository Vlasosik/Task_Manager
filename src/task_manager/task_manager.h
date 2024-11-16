#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H
#include <map>

#include "../category/category.h"
#include "../factory/task.h"

enum class PRIORITY;
enum class STATUS;
class task;

class task_manager {
    std::unordered_multimap<category, std::vector<std::shared_ptr<task> > > task_manager_configure;
    static std::unique_ptr<task_manager> singleton_task_manager;

    task_manager() = default;

public:
    task_manager(const task_manager &other) = delete;

    task_manager(task_manager &&other) = delete;

    void operator=(task_manager &&other) = delete;

    void operator=(const task_manager &other) = delete;

    static task_manager *get_instance();

    std::unordered_map<category, std::vector<std::shared_ptr<task> > >::iterator get_iterator(const category &category);

    void add_new_task_in_category(const category &category, std::shared_ptr<task> task);

    void update_task(const category &category, const std::shared_ptr<task> &task);

    void remove_task(const category &category, const std::shared_ptr<task> &task);

    void sort_by_priority();

    std::vector<std::shared_ptr<task> > filter_by_priority(PRIORITY priority);

    std::vector<std::shared_ptr<task> > filter_by_status(STATUS status);

    std::optional<category> filter_by_category(const category &other_category);

    std::vector<std::shared_ptr<task> > filter_by_nearest_deadline();

    std::unordered_multimap<category, std::vector<std::shared_ptr<task> > > get_competed_task();

    std::unordered_multimap<category, std::vector<std::shared_ptr<task> > > get_category_and_tasks();

    void show_all_tasks_with_category() const;
};


#endif //TASK_MANAGER_H
