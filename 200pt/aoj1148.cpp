// Analyzing Login/Logout Records (200)
// 2020/11/27

#include <bits/stdc++.h>

using namespace std;

const int MIN_T = 540;
const int MAX_T = 1260;

int main()
{
    vector<int> ans;
    while (true)
    {
        int n_pcs, n_students;
        cin >> n_pcs >> n_students;
        if (n_pcs == 0 && n_students == 0)
            break;

        // (pc, student) -> [login, logout, login, logout...]
        map<pair<int, int>, vector<int>> record;

        // logging
        int r;
        cin >> r;
        for (int i = 0; i < r; i++)
        {
            int time, pc, student, status;
            cin >> time >> pc >> student >> status;

            // 1: login  0: logout

            // odd records and login is not valid
            assert((record[make_pair(pc, student)].size() % 2) == 0 || status == 0);
            // even records and logout is not valid
            assert((record[make_pair(pc, student)].size() % 2) == 1 || status == 1);
            record[make_pair(pc, student)].push_back(time);
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            int time_s, time_e, student;
            cin >> time_s >> time_e >> student;

            vector<bool> used(MAX_T + 2);

            for (int pc = 1; pc <= n_pcs; pc++)
            {
                vector<int> record_time = record[make_pair(pc, student)];
                for (int j = 0; j < record_time.size(); j += 2)
                {
                    // q(<=50) * n_pcs(<=1000) * r(<=1000)

                    int login_t = max(record_time[j], time_s);
                    int logout_t = min(record_time[j + 1], time_e);

                    // cout << login_t << " " << logout_t << endl;

                    for (int t = login_t; t <= logout_t; t++)
                        used[t] = true;
                }
            }
            int cnt = 0;
            for (int t = time_s; t < time_e; t++)
            {
                if (used[t])
                {
                    int tmp_s = t;
                    while (used[t])
                        t++;
                    cnt += (t - tmp_s - 1);
                }
            }
            ans.push_back(cnt);
        }
    }

    for (int a : ans)
        cout << a << endl;
}
