#include "task_notifier.h"

void task_notifier::attach(task_observer_interface *obs) {
    if (std::find(observers.begin(), observers.end(), obs) == observers.end()) {
        observers.push_back(obs);
    }
}

void task_notifier::detach(task_observer_interface *obs) {
    observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
}

void task_notifier::notify() {
    for (const auto& observer : observers) {
        if (observer) {
            observer->update();
        }
    }
}

int task_notifier::how_many_observer() const {
    return static_cast<int>(observers.size());
}
