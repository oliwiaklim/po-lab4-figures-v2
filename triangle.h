#pragma once
#include <string>
#include "point.h"
#include "figure.h"

class Triangle : public Figure {
    Point a;
    Point b;
    Point c;

public:
    Triangle();
    Triangle(Point a, Point b, Point c);
    Triangle(const Triangle& other);

    // specyficzne
    bool equals(const Triangle& other) const;
    Point getA() const { return a; }
    Point getB() const { return b; }
    Point getC() const { return c; }

    // Figure:
    // dokładnie wg wzorca z treści zadania (dynamic_cast)
    bool equals(const Figure* other) const override {
        const Triangle* otherTriangle = dynamic_cast<const Triangle*>(other);
        if (otherTriangle == nullptr) return false;
        return equals(*otherTriangle);
    }
    void flip() override;
    void move(double x, double y) override;
    double getSurface() const override;  // Heron – masz już gotowe
    std::string toString() const override;
    Figure* clone() const override { return new Triangle(*this); }
};
