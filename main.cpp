#include "pch.h"
#include "src/category/category.h"
#include "src/factory/factory_task.h"

int main() {
    auto task = factory_task::get_factory_task(TaskType::PERSONAL, "Learn English", "Study words", PRIORITY::TODAY,
                                                     STATUS::PROCESS);
    category category;
    category.add_task_to_category("Job", std::move(task));
    category.show_category_tasks();
    return 0;
}
