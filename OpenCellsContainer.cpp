//
// Created by akvasha on 05.12.18.
//

#include "OpenCellsContainer.h"

void OpenCellsContainer::insert(Node node) {
    nodes[CellCoords(node)] = node;
    min_value.insert(std::make_pair(std::make_pair(node.F, node.g), CellCoords(node)));
}

bool OpenCellsContainer::consist(Node node) {
    return nodes.count(CellCoords(node)) != 0;
}

void OpenCellsContainer::erase(Node node) {
    if (consist(node)) {
        CellCoords nd = CellCoords(node);
        Node _node = nodes[nd];
        min_value.erase(std::make_pair(std::make_pair(_node.F, _node.g), nd));
        nodes.erase(nd);
    }
}

std::size_t OpenCellsContainer::size() const {
    return nodes.size();
}

bool OpenCellsContainer::empty() const {
    return nodes.empty();
}

Node OpenCellsContainer::min_element() const {
    return nodes.at(min_value.begin()->second);
}

void OpenCellsContainer::recalc(Node node) {
    CellCoords nd = CellCoords(node);
    if (consist(node)) {;
        Node previous = nodes[nd];
        if (previous.F < node.F || (previous.F == node.F && previous.g < node.g)) {
            return;
        }
        erase(previous);
    }
    insert(node);
}

