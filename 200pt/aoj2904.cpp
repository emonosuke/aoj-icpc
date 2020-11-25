// GuruGuru (200)
// 2020/11/24

#include <bits/stdc++.h>

using namespace std;

// N: 0, E: 1, S: 2, W: 3
const int DEGMOD = 4;
vector<bool> visitR(4);

int move(int deg, char command)
{
    if (command == 'L')
        return (deg + 1) % DEGMOD;
    if (command == 'R')
    {
        int newdeg = ((deg - 1) + DEGMOD) % DEGMOD;
        visitR[newdeg] = true;
        return newdeg;
    }
}

int main()
{
    string S;
    cin >> S;
    int ans = 0;
    int deg = 0; // first, it faces North
    for (char command : S)
    {
        if (deg == 0)
        {
            // it faces north, east, south, and west one or more times, respectively,
            // after the command of 'R'
            if (visitR[0] && visitR[1] && visitR[2] && visitR[3])
                ans++;
            fill(visitR.begin(), visitR.end(), false);
        }
        // move
        deg = move(deg, command);
    }
    if (deg == 0 && visitR[0] && visitR[1] && visitR[2] && visitR[3])
    {
        ans++;
    }
    cout << ans << endl;
}
