#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int total{0};
        unordered_map<int, int> count;

        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            x -= 2 * i;
            total += count[x];
            count[x]++;
        }

        cout << total << "\n";
    }

    return 0;
}