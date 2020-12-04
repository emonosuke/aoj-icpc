// Rearranging a Sequence (200)
// 2020/12/4

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200001;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<bool> used(n + 1);
    stack<int> heads;
    for (int i = n; i >= 1; i--)
        heads.push(i);
    for (int i = 0; i < m; i++)
    {
        int e;
        cin >> e;
        heads.push(e);
    }
    vector<int> ans;
    while (!heads.empty())
    {
        int a = heads.top();
        if (!used[a])
            ans.push_back(a);
        used[a] = true;
        heads.pop();
    }
    for (int a : ans)
        cout << a << endl;
}
