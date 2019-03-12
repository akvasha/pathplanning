//
// Created by akvasha on 11.03.19.
//

#ifndef PATHPLANNING_THETA_H
#define PATHPLANNING_THETA_H

#include "astar.h"

class ThetaStar : public Astar {
public:
    ThetaStar(double hweight, bool breakingties) : Astar(hweight, breakingties) {}

    double dist(Node &node1, Node &node2);
    Node resetParent(Node current, Node parent, const Map &map, const EnvironmentOptions &options);
    bool can_see(int i1, int i2, int j1, int j2, const Map &map, bool cutcorners);
    void makePrimaryPath(Node node);
    void makeSecondaryPath();
};

#endif //PATHPLANNING_THETA_H
