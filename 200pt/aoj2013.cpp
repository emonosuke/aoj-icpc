// Osaki
// 2020/11/24

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int dh[4] = {+1, 0, -1, 0};
const int dw[4] = {0, -1, 0, +1};

const int MAX_T = 24 * 60 * 60;

int convert_time(string str)
{
    int hour = stoi(str.substr(0, 2));
    int minute = stoi(str.substr(3, 2));
    int second = stoi(str.substr(6, 2));
    return hour * 60 * 60 + minute * 60 + second;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<int> ans;
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<int> timetable(MAX_T);
        for (int i = 0; i < n; i++)
        {
            string depstr, arrstr;
            cin >> depstr >> arrstr;
            int depsec = convert_time(depstr), arrsec = convert_time(arrstr);
            timetable[depsec]++;
            timetable[arrsec]--;
        }
        int cnt = 0, maxcnt = 0;
        for (int t : timetable)
        {
            cnt += t;
            maxcnt = max(maxcnt, cnt);
        }
        ans.push_back(maxcnt);
    }
    for (int a : ans)
        cout << a << endl;
}
