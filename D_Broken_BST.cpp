#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    int left;
    int right;
};

void dfs(TreeNode tree[], set<int>& s, int node, int leftBound, int rightBound) {
    if (node == -1) return;
    if (tree[node].val > leftBound && tree[node].val < rightBound)
        s.insert(tree[node].val);
    dfs(tree, s, tree[node].left, leftBound, min(rightBound, tree[node].val));
    dfs(tree, s, tree[node].right, max(leftBound, tree[node].val), rightBound);
}

int main() {
    int n;
    cin >> n;
    TreeNode tree[n + 1];
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].val >> tree[i].left >> tree[i].right;
        if (tree[i].left != -1)
            vis[tree[i].left] = true;
        if (tree[i].right != -1)
            vis[tree[i].right] = true;
    }
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            root = i;
            break;
        }
    }
    set<int> s;
    dfs(tree, s, root, INT_MIN, INT_MAX);
    cout << n - s.size() << endl;
    return 0;
}
