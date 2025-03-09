// Copyright 2025 VasilevSA
#include "tasks.h"
#include "circle.h"

double calculateRopeGap(double earthRadiusKm, double extraLengthMeters) {
    double extraLengthKm = extraLengthMeters / 1000.0;
    Circle earth(earthRadiusKm);
    double originalCircumference = earth.getFerence();
    double newCircumference = originalCircumference + extraLengthKm;
    earth.setFerence(newCircumference);
    double newRadiusKm = earth.getRadius();
    double gapKm = newRadiusKm - earthRadiusKm;
    return gapKm * 1000.0;
}

PoolCosts calculatePoolCosts(double poolRadius, double roadWidth, double concreteCostPerSquareMeter, double fenceCostPerMeter) {
    double outerRadius = poolRadius + roadWidth;
    Circle pool(poolRadius);
    double poolArea = pool.getArea();
    Circle outer(outerRadius);
    double outerArea = outer.getArea();
    double roadArea = outerArea - poolArea;
    double roadCost = roadArea * concreteCostPerSquareMeter;
    double fenceCost = outer.getFerence() * fenceCostPerMeter;
    return PoolCosts{roadCost, fenceCost};
}
