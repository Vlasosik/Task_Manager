#ifndef TASK_H
#define TASK_H
#include "pch.h"
#include "task_interface.h"

enum class PRIORITY {
    TODAY = 1, WEEK, MONTH
};

enum class STATUS {
    DONE = 1, PROCESS, CANCELLED
};


class task : public task_interface {
    std::string name;
    std::string description;
    PRIORITY priority{};
    STATUS status{};

public:
    task(std::string name, std::string description, PRIORITY priority, STATUS status);

    [[nodiscard]] std::string get_name() const;

    [[nodiscard]] std::string get_description() const;

    [[nodiscard]] PRIORITY get_priority() const;

    [[nodiscard]] STATUS get_status() const;

    void set_name(const std::string &name);

    void set_description(const std::string &description);

    void set_priority(PRIORITY priority);

    void set_status(STATUS status);

    void mark_as_done() override;

    void cancel_task() override;

    bool is_task_completed() override;

    ~task() override = 0;

    [[nodiscard]] static std::string priority_to_string(PRIORITY priority);

    [[nodiscard]] static std::string status_to_string(STATUS status);

    void show() const;
};

inline task::~task() = default;

#endif //TASK_H
