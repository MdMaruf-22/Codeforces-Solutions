#include<bits/stdc++.h>
using namespace std;

#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int MAX = 3e5 + 10;
struct Node {
    int parent;
    bool hasParent;
};

vector<Node> nodes(MAX);
int query(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int x;
    cin >> x;
    return x;
}

void make_edge(int a, int b) {
    if (a == b) return;
    if (nodes[b].hasParent) return;
    int x = query(a, b);
    if (x == a) {
        nodes[b].parent = a;
        nodes[b].hasParent = true;
        return;
    }
    make_edge(a, x);
    make_edge(x, b);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        nodes[i].parent = 0;
        nodes[i].hasParent = false;
    }

    for (int i = 1; i <= n; ++i) {
        if (!nodes[i].hasParent) make_edge(1, i);
    }

    cout << "!";
    for (int i = 2; i <= n; ++i) {
        cout << ' ' << i << ' ' << nodes[i].parent;
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
