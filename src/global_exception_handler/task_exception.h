#ifndef TASK_EXCEPTION_H
#define TASK_EXCEPTION_H
#include "task_manager_exception.h"


class task_exception : public task_manager_exception{
public:
    explicit task_exception(const std::string &task_name);

    [[nodiscard]] const char * what() const noexcept override;
};



#endif //TASK_EXCEPTION_H
