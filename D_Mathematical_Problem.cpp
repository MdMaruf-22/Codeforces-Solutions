#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    if(n<=2){
        int first = s[0] - '0';
        int second = s[1] - '0';
        int ans = first * 10 + second;
        cout<<ans<<endl;
        return;
    }
    if (n == 3) {
        int first = s[0] - '0';
        int second = s[1] - '0';
        int third = s[2] - '0';
        int ans = min((first*10 + second) * third, first * (second*10 + third));
        int ans2 = min(first*10 + second +third, first + (second*10 + third));
        //cout<<s<<" "<<min(ans,ans2)<<endl;
        cout<<min(ans,ans2)<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            //cout<<s<<" " <<0<<endl;
            cout<<0<<endl;
            return;
        }
    }
    // int cnt=0;;
    // for(int i=0;i<n;i++) if(s[i]=='1') cnt++;
    // if(cnt==n){
    //     cout<<1<<endl;
    //     //cout<<s<<" "<<1<<endl;
    //     return;
    // }
    int pair = INT_MAX;
    int ind = -1;

    for(int i = 0; i < n - 1; i++) {
        int pr;
        if(s[i+1] != '1') {
            pr = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(pr < pair) {
                pair = pr;
                ind = i;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(i != ind && i != ind + 1 && s[i] != '1') {
            sum += s[i] - '0';
        }
    }
    //cout<<s<<" " <<sum+pair<<endl;
    int ans1 = sum+pair;
    pair = INT_MAX;
    ind = -1;
    for(int i = 0; i < n - 1; i++) {
        int pr;
        pr = (s[i] - '0') * 10 + (s[i+1] - '0');
        if(pr < pair) {
            pair = pr;
            ind = i;
        }
        
    }
    int sum2=0;
    for(int i = 0; i < n; i++) {
        if(i != ind && i != ind + 1 && s[i] != '1') {
            sum2 += s[i] - '0';
        }
    }
    //cout << s << " " << pair + sum2 << endl;
    int ans2 = sum2 + pair;
    cout<<min(ans1,ans2)<<endl;
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
