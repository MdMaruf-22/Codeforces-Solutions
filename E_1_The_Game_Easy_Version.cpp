#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 400010;
vector<int> tree[N + 1];
vector<int> vc(N);
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        tree[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        cin >> vc[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int root = 1;

    vector<pair<int, int>> pr;
    for (auto child : tree[root]) {
        pr.emplace_back(vc[child], child);
    }

    sort(pr.rbegin(), pr.rend());

    if (pr.empty()) {
        cout << "0" << endl;
        return;
    }

    if (pr.size() == 1) {
        if (pr[0].first < vc[root]) cout << pr[0].second << endl;
        else cout << "0" << endl;
        return;
    }

    int mx = pr[0].first;
    int sc = -1;
    for(auto x:pr){
        cout<<x.first<<" "<<x.second<<endl;
        if(x.first<mx){
            sc=x.second;
            //break;
        }
    }
    cout<<mx<<" "<<sc<<endl;
    if(sc==-1){
        cout<<"0"<<endl;
        return;
    }
    for (auto x : pr) {
        if (x.first == sc) {
            cout << x.second << endl;
            return;
        }
    }
    cout << "0" << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
