//
// Created by akvasha on 05.12.18.
//

#ifndef PATHPLANNING_OPENCELLSCONTAINER_H
#define PATHPLANNING_OPENCELLSCONTAINER_H

#include <cstddef>
#include <unordered_map>
#include <set>
#include "node.h"
#include "CellCoords.h"

class OpenCellsContainer {
public:
    OpenCellsContainer() {}

    void insert(Node node);
    bool consist(Node node);
    void erase(Node node);
    std::size_t size() const;
    bool empty() const;
    Node min_element() const;
    void recalc(Node node);
    std::unordered_map<CellCoords, Node, CellCoords::hasher> get_nodes() const;
    void setBreakingTies(bool breakingties);
    double getG(double g);

private:
    std::unordered_map<CellCoords, Node, CellCoords::hasher> nodes;
    std::set<std::pair<std::pair<double, double>, CellCoords>> min_value;
    bool breakties;
};

#endif //PATHPLANNING_OPENCELLSCONTAINER_H
