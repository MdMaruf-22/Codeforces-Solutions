#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n,x;
    cin>>n>>x;
    if(n==1||n==2) cout<<1<<endl;
    else{
        int ans=ceil((n-2)*1.00/x);
        cout<<ans+1<<endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
