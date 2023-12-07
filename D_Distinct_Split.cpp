#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    map<char,int> mp1,mp2;
    for(auto x:s){
        mp2[x]++;
    }
    
    int mx = INT_MIN;
    int sz=mp2.size();
    for(int i=0;i<n;i++){
        mp1[s[i]]++;
        mp2[s[i]]--;
        if(mp2[s[i]]==0) sz--;
        int val = mp1.size()+sz;
        mx = max(mx,val);
    }
    cout<<mx<<endl;
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
