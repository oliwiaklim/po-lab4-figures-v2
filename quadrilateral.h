#pragma once
#include <string>
#include "point.h"
#include "figure.h"

class Quadrilateral : public Figure {
    Point a, b, c, d;

public:
    Quadrilateral();
    Quadrilateral(Point a, Point b, Point c, Point d);
    Quadrilateral(const Quadrilateral& other);

    // specyficzne
    bool equals(const Quadrilateral& other) const;
    Point getA() const { return a; }
    Point getB() const { return b; }
    Point getC() const { return c; }
    Point getD() const { return d; }

    // Figure:
    bool equals(const Figure* other) const override {
        auto o = dynamic_cast<const Quadrilateral*>(other);
        return o && equals(*o);
    }
    void flip() override;
    void move(double x, double y) override;
    double getSurface() const override;  // Shoelace – masz już gotowe
    std::string toString() const override;
    Figure* clone() const override { return new Quadrilateral(*this); }
};
