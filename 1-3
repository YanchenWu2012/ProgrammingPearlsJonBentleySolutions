#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <chrono>

int getMax(const std::vector<int>& arr) {
    if (arr.empty()) return 0;
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

void bitmapSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    std::vector<bool> bits(getMax(arr) + 1, false);

    for (int num : arr) {
        bits[num] = true;
    }

    arr.clear();
    for (int i = 0; i < bits.size(); i++) { 
        if (bits[i]) { 
            arr.push_back(i);
        }
    }
}

int main() {
    int n = 1000000;
    int l = 2000000;
    std::vector<int> vec(l);
    std::iota(vec.begin(), vec.end(), 1);

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(vec.begin(), vec.end(), g);
    vec.resize(n);

    std::cout << "Sorting " << n << " elements using Bitmap Sort...\n";

    auto start = std::chrono::high_resolution_clock::now();

    bitmapSort(vec);

    auto end = std::chrono::high_resolution_clock::now();

    auto duration_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    std::cout << "Performance Results:\n";
    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    std::cout << "Execution time: " << duration_us.count() << " microseconds\n";
    std::cout << "Execution time: " << duration_ms.count() << " milliseconds\n";

    return 0;
}
