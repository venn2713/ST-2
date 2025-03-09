// Copyright 2025 VasilevSA
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_


class Circle {
private:
    double radius;
    double ference;
    double area;
    static constexpr double PI = 3.14159265358979323846;
public:
    Circle(double r);

    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;
};

#endif // INCLUDE_CIRCLE_H_
