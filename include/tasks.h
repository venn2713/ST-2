// Copyright 2025 VasilevSA
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct PoolCosts {
    double roadCost;
    double fenceCost;
};

double calculateRopeGap(double earthRadiusKm, 
                        double extraLengthMeters);

PoolCosts calculatePoolCosts(double poolRadius, 
                             double roadWidth, 
                             double concreteCostPerSquareMeter, 
                             double fenceCostPerMeter);

#endif // INCLUDE_TASKS_H_
