#ifndef HIGH_PRIORITY_TASK_H
#define HIGH_PRIORITY_TASK_H
#include "task.h"

class high_priority_task final : public task {
public:
    high_priority_task(std::string name, std::string description, deadline_t deadline, PRIORITY priority,
                       STATUS status);

    void mark_as_done() override;

    void cancel_task() override;

    bool is_task_completed() override;

    ~high_priority_task() override;
};


#endif //HIGH_PRIORITY_TASK_H
