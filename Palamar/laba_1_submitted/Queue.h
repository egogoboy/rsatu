#pragma once

#include <cstdio>
#include <fstream>
#include <memory>
#include <queue>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <sstream>
#include <vector>
#include "Car.h"
#include "PassengerCar.h"
#include "Truck.h"

class Queue {
public:

    Queue (const std::string& input_file) {
        std::ifstream fin(input_file);
        if (!fin.is_open()) {
            throw std::runtime_error("File " + input_file + " is not exist");
        }

        ReadData(fin);
    }

    ~Queue() {
        while (!Empty()) {
            Pop();
        }
    }
    
    void Push(std::shared_ptr<Car> car) {
        q_.push(std::move(car));
    }

    std::shared_ptr<Car> Front() const {
        return q_.front();
    }

    void Pop() {
        if (Empty()) {
            throw std::runtime_error("Queue is empty");
        }
        q_.pop();
    }

    bool Empty() const {
        return q_.empty();
    }

    size_t Size() const {
        return q_.size();
    }

private:
    void ReadData(std::ifstream& fin) {
        std::string data;
        while (std::getline(fin, data)) {
            q_.push(Parse(data));
        }
    }

    std::shared_ptr<Car> Parse(const std::string& data) {
        int i = 0;
        std::string surname, name, midname;
        float volume, power, last_param;
        int radius;
        std::istringstream iss(data);
        iss >> surname >> name >> midname >> volume >> power >> radius >> last_param;
        
        if (last_param == static_cast<int>(last_param)) {
            return std::make_shared<PassengerCar>(PassengerCar(std::make_shared<Owner>(surname + name + midname), 
                                    Engine(volume, power), 
                                    std::vector<Wheel>(4, radius), 
                                    last_param));
        }
        return std::make_shared<Truck>(Truck(std::make_shared<Owner>(surname + name + midname), 
                         Engine(volume, power), 
                         std::vector<Wheel>(4, radius), 
                         last_param));

    }

    std::queue<std::shared_ptr<Car>> q_;
};
