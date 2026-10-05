#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <chrono>
#include <algorithm>
#include <fstream>

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
    /*
    // Uncomment if you need to generate "in.txt" first:
    const int TOTAL_NUMBERS = 10000000;
    std::vector<int> numbers(TOTAL_NUMBERS);
    std::iota(numbers.begin(), numbers.end(), 1);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(numbers.begin(), numbers.end(), g);
    std::ofstream outfile("in.txt");
    for (int num : numbers) {
        outfile << num << "\n";
    }
    outfile.close();
    std::cout << "Successfully wrote 10,000,000 unique random integers to in.txt\n";
    */

    const int CHUNK = 200000;
    const int PASSES = 50;

    std::cout << "--- Starting QuickSort Benchmark ---" << std::endl;
    auto startQuick = std::chrono::high_resolution_clock::now();

    {
        std::ofstream OutFile("out_quicksort.txt");
        if (!OutFile) {
            std::cerr << "Error: Could not create out_quicksort.txt\n";
            return 1;
        }

        for (int pass = 0; pass < PASSES; ++pass) {
            int low = (pass * CHUNK) + 1;
            int high = (pass + 1) * CHUNK;

            std::ifstream infile("in.txt");
            if (!infile) {
                std::cerr << "Error: Could not open in.txt\n";
                return 1;
            }

            std::vector<int> chunk;
            int val;

            while (infile >> val) {
                if (val >= low && val <= high) {
                    chunk.push_back(val);
                }
            }
            infile.close();

            if (!chunk.empty()) {
                Sort(chunk);
                for (int num : chunk) {
                    OutFile << num << "\n";
                }
            }
        }
    }

    auto endQuick = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedQuick = endQuick - startQuick;
    std::cout << "QuickSort finished.\n\n";

    std::cout << "--- Starting BitmapSort Benchmark ---" << std::endl;
    auto startBitmap = std::chrono::high_resolution_clock::now();

    {
        std::ofstream OutFile("out_bitmap.txt");
        if (!OutFile) {
            std::cerr << "Error: Could not create out_bitmap.txt\n";
            return 1;
        }

        for (int pass = 0; pass < PASSES; ++pass) {
            int low = (pass * CHUNK) + 1;
            int high = (pass + 1) * CHUNK;

            std::ifstream infile("in.txt");
            if (!infile) {
                std::cerr << "Error: Could not open in.txt\n";
                return 1;
            }

            std::vector<int> chunk;
            int val;

            while (infile >> val) {
                if (val >= low && val <= high) {
                    chunk.push_back(val);
                }
            }
            infile.close();

            if (!chunk.empty()) {
                bitmapSort(chunk);
                for (int num : chunk) {
                    OutFile << num << "\n";
                }
            }
        }
    }

    auto endBitmap = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedBitmap = endBitmap - startBitmap;
    std::cout << "BitmapSort finished.\n\n";

    std::cout << "QuickSort Time:  " << elapsedQuick.count() << " seconds\n";
    std::cout << "BitmapSort Time: " << elapsedBitmap.count() << " seconds\n";


    return 0;
}
