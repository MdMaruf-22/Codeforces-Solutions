#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a, b, c;
        cin >> a >> b >> c;
        int prod = a * b * c;
        for (int i = 0; i <= 5; ++i) {
            for (int j = 0; j <= 5 - i; ++j) {
                int nw = 5 - i - j;
                int newA = a + i;
                int newB = b + j;
                int newC = c + nw;
                int fck = newA * newB * newC;
                prod = max(prod, fck);
            }
        }
        
        cout << prod << endl;
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
