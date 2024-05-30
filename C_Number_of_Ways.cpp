#include<bits/stdc++.h>
using namespace std;
#define int long long

int binarySearch(vector<int>& pos2, int target){
    int lo=0,hi=pos2.size()-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(pos2[mid]<target) lo = mid+1;
        else hi=mid-1;
    }
    return lo;
}


void solve() {
    int n; cin >> n;
    vector<int> vc(n);
    for(int i = 0; i < n; i++) cin >> vc[i];
    vector<int> preSum(n + 1);
    preSum[0] = 0;
    for(int i = 1; i <= n; i++) preSum[i] = preSum[i - 1] + vc[i - 1];
    int sum = preSum[n];
    if(sum%3!=0){
        cout<<0<<endl;
        return;
    }
    int target = sum/3;
    int targetMid = 2*target;
    vector<int> pos1,pos2;
    for(int i=1;i<n;i++){
        if(preSum[i]==target) pos1.push_back(i);
        if(preSum[i]==targetMid) pos2.push_back(i);
    }
    int ans=0;
    for(auto x:pos1){
        int ind = binarySearch(pos2,x+1);
        //cout<<ind<<endl;
        ans += pos2.size()-ind;
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}