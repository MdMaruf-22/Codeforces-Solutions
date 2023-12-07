#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    sort(vc.begin(),vc.end());
    int cnt=0;
    int lo=0,hi=n-1;
    int combo=n;
    while(lo<hi){
        int val = min(vc[lo],vc[hi]);
        if(val>0){
            if(combo>hi) cnt++;
            combo=hi;
        }
        vc[lo]-=val;
        vc[hi]-=val;
        cnt+=val;
        if(vc[lo]==0) lo++;
        if(vc[hi]==0) hi--;
    }
    if(lo==hi){
        if(vc[lo]==1) cnt++;
        else{
            cnt+=((vc[lo]+1)/2);
            if(combo>lo) cnt++;
        }
    }
    cout<<cnt<<endl;
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
