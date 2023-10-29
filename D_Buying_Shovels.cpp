#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b;
    cin>>a>>b;
    map<int,int> mp;
    for(int i=1;i*i<=a;i++){
        if(a%i==0){
            mp[i]++;
            mp[a/i]++;
        }
    }
    //reverse(mp.begin(),mp.end());
    int pack;
    for(auto x:mp){
        if(x.first<=b){
            pack = x.first;
        }
    }
    int ttl = a/pack;
    cout<<ttl<<endl;
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
