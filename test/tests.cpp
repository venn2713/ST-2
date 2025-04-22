#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"
#include <cmath>

const double PI = 3.14159265358979323846;
const double tol = 1e-6;

TEST(CircleTest, Constructor) {
    Circle c(1.0);
    EXPECT_NEAR(c.getRadius(), 1.0, tol);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1.0, tol);
    EXPECT_NEAR(c.getArea(), PI * 1.0, tol);
}

TEST(CircleTest, SetRadius) {
    Circle c(0.0);
    c.setRadius(2.0);
    EXPECT_NEAR(c.getRadius(), 2.0, tol);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 2.0, tol);
    EXPECT_NEAR(c.getArea(), PI * 4.0, tol);
}

TEST(CircleTest, SetFerence) {
    Circle c(1.0);
    double newFerence = 2 * PI * 3.0;
    c.setFerence(newFerence);
    EXPECT_NEAR(c.getRadius(), 3.0, tol);
    EXPECT_NEAR(c.getFerence(), newFerence, tol);
    EXPECT_NEAR(c.getArea(), PI * 9.0, tol);
}

TEST(CircleTest, SetArea) {
    Circle c(1.0);
    double newArea = PI * 16.0;
    c.setArea(newArea);
    EXPECT_NEAR(c.getRadius(), 4.0, tol);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 4.0, tol);
    EXPECT_NEAR(c.getArea(), newArea, tol);
}

TEST(CircleTest, AreaFerenceRelation) {
    Circle c(5.0);
    double calcArea = (c.getFerence() * c.getFerence()) / (4 * PI);
    EXPECT_NEAR(c.getArea(), calcArea, tol);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, tol);
    EXPECT_NEAR(c.getFerence(), 0.0, tol);
    EXPECT_NEAR(c.getArea(), 0.0, tol);
}

TEST(CircleTest, NonIntegerFerence) {
    Circle c(2.0);
    double newFerence = 13.5;
    c.setFerence(newFerence);
    double expectedRadius = newFerence / (2 * PI);
    EXPECT_NEAR(c.getRadius(), expectedRadius, tol);
    EXPECT_NEAR(c.getArea(), PI * expectedRadius * expectedRadius, tol);
}

TEST(CircleTest, NonIntegerArea) {
    Circle c(2.0);
    double newArea = 20.0;
    c.setArea(newArea);
    double expectedRadius = std::sqrt(newArea / PI);
    EXPECT_NEAR(c.getRadius(), expectedRadius, tol);
    EXPECT_NEAR(c.getFerence(), 2 * PI * expectedRadius, tol);
}

TEST(TasksTest, EarthRopeGap) {
    double earthRadiusKm = 6378.1;
    double extraLengthM = 1.0;
    double gap = calculateRopeGap(earthRadiusKm, extraLengthM);
    double expectedGap = extraLengthM / (2 * PI);
    EXPECT_NEAR(gap, expectedGap, tol);
}

TEST(TasksTest, PoolCosts) {
    double poolRadius = 3.0;
    double roadWidth = 1.0;
    double concreteCost = 1000.0;
    double fenceCostPerMeter = 2000.0;
    PoolCosts costs = calculatePoolCosts(poolRadius, roadWidth, concreteCost, fenceCostPerMeter);
    double outerRadius = poolRadius + roadWidth;
    double roadArea = PI * (outerRadius * outerRadius - poolRadius * poolRadius);
    double expectedRoadCost = roadArea * concreteCost;
    double expectedFenceCost = (2 * PI * outerRadius) * fenceCostPerMeter;
    EXPECT_NEAR(costs.roadCost, expectedRoadCost, tol);
    EXPECT_NEAR(costs.fenceCost, expectedFenceCost, tol);
}

TEST(CircleTest, SequentialSetters) {
    Circle c(1.0);
    c.setRadius(3.0);
    c.setFerence(2 * PI * 2.0);
    c.setArea(PI * 9.0);
    EXPECT_NEAR(c.getRadius(), 3.0, tol);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 3.0, tol);
    EXPECT_NEAR(c.getArea(), PI * 9.0, tol);
}

