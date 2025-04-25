#pragma once

class Wheel {
public:
    Wheel(int radius): radius_{radius} {}

    int GetRadius() const {
        return radius_;
    }

    void SetRadius(int radius) {
        radius_ = radius;
    }

private:
    int radius_;
};
