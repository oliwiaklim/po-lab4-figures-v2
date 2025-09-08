#include "group.h"
#include <sstream>

Group::Group() = default;

Group::Group(const Group& other) {
    figures.reserve(other.getFigures().size());
    for (const auto* f : other.getFigures()) figures.push_back(f->clone());
}

Group& Group::operator=(const Group& other) {
    if (this == &other) return *this;
    for (auto* f : figures) delete f;
    figures.clear();
    figures.reserve(other.getFigures().size());
    for (const auto* f : other.getFigures()) figures.push_back(f->clone());
    return *this;
}

Group::~Group() {
    for (auto* f : figures) delete f;
}

bool Group::equals(const Group& other) const {
    if (figures.size() != other.getFigures().size()) return false;
    // porównanie niezależne od kolejności
    std::vector<bool> used(other.getFigures().size(), false);
    for (const auto* f : figures) {
        bool found = false;
        for (std::size_t i = 0; i < other.getFigures().size(); ++i) {
            if (!used[i] && f->equals(other.getFigures()[i])) {
                used[i] = true; found = true; break;
            }
        }
        if (!found) return false;
    }
    return true;
}

void Group::add(Figure* figure) {
    figures.push_back(figure->clone());
}

void Group::remove(Figure* figure) {
    for (auto it = figures.begin(); it != figures.end(); ++it) {
        if ((*it)->equals(figure)) {
            delete *it;            
            figures.erase(it);
            return;
        }
    }
}

double Group::getSurface() const {
    double s = 0.0;
    for (const auto* f : figures) s += f->getSurface();
    return s;
}

void Group::flip() {
    for (auto* f : figures) f->flip();
}

void Group::move(double dx, double dy) {
    for (auto* f : figures) f->move(dx, dy);
}

std::string Group::toString() const {
    if (figures.empty()) return "Group()";
    std::ostringstream os;
    os << "Group(";
    for (const auto* f : figures) os << f->toString() << ", ";
    os << ")";
    return os.str();
}
