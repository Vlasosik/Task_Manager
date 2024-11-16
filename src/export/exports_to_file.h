#ifndef EXPORT_TO_FILE_H
#define EXPORT_TO_FILE_H

class category;

#include "pch.h"
#include "../factory/task.h"

class exports_to_file {
    std::ofstream ofs;;
    std::ifstream ifs;

public:
    exports_to_file() = default;

    void create_to_file(const std::string &file_name);

    static void write_info_to_file(const std::string &file_path, const std::unordered_multimap<category,
                                       std::vector<std::shared_ptr<task> > > &competed_tasks);
};

#endif //EXPORT_TO_FILE_H
