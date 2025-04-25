#include <iostream>
#include <memory>
#include <string>
#include "Queue.h"

int main() {
    std::cout << "Laba 1\n";
    std::cout << "Enter input file: ";
    std::string input_file;
    std::cin >> input_file;

    Queue queue(input_file);
    std::cout << "Queue was initialized from file " << input_file << std::endl;

    int all_passengers = 0;
    float all_weight = 0;

    int i = 0;
    while (!queue.Empty()) {
        std::shared_ptr<Car> car = queue.Front();
        queue.Pop();
        
        if (std::shared_ptr<PassengerCar> temp = std::dynamic_pointer_cast<PassengerCar>(car)) {
            all_passengers += temp->GetCountOfPassengers();
        } else if (std::shared_ptr<Truck> temp = std::dynamic_pointer_cast<Truck>(car)) {
            all_weight += temp->GetCapacity();
        }
    }

    std::cout << "Passengers number: " << all_passengers << std::endl;
    std::cout << "All weight of trucks: " << all_weight << std::endl;

    return 0;
}
