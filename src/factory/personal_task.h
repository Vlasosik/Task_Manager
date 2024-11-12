#ifndef PERSONAL_TASK_H
#define PERSONAL_TASK_H
#include "task.h"

class personal_task final : public task {
    std::string name;
    std::string description;
    PRIORITY priority{};
    STATUS status{};

public:
    personal_task(std::string name, std::string description, PRIORITY priority, STATUS status);

    void mark_as_done() override;

    void cancel_task() override;

    bool is_task_completed() override;

    ~personal_task() override;
};


#endif //PERSONAL_TASK_H
