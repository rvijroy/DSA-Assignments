#include <bits/stdc++.h>
#include <iostream>
#include <vector>
 
using namespace std;
 
int solve(int N, int K, vector<int> arr) {
    
    sort(arr.begin(), arr.end());
    int count = 0, curr_sum = 0;
    
    for (auto x: arr) {
        curr_sum += x;
        if (curr_sum <= K) count++;
        else break;
    }
 
    return count;
}
 
int main() {
    int n, k; 
    cin >> n >> k;
    vector<int> arr(n);
 
    for (auto& x: arr) {
        cin >> x;
    }
 
    cout << solve(n, k, arr);
}