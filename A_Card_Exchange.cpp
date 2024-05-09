#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    map<int,int> m;
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        m[a]++;
    }
    for(auto x:m){
        if(x.second>=k){
            cout<<k-1<<endl;
            return;
        }
    }
    cout<<n<<endl;
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
