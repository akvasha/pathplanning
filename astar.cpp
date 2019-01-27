#include "astar.h"

Astar::Astar(double HW, bool BT)
{
    hweight = HW;
    breakingties = BT;
}

double Astar::computeHFromCellToCell(int i1, int j1, int i2, int j2, const EnvironmentOptions &options)
{
    if (options.metrictype == CN_SP_MT_MANH) {
        return std::abs(i2 - i1) + std::abs(j2 - j1);
    } else if (options.metrictype == CN_SP_MT_EUCL) {
        return std::sqrt((i2 - i1) * (i2 - i1) + (j2 - j1) * (j2 - j1));
    } else if (options.metrictype == CN_SP_MT_CHEB) {
        return std::max(std::abs(i2 - i1), std::abs(j2 - j1));
    } else if (options.metrictype == CN_SP_MT_DIAG) {
        return std::abs(std::abs(i2 - i1) + std::abs(j2 - j1)) + std::sqrt(2) * std::min(std::abs(i2 - i1), std::abs(j2 - j1));
    } else {
        return 0;
    }
}
