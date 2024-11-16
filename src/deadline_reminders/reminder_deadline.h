#ifndef REMINDER_DEADLINE_H
#define REMINDER_DEADLINE_H
#include "pch.h"

class category;
class task;

class reminder_deadline {
    std::thread thread_reminder;
    std::atomic<bool> is_running{true};

    static void check_deadline(const std::unordered_multimap<category,
        std::vector<std::shared_ptr<task> > > &competed_tasks);

public:
    reminder_deadline() = default;

    ~reminder_deadline();

    void start_reminder(const std::unordered_multimap<category,
        std::vector<std::shared_ptr<task> > > &competed_tasks);

    void stop_reminder();
};


#endif //REMINDER_DEADLINE_H
