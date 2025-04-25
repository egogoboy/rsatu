#pragma once

#include "Car.h"
#include <memory>

class PassengerCar: public Car {
public:
    PassengerCar(const std::shared_ptr<Owner> owner, 
                 const Engine& engine, 
                 const std::vector<Wheel>& wheels, 
                 int count_of_passenger): Car(owner, engine, wheels), 
                                          count_of_passenger_(count_of_passenger) {}

    int GetCountOfPassengers() const {
        return count_of_passenger_;
    }

    void SetCountOfPassengers(int new_count) {
        count_of_passenger_ = new_count;
    }

private:
    int count_of_passenger_;

};
