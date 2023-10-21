#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9;
int func(string s1,string s2){
    int n = s1.size()-1;
    int ans=0;
    while(n>=0 && s1[n]!=s2[1]){
        ans++;
        n--;
    }
    if(n<0) return INF;
    n--;
    while (n>=0 && s1[n]!=s2[0])
    {
        ans++;
        n--;
    }
    if(n<0) return INF;
    return ans;
    
}
void solve()
{
    string s;cin>>s;
    int ans = min(min(min(func(s,"00"),func(s,"25")),func(s,"50")),func(s,"75"));
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
