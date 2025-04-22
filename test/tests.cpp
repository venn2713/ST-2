// Copyright 2025 VasilevSA

#include "tasks.h"
#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"

const double PI = 3.14159265358979323846;
const double TOL = 1e-6;

TEST(CircleTest, Constructor) {
    Circle c(1.0);
    EXPECT_NEAR(c.getRadius(), 1.0, TOL);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1.0, TOL);
    EXPECT_NEAR(c.getArea(), PI * 1.0, TOL);
}

TEST(CircleTest, SetRadius) {
    Circle c(0.0);
    c.setRadius(2.0);
    EXPECT_NEAR(c.getRadius(), 2.0, TOL);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 2.0, TOL);
    EXPECT_NEAR(c.getArea(), PI * 4.0, TOL);
}

TEST(CircleTest, SetFerence) {
    Circle c(1.0);
    double nf = 2 * PI * 3.0;
    c.setFerence(nf);
    EXPECT_NEAR(c.getRadius(), 3.0, TOL);
    EXPECT_NEAR(c.getFerence(), nf, TOL);
    EXPECT_NEAR(c.getArea(), PI * 9.0, TOL);
}

TEST(CircleTest, SetArea) {
    Circle c(1.0);
    double na = PI * 16.0;
    c.setArea(na);
    EXPECT_NEAR(c.getRadius(), 4.0, TOL);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 4.0, TOL);
    EXPECT_NEAR(c.getArea(), na, TOL);
}

TEST(CircleTest, AreaFerenceRelation) {
    Circle c(5.0);
    double ca = (c.getFerence() * c.getFerence()) / (4 * PI);
    EXPECT_NEAR(c.getArea(), ca, TOL);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, TOL);
    EXPECT_NEAR(c.getFerence(), 0.0, TOL);
    EXPECT_NEAR(c.getArea(), 0.0, TOL);
}

TEST(CircleTest, NonIntegerFerence) {
    Circle c(2.0);
    double nf = 13.5;
    c.setFerence(nf);
    double er = nf / (2 * PI);
    EXPECT_NEAR(c.getRadius(), er, TOL);
    EXPECT_NEAR(c.getArea(), PI * er * er, TOL);
}

TEST(CircleTest, NonIntegerArea) {
    Circle c(2.0);
    double na = 20.0;
    c.setArea(na);
    double er = std::sqrt(na / PI);
    EXPECT_NEAR(c.getRadius(), er, TOL);
    EXPECT_NEAR(c.getFerence(), 2 * PI * er, TOL);
}

TEST(TasksTest, EarthRopeGap) {
    double er = 6378.1;
    double el = 1.0;
    double g = calculateRopeGap(er, el);
    double eg = el / (2 * PI);
    EXPECT_NEAR(g, eg, TOL);
}

TEST(TasksTest, PoolCosts) {
    double pr = 3.0;
    double rw = 1.0;
    double cc = 1000.0;
    double fc = 2000.0;
    PoolCosts c = calculatePoolCosts(pr, rw, cc, fc);
    double orad = pr + rw;
    double ra = PI * (orad * orad - pr * pr);
    double erc = ra * cc;
    double efc = (2 * PI * orad) * fc;
    EXPECT_NEAR(c.roadCost, erc, TOL);
    EXPECT_NEAR(c.fenceCost, efc, TOL);
}

TEST(CircleTest, SequentialSetters) {
    Circle c(1.0);
    c.setRadius(3.0);
    c.setFerence(2 * PI * 2.0);
    c.setArea(PI * 9.0);
    EXPECT_NEAR(c.getRadius(), 3.0, TOL);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 3.0, TOL);
    EXPECT_NEAR(c.getArea(), PI * 9.0, TOL);
}

TEST(CircleTest, RepeatedGetters) {
    Circle c(4.0);
    double r1 = c.getRadius();
    double r2 = c.getRadius();
    EXPECT_NEAR(r1, r2, TOL);
}

TEST(CircleTest, RadiusFive) {
    Circle c(5.0);
    EXPECT_NEAR(c.getArea(), PI * 25.0, TOL);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 5.0, TOL);
}

TEST(CircleTest, RadiusTen) {
    Circle c(10.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 10.0, TOL);
}

TEST(CircleTest, ZeroArea) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_NEAR(c.getArea(), 0.0, TOL);
    EXPECT_NEAR(c.getRadius(), 0.0, TOL);
    EXPECT_NEAR(c.getFerence(), 0.0, TOL);
}

TEST(CircleTest, NegativeArea) {
    Circle c(5.0);
    c.setArea(-10.0);
    EXPECT_TRUE(std::isnan(c.getRadius()) || std::isnan(c.getFerence()));
    EXPECT_NEAR(c.getArea(), -10.0, TOL);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_NEAR(c.getRadius(), 1e6, TOL);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1e6, TOL);
    EXPECT_NEAR(c.getArea(), PI * 1e6 * 1e6, TOL);
}

TEST(CircleTest, ResetRadius) {
    Circle c(5.0);
    c.setRadius(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, TOL);
    EXPECT_NEAR(c.getFerence(), 0.0, TOL);
    EXPECT_NEAR(c.getArea(), 0.0, TOL);
}

TEST(CircleTest, CompareTwoCircles) {
    Circle c1(3.0);
    Circle c2(5.0);
    EXPECT_TRUE(
        c2.getArea() > c1.getArea() ||
        c2.getFerence() > c1.getFerence());
}

TEST(CircleTest, FractionalRadius) {
    Circle c(0.5);
    EXPECT_NEAR(c.getRadius(), 0.5, TOL);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 0.5, TOL);
    EXPECT_NEAR(c.getArea(), PI * 0.5 * 0.5, TOL);
}

TEST(TasksTest, ZeroEarthRopeGap) {
    double er = 6378.1;
    double el = 0.0;
    double g = calculateRopeGap(er, el);
    EXPECT_NEAR(g, 0.0, TOL);
}

TEST(CircleTest, RadiusAfterMultipleUpdates) {
    Circle c(2.0);
    c.setRadius(4.0);
    c.setFerence(2 * PI * 6.0);
    c.setArea(PI * 16.0);
    EXPECT_NEAR(c.getRadius(), 4.0, TOL);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 4.0, TOL);
    EXPECT_NEAR(c.getArea(), PI * 16.0, TOL);
}

TEST(CircleTest, VerySmallRadius) {
    Circle c(1e-9);
    EXPECT_NEAR(c.getRadius(), 1e-9, TOL);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1e-9, TOL);
    EXPECT_NEAR(c.getArea(), PI * 1e-9 * 1e-9, TOL);
}

TEST(TasksTest, HighPoolCosts) {
    double pr = 50.0;
    double rw = 10.0;
    double cc = 5000.0;
    double fc = 3000.0;
    PoolCosts c = calculatePoolCosts(pr, rw, cc, fc);
    double orad = pr + rw;
    double ra = PI * (orad * orad - pr * pr);
    double erc = ra * cc;
    double efc = (2 * PI * orad) * fc;
    EXPECT_NEAR(c.roadCost, erc, TOL);
    EXPECT_NEAR(c.fenceCost, efc, TOL);
}
