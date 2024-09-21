#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

using namespace std;

const int N = 2e5 + 10;
vector<int> vc(N),black(N);      
vector<bool> vis(N);
void dfs(int vertex, vector<int>& cycle, int& cnt) {
    vis[vertex] = true;
    cycle.push_back(vertex);
    cnt += black[vertex];
    int nxt = vc[vertex]; 
    if (!vis[nxt]) {
        dfs(nxt, cycle, cnt);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> vc[i];         
        vc[i]--;             
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if(s[i]=='0') black[i] = 1;
        else black[i] = 0;
        vis[i] = false;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vector<int> cycle;
            int cnt = 0;
            dfs(i, cycle, cnt);
            for (auto vertex : cycle) {
                ans[vertex] = cnt; 
            }
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " "; 
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
