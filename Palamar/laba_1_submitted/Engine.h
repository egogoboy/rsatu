#pragma once


class Engine {
public:
    Engine(float volume, 
           float power): volume_{volume}, 
                         power_{power} {}

    float GetVolume() const {
        return volume_;
    }

    float GetPower() const {
        return power_;
    }

private:
    float volume_;
    float power_;
};
