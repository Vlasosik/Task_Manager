#ifndef CATEGORY_EXCEPTION_H
#define CATEGORY_EXCEPTION_H
#include "task_manager_exception.h"


class category_exception : public task_manager_exception {
public:
    explicit category_exception(const std::string& category_name);

    [[nodiscard]] const char * what() const noexcept override;

};



#endif //CATEGORY_EXCEPTION_H
