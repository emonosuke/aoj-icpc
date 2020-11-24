// M and A
// 2020/11/24

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;
    bool ans = false;
    for (int k = 0; k <= 1; k++)
    {
        vector<int> required;
        bool ok = true;
        for (int i = k; i < S.size(); i += 2)
        {
            required.push_back(S[i]);
        }
        int i = 0;
        for (int r : required)
        {
            bool found = false;
            while (i < T.size())
            {
                int t = T[i];
                i++;
                if (t == r)
                {
                    found = true;
                    break;
                }
            }
            // r not found in T
            if (!found)
            {
                ok = false;
            }
        }
        ans |= ok;
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
