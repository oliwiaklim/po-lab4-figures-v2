#include "quadrilateral.h"
#include <sstream>
#include <array>
#include <cmath>

Quadrilateral::Quadrilateral()
    : a(0,0), b(0,0), c(0,0), d(0,0) {}

Quadrilateral::Quadrilateral(Point a_, Point b_, Point c_, Point d_)
    : a(a_), b(b_), c(c_), d(d_) {}

Quadrilateral::Quadrilateral(const Quadrilateral& other)
    : a(other.a), b(other.b), c(other.c), d(other.d) {}

bool Quadrilateral::equals(const Quadrilateral& other) const {
    // porównanie zbioru 4 wierzchołków bez względu na kolejność
    std::array<Point,4> s1{a,b,c,d};
    std::array<Point,4> s2{other.getA(), other.getB(), other.getC(), other.getD()};

    bool used[4] = {false,false,false,false};
    for (int i=0;i<4;++i) {
        bool found=false;
        for (int j=0;j<4;++j) {
            if (!used[j] && s1[i].equals(s2[j])) {
                used[j]=true; found=true; break;
            }
        }
        if (!found) return false;
    }
    return true;
}

void Quadrilateral::flip() {
    a.flip(); b.flip(); c.flip(); d.flip();
}

void Quadrilateral::move(double dx, double dy) {
    a.move(dx, dy);
    b.move(dx, dy);
    c.move(dx, dy);
    d.move(dx, dy);
}

double Quadrilateral::getSurface() const {
    // Shoelace (Gauss) – zakładamy kolejność wierzchołków jak w konstruktorze
    const double x[] = {a.getX(), b.getX(), c.getX(), d.getX(), a.getX()};
    const double y[] = {a.getY(), b.getY(), c.getY(), d.getY(), a.getY()};
    double s = 0.0;
    for (int i=0; i<4; ++i) s += x[i]*y[i+1] - y[i]*x[i+1];
    return std::abs(s) * 0.5;
}

std::string Quadrilateral::toString() const {
    std::ostringstream os;
    os << "Quadrilateral(" << a.toString() << ", " << b.toString()
       << ", " << c.toString() << ", " << d.toString() << ")";
    return os.str();
}