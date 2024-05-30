#include<bits/stdc++.h>
using namespace std;
#define int long long

bool customSort(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}



void solve()
{
    int n,p;cin>>n>>p;
    vector<int> vc(n),vc1(n);
    for(int i=0;i<n;i++){
        cin>>vc[i];
    }
    for(int i=0;i<n;i++) cin>>vc1[i];
    vector<pair<int,int>> pr(n);
    for(int i=0;i<n;i++){
        int x = vc[i];
        int y = vc1[i];
        pr[i] = {y,x};
    }
    sort(pr.begin(),pr.end(),customSort);
    int cnt=0,making=0,total=0;
    total += p;
    making+=1;
    for(int i=0;i<n;i++){
        if(pr[i].first > p) break;
        if(making + pr[i].second >= n){
            total += (n-making)*pr[i].first;
            making = n;
        }
        else{
            making += pr[i].second;
            total += pr[i].first * pr[i].second;
        }
    }
    total += (n-making)*p;
    cout<<total<<endl;
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
