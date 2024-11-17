#ifndef TASK_OBSERVER_INTERFACE_H
#define TASK_OBSERVER_INTERFACE_H

class task_observer_interface {
public:
    virtual void update() = 0;

    virtual ~task_observer_interface() = default;
};

#endif
