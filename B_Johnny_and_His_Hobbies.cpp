#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>vc[i];
        m[vc[i]]++;
    }
    for(int k=1;k<=1024;k++){
        int cnt=0;
        map<int,int> nw_mp = m;
        for(int i=0;i<n;i++){
            int nw = vc[i]^k;
            if(nw_mp.find(nw)!=nw_mp.end()){
                cnt++;
                nw_mp[nw]--;
            }
        }
        if(cnt==n){
            cout<<k<<endl;
            return;
        }
    }
    cout<<-1<<endl;

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
