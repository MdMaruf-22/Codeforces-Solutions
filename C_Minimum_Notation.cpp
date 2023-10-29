#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;cin>>s;
    string t="";
    reverse(s.begin(),s.end());
    char mn='9';
    for(int i=0;i<s.size();i++){
        mn = min(s[i],mn);
        if(s[i]=='9') t.push_back(s[i]);
        else if(s[i]>mn) t.push_back(s[i]+1);
        else t.push_back(s[i]);
    }
    sort(t.begin(),t.end());
    cout<<t<<endl;
    
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