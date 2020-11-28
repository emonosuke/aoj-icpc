// Thread Tree (200)
// 2020/11/26

#include <bits/stdc++.h>

using namespace std;

struct ThreadTree
{
    int depth;
    string message;
    vector<ThreadTree *> subnodes;

    ThreadTree(int d, string m)
    {
        depth = d;
        message = m;
    }

    void add_subnode(ThreadTree *tree)
    {
        subnodes.push_back(tree);
    }

    void print()
    {
        for (int i = 0; i < depth; i++)
            cout << ".";
        cout << message << endl;
        for (ThreadTree *subnode : subnodes)
            subnode->print();
    }
};

int main()
{
    int n;
    cin >> n;

    vector<ThreadTree *> trees;

    int k;
    cin >> k;
    assert(k == 0);
    string message;
    cin >> message;
    trees.push_back(new ThreadTree(0, message));
    for (int i = 1; i < n; i++)
    {
        int k;
        cin >> k;
        string message;
        cin >> message;
        ThreadTree *tree = new ThreadTree(trees[k - 1]->depth + 1, message);
        trees[k - 1]->add_subnode(tree);
        trees.push_back(tree);
    }

    trees[0]->print();
}
