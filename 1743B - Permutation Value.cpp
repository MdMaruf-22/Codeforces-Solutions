#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc;
    if(n%2==0){
        for(int i=n-1;i>=1;i-=2) vc.push_back(i);
        for(int i=n;i>=2;i-=2) vc.push_back(i);
    }
    else{
        for(int i=n-1;i>=2;i-=2) vc.push_back(i);
        for(int i=n;i>=1;i-=2) vc.push_back(i);
    }
    for(auto x:vc) cout<<x<<" ";
    cout<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
