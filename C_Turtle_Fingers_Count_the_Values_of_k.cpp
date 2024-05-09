#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int l,a,b;
    cin>>a>>b>>l;
    set<int> s;
    for(int i=0;i<=20;i++){
        int pw_a = pow(a,i);
        for(int j=0;j<=20;j++){
            int power = pow(a,i)*pow(b,j);
            if(power>l){
                break;
            }
            if(l%power==0) s.insert(power);
        }
    }
    cout<<s.size()<<endl;
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
