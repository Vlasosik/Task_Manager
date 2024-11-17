#ifndef TASK_EVENTS_INTERFACE_H
#define TASK_EVENTS_INTERFACE_H
#include "task_observer_interface.h"

class task_observer_interface;

class task_events_interface {
public:
    virtual void attach(task_observer_interface *obs) = 0;

    virtual void detach(task_observer_interface *obs) = 0;

    virtual void notify() = 0;

    virtual ~task_events_interface() = default;
};
#endif //TASK_EVENTS_INTERFACE_H
