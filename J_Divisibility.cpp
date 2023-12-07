#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b) {
    if (b == 0)
        return a;
    if (b > a)
        return gcd(b, a);
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
void solve()
{
    int lc=2;
    for(int i=2;i<=10;i++) lc=lcm(lc,i);
    int n;cin>>n;
    int cnt = n/lc;
    cout<<cnt<<endl;
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
