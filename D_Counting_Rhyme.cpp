#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    map<int,int> mp;
    for(int i=0;i<n;i++) cin>>vc[i],mp[vc[i]]++;
    int ttl = (n*(n-1))/2;
    int ans=0;

    for (auto p : mp) {
        int x = p.first;
        int y = p.second;
        if (x == 1) {
            ans += n - 1;
            continue;
        }
        ans += (y * (y - 1)) / 2;
        for (int j = 2;j <= sqrt(x); j++) {
            if (x % j == 0) {
                ans += mp[j];
                if (j != x / j){
                    ans += mp[x / j];
                }
            }
        }
    }
    
    cout<<ttl<<" "<<ans<<endl;
    for(auto x:mp){
        int cl = (x.second*(x.second-1))/2;
        if(cl==0) continue;
        ttl-=(cl-1);
    }
    cout<<ttl-ans<<endl;

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
