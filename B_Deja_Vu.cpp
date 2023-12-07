#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,q;cin>>n>>q;
    vector<int> vc(n,0);
    for(int i=0;i<n;i++) cin>>vc[i];
    vector<int> fck;
    int las=0;
    for(int i=0;i<q;i++){
        int val;cin>>val;
        if(fck.size()==0){
            fck.push_back(val);
            las=val;
        }
        if(las>val){
            fck.push_back(val);
            las=val;
        }
    }
    for(int i=0;i<n;i++){
        for(auto &x:fck){
            int po = pow(2,x);
            if(vc[i]%po==0){
                vc[i] += pow(2,x-1);
            }
        }
    }
    for(auto x:vc) cout<<x<<" ";
    cout<<endl;
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
