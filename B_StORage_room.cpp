#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int vc[n];
    int mx = pow(2,30)-1;
    for(int i=0;i<n;i++){
        int val = mx;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            val = val & arr[i][j];
        }
        vc[i]=val;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if((vc[i]|vc[j])!=arr[i][j]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++) cout<<vc[i]<<" ";
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
