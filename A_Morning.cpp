#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    // int n;cin>>n;
    string a;
    cin >> a;

    string s = "1234567890987654321234567890987654321234567890";
    char x = a[0];
    char b = a[1];
    char c = a[2];
    char d = a[3];
    int cnt = 0;
    int ind = 0;
    while (x != s[ind])
        cnt++, ind++;
    if (x == s[ind])
        cnt++;
    while (b != s[ind])
        cnt++, ind++;
    if (b == s[ind])
        cnt++;
    while (c != s[ind])
        cnt++, ind++;
    if (c == s[ind])
        cnt++;
    while (d != s[ind])
        cnt++, ind++;
    if (d == s[ind])
        cnt++;
    cout << cnt << endl;
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
