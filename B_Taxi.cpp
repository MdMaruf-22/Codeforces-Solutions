#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    map<int,int> mp;
    for(int i=0;i<n;i++) mp[vc[i]]++;
    int sum = mp[4];
    sum+=mp[3];
    mp[1]-=mp[3];
    sum+=(mp[2]/2);
    int x = mp[2]/2;
    mp[2]-=(x*2);
    if(mp[2]>0){
        sum+=1;
        mp[1]-=2;
    }
    if(mp[1]>0) sum+=ceil((mp[1]*1.0/4));
    cout<<sum<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
