#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    bool f=false;
    for(int i=1;i<n;i++){
        if(vc[i]!=vc[i-1]){
            f = true;
            break;
        }
    }
    if(!f){
        cout<<"YES"<<endl;
        return;
    }
    sort(vc.begin(),vc.end());
    f=true;
    bool k=true;
    for(int i=0;i<n;i++){
        if(vc[i]==1) f=false;
        if(vc[i]==0) k=false;
    }
    if(!f && !k){
        cout<<"NO"<<endl;
        return;
    }
    if(!f && k){
        bool fck=true;
        for(int i=1;i<n;i++){
            if(vc[i]-vc[i-1]==1){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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