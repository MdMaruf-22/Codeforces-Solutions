#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='9' && i!=0){
            s[i]='0';
        }
        else if(s[i]=='8'){
            s[i]='1';
        }
        else if(s[i]=='7'){
            s[i]='2';
        }
        else if(s[i]=='6'){
            s[i]='3';
        }
        else if(s[i]=='5'){
            s[i]='4';
        }
    }
    cout<<s<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
