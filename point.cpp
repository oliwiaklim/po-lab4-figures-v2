

#include "point.h"
#include <sstream>
#include <iomanip>

Point::Point(double x_, double y_) : x(x_), y(y_) {}
Point::Point(const Point& other) : x(other.x), y(other.y) {}

bool Point::equals(const Point& other) const {
    return x == other.x && y == other.y;
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

void Point::flip() {
    x = -x;
    y = -y;
}

void Point::move(double dx, double dy) {
    x += dx;
    y += dy;
}

std::string Point::toString() const {
    std::ostringstream os;
    os << "Point(" << std::fixed << std::setprecision(1) << x << ", " << y << ")";
    return os.str();
}