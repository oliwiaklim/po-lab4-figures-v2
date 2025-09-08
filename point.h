

#pragma once
#include <string>

class Point {
    double x;
    double y;

public:
    Point(double x = 0.0, double y = 0.0);
    Point(const Point& other);

    bool   equals(const Point& other) const;
    double getX() const;
    double getY() const;

    // flip: odbicie względem (0,0)
    void flip();

    // move(x, y): przesunięcie o wektor (x, y)
    void move(double x, double y);

    std::string toString() const;
};