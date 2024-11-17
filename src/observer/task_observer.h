#ifndef TASK_OBSERVER_H
#define TASK_OBSERVER_H
#include "task_notifier.h"
#include <memory>


class task_observer : public task_observer_interface{
    task_notifier &tn;
    int id;

public:
    explicit task_observer(task_notifier &tn);

    void update() override;

    void remove();

    void print_info() const;
};


#endif //TASK_OBSERVER_H
