#ifndef DIVSALES_H
#define DIVSALES_H

class DivSales {
private:
    double quarterlySales[4];
    static double totalCorporateSales;

public:
    DivSales();

    // Stores the four quarterly sales and adds them to the corporate total.
    void setSales(double quarter1, double quarter2,
                  double quarter3, double quarter4);

    // Returns sales for quarter 0, 1, 2, or 3.
    double getQuarterSales(int quarter) const;

    // Returns total sales for all divisions for the year.
    static double getCorporateSales();
};

#endif
