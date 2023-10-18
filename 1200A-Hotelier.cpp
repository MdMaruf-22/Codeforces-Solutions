#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    vector<int> vc(10,0);
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            for(int i=0;i<10;i++){
                if(vc[i]==0){
                    vc[i]=1;
                    break;
                }
            }
        }
        else if(s[i]=='R'){
            for(int i=9;i>=0;i--){
                if(vc[i]==0){
                    vc[i]=1;
                    break;
                }
            }
        }
        else if(s[i]>='0' && s[i]<='9') vc[s[i]-'0']=0;
    }
    for(auto x:vc) cout<<x;
    cout<<endl;
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
