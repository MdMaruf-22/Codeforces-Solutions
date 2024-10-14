#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int b, c, d;
    cin >> b >> c >> d;

    int a = 0;           
    int mask = 1;         
    bool flag = true; 

    for (int i = 0; i < 62; i++)
    {
        bool bit_b = (b & mask) != 0;
        bool bit_c = (c & mask) != 0;
        bool bit_d = (d & mask) != 0;

        //b=1,c=0,d=0 and b=0,c=1,d=1 hoile impossible
        if (bit_b == 1 && bit_c == 0 && bit_d == 0) {
            flag = false;
            break;
        }
        if (bit_b == 0 && bit_c == 1 && bit_d == 1) {
            flag = false;
            break;
        }
        //Set the bit for a by trying all the 8 combo for b,c,d
        if (bit_b && bit_c){
            if (!bit_d) a |= mask;
        }
        else{
            if (bit_d) a |= mask;
        }
        mask <<= 1;
    }

    if (flag) cout << a << endl;
    else cout << -1 << endl;
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
