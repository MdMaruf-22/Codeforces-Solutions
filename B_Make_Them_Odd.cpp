#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    map<int,int,greater<int>> mp;
    for(int i=0;i<n;i++){
        if(vc[i]%2==0) mp[vc[i]]++;
    }
    int cnt=0;
    for(auto x:mp){
        int val = x.first;
        while(val%2==0){
            val/=2;
            cnt++;
            mp[val]++;
            mp.erase(val);
        }
    }
    cout<<cnt<<endl;
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
