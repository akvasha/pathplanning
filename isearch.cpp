#include <cassert>
#include <memory>
#include "isearch.h"

ISearch::ISearch()
{
    hweight = 1;
    breakingties = CN_SP_BT_GMAX;
}

ISearch::~ISearch(void) {}


SearchResult ISearch::startSearch(ILogger *Logger, const Map &map, const EnvironmentOptions &options)
{
    std::chrono::time_point<std::chrono::system_clock> stime, etime;
    stime = std::chrono::system_clock::now();
    sresult.pathfound = false;
    Node startNode = Node(map.getStart());
    Node goalNode = Node(map.getGoal());
    startNode.H = computeHFromCellToCell(startNode.i, startNode.j, goalNode.i, goalNode.j, options);
    startNode.F = startNode.H * hweight;
    startNode.g = 0;
    Node currNode;
    open.insert(startNode);
    while (!open.empty()) {
        currNode = open.min_element();
        open.erase(currNode);
        close.insert(currNode);
        Node* par = close.get(currNode);
        if (currNode == goalNode) {
            sresult.pathfound = true;
            break;
        }
        std::list<Node> successors = findSuccessors(par, map, options);
        for (auto successor : successors) {
            open.recalc(successor);
        }
        Logger->writeToLogOpenClose(open, close, false);
    }
    Logger->writeToLogOpenClose(open, close, true);
    if (sresult.pathfound) {
        sresult.pathlength = static_cast<float>(currNode.g);
        makePrimaryPath(currNode);
        etime = std::chrono::system_clock::now();
        sresult.time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(etime - stime).count()) / 1000; //counted in seconds
        makeSecondaryPath();
    }
    sresult.nodescreated = static_cast<unsigned int>(open.size() + close.size());
    sresult.numberofsteps = static_cast<unsigned int>(close.size());
    sresult.hppath = &hppath; //Here is a constant pointer
    sresult.lppath = &lppath;
    return sresult;
}

std::list<Node> ISearch::findSuccessors(Node* curNode, const Map &map, const EnvironmentOptions &options)
{
    std::list<Node> successors;
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            if (di == 0 && dj == 0) {
                continue;
            }
            int go_i = curNode->i + di;
            int go_j = curNode->j + dj;
            if (!map.CellOnGrid(go_i,go_j)) {
                continue;
            }
            if (!map.CellIsTraversable(go_i, go_j)) {
                continue;
            }
            if (di != 0 && dj != 0) {
                if (!options.allowdiagonal) {
                    continue;
                } else {
                    bool v1 = map.CellIsObstacle(curNode->i, go_j);
                    bool v2 = map.CellIsObstacle(go_i, curNode->j);
                    if (!options.cutcorners) {
                        if (v1 || v2) {
                            continue;
                        }
                    } else if (!options.allowsqueeze){
                        if (v1 && v2) {
                            continue;
                        }
                    }
                }
            }
            if (close.consist(go_i, go_j)) {
                continue;
            }
            Node successor(go_i, go_j);
            if (di == 0 || dj == 0) {
                successor.g = curNode->g + 1;
            } else {
                successor.g = curNode->g + std::sqrt(2);
            }
            Node goalNode = map.getGoal();
            successor.H = computeHFromCellToCell(successor.i, successor.j, goalNode.i, goalNode.j, options);
            successor.F = successor.H * hweight + successor.g;
            successor.parent = curNode;
            successors.push_back(successor);
        }
    }
    return successors;
}

void ISearch::makePrimaryPath(Node curNode)
{
    for (Node *currNode = &curNode; currNode != nullptr; currNode = currNode->parent) {
        lppath.push_front(*currNode);
    }

}

void ISearch::makeSecondaryPath()
{
    int vx = 7, vy = 7;
    int vdx, vdy;
    Node previous;
    for (Node vertex : lppath) {
        vdx = vertex.i - previous.i;
        vdy = vertex.j - previous.j;
        if (!(vdx == vx && vdy == vy)) {
            hppath.push_back(vertex);
            vx = vdx, vy = vdy;
        }
        previous = vertex;
    }
    if (!(hppath.back() == lppath.back()))
        hppath.push_back(lppath.back());
}
