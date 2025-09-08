#pragma once
#include <vector>
#include <string>
#include "figure.h"

class Group {
    std::vector<Figure*> figures;    // grupa posiada własne kopie figur

public:
    Group();
    Group(const Group& other);
    Group& operator=(const Group& other);
    ~Group();

    bool equals(const Group& other) const;

    void add(Figure* figure);       
    void remove(Figure* figure);     

    double getSurface() const;
    void flip();
    void move(double x, double y);

    std::string toString() const;

    const std::vector<Figure*>& getFigures() const { return figures; }
};
