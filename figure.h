#pragma once
#include <string>

class Figure {
public:
    virtual ~Figure() = default;

    // porównanie „po figurze” (typ + zawartość)
    virtual bool equals(const Figure* other) const = 0;

    // transformacje
    virtual void flip() = 0;
    virtual void move(double dx, double dy) = 0;

    // dane opisowe
    virtual double getSurface() const = 0;     // dla linii 0
    virtual std::string toString() const = 0;

    // potrzebne do kopiowania (Group – kopia głęboka)
    virtual Figure* clone() const = 0;
};
