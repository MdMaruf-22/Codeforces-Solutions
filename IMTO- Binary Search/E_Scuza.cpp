#include <bits/stdc++.h>
using namespace std;
#define int long long

int binarySerach(vector<int>& vc,int target){
    int lo=0,hi=vc.size();
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        if(vc[mid]<=target) lo=mid+1;
        else hi=mid;
    }
    return lo;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> vc(n), presum(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> vc[i];
    for (int i = 1; i <= n; i++)
        presum[i] = vc[i - 1] + presum[i - 1];
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        m = max(m, vc[i]);
        vc[i] = m;
    }
    while (q--)
    {
        int x;
        cin >> x;
        int y = binarySerach(vc, x);
        cout << presum[y] << " ";
    }
    cout << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
