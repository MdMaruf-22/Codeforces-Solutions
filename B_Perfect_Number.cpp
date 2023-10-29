#include<bits/stdc++.h>
using namespace std;
#define int long long
bool sum(int n){
    int sum=0;
    while(n>0){
        sum+= n%10;
        n/=10;
    }
    return sum==10;
}

void solve()
{   
    int n;cin>>n;
    int ans;
    for(int i=19;n;i+=9){
        if(sum(i)){
            n--;
            ans=i;
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
