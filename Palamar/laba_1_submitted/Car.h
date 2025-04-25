#pragma once

#include "Owner.h"
#include "Engine.h"
#include "Wheel.h"
#include <vector>
#include <memory>

class Car {
public:
    Car (const std::shared_ptr<Owner> owner, 
         const Engine& engine, 
         const std::vector<Wheel>& wheels): owner_{owner}, 
                                           engine_{engine},
                                           wheels_{wheels} {
        ++count_of_car_;
    }

    virtual ~Car() {}

    virtual std::string owner_info() {
        return owner_->GetName();
    }

    virtual int count_info() const {
        return count_of_car_;
    }

private:
    const std::shared_ptr<Owner> owner_;
    Engine engine_;
    std::vector<Wheel> wheels_;
    
    static inline int count_of_car_ = 0;

};
