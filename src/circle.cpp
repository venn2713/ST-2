// Copyright 2025 VasilevSA
#include "circle.h"
#include <cmath>

Circle::Circle(double r) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    radius = r;
    ference = 2 * PI * r;
    area = PI * r * r;
}

void Circle::setFerence(double f) {
    ference = f;
    radius = f / (2 * PI);
    area = PI * radius * radius;
}

void Circle::setArea(double a) {
    area = a;
    radius = std::sqrt(a / PI);
    ference = 2 * PI * radius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}
