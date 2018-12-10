//
// Created by akvasha on 05.12.18.
//

#ifndef PATHPLANNING_CELLCOORDS_H
#define PATHPLANNING_CELLCOORDS_H

#include <pthread.h>
#include <cstddef>
#include "node.h"

class CellCoords {
public:
    int i, j;

    CellCoords() : i(0), j(0) {}

    CellCoords(int i, int j) : i(i), j(j) {}

    CellCoords(const Node &node) : i(node.i), j(node.j) {}

    class hasher {
    public:
        std::size_t operator () (const CellCoords &obj) const {
            return static_cast<std::size_t>(obj.i) | ((static_cast<std::size_t>(obj.j)) << 32);
        }
    };

    bool operator == (const CellCoords &other) const {
        return i == other.i && j == other.j;
    }

    bool operator < (const CellCoords &other) const {
        return i < other.i || (i == other.i && j < other.j);
    }
};

#endif //PATHPLANNING_CELLCOORDS_H
