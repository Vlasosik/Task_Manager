#include "category.h"

category::category(std::string name_category) : name_category(std::move(name_category)) {

}

bool category::operator<(const category &other) const {
    return this->name_category < other.name_category;
}

bool category::operator>(const category &other) const {
    return this->name_category > other.name_category;
}

bool category::operator==(const category &other) const {
    return this->name_category == other.get_category();
}

std::string category::get_category() const {
    return this->name_category;
}

void category::set_category(const std::string &name_category) {
    this->name_category = name_category;
}