#include "shapes.h"

#include <cmath>

Rectangle::Rectangle(double height, double width)
    : _height(height), _width(width) {}

double Rectangle::area() const { return _height * _width; }

double Rectangle::perimeter() const { return 2 * (_height + _width); }

double Rectangle::height() const { return _height; }

double Rectangle::width() const { return _width; }

void Rectangle::rotate() { std::swap(_height, _width); }

Square::Square(double side) : Rectangle(side, side) {}

void Square::rotate() {
    // No effect on rotating a square
}

Circle::Circle(double radius) : _radius(radius) {}

double Circle::area() const { return M_PI * _radius * _radius; }

double Circle::perimeter() const { return 2 * M_PI * _radius; }

double Circle::height() const { return 2 * _radius; }

double Circle::width() const { return 2 * _radius; }

void Circle::rotate() {
    // No effect on rotating a circle
}
