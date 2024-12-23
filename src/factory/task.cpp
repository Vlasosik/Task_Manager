#include "task.h"

task::task(std::string name, std::string description, const deadline_t deadline, const PRIORITY priority,
           const STATUS status)
    : name(std::move(name)), description(std::move(description)), deadline(deadline), priority(priority),
      status(status) {
}

bool task::operator<(const task &other) const {
    return static_cast<int>(this->priority) < static_cast<int>(other.priority);
}

bool task::operator>(const task &other) const {
    return static_cast<int>(this->priority) > static_cast<int>(other.priority);
}

std::string task::get_name() const {
    return this->name;
}

std::string task::get_description() const {
    return this->description;
}

std::string task::get_deadline_to_string() const {
    const std::time_t deadline_time = std::chrono::system_clock::to_time_t(deadline);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&deadline_time), "%d.%m.%Y");
    return oss.str();
}

deadline_t task::get_deadline() const {
    return this->deadline;
}

PRIORITY task::get_priority() const {
    return this->priority;
}

STATUS task::get_status() const {
    return status;
}

void task::set_name(const std::string &name) {
    this->name = name;
}

void task::set_description(const std::string &description) {
    this->description = description;
}

void task::set_deadline(const deadline_t &deadline) {
    this->deadline = deadline;
}


void task::set_priority(const PRIORITY priority) {
    this->priority = priority;
}

void task::set_status(const STATUS status) {
    this->status = status;
}

void task::mark_as_done() {
    status = STATUS::DONE;
}

void task::cancel_task() {
    status = STATUS::CANCELLED;
}

bool task::is_task_completed() {
    return status == STATUS::DONE;
}

std::string task::priority_to_string(const PRIORITY priority) {
    switch (priority) {
        case PRIORITY::TODAY:
            return "Today";
        case PRIORITY::WEEK:
            return "Week";
        case PRIORITY::MONTH:
            return "Month";
        default:
            return "Unknown Priority";
    }
}

std::string task::status_to_string(const STATUS status) {
    switch (status) {
        case STATUS::DONE:
            return "Done";
        case STATUS::PROCESS:
            return "In Process";
        case STATUS::CANCELLED:
            return "Cancelled";
        default:
            return "Unknown Status";
    }
}

void task::convert_time_to_string(std::ostringstream &oss) const {
    const auto time = std::chrono::system_clock::to_time_t(deadline);
    const std::tm tm = *std::localtime(&time);
    oss << std::put_time(&tm, "%Y-%m-%d");
}

void task::show() const {
    std::cout << "Task name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::ostringstream oss;
    convert_time_to_string(oss);
    std::cout << "Deadline: " << oss.str() << std::endl;
    std::cout << "Priority: " << priority_to_string(priority) << std::endl;
    std::cout << "Status: " << status_to_string(status) << std::endl;
}
