// Chain Disappearance Puzzle (200)
// 2020/11/25

#include <bits/stdc++.h>

using namespace std;

const int W = 5;
int h;

bool isequal(vector<int> row, int s, int t)
{
    // out of puzzle
    if (row[2] == 0)
        return false;

    bool iseq = true;
    for (int i = s; i < t; i++)
        iseq &= (row[i] == row[i + 1]);

    return iseq;
}

int solve(vector<vector<int>> puzzle, int h)
{
    int score = 0;

    while (true)
    {
        int prevscore = score;
        for (int i = h - 1; i >= 0; i--)
        {
            // already found disapperance in the row
            bool found = false;

            for (int num = 5; num >= 3; num--)
            {
                for (int j = 0; j + num - 1 < W; j++)
                {
                    if (isequal(puzzle[i], j, j + num - 1))
                    {
                        score += (num * puzzle[i][2]);
                        for (int k = j; k <= j + num - 1; k++)
                            puzzle[i][k] = 0; // disappear
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
        }

        // re-fill the puzzle
        vector<vector<int>> newpuzzle(h, vector<int>(W)); // 0

        for (int j = 0; j < W; j++)
        {
            int newi = h - 1;
            for (int i = h - 1; i >= 0; i--)
            {
                if (puzzle[i][j] != 0)
                {
                    newpuzzle[newi][j] = puzzle[i][j];
                    newi--;
                }
            }
        }
        puzzle = newpuzzle;

        if (prevscore == score)
            break;
    }
    return score;
}

int main()
{
    vector<int> ans;
    while (true)
    {
        int h;
        cin >> h;
        if (h == 0)
            break;

        vector<vector<int>> puzzle(h, vector<int>(W));

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cin >> puzzle[i][j];
            }
        }
        ans.push_back(solve(puzzle, h));
    }
    for (int a : ans)
        cout << a << endl;
}
