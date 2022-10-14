#include <bits/stdc++.h>
#include <chrono>
#include <iomanip>

using namespace std;

// THIS TAKES O(N) time in the WORST CASE.
// The timing can be obtained by solving the following recurrence relation:
// T(n) = T(n - 1) + O(1) with the base case that T(1) = O(1)
pair<int, int> find_sum(vector<int> A, int k, int i, int j) {
    if (i >= j) {
        return {-1, -1};
    }
    if (A[i] + A[j] == k) {
        return {A[i], A[j]};
    }
    if (A[i] + A[j] > k) {
        return find_sum(A, k, i, j - 1);
    }
    return find_sum(A, k, i + 1, j);
}

pair<float, float> linear_regression(unordered_map<int, float> data) {
    int n = data.size();

    vector<float> xs, ys, x2, xy;

    float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;

    for (auto [x, y] : data) {
        sum_x += x;
        sum_y += y;
        sum_x2 += x * x;
        sum_xy += x * y;
    }

    float dr = n * sum_x2 - (sum_x * sum_x) + 1e-8;

    return {
        (n * sum_xy - sum_x * sum_y) / dr,       // m
        (sum_y * sum_x2 - sum_x * sum_xy) / dr,  // c
    };
}

void benchmark() {
    // array<int, 12> sizes{100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000, 50000000};
    array<int, 5> sizes{100, 500, 1000, 5000, 10000};
    unordered_map<int, float> avg_duration;

    cout << fixed << setprecision(4); // << setfill('0');
    cout << "    N    | total_time | iters | avg \n";
    cout << "--------------------------------------------\n";

    for (auto size : sizes) {
        vector<int> arr(size);
        for (int i = 0; i < size; ++i) arr[i] = i;
        auto rng = std::default_random_engine{};
        std::uniform_int_distribution<> distr(1, 2 * size - 3);

        int64_t total_duration = 0;
        int num_iters = pow(2, log10(size));

        for (int i = 0; i < num_iters; ++i) {
            std::shuffle(arr.begin(), arr.end(), rng);
            int k = distr(rng);

            auto ts = chrono::high_resolution_clock::now();
            pair<int, int> res = find_sum(arr, k, 0, size - 1);
            auto te = chrono::high_resolution_clock::now();

            auto duration = chrono::duration_cast<chrono::microseconds>(te - ts);

            total_duration += duration.count();
        }

        avg_duration[size] = (float)total_duration / (float)num_iters;
        cout << " " 
             << setw(7) << size << " | " 
             << setw(10) << total_duration << " | " 
             << setw(5) << num_iters << " | " 
             << setw(5) << avg_duration[size] << "\n";
    }

    auto [m, c] = linear_regression(avg_duration);
    cout << "Approximate average case time (in us) T(n) ~ " << m << " * n + O(1)\n";
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto ts = chrono::high_resolution_clock::now();
    pair<int, int> res = find_sum(arr, k, 0, n - 1);
    auto te = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(te - ts);

    auto [x, y] = res;
    cout << x << " " << y << endl;
    cout << "Execution took: " << duration.count() << "us" << endl;

    cout << "\n\nConducting a benchmark...\n";
    benchmark();

    return 0;
}