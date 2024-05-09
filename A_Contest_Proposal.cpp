#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int i=0,j=0,k=0;
    int cnt=0;
    while(k<n){
        if(a[i]>b[j]){
            cnt++;
            j++;
        }
        else{
            i++;j++;
        }
        k++;
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
