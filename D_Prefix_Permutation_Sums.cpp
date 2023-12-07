#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n-1);
    for(int i=0;i<n-1;i++) cin>>vc[i];
    int mx = *max_element(vc.begin(),vc.end());
    int sum = (n*(n+1))/2;
    if(mx>sum){
        cout<<"NO"<<endl;
        return;
    }
    bool f=false;
    for(auto x:vc){
        if(x==sum){
            f=true;
            break;
        }
    }
    vector<int> chk;
    map<int,int> mp;
    if(!f){
        chk.push_back(vc[0]);
        for(int i=1;i<vc.size();i++) chk.push_back(vc[i]-vc[i-1]);
        chk.push_back(sum-vc.back());
        int k;
        for(auto x:chk) mp[x]++;
        for(auto x:mp){
            k=x.first;
        }
        if(k==n && mp.size()==n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    mp[vc[0]]++;
    for(int i=1;i<vc.size();i++){
        int dif = vc[i]-vc[i-1];
        mp[dif]++;
    }
    int cnt=0,val;
    for(auto x:mp){
        if(x.second>1){
            val=x.first;
            cnt++;
        }
    }
    if(cnt>1){
        cout<<"NO"<<endl;
        return;
    }
    sum=0;
    for(int i=1;i<=n;i++){
        if(!mp[i]) sum+=i;
    }
    if(mp[sum]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
