#include "exports_to_file.h"

#include "../category/category.h"

void exports_to_file::create_to_file(const std::string &file_name) {
    ofs.open(file_name);
    if (ofs.is_open()) {
        std::cout << "File successfully create." << std::endl;
    } else {
        std::cerr << "File isn`t open.";
    }
}

void exports_to_file::write_info_to_file(const std::string &file_path,
                                         const std::unordered_multimap<category, std::vector<std::shared_ptr<task> > > &
                                         competed_tasks) {
    std::ofstream ofs(file_path);
    ofs << "Category,Name,Description,Deadline,Priority,Status\n";
    for (const auto &[category, tasks]: competed_tasks) {
        for (auto &task: tasks) {
            ofs << category.get_category() << ","
                    << task->get_name() << ","
                    << task->get_description() << ","
                    << task->get_deadline_to_string() << ","
                    << task::priority_to_string(task->get_priority()) << ","
                    << task::status_to_string(task->get_status()) << "\n";
        }
    }
    ofs.close();
    std::cout << "Tasks exported to " << file_path << std::endl;
}
