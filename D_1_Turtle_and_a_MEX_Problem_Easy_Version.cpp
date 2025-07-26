#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n,m;cin>>n>>m;
    vector<int> mn(n),mn2(n);
    for(int i=0;i<n;i++){
        int q;cin>>q;
        set<int> st;
        while(q--){
            int x;cin>>x;
            st.insert(x);
        }
        int fnd = 0;
        while(st.count(fnd)) fnd++;
        mn[i] = fnd;
        st.insert(mn[i]);
        fnd=0;
        while(st.count(fnd)) fnd++;
        mn2[i] = fnd;
    }
    int mx = *max_element(mn2.begin(),mn2.end());
    int ans=0;
    ans = min(m + 1, mx + 1) * mx;
    if(m>mx){
        int all = m*(m+1)/2;
        int rem = mx*(mx+1)/2;
        ans += (all-rem);
    }
    cout<<ans<<endl;
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
