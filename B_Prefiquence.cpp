#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,m;cin>>n>>m;
    string a,b;cin>>a>>b;
    int i=0,j=0;
    int cnt=0,mx = 0;
    while(i<n && j<m){
        if(a[i]==b[j]){
            i++;
            cnt++;
            mx = max(mx, cnt);
        }
        j++;
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
