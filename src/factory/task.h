#ifndef TASK_H
#define TASK_H
#include "pch.h"
#include "task_interface.h"

using deadline_t = std::chrono::system_clock::time_point;

enum class PRIORITY {
    TODAY, WEEK, MONTH
};

enum class STATUS {
    DONE, PROCESS, CANCELLED
};


class task : public task_interface {
    std::string name;
    std::string description;
    deadline_t deadline;
    PRIORITY priority{};
    STATUS status{};

public:
    task(std::string name, std::string description, deadline_t deadline, PRIORITY priority, STATUS status);

    task(task &&other) noexcept = default;

    task &operator=(task &&other) noexcept = default;

    bool operator <(const task &other) const;

    bool operator >(const task &other) const;

    [[nodiscard]] std::string get_name() const;

    [[nodiscard]] std::string get_description() const;

    [[nodiscard]] std::string get_deadline_to_string() const;

    [[nodiscard]] deadline_t get_deadline() const;

    [[nodiscard]] PRIORITY get_priority() const;

    [[nodiscard]] STATUS get_status() const;

    void set_name(const std::string &name);

    void set_description(const std::string &description);

    void set_deadline(const deadline_t &deadline);

    void set_priority(PRIORITY priority);

    void set_status(STATUS status);

    void mark_as_done() override;

    void cancel_task() override;

    bool is_task_completed() override;

    ~task() override = 0;

    [[nodiscard]] static std::string priority_to_string(PRIORITY priority);

    [[nodiscard]] static std::string status_to_string(STATUS status);

    void convert_time_to_string(std::ostringstream &oss) const;

    void show() const;
};

inline task::~task() = default;

#endif //TASK_H
