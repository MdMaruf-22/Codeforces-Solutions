#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a,int b){
    if(b==0) return a;
    if(b>a) return gcd(b,a);
    return gcd(b,a%b);
}


void solve()
{
    int n;cin>>n;
    vector<pair<int,int>> vc(n);
    int mn = INT_MAX;
    for(int i=0;i<n;i++){
        cin>>vc[i].first;
        vc[i].second=i;
        if(vc[i].first<mn) mn=vc[i].first;
    }
    sort(vc.begin(),vc.end());
    bool f = true;
    for(int i=0;i<n;i++){
        int ind = vc[i].second;
        int val = vc[i].first;
        if(ind==i) continue;
        if(gcd(val,mn)!=mn){
            f=false;
            break;
        } 
    }
    if(!f) cout<<"NO"<<endl;
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
