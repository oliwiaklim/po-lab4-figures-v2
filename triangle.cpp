#include "triangle.h"
#include <cmath>
#include <sstream>
#include <array>

static double dist(const Point& p, const Point& q) {
    double dx = p.getX() - q.getX();
    double dy = p.getY() - q.getY();
    return std::sqrt(dx*dx + dy*dy);
}

Triangle::Triangle() : a(0,0), b(0,0), c(0,0) {}
Triangle::Triangle(Point a_, Point b_, Point c_) : a(a_), b(b_), c(c_) {}
Triangle::Triangle(const Triangle& other) : a(other.a), b(other.b), c(other.c) {}

bool Triangle::equals(const Triangle& other) const {
    // porównanie zbioru wierzchołków (bez względu na kolejność)
    std::array<Point,3> s1{a,b,c};
    std::array<Point,3> s2{other.getA(), other.getB(), other.getC()};

    bool used[3] = {false,false,false};
    for (int i=0;i<3;++i) {
        bool found=false;
        for (int j=0;j<3;++j) {
            if (!used[j] && s1[i].equals(s2[j])) {
                used[j]=true; found=true; break;
            }
        }
        if (!found) return false;
    }
    return true;
}

void Triangle::flip() {
    a.flip(); b.flip(); c.flip();
}

void Triangle::move(double dx, double dy) {
    a.move(dx, dy);
    b.move(dx, dy);
    c.move(dx, dy);
}

double Triangle::getSurface() const {
    // Heron
    double ab = dist(a,b);
    double bc = dist(b,c);
    double ca = dist(c,a);
    double s  = (ab+bc+ca)/2.0;
    return std::sqrt(std::max(0.0, s*(s-ab)*(s-bc)*(s-ca)));
}

std::string Triangle::toString() const {
    std::ostringstream os;
    os << "Triangle(" << a.toString() << ", " << b.toString()
       << ", " << c.toString() << ")";
    return os.str();
}