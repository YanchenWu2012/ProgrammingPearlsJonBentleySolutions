#include <iostream>
#include <chrono>
#include <vector>

int main() {
    const int size = 32768;
    const int repeats = 50000;

    std::vector<float> f_arr(size, 1.000001f);
    std::vector<double> d_arr(size, 1.000001);

    auto startFloat = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < repeats; r++) {
        for (int i = 0; i < size; i += 8) {
            f_arr[i] *= 1.000001f;
            f_arr[i + 1] *= 1.000001f;
            f_arr[i + 2] *= 1.000001f;
            f_arr[i + 3] *= 1.000001f;
            f_arr[i + 4] *= 1.000001f;
            f_arr[i + 5] *= 1.000001f;
            f_arr[i + 6] *= 1.000001f;
            f_arr[i + 7] *= 1.000001f;
        }
    }
    auto endFloat = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> floatTime = endFloat - startFloat;

    auto startDouble = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < repeats; r++) {
        for (int i = 0; i < size; i += 4) {
            d_arr[i] *= 1.000001;
            d_arr[i + 1] *= 1.000001;
            d_arr[i + 2] *= 1.000001;
            d_arr[i + 3] *= 1.000001;
        }
    }
    auto endDouble = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> doubleTime = endDouble - startDouble;

    std::cout << "Float time: " << floatTime.count() << " seconds\n";
    std::cout << "Double time: " << doubleTime.count() << " seconds\n";
    std::cout << "Speedup: " << doubleTime.count() / floatTime.count() << "x\n";

    std::cout << "\nCheck values: " << f_arr[0] << ", " << d_arr[0] << "\n";

    return 0;
}
