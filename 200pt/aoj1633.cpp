// On-Screen Keyboard (200)
// 2020/11/25

#include <bits/stdc++.h>

using namespace std;

unordered_map<char, pair<int, int>> keyboard;

int solve(string target)
{
    pair<int, int> pos = make_pair(0, 0);
    int steps = 0;
    for (char t : target)
    {
        pair<int, int> newpos = keyboard[t];
        steps += (abs(newpos.first - pos.first) + abs(newpos.second - pos.second) + 1);
        pos = newpos;
    }
    return steps;
}

int main()
{
    vector<int> ans;
    while (true)
    {
        int h, w;
        cin >> h >> w;

        if (h == 0 && w == 0)
            break;

        keyboard.clear();

        for (int i = 0; i < h; i++)
        {
            string keys;
            cin >> keys;
            for (int j = 0; j < w; j++)
            {
                char key = keys[j];
                keyboard[key] = make_pair(i, j);
            }
        }
        string target;
        cin >> target;
        ans.push_back(solve(target));
    }
    for (int a : ans)
        cout << a << endl;
}
