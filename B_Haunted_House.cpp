#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    int lo=0,hi=n-1;
    while(lo<hi){
        swap(s[lo],s[hi]);
        lo++;
        hi--;
    }
    vector<pair<int,int>> vc;
    int cnt=0,cnt1=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            cnt++;
            vc.push_back({i,cnt});
        }
        else cnt1++;
    }
    int mxcnt=INT_MIN;
    for(int i=0;i<vc.size();i++){
        mxcnt = max(mxcnt,vc[i].second);
    }
    vector<int> ans;
    int mar=1,xx=0;
    for(auto x:vc){
        int cal = x.first+1-mar+xx;
        ans.push_back(cal);
        xx+=x.first+1-mar;
        mar++;
    }
    //for(auto x:ans) cout<<x<<" ";
    for(auto x:vc) cout<<x.second<<" ";
    for(int i=0;i<cnt1;i++){
        cout<<-1<<" ";
    }
    cout<<endl;
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

