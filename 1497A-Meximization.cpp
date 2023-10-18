#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> freq(200,0);
    for(int i=0;i<n;i++) freq[arr[i]]++;
    for(int i=0;i<200;i++){
        if(freq[i]>0){
            cout<<i<<" ";
            --freq[i];
        }
    }
    for(int i=0;i<200;i++){
        if(freq[i]>0){
            for(int j=0;j<freq[i];j++){
                cout<<i<<" ";
            }
        }
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
