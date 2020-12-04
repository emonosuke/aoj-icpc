// Surrounding Area (200)
// 2020/12/4

#include <bits/stdc++.h>

using namespace std;

const int MAX_W = 50;
const int dh[4] = {+1, 0, -1, 0};
const int dw[4] = {0, -1, 0, +1};

int W, H;
vector<string> a(MAX_W);
vector<vector<bool>> black(MAX_W, vector<bool>(MAX_W));
vector<vector<bool>> white(MAX_W, vector<bool>(MAX_W));

void dfs(int i, int j, char color)
{
    // except for the start point
    if (a[i][j] == '.')
    {
        if (color == 'B')
            black[i][j] = true;
        else // color == 'W'
            white[i][j] = true;
    }
    for (int k = 0; k < 4; k++)
    {
        int newi = i + dh[k], newj = j + dw[k];
        if (newi < 0 || newi >= H)
            continue;
        if (newj < 0 || newj >= W)
            continue;
        //cout << newi << " " << newj << endl;
        if (a[newi][newj] == '.')
        {
            if ((color == 'B' && !black[newi][newj]) || (color == 'W' && !white[newi][newj]))
                dfs(newi, newj, color);
        }
    }
}

int main()
{
    vector<pair<int, int>> ans; // black, white
    while (true)
    {
        cin >> W >> H;
        if (W == 0 && H == 0)
            break;
        for (int i = 0; i < H; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < H; i++)
            fill(black[i].begin(), black[i].end(), false);
        for (int i = 0; i < H; i++)
            fill(white[i].begin(), white[i].end(), false);

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (a[i][j] == 'B' || a[i][j] == 'W')
                {
                    dfs(i, j, a[i][j]);
                }
            }
        }
        int cntB = 0, cntW = 0;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (black[i][j] && !white[i][j])
                    cntB++;
                if (white[i][j] && !black[i][j])
                    cntW++;
            }
        }
        ans.push_back(make_pair(cntB, cntW));
    }
    for (pair<int, int> a : ans)
        cout << a.first << " " << a.second << endl;
}
