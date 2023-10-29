#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    string k = "01";
    int lo=0,hi=n-1;
    while(1){
        if(s[lo]==s[hi]){
            s.push_back('0');
            s.push_back('1');
        }
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
