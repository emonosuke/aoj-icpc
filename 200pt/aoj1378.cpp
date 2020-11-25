// Secret of Chocolate Poles (200)
// 2020/11/25

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX_L = 100;

vector<ll> dp(MAX_L);
ll l, k;

ll rec(ll x)
{
    if (x > l)
        return 0;
    if (x == l)
        return 1;
    if (dp[x])
        return dp[x];

    return dp[x] = rec(x + 1 + 1) + rec(x + 1 + k) + 1; // the last "+ 1" means ending here
}

int main()
{
    cin >> l >> k;
    cout << rec(1) + rec(k) << endl;
}
