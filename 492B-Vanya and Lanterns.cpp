#include <bits/stdc++.h>
using namespace std;
#define int long long

double binarySearch(vector<int> &vc, int l, int n)
{
    double lo = 0.0;
    double hi = l;
    double ans = 0.0;
    while (hi - lo > 1e-9)
    {
        double mid = (hi + lo) / 2.0;
        bool f = true;
        for (int i = 1; i < n; i++)
        {
            double gap = vc[i] - vc[i - 1];
            if (gap > 2 * mid)
            {
                f = false;
                break;
            }
        }
        if (mid < vc.front() || mid < l - vc.back())
            f = false;
        if (f)
        {
            ans = mid;
            hi = mid;
        }
        else
            lo = mid;
    }
    return ans;
}

void solve()
{
    int n, l;
    cin >> n >> l;
    vector<int> vc(n);
    
    for (int i = 0; i < n; i++)
        cin >> vc[i];
    sort(vc.begin(), vc.end());
    auto it = unique(vc.begin(), vc.end());
    vc.resize(distance(vc.begin(), it));
    if (vc.size() == 1)
    {
        if(vc[0]==l){
            cout << fixed << setprecision(10) << l*1.00 << endl;
            return;
        }
        double x = l-vc[0];
        double y = vc[0]-0;
        cout << fixed << setprecision(10)<<max(x,y)*1.00<<endl;
        return;
    }
    
    double ans = binarySearch(vc, l, n);
    cout << fixed << setprecision(10) << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
