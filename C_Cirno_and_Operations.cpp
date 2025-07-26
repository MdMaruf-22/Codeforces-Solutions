#include <bits/stdc++.h>
using namespace std;
#define int long long

set<vector<int>> s;

vector<int> diff(const vector<int> &seq)
{
    vector<int> diffseq;
    for (size_t i = 1; i < seq.size(); ++i)
    {
        diffseq.push_back(seq[i] - seq[i - 1]);
    }
    return diffseq;
}

int calc(vector<int> &seq)
{
    if (seq.size() <= 1)
    {
        if (seq.empty())
        {
            return LLONG_MIN;
        }
        else
        {
            return seq[0];
        }
    }

    if (s.count(seq))
        return LLONG_MIN;
    s.insert(seq);

    int curr = accumulate(seq.begin(), seq.end(), 0LL);

    vector<int> rev(seq.rbegin(), seq.rend());
    int rsum = calc(rev);
    vector<int> diffseq = diff(seq);
    int dsum = calc(diffseq);
    return max({curr, rsum, dsum});
}

void solve()
{
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }

    s.clear();
    cout << calc(vc) << endl;
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
