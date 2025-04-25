#pragma once

#include <string>

class Owner {
public:
    explicit Owner(const std::string& name): name_{name} {}

    std::string GetName() const {
        return name_;
    }

    void SetName(const std::string& name) {
        name_ = name;
    }

private:
    std::string name_;
};
