#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

const int N = 2e6 + 12;
const int M = 5001;
int n, m;
int arr[N];
map<tuple<int, int, int>, int> dp;
int cal(int i, int in, int st)
{

    if (i == n + 1)
    {
        return 0;
    }
    tuple<int, int, int> curr = make_tuple(i, in, st);
    if (dp.find(curr) != dp.end())
    {
        return dp[curr];
    }
    int ans = 0;
    if (arr[i] == 0)
    {

        ans = max(cal(i + 1, in + 1, st),
                  cal(i + 1, in, st + 1));
    }
    else if (arr[i] > 0)
    {
        if (in >= arr[i])
        {
            ans = 1 + cal(i + 1, in, st);
        }
        else
        {
            ans = cal(i + 1, in, st);
        }
    }
    else
    {
        if (st >= abs(arr[i]))
        {
            ans = 1 + cal(i + 1, in, st);
        }
        else
        {
            ans = cal(i + 1, in, st);
        }
    }
    dp[curr] = ans;
    return ans;
}
int main()
{

    // int n,m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cout << cal(1, 0, 0) << endl;
    return 0;
}