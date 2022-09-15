#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    unordered_map<int,int> ump;
    unordered_map<int,int>::iterator it;
    pair<int,int> ent=make_pair(0,0);
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        ump.insert({num,i});
    }
    for(it=ump.begin();it!=ump.end();it++){
        if(it->first>ent.first){
            ent=make_pair(it->first,it->second);
        }
    }
    cout<<ent.second<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
