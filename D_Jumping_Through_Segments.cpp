#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

bool chk(int mid,vector<pair<int,int>>& vc){
    int left=0,right=0;
    for(auto x:vc){
        left -= mid;
        right += mid;
        left = max(left, x.first);
        right = min(right, x.second);
        if(left>right) return false;
    }
    return true;
}

void solve()
{
    int n;cin>>n;
    vector<pair<int,int>> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i].first>>vc[i].second;
    int lo=0,hi=1e9;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(chk(mid,vc)){
            hi=mid-1;
        }
        else lo=mid+1;
    }
    cout<<lo<<endl;
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
