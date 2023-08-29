#include "vector2d.h"

#include <cmath>

v2d::v2d(double a, double b) : x(a), y(b) {
    // Constructor implementation
}

v2d::v2d(const v2d &v) : x(v.x), y(v.y) {
    // Copy constructor implementation
}

v2d::~v2d() {
    // Destructor implementation (no need for additional actions)
}

v2d &v2d::operator=(const v2d &v) {
    if (this != &v) {  // Avoid self-assignment
        x = v.x;
        y = v.y;
    }
    return *this;
}

v2d &v2d::operator+(const v2d &v) {
    x += v.x;
    y += v.y;
    return *this;
}

double v2d::operator*(const v2d &v) { return x * v.x + y * v.y; }

v2d &v2d::operator*(double k) {
    x *= k;
    y *= k;
    return *this;
}

double v2d::length() { return std::sqrt(x * x + y * y); }
