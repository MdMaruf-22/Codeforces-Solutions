#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,k;cin>>n>>k;
    vector<int> vc(n);

    for(int i=0;i<n;i++){
        cin>>vc[i];
    }
    bool f=true;
    for(int i=0;i<n-1;i++){
        if(vc[i]>vc[i+1]){
            f=false;
            break;
        }
    }
    if(f){
        cout<<"YES"<<endl;
        return;
    }
    if(k==1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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
