#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{   int n,q;cin>>n>>q;
    string a,b;cin>>a>>b;
    vector<unordered_map<char,int>> prefA(n+1),prefB(n+1);
    for(int i=0;i<n;i++){
        prefA[i+1] = prefA[i];
        prefB[i+1] = prefB[i];
        prefA[i+1][a[i]]++;
        prefB[i+1][b[i]]++;
    }

    while (q--)
    {
        /* code */
        int l,r;cin>>l>>r;
        l--,r--;
        unordered_map<char,int> freqA,freqB;
        for(char ch = 'a';ch<='z';ch++){
            freqA[ch] = prefA[r+1][ch] - prefA[l][ch];
            freqB[ch] = prefB[r+1][ch] - prefB[l][ch];
        }
        int ans=0;
        for(char ch='a';ch<='z';ch++) ans+=abs(freqA[ch]-freqB[ch]);
        //cout<<ans<<endl;
        ans/=2;
        cout<<ans<<endl;
    }
    
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
