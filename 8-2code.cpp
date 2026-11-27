#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Algorithm 1
long long algo1_cubic(const vector<int>& x) {
    int n = x.size();
    long long maxsofar = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            long long sum = 0;
            for (int k = i; k <= j; ++k) {
                sum += x[k];
            }
            maxsofar = max(maxsofar, sum);
        }
    }
    return maxsofar;
}

// Algorithm 2
long long algo2_quadratic(const vector<int>& x) {
    int n = x.size();
    long long maxsofar = 0;
    for (int i = 0; i < n; ++i) {
        long long sum = 0;
        for (int j = i; j < n; ++j) {
            sum += x[j];
            maxsofar = max(maxsofar, sum);
        }
    }
    return maxsofar;
}

// Helper for Algorithm 3
long long maxsum3(const vector<int>& x, int l, int u) {
    if (l > u) return 0;
    if (l == u) return max(0, x[l]);

    int m = l + (u - l) / 2;

    long long lmax = 0, sum = 0;
    for (int i = m; i >= l; --i) {
        sum += x[i];
        lmax = max(lmax, sum);
    }

    long long rmax = 0;
    sum = 0;
    for (int i = m + 1; i <= u; ++i) {
        sum += x[i];
        rmax = max(rmax, sum);
    }

    return max({ lmax + rmax, maxsum3(x, l, m), maxsum3(x, m + 1, u) });
}

// Algorithm 3
long long algo3_divide_and_conquer(const vector<int>& x) {
    if (x.empty()) return 0;
    return maxsum3(x, 0, x.size() - 1);
}

long long algo4_linear(const vector<int>& x) {
    long long maxsofar = 0;
    long long maxendinghere = 0;
    for (int val : x) {
        maxendinghere = max(0LL, maxendinghere + val);
        maxsofar = max(maxsofar, maxendinghere);
    }
    return maxsofar;
}

int main() {
    int n;
    cout << "Enter input vector length (n): ";
    if (!(cin >> n) || n < 0) {
        cerr << "Invalid input length.\n";
        return 1;
    }

    vector<int> x(n);
    mt19937 rng(42);
    uniform_int_distribution<int> dist(-100, 100);
    for (int i = 0; i < n; ++i) {
        x[i] = dist(rng);
    }

    cout << fixed << setprecision(6);
    cout << "\nBenchmarking for n = " << n << " ...\n";
    cout << "------------------------------------------------------------\n";

    auto start4 = high_resolution_clock::now();
    long long res4 = algo4_linear(x);
    auto end4 = high_resolution_clock::now();
    duration<double, milli> time4 = end4 - start4;
    cout << "Algorithm 4 (O(n))       | Max Sum: " << res4 << " | Time: " << time4.count() << " ms\n";

    auto start3 = high_resolution_clock::now();
    long long res3 = algo3_divide_and_conquer(x);
    auto end3 = high_resolution_clock::now();
    duration<double, milli> time3 = end3 - start3;
    cout << "Algorithm 3 (O(n log n)) | Max Sum: " << res3 << " | Time: " << time3.count() << " ms\n";

    auto start2 = high_resolution_clock::now();
    long long res2 = algo2_quadratic(x);
    auto end2 = high_resolution_clock::now();
    duration<double, milli> time2 = end2 - start2;
    cout << "Algorithm 2 (O(n^2))     | Max Sum: " << res2 << " | Time: " << time2.count() << " ms\n";

    auto start1 = high_resolution_clock::now();
    long long res1 = algo1_cubic(x);
    auto end1 = high_resolution_clock::now();
    duration<double, milli> time1 = end1 - start1;
    cout << "Algorithm 1 (O(n^3))     | Max Sum: " << res1 << " | Time: " << time1.count() << " ms\n";

    return 0;
}
