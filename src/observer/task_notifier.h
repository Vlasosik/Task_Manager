#ifndef TASK_NOTIFIER_H
#define TASK_NOTIFIER_H
#include "task_events_interface.h"


class task_notifier : public task_events_interface {
    std::vector<task_observer_interface *> observers;
public:
    void attach(task_observer_interface *obs) override;

    void detach(task_observer_interface *obs) override;

    void notify() override;

    [[nodiscard]] int how_many_observer() const;

    ~task_notifier() override;
};
inline task_notifier::~task_notifier() = default;


#endif //TASK_NOTIFIER_H
