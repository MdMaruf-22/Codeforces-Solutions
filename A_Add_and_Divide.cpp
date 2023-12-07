#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b;cin>>a>>b;
    int mx = INT_MAX;
    for(int i=0;i<mx;i++){
        int fck = b+i;
        int sx = a;
        int cnt = i;
        if(fck==1) continue;;
        while(sx){
            ++cnt;
            sx/=fck;
        }
        mx = min(mx,cnt);
    }
    cout<<mx<<endl;
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
