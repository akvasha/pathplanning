//
// Created by akvasha on 05.12.18.
//

#include "ClosedCellsContainer.h"

std::size_t ClosedCellsContainer::size() {
    return nodes.size();
}

void ClosedCellsContainer::insert(Node node) {
    nodes[CellCoords(node)] = node;
}

bool ClosedCellsContainer::consist(int i, int j) {
    return nodes.find(CellCoords(i, j)) != nodes.end();
}

Node* ClosedCellsContainer::get(Node node) {
    return &nodes[CellCoords(node)];
}

std::unordered_map<CellCoords, Node, CellCoords::hasher> ClosedCellsContainer::get_nodes() const {
    return nodes;
}