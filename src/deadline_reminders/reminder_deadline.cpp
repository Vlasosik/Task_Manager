#include "reminder_deadline.h"
#include "../category/category.h"
#include "../factory/task.h"

void reminder_deadline::check_deadline(const std::unordered_multimap<category,
    std::vector<std::shared_ptr<task> > > &competed_tasks) {
    for (const auto &[category, tasks]: competed_tasks) {
        for (const auto &task: tasks) {
            auto deadline = task->get_deadline();
            auto now = std::chrono::system_clock::now();
            if (auto one_day_before_deadline = deadline - std::chrono::hours(24);
                now >= one_day_before_deadline && now < deadline) {
                std::cout << "Reminder: Task in category " << category.get_category() << ", "
                        << task->get_name() << " is due soon!" << std::endl;
                notify();
            }
        }
    }
}

void reminder_deadline::start_reminder(const std::unordered_multimap<category,
    std::vector<std::shared_ptr<task> > > &competed_tasks) {
    thread_reminder = std::thread([this, &competed_tasks]() {
        is_running = true;
        while (is_running) {
            check_deadline(competed_tasks);
            // check deadline every 12 hours
            std::this_thread::sleep_for(std::chrono::hours(12));
        }
    });
}

void reminder_deadline::stop_reminder() {
    is_running = false;
    if (thread_reminder.joinable()) {
        thread_reminder.join();
    }
}

reminder_deadline::~reminder_deadline() {
    stop_reminder();
}
