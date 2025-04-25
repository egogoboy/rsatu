#pragma once

#include "Car.h"
#include <memory>

class Truck: public Car {
public: 
    Truck(const std::shared_ptr<Owner> owner, 
          const Engine& engine, 
          const std::vector<Wheel>& wheels, 
          float capacity): Car(owner, engine, wheels), 
                           capacity_{capacity} {}

    float GetCapacity() const {
        return capacity_;
    }

    void SetCapacity(float capacity) {
        capacity_ = capacity;
    }

private:
    float capacity_;
};
