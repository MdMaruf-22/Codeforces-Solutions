#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,k;cin>>n>>k;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    sort(vc.begin(),vc.end());
    vector<int> diff(n - 1);
    for (int i = 0; i < n - 1; i++) {
        diff[i] = vc[i+1] - vc[i];
    }
    int nw=0,cnt=0;
    bool flag= false;
    for(int i=0;i<n-1;i++){
        if(k >= (diff[i] * (i + 1))){
            k -= (diff[i] * (i + 1));
            vc[i] = vc[i+1];
            nw = vc[i];
            cnt = i+1;
        }
        else{
            int div = k / (i+1);
            k %=(i+1);
            vc[i] += div;
            nw = vc[i];
            cnt = i + 1;
            break;
        }
        if(i == n - 2) flag = true;
    }
    if(n==1){
        flag=true;
        nw=vc[0];
    }
    int div = k/n;
    int rem = k%n;
    int val = nw*n - (n-1);
    if(flag){
        nw += div;
        cout << rem + nw * n - (n - 1) << endl;
    }
    else cout << k+n+val-cnt << endl;
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
