#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;

    map<string,int> mp;
    while(t--){
        
        string s;
        cin>>s;
        mp[s]++;
        if(mp[s]==1){
            cout<<"OK"<<endl;
        }
        else{
            cout<<s<<mp[s]-1<<endl;
        }
    }
    return 0;
}
