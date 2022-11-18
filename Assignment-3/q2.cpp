#include <queue>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long int n, sum{0};
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (long int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            pq.push(x);
        }

        for (long int j = 0; j < n - 1; j++)
        {
            int elem1 = pq.top();
            pq.pop();
            int elem2 = pq.top();
            pq.pop();
            sum += elem1 + elem2;
            pq.push(elem1 + elem2);
        }

        cout << sum << "\n";
    }
}