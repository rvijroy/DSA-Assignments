#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int min_swaps(const vector<int> &arr) {
    int n = arr.size();
    vector<pair<int, int>> val_idx;
    val_idx.reserve(n);

    for (int i = 0; i < n; i++)
        val_idx.push_back({arr[i], i});

    sort(val_idx.rbegin(), val_idx.rend());
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (val_idx[i].second != i) {
            count++;
            swap(val_idx[i], val_idx[val_idx[i].second]);
            i--;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << min_swaps(arr);

    return 0;
}

// Sample Input: (from the example given in problem)
// 4
// 1 5 4 3
