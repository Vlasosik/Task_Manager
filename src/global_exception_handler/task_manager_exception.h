#ifndef TASK_MANAGER_EXCEPTION_H
#define TASK_MANAGER_EXCEPTION_H
#include "pch.h"


class task_manager_exception : public std::exception {
    std::string message;

public:
    explicit task_manager_exception(std::string msg) : message(std::move(msg)) {
    }

    [[nodiscard]] const char *what() const noexcept override {
        return message.c_str();
    }
};


#endif //TASK_MANAGER_EXCEPTION_H
