#include <bits/stdc++.h>

using namespace std;

vector<int> subarray_tallest(vector<int> heights, int k) {
    deque<int> Q(k);

    int i;
    for (i = 0; i < k; ++i) {
        while (!Q.empty() and heights[i] > heights[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }

    vector<int> res;

    for (; i < heights.size(); ++i) {
        res.push_back(heights[Q.front()]);
        while (!Q.empty() and Q.front() <= i - k)
            Q.pop_front();

        while ((!Q.empty()) && heights[i] >= heights[Q.back()])
            Q.pop_back();

        Q.push_back(i);
    }

    res.push_back(heights[Q.front()]);
    return res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> heights(n);
        for (auto &x : heights)
            cin >> x;

        auto res = subarray_tallest(heights, k);
        for (const int &x : res)
            cout << x << " ";
        
        cout << "\n";
    }

    return 0;
}