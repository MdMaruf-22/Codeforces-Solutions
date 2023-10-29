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
    int a,b;cin>>a>>b;
    if(b==1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int cnt = a*b;
    cout<<a<<" "<<cnt<<" "<<a+cnt<<endl;
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
