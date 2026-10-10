#include <iostream>
#include <vector>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void jugglingRotate(std::vector<int>& arr, int distance) {
    int n = arr.size();

    distance = distance % n;

    int cycles = gcd(n, distance);

    for (int start = 0; start < cycles; start++) {
        int temp = arr[start];
        int current = start;

        while (true) {
            int next = (current + distance) % n;

            if (next == start) {
                break;
            }

            arr[current] = arr[next];
            current = next;
        }

        arr[current] = temp;
    }
}
