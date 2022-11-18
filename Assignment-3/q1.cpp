#include <vector>
#include <iostream>
using namespace std;

void eulerTree(int u, int &index, const vector<vector<int>> &adj, vector<int> &euler_tour, vector<bool> &vis)
{
    vis[u] = 1;
    euler_tour[index++] = u;
    for (auto it : adj[u])
    {
        if (!vis[it])
        {
            eulerTree(it, index, adj, euler_tour, vis);
            euler_tour[index++] = u;
        }
    }
}

void printEulerTour(const vector<int> &arr, const vector<int> &euler_tour)
{
    long long int sum{0};
    for (int i = 0; i < euler_tour.size(); ++i)
    {
        int index = euler_tour[i];
        sum += arr[index - 1];
    }
    cout << sum;
}

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;

    vector<int> euler_tour(2 * n - 1);
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);

    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int index = 0;
    eulerTree(1, index, adj, euler_tour, vis);
    printEulerTour(arr, euler_tour);

    return 0;
}