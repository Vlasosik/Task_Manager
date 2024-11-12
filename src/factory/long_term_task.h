#ifndef LONG_TERM_TASK_H
#define LONG_TERM_TASK_H
#include "task.h"


class long_term_task final : public task {
    std::string name;
    std::string description;
    PRIORITY priority{};
    STATUS status{};

public:
    long_term_task(std::string name, std::string description, PRIORITY priority, STATUS status);

    void mark_as_done() override;

    void cancel_task() override;

    bool is_task_completed() override;

    ~long_term_task() override;
};


#endif //LONG_TERM_TASK_H
