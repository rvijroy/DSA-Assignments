#include <bits/stdc++.h>
using namespace std;

bool can_sort(int n, queue<int> q) {
    stack<int> st;
    int expected = 1;
    int front;

    while (!q.empty()) {
        front = q.front();
        q.pop();

        if (front == expected)
            expected++;

        else {
            if (st.empty()) {
                st.push(front);
            }

            else if (!st.empty() && st.top() < front) {
                return false;
            }

            else
                st.push(front);
        }

        while (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
    }

    return (expected - 1 == n && st.empty());
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            q.push(x);
        }

        cout << ((can_sort(n, q)) ? "YES\n" : "NO\n");
    }

    return 0;
}