TEST(CircleTest, RepeatedGetters) {
    Circle c(4.0);
    double r1 = c.getRadius();
    double r2 = c.getRadius();
    EXPECT_NEAR(r1, r2, tol);
}

TEST(CircleTest, RadiusFive) {
    Circle c(5.0);
    EXPECT_NEAR(c.getArea(), PI * 25.0, tol);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 5.0, tol);
}

TEST(CircleTest, RadiusTen) {
    Circle c(10.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 10.0, tol);
}

TEST(CircleTest, ZeroArea) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_NEAR(c.getArea(), 0.0, tol);
    EXPECT_NEAR(c.getRadius(), 0.0, tol);
    EXPECT_NEAR(c.getFerence(), 0.0, tol);
}

TEST(CircleTest, NegativeArea) {
    Circle c(5.0);
    c.setArea(-10.0);
    EXPECT_TRUE(std::isnan(c.getRadius()));
    EXPECT_TRUE(std::isnan(c.getFerence()));
    EXPECT_NEAR(c.getArea(), -10.0, tol);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_NEAR(c.getRadius(), 1e6, tol);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1e6, tol);
    EXPECT_NEAR(c.getArea(), PI * 1e6 * 1e6, tol);
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-5.0);
    EXPECT_TRUE(std::isnan(c.getRadius()));
    EXPECT_TRUE(std::isnan(c.getFerence()));
    EXPECT_TRUE(std::isnan(c.getArea()));
}

TEST(CircleTest, ResetRadius) {
    Circle c(5.0);
    c.setRadius(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, tol);
    EXPECT_NEAR(c.getFerence(), 0.0, tol);
    EXPECT_NEAR(c.getArea(), 0.0, tol);
}

TEST(CircleTest, CompareTwoCircles) {
    Circle c1(3.0);
    Circle c2(5.0);
    EXPECT_GT(c2.getArea(), c1.getArea());
    EXPECT_GT(c2.getFerence(), c1.getFerence());
}

TEST(CircleTest, FractionalRadius) {
    Circle c(0.5);
    EXPECT_NEAR(c.getRadius(), 0.5, tol);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 0.5, tol);
    EXPECT_NEAR(c.getArea(), PI * 0.5 * 0.5, tol);
}

TEST(TasksTest, ZeroEarthRopeGap) {
    double earthRadiusKm = 6378.1;
    double extraLengthM = 0.0;
    double gap = calculateRopeGap(earthRadiusKm, extraLengthM);
    EXPECT_NEAR(gap, 0.0, tol);
}

TEST(TasksTest, NegativeEarthRopeGap) {
    double earthRadiusKm = 6378.1;
    double extraLengthM = -1.0;
    double gap = calculateRopeGap(earthRadiusKm, extraLengthM);
    EXPECT_TRUE(std::isnan(gap));
}

TEST(CircleTest, RadiusAfterMultipleUpdates) {
    Circle c(2.0);
    c.setRadius(4.0);
    c.setFerence(2 * PI * 6.0);
    c.setArea(PI * 16.0);
    EXPECT_NEAR(c.getRadius(), 4.0, tol);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 4.0, tol);
    EXPECT_NEAR(c.getArea(), PI * 16.0, tol);
}

TEST(CircleTest, VerySmallRadius) {
    Circle c(1e-9);
    EXPECT_NEAR(c.getRadius(), 1e-9, tol);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1e-9, tol);
    EXPECT_NEAR(c.getArea(), PI * 1e-9 * 1e-9, tol);
}

TEST(TasksTest, HighPoolCosts) {
    double poolRadius = 50.0;
    double roadWidth = 10.0;
    double concreteCost = 5000.0;
    double fenceCostPerMeter = 3000.0;
    PoolCosts costs = calculatePoolCosts(poolRadius, roadWidth, concreteCost, fenceCostPerMeter);
    double outerRadius = poolRadius + roadWidth;
    double roadArea = PI * (outerRadius * outerRadius - poolRadius * poolRadius);
    double expectedRoadCost = roadArea * concreteCost;
    double expectedFenceCost = (2 * PI * outerRadius) * fenceCostPerMeter;
    EXPECT_NEAR(costs.roadCost, expectedRoadCost, tol);
    EXPECT_NEAR(costs.fenceCost, expectedFenceCost, tol);
}

