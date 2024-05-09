#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{   
    string s;cin>>s;
    int ans=0,cnt=0;
    vector<int> dp(s.size()+1,0);
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            //cnt++;
            dp[i] = cnt++;
        }
        else if(cnt) {
            //ans+=(cnt+1);
            dp[i] = cnt+1;
        }
    }
    int sum=0;
    for(auto x:dp) sum+=x; 
    cout<<sum<<endl;
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
