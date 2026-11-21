#include <iostream>
#include <chrono>

int main() {
    const int iterations = 500000000;

    auto startFloat = std::chrono::high_resolution_clock::now();

    float f_val = 1.0f;
    for (int i = 0; i < iterations; i++) {
        f_val = f_val * 1.000001f;
    }

    auto endFloat = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> floatTime = endFloat - startFloat;

    auto startDouble = std::chrono::high_resolution_clock::now();

    double d_val = 1.0;
    for (int i = 0; i < iterations; i++) {
        d_val = d_val * 1.000001;
    }

    auto endDouble = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> doubleTime = endDouble - startDouble;

    std::cout << "Single-precision (float) time: " << floatTime.count() << " seconds\n";
    std::cout << "Double-precision (double) time: " << doubleTime.count() << " seconds\n";
    std::cout << "Speedup (Double time / Float time): " << doubleTime.count() / floatTime.count() << "x\n";

    std::cout << "\n(Ignore) Final values: " << f_val << ", " << d_val << "\n";

    return 0;
}
