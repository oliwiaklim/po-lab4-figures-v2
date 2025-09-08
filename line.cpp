

#include "line.h"
#include <sstream>

Line::Line() : a(0,0), b(0,0) {}
Line::Line(Point a_, Point b_) : a(a_), b(b_) {}
Line::Line(const Line& other) : a(other.a), b(other.b) {}

bool Line::equals(const Line& other) const {
    // równość odcinków niezależnie od kolejności końców
    bool sameOrder  = a.equals(other.getA()) && b.equals(other.getB());
    bool swapOrder  = a.equals(other.getB()) && b.equals(other.getA());
    return sameOrder || swapOrder;
}

void Line::flip() {
    a.flip();
    b.flip();
}

void Line::move(double dx, double dy) {
    a.move(dx, dy);
    b.move(dx, dy);
}

std::string Line::toString() const {
    std::ostringstream os;
    os << "Line(" << a.toString() << ", " << b.toString() << ")";
    return os.str();
}

