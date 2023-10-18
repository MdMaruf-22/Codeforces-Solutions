#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a-1==abs(b-c)+(c-1)) cout<<3<<endl;
    else if(a-1<abs(b-c)+(c-1)) cout<<1<<endl;
    else cout<<2<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
