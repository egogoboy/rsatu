#ifndef TDATLININT_H
#define TDATLININT_H

#include "MyException.h"
#include "TDat.h"
#include <iostream>

class TDatLinInt : public TDat {

    public:

        using TDat::TDat;

        double getY(double x) override {
            try{
                int res = TDat::getY(x);
                return res;
            } catch (MyException e) {
            for (int i = 0; i < points_.size(); i++) {
                if (points_[i].x > x) {
                    if (i == 0 || i == points_.size() - 1) {
                        throw MyException("TDatLinInt::getY: невозможно вычислить");
                    }

                    double k = (points_[i - 1].y - points_[i].y) / (points_[i - 1].x - points_[i].x);
                    double b = points_[i].y - points_[i].x * k;
                    
                    return k * x + b;
                }
            }
            // сюда дойти не должно
            return 0;
            }
        }

};

#endif // TDATLININT_H
