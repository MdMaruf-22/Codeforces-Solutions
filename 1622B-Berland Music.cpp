#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;
    int p[n];
    string s;
    for(int i=0;i<n;i++) cin>>p[i];
    cin>>s;
    vector<int> q1,q2;
    for(int i=0;i<n;i++){
        if(s[i]=='0') q1.push_back(p[i]);
        else q2.push_back(p[i]);
    }
    sort(q1.rbegin(),q1.rend());
    sort(q2.rbegin(),q2.rend());
    int sz1=q1.size();
    int sz2=sz1;
    int nw=n;
    int arr[n+1];
    for(int i=0;i<q1.size();i++){
        cout<<p[i]<<" ";
        arr[p[i]]=sz1;
        sz1--;
    }
    //for(int i=0;i<n+1;i++) cout<<arr[i]<<" ";
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
