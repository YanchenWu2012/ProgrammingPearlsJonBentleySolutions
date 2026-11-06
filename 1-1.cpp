#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <chrono>
#include <algorithm>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void Sort(std::vector<int>& vec) {
    if (!vec.empty()) {
        quickSort(vec, 0, vec.size() - 1);
    }
}

int main() {
    int n = 10;
    int l = 20;
    std::vector<int> vec(l);
    std::iota(vec.begin(), vec.end(), 1);

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(vec.begin(), vec.end(), g);
    vec.resize(n);

    std::cout << "Unsorted elements: ";
    for (int v : vec) std::cout << v << " ";
    std::cout << "\n\n";

    std::cout << "Sorting " << n << " elements using Quick Sort...\n";

    auto start = std::chrono::high_resolution_clock::now();

    Sort(vec);

    auto end = std::chrono::high_resolution_clock::now();

    auto duration_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "\nSorted elements:   ";
    for (int v : vec) std::cout << v << " ";
    std::cout << "\n";

    std::cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    std::cout << "Performance Results:\n";
    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    std::cout << "Execution time: " << duration_us.count() << " microseconds\n";
    std::cout << "Execution time: " << duration_ms.count() << " milliseconds\n";

    return 0;
}
