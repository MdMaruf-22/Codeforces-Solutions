#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b;cin>>a>>b;
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    int mx = *max_element(vc.begin(),vc.end());
    int sum=0;
    for(int i=0;i<n;i++) sum+=vc[i];
    int low=mx,high=sum;
    while(low<high){
        int mid = low + (high-low)/2;
        int cnt=1,ans=0;
        bool f = true;
        for(auto x:vc){
            if(ans+x>mid){
                cnt++;
                ans=0;
                if(cnt>a){
                    f = false;
                    break;
                }
            }
            ans+=x;
        }
        if(f) high=mid;
        else low=mid+1; 
    }
    cout<<low*b<<endl;
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
