//
// Created by akvasha on 11.03.19.
//

#include "theta.h"

double ThetaStar::dist(Node &node1, Node &node2) {
    return sqrt((node1.i - node2.i) * (node1.i - node2.i) + (node1.j - node2.j) * (node1.j - node2.j));
}

Node ThetaStar::resetParent(Node current, Node parent, const Map &map, const EnvironmentOptions &options) {
    Node *node = parent.parent;
    if (node == nullptr || current == *node) {
        return current;
    }
    if (can_see(node->i, node->j, current.i, current.j, map, options.cutcorners)) {
        current.g = node->g + dist(*node, current);
        current.parent = node;
    }
    return current;
}

bool ThetaStar::can_see(int i1, int i2, int j1, int j2, const Map &map, bool cutcorners) {
    int deltaI = abs(i1 - i2);
    int deltaJ = abs(j1 - j2);
    int signI = i1 < i2 ? 1 : -1;
    int signJ = j1 < j2 ? 1 : -1;
    int error = 0;
    if (deltaI > deltaJ) {
        while (i1 != i2) {
            error += deltaJ;
            if (error >= deltaI) {
                if (map.CellIsTraversable(i1 + (signI - 1) / 2, j1 + (signJ - 1) / 2)) {
                    return false;
                }
                j1 += signJ;
                error -= deltaI;
            }
            if (error != 0 && map.CellIsTraversable(i1 + (signI - 1) / 2, j1 + (signJ - 1) / 2)) {
                return false;
            }
            if (deltaJ == 0 && map.CellIsTraversable(i1 + (signI - 1) / 2, j1) && map.CellIsTraversable(i1 + (signI - 1) / 2, j1 - 1)) {
                return false;
            }
            i1 += signI;
        }
    } else {
        while (j1 != j2) {
            error += deltaI;
            if (error >= deltaJ) {
                if (map.CellIsTraversable(i1 + (signI - 1) / 2, j1 + (signJ - 1) / 2)) {
                    return false;
                }
                i1 += signI;
                error -= deltaJ;
            }
            if (error != 0 && map.CellIsTraversable(i1 + (signI - 1) / 2, j1 + (signJ - 1) / 2)) {
                return false;
            }
            if (deltaI == 0 && map.CellIsTraversable(i1, j1 + (signJ - 1) / 2) && map.CellIsTraversable(i1 - 1, j1 + (signJ - 1) / 2)) {
                return false;
            }
            j1 += signJ;
        }
    }
    return true;
}

void ThetaStar::makePrimaryPath(Node node) {
    while (node.parent != nullptr) {
        hppath.push_front(node);
        node = *node.parent;
    }
    hppath.push_front(node);
}

void ThetaStar::makeSecondaryPath() {
    return;
}