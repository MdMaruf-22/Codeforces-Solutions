#include<bits/stdc++.h>
using namespace std;
#define int long long

int cntdigit(int val){
    int cnt=0;
    while(val!=0){
        val/=10;
        cnt++;
    }
    return cnt;
}

void solve()
{
    int a,b,c;cin>>a>>b>>c;
    int gcd = 1;
    for(int i=1;i<c;i++) gcd*=10;
    int nw_a = gcd,nw_b=gcd;
    while(1){
        if(cntdigit(nw_a)==a) break;
        nw_a*=2;
    }
    while(1){
        if(cntdigit(nw_b)==b) break;
        nw_b*=5;
    }
    // cout<<__gcd(nw_a,nw_b)<<endl;
    cout<<nw_a<<" "<<nw_b<<endl;
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




