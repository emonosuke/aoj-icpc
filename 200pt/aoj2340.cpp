// Carpenter's Language (200)
// 2020/11/27

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    int q;
    cin >> q;
    ll cntL = 0, cntR = 0;
    vector<string> ans;
    for (int i = 0; i < q; i++)
    {
        ll p, n;
        char c;
        cin >> p >> c >> n;
        if (c == '(')
            cntL += n;
        else // ')'
            cntR += n;
        if (cntL == cntR)
            ans.push_back("Yes");
        else
            ans.push_back("No");
    }
    for (string a : ans)
        cout << a << endl;
}
