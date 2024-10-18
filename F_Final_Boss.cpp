#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int h, n;
    cin >> h >> n;
    vector<int> vc1(n), vc2(n);
    for(int i=0;i<n;i++) cin>>vc1[i];
    for(int i=0;i<n;i++) cin>>vc2[i];
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({1, i});
    }

    int ans = 1;
    while (h > 0) {
        pair<int, int> curr = pq.top();
        int turn = curr.first;
        int ind = curr.second;
        pq.pop();
        ans = turn;
        h -= vc1[ind];
        pq.push({turn + vc2[ind], ind});
    }
    cout << ans << "\n";
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
