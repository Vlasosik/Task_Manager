#ifndef HIGH_PRIORITY_TASK_H
#define HIGH_PRIORITY_TASK_H
#include "task.h"

class high_priority_task final : public task {
    std::string name;
    std::string description;
    PRIORITY priority{};
    STATUS status{};

public:
    high_priority_task(std::string name, std::string description, PRIORITY priority, STATUS status);

    void mark_as_done() override;

    void cancel_task() override;

    bool is_task_completed() override;

    ~high_priority_task() override;
};


#endif //HIGH_PRIORITY_TASK_H
