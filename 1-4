#include <iostream>
#include <vector>
#include <chrono> 

void swap(int& i, int& j) {
    int temp = i;
    i = j;
    j = temp;
}

int random(int l, int h, long long s) {
    if (h <= l) return l;
    long long r = s * 1399;
    return l + (std::abs(r) % (h - l));
}

void shuffle(std::vector<int>& vec, long long time_seed) {
    if (vec.empty()) return;

    int size = static_cast<int>(vec.size());

    for (int i = 0; i < 2 * size; i++) {
        int j = random(0, size, time_seed + i * 31231);
        int k = random(0, size, time_seed + i * 23653);
        swap(vec[j], vec[k]);
    }
}

int main() {
    std::vector<int> vec;
    int k = 5;  
    int n = 300;  

    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    long long time_seed = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 10; j++) {
            vec.push_back(i);
        }
    }

    shuffle(vec, time_seed);

    if (k <= vec.size()) {
        vec.resize(k);
    }

    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
