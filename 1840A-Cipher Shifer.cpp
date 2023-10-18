#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    int cnt=0;
    bool f=false;
    int ind=0;
    string nw="";
    for(int i=0;i<n;i++){
        char ch=s[i];
        for(int j=i+1;j<n;j++){
            if(s[j]==ch){
                nw+=ch;
                f=true;
                i=j;
                break;
            }
        }
    }
    cout<<nw<<endl;
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
