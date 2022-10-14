#include <bits/stdc++.h>

using namespace std;

vector<int> next_largest(vector<int> line) {
    stack<int> s;
    vector<int> res(line.size(), -1);
    for (int i = line.size() - 1; i >= 0; i--) {
        while (!s.empty() && line[i] >= s.top()) {
            s.pop();
        }
        if (!s.empty()) {
            res[i] = s.top();
        }
        s.push(line[i]);
    }
    return res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> line(n);
        for (auto& x : line)
            cin >> x;

        auto ans = next_largest(line);
        for (const int& x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}