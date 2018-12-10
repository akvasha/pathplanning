//
// Created by akvasha on 05.12.18.
//

#ifndef PATHPLANNING_CLOSEDCELLSCONTAINER_H
#define PATHPLANNING_CLOSEDCELLSCONTAINER_H

#include <unordered_map>
#include "node.h"
#include "CellCoords.h"

class ClosedCellsContainer {
public:
    ClosedCellsContainer() {}

    std::size_t size();

    void insert(Node node);
    bool consist(int i, int j);
    Node* get(Node node);

private:
    std::unordered_map<CellCoords, Node, CellCoords::hasher> nodes;
};

#endif //PATHPLANNING_CLOSEDCELLSCONTAINER_H