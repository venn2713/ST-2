#ifndef TASKS_H
#define TASKS_H

struct PoolCosts {
    double roadCost;
    double fenceCost;
};

double calculateRopeGap(double earthRadiusKm, double extraLengthMeters);

PoolCosts calculatePoolCosts(double poolRadius, double roadWidth, double concreteCostPerSquareMeter, double fenceCostPerMeter);

#endif // TASKS_H
