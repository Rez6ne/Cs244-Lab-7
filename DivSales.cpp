#include "DivSales.h"
#include <stdexcept>

double DivSales::totalCorporateSales = 0.0;

DivSales::DivSales() {
    for (int i = 0; i < 4; ++i) {
        quarterlySales[i] = 0.0;
    }
}

void DivSales::setSales(double quarter1, double quarter2,
                        double quarter3, double quarter4) {
    if (quarter1 <= 0 || quarter2 <= 0 ||
        quarter3 <= 0 || quarter4 <= 0) {
        throw std::invalid_argument("Quarterly sales must be positive values.");
    }

    quarterlySales[0] = quarter1;
    quarterlySales[1] = quarter2;
    quarterlySales[2] = quarter3;
    quarterlySales[3] = quarter4;

    totalCorporateSales += quarter1 + quarter2 + quarter3 + quarter4;
}

double DivSales::getQuarterSales(int quarter) const {
    if (quarter < 0 || quarter > 3) {
        throw std::out_of_range("Quarter must be from 0 through 3.");
    }

    return quarterlySales[quarter];
}

double DivSales::getCorporateSales() {
    return totalCorporateSales;
}
