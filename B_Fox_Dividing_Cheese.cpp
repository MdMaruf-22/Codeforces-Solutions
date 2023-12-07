#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b;cin>>a>>b;
    int gcd = __gcd(a,b);
    a/=gcd;
    b/=gcd;
    vector<int> vc1(3,0),vc2(3,0);
    while(a%2==0){
        a/=2;
        vc1[0]++;
    }
    while(b%2==0){
        b/=2;
        vc2[0]++;
    }
    while(a%3==0){
        a/=3;
        vc1[1]++;
    }
    while(b%3==0){
        b/=3;
        vc2[1]++;
    }
    while(a%5==0){
        a/=5;
        vc1[2]++;
    }
    while(b%5==0){
        b/=5;
        vc1[2]++;
    }
    int fr_a=vc1[0]+vc1[1]+vc1[2],fr_b=vc2[0]+vc2[1]+vc2[2];
    if(a==b){
        cout<<fr_a+fr_b<<endl;
        return;
    }
    cout<<-1<<endl;
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
