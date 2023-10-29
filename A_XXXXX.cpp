// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// void solve()
// {
//     int n,x;
//     cin>>n>>x;
//     vector<int> vc(n);
//     int sum=0;
//     for(int i=0;i<n;i++){
//         cin>>vc[i];
//         sum+=vc[i];
//     }
//     int lo=0,hi=n-1;
//     int k=n;
//     while(lo<=hi){
//         if(sum%k) break;
//         if((sum-vc[lo])%k==0){
//             sum-=vc[lo];
//             lo++;
//             k--;
//         }
//         else if((sum-vc[hi])%k==0){
//             sum-=vc[hi];
//             hi--;
//             k--;
//         }
//         else{
//             lo++;
//             hi--;
//             k-=2;
//         }
//     }
//     if(k<=0) k=-1;
//     cout<<k<<endl;
// }

// signed main()
// {
//     ios_base::sync_with_stdio(false);cin.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> vc(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>vc[i];
        sum+=vc[i];
    }
    int lo=0,hi=n-1;
    int k=n;
    int nw_sum=sum;
    while(lo<=hi){
        if(sum%x) break;
        sum-=vc[lo];
        lo++;
        k--;
    }
    lo=0,hi=n-1;
    int nw=n;
    while(lo<=hi){
        if(nw_sum%x) break;
        nw_sum-=vc[hi];
        hi--;
        nw--;
    }
    k = max(nw,k);
    if(k<=0) k=-1;
    cout<<k<<endl;
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