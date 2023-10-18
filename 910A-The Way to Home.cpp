#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
string s;
int ans=0;
bool dfs(int vertex){
    if(vertex==n){
        return true;
    }
    for(int i=d;i>=1;i--){
        if((vertex+i<=n) && s[vertex+i-1]=='1'){
            vertex+=i;
            ans++;
            if(dfs(vertex)){
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    
    cin>>n>>d;
    
    cin>>s;
    if(dfs(1)) cout<<ans<<endl;
    else cout<<-1<<endl;
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
