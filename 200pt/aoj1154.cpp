// Monday-Saturday Prime Factors (200)
// 2020/11/25

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300000;

int main()
{
    vector<string> ans;

    vector<int> msnumbers;
    for (int i = 1; i < MAX_N; i++)
    {
        if ((i % 7 == 1) || (i % 7 == 6))
        {
            msnumbers.push_back(i);
        }
    }

    // eratosthenes
    vector<int> msprimes;
    vector<bool> isprime(MAX_N);
    fill(isprime.begin(), isprime.end(), true);
    isprime[1] = false;
    for (int msnumber : msnumbers)
    {
        if (isprime[msnumber])
        {
            msprimes.push_back(msnumber);
            for (int j = 2 * msnumber; j <= MAX_N; j += msnumber)
                isprime[j] = false;
        }
    }

    while (true)
    {
        int n;
        cin >> n;
        if (n == 1)
            break;

        vector<int> factors;
        for (int msprime : msprimes)
        {
            if (n % msprime == 0 && ((n / msprime) % 7 == 1 || (n / msprime) % 7 == 6))
                factors.push_back(msprime);
        }
        string s = to_string(n) + ":";
        for (int factor : factors)
        {
            s += (" " + to_string(factor));
        }
        ans.push_back(s);
    }
    for (string a : ans)
    {
        cout << a << endl;
    }
}
