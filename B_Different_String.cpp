#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;cin>>s;
    map<char,int> m;
    for(auto x:s) m[x]++;
    if(m.size()==1){
        cout<<"NO"<<endl;
    }
    else{
        int x=0;
        for(int i=1;i<s.size();i++){
            if(s[0]!=s[i]){
                x=i;
                break;
            }
        }
        swap(s[0],s[x]);
        cout<<"YES"<<endl<<s<<endl;
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
