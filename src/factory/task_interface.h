#ifndef TASK_INTERFACE_H
#define TASK_INTERFACE_H

class task_interface {
public:
    virtual void mark_as_done() = 0;
    virtual void cancel_task() = 0;
    virtual bool is_task_completed() = 0;
    virtual ~task_interface() = default;
};
#endif //TASK_INTERFACE_H
