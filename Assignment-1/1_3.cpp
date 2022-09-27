#include <bits/stdc++.h>
 
using namespace std;
 
void paranthesis(int open, int close, string str)
{
    if (open == 0 && close == 0)
    {
        cout << str << "\n";
        return;
    }
    if (open > 0)
    {
        paranthesis(open - 1, close, str + "(");
    }
    if (close > open)
    {
        paranthesis(open, close - 1, str + ")");
    }
}
 
int main()
{
    int n;
    cin >> n;
    string str = "";
    paranthesis(n, n, str);
    return 0;
}
 