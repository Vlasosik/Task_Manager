#include "task_observer.h"


static int generate_id() {
    static int id_counter = 0;
    return ++id_counter;
}

task_observer::task_observer(task_notifier &tn) : tn(tn), id(generate_id()) {
    tn.attach(this);
}

void task_observer::update() {
    std::cout << "Notification: Task deadline is approaching for Observer #" << id << "!" << std::endl;
}

void task_observer::remove() {
    tn.detach(this);
    std::cout << "Observer #" << id << " removed." << std::endl;
}

void task_observer::print_info() const {
    std::cout << "Observer #" << id << " is currently active.\n";
}
