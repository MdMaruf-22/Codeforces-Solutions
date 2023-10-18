#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> vec;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        vec.push_back(num);
    }
    int mn=*min_element(vec.begin(),vec.end());
    int mx=*max_element(vec.begin(),vec.end());
    int res=max(mx-vec[0],vec[n-1]-mn);
    for(int i=0;i<n-1;i++){
        res=max(res,vec[i]-vec[i+1]);
    }
    cout<<res<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
