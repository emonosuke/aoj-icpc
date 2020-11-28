// Broken Audio Signal (200)
// 2020/11/26

#include <bits/stdc++.h>

using namespace std;

const int MIN_V = -1000000010, MAX_V = 1000000010;

string solve(vector<string> samples, int n)
{
    int minval = MIN_V, maxval = MAX_V;
    string status = "";

    for (int i = 0; i < n - 1; i++)
    {
        if (samples[i] == "x" && samples[i + 1] == "x")
        {
            status = "none";
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (status != "")
            return status;
        if (samples[i] == "x")
        {
            if (i % 2 == 1) // i + 1 is even
            {
                if (i == 0)
                    minval = max(minval, stoi(samples[1]));
                else if (i == n - 1)
                    minval = max(minval, stoi(samples[n - 2]));
                else
                    minval = max(minval, max(stoi(samples[i - 1]), stoi(samples[i + 1])));
            }
            else // i + 1 is odd
            {
                if (i == 0)
                    maxval = min(maxval, stoi(samples[1]));
                else if (i == n - 1)
                    maxval = min(maxval, stoi(samples[n - 2]));
                else
                    maxval = min(maxval, min(stoi(samples[i - 1]), stoi(samples[i + 1])));
            }
        }
        else
        {
            if (i % 2 == 1)
            {
                // even
                bool isnone = false;

                isnone |= (i + 1 < n && samples[i + 1] != "x" && stoi(samples[i]) <= stoi(samples[i + 1]));
                isnone |= (i - 1 > 0 && samples[i - 1] != "x" && stoi(samples[i]) <= stoi(samples[i - 1]));

                if (isnone)
                    status = "none";
            }
            else
            {
                // odd
                bool isnone = false;

                isnone |= (i + 1 < n && samples[i + 1] != "x" && stoi(samples[i]) >= stoi(samples[i + 1]));
                isnone |= (i - 1 > 0 && samples[i - 1] != "x" && stoi(samples[i]) >= stoi(samples[i - 1]));

                if (isnone)
                    status = "none";
            }
        }
    }

    // cout << "minval: " << minval << " "
    //      << "maxval: " << maxval << endl;

    if (minval + 2 == maxval)
        status = to_string(minval + 1);
    else if (minval + 2 < maxval)
        status = "ambiguous";
    else
        status = "none";

    return status;
}

int main()
{
    vector<string> ans;
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        vector<string> samples(n);
        for (int i = 0; i < n; i++)
        {
            string sample;
            cin >> sample;
            samples[i] = sample;
        }
        string status = solve(samples, n);
        ans.push_back(status);
    }
    for (string a : ans)
        cout << a << endl;
}
