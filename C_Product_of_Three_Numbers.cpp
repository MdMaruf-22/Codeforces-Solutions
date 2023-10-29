#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    int k=n;
    if(n==1){
        cout<<"NO"<<endl;
        return;
    }
    unordered_map<int,int> mp;
    int cnt=0;
    for(int i=2;i*i<=n;i++){
        if(cnt==2) break;
        if(n%i==0 && !mp[i]){
            mp[i]++;
            cnt++;
            n/=i;
        }
    }
    mp[n]++;
    if(mp.size()<=2 || mp[k]) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(auto x:mp){
            if(x.first==k) continue;
            cout<<x.first<<" ";
        }
        cout<<endl;
    }
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
