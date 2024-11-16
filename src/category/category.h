#ifndef CATEGORY_H
#define CATEGORY_H

#include "pch.h"

class category {
    std::string name_category;

public:
    category() = default;

    explicit category(std::string name_category);

    category(const category &other) = default;

    category(category &&other) noexcept = default;

    category& operator=(const category& other) = default;

    category &operator=(category &&other) noexcept = default;

    bool operator<(const category &other) const;

    bool operator>(const category &other) const;

    bool operator==(const category &other) const;

    [[nodiscard]] std::string get_category() const;

    void set_category(const std::string &name_category);
};

template<>
struct std::hash<category> {
    std::size_t operator()(const category &cat) const noexcept {
        return std::hash<std::string>{}(cat.get_category());
    }
};

#endif //CATEGORY_H
