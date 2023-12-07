#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b;cin>>a>>b;
    if(a==1 || b==1){
        cout<<"Finite"<<endl;
        return;
    }
    int val = a*b-a-b;
    if(a>b) swap(a,b);
    for(int i=val+1;i<=val+3;i++){
        int x = i;
        bool f = false;
        while(x>=0){
            if(x%a==0){
                f=true;
                break;
            }
            x-=b;
        }
        if(!f){
            cout<<"Infinite"<<endl;
            return;
        }
    }
    cout<<"Finite"<<endl;
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
