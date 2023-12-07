#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;cin>>s;
    if(s.size()==1){
        int val = s[s.size()-1]-'0';
        if(val%4==0) cout<<4<<endl;
        else cout<<0<<endl;
        return;
    }
    int dec = s[s.size()-2]-'0';
    int ekok = s[s.size()-1]-'0';
    int num = dec*10+ekok;
    if(num%4==0) cout<<4<<endl;
    else cout<<0<<endl;
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
