// Amazing Mazes (200)
// 2020/11/24

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;
#define mod(x) (x % MOD + MOD) % MOD

const int MAX_H = 30, MAX_W = 30;
int H, W;

// down, left, up, right (clockwise)
const int dh[4] = {+1, 0, -1, 0};
const int dw[4] = {0, -1, 0, +1};
vector<vector<vector<bool>>> blocked(MAX_H, vector<vector<bool>>(MAX_W, vector<bool>(4)));

int solve()
{
    vector<vector<int>> dist(H, vector<int>(W));      // false
    vector<vector<bool>> visited(H, vector<bool>(W)); // false

    queue<pair<pair<int, int>, int>> Q;
    visited[0][0] = true;
    Q.push(make_pair(make_pair(0, 0), 1));
    while (!Q.empty())
    {
        pair<pair<int, int>, int> p = Q.front();
        Q.pop();
        int h = p.first.first, w = p.first.second, d = p.second;

        dist[h][w] = d;
        for (int k = 0; k < 4; k++)
        {
            int nh = h + dh[k];
            int nw = w + dw[k];
            if (nh < 0 || nh >= H || nw < 0 || nw >= W)
                continue;
            if (!visited[nh][nw])
            {
                if (!blocked[h][w][k]) // there is a way (no wall)
                {
                    visited[nh][nw] = true;
                    Q.push(make_pair(make_pair(nh, nw), d + 1));
                }
            }
        }
    }
    return dist[H - 1][W - 1];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<int> ans;
    while (true)
    {
        cin >> W >> H;
        if (W == 0 && H == 0)
            break;

        for (int h = 0; h < MAX_H; h++)
            for (int w = 0; w < MAX_W; w++)
                for (int k = 0; k < 4; k++)
                    blocked[h][w][k] = true;

        for (int i = 0; i < 2 * H - 1; i++)
        {
            if (i % 2 == 0)
            {
                // vertical
                for (int j = 0; j < W - 1; j++)
                {
                    bool isblocked;
                    cin >> isblocked;
                    blocked[i / 2][j][3] = isblocked;     // right
                    blocked[i / 2][j + 1][1] = isblocked; // left
                }
            }
            else
            {
                // horizontal
                for (int j = 0; j < W; j++)
                {
                    bool isblocked;
                    cin >> isblocked;
                    blocked[i / 2][j][0] = isblocked;       // down
                    blocked[(i + 1) / 2][j][2] = isblocked; // up
                }
            }
        }

        ans.push_back(solve());
    }
    for (int a : ans)
        cout << a << endl;
}
