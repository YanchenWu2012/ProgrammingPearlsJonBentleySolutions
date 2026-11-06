#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>

int random(int low, int high) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> distrib(low, high);
    int n = distrib(gen);
    return n;
}

int coffeecan(std::vector<bool> beans) {
    if (beans.empty()) return -1;

    while (beans.size() > 1) {
        int idx1 = random(0, beans.size() - 1);
        int idx2 = random(0, beans.size() - 1);

        while (idx1 == idx2) {
            idx2 = random(0, beans.size() - 1);
        }

        bool bean1 = beans[idx1];
        bool bean2 = beans[idx2];

        int higher = std::max(idx1, idx2);
        int lower = std::min(idx1, idx2);

        if (bean1 == bean2) {
            beans.erase(beans.begin() + higher);
            beans.erase(beans.begin() + lower);
            beans.push_back(false);
        }
        else {
            int black_idx = -1;

            if (beans[higher] == false) {
                black_idx = higher;
            }
            else {
                black_idx = lower;
            }
            beans.erase(beans.begin() + black_idx);
        }
    }

    return beans[0];
}

void check_case(const std::string& test_name, const std::vector<bool>& beans, int expected) {
    int actual = coffeecan(beans);
    bool passed = (actual == expected);

    std::cout << "[" << (passed ? "PASS" : "FAIL") << "] " << test_name << "\n"
        << "  Expected: " << expected << "\n"
        << "  Actual:   " << actual << "\n"
        << "----------------------------------------\n";
}

int main() {
    // 1. Single bean base cases
    check_case("Single White Bean", { true }, 1);
    check_case("Single Black Bean", { false }, 0);

    // 2. Pairs of identical beans
    // Even number of whites -> always evaluates to 0
    check_case("Two White Beans", { true, true }, 0);
    check_case("Two Black Beans", { false, false }, 0);

    // 3. Pairs of mixed beans
    // Odd number of whites -> always evaluates to 1
    check_case("One White, One Black (Order 1)", { true, false }, 1);
    check_case("One White, One Black (Order 2)", { false, true }, 1);

    // 4. Triplet combinations
    check_case("Three Whites (Odd)", { true, true, true }, 1);
    check_case("Two Whites, One Black (Even)", { true, true, false }, 0);
    check_case("One White, Two Blacks (Odd)", { true, false, false }, 1);
    check_case("Zero Whites, Three Blacks (Even)", { false, false, false }, 0);

    // 5. Larger arbitrary sets (Parity Invariant)
    // 5 whites (Odd) -> Expected 1
    check_case("Eight Beans: 5 White, 3 Black",
        { true, false, true, false, true, true, false, true }, 1);

    // 4 whites (Even) -> Expected 0
    check_case("Eight Beans: 4 White, 4 Black",
        { true, false, true, false, true, true, false, false }, 0);

    return 0;
}
