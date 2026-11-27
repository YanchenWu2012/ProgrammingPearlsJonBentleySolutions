#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

double maxsum(const vector<double>& x) {
    double maxsofar = 0.0;
    double maxendinghere = 0.0;
    for (double val : x) {
        maxendinghere = max(maxendinghere + val, 0.0);
        maxsofar = max(maxsofar, maxendinghere);
    }
    return maxsofar;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(-1.0, 1.0);

    const int trials = 1000;
    const int n = 10000;

    vector<double> maxsums;
    maxsums.reserve(trials);

    vector<double> x(n);
    for (int i = 0; i < trials; i++) {
        for (int j = 0; j < n; j++) {
            x[j] = dis(gen);
        }
        maxsums.push_back(maxsum(x));
    }

    double result = 0.0;
    for (double s : maxsums) {
        result += s;
    }
    result /= maxsums.size();

    cout << "Average maxval of inputs [-1, 1]: " << result << '\n';
}
