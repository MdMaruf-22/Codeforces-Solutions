#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a,int b){
    if(b==0) return a;
    if(b>a) return gcd(b,a);
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
void solve()
{
    string a,b;cin>>a>>b;
    string nw_a="",nw_b="";
    int lc = lcm(a.size(),b.size());
    for(int i=0;i<lc/b.size();i++) nw_b+=b;
    for(int i=0;i<lc/a.size();i++) nw_a+=a;
    if(nw_a==nw_b){
        cout<<nw_a<<endl;
    }
    else cout<<-1<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
