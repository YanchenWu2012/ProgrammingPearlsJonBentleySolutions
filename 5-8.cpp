#include <iostream>
#include <cassert>

double calculateShipping(double weight, int distance, bool isExpress) {
    if (weight <= 0 || distance < 0) return -1.0;

    double cost = 5.0 + (weight * 0.5) + (distance * 0.02);
    if (weight > 50.0) cost += 15.0;
    if (isExpress) cost *= 1.5;

    return cost;
}

int main() {
    assert(calculateShipping(-5, 100, false) == -1.0);
    assert(calculateShipping(10, 0, false) == 10.0);
    assert(calculateShipping(10, 100, false) == 12.0);
    assert(calculateShipping(10, 100, true) == 18.0);
    assert(calculateShipping(60, 100, false) == 52.0);

    std::cout << "All automated tests passed!\n\n";

    double w;
    int d;
    bool exp;

    std::cout << "Enter weight, distance, and express (1 or 0) to test: \n";
    while (std::cout << "> " && std::cin >> w >> d >> exp) {
        double result = calculateShipping(w, d, exp);
        std::cout << "Result: " << result << "\n";
    }

    return 0;
}
