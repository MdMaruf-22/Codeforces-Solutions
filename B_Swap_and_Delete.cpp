#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    cin>>s;
    int zero=0,one=0;
    for (int i = 0; i < s.length(); i++){
        if(s[i]=='0')zero++;
        else one++;
    }
    int ans=0;
    int i=0;
    for ( i =0;zero>=0&&one>=0; i++){
        if(s[i]=='1')zero--;
        else one--;    
    }
    cout<<(s.length()-i+1)<<endl; 
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
