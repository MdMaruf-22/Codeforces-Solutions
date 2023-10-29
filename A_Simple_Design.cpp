#include<bits/stdc++.h>
using namespace std;
#define int long long

int sum(int x){
    int sum = 0;
    while(x>0){
        sum += (x%10);
        x/=10;
    }
    return sum;
}
void solve()
{
    int x,k;
    cin>>x>>k;
    int val;
    int sm = sum(x);
    if(sm%k==0){
        cout<<x<<endl;
        return;
    }
    while(true){
        x++;
        sm = sum(x);
        if(sm%k==0) break;
    } 
    cout<<x<<endl;
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
