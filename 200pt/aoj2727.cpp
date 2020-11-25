// M and A (200)
// 2020/11/24

#include <bits/stdc++.h>

using namespace std;

int main()
{
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
