#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
vector<int> ice[N];
bool vis[N];

void dfs(int pos){
    vis[pos] = true;
    for(auto child:ice[pos]){
        if(vis[child]) continue;
        dfs(child);
    }
}


void solve()
{
    int n;cin>>n;
    vector<pair<int,int>> vc(n);
    for(int i=0;i<n;i++){
        cin>>vc[i].first>>vc[i].second;
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((vc[i].first == vc[j].first) || (vc[i].second == vc[j].second)){
                ice[i].push_back(j);
                ice[j].push_back(i);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
            
        }
    }
    cout<<cnt-1<<endl;
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
