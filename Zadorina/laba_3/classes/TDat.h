#ifndef TDAT_H
#define TDAT_H

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

#include "MyException.h"

class TDat {

    public:
        TDat() {};

        TDat(std::string filename) {
            std::ifstream fin(filename);
            
            if (fin.is_open()) {
                do {
                    Point_ inputPoint;
                    fin >> inputPoint.x >> inputPoint.y;
                    points_.push_back(inputPoint);
                } while (!fin.eof());

                fin.close();
                points_.resize(points_.size() - 1);
                std::sort(points_.begin(), points_.end(),
                                [] (auto& lhs, auto& rhs) { return lhs.x < rhs.x; });
            }
            else {
                throw MyException("TDat::TDat: Не существует файла с таким именем");
            }

        }

        ~TDat() {
            std::ofstream fout(OUTPUT_FILE_NAME);
            for (auto i : points_)
                fout << i.x << " " << i.y << "\n";
            fout.close();
        }

        virtual double getY(double x) {
            if (x >= 0 && x < points_.size()) {
                for (int i = 0; i < points_.size(); i++) {
                    if (points_[i].x == x) {
                        return points_[i].y;
                    }
                }
                throw MyException("TDat::getY: нет такого x");
            }
            else {
                throw MyException("TDat::getY: out of range");
            }
        }

        void addPoint(double x, double y) {
            points_.push_back({x, y});
            std::sort(points_.begin(), points_.end(),
                                [] (auto& lhs, auto& rhs) { return lhs.x < rhs.x; });
        }

        void deleteAllPoint() {
            points_.clear();
        }

    private:

        static inline const std::string OUTPUT_FILE_NAME = "output.txt";

    protected:

        
        struct Point_ {
            double x;
            double y;
        };


        std::vector<Point_> points_;
};

#endif // TDAT_H
