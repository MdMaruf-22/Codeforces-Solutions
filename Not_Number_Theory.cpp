#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    string s;
    cin >> s; 
    queue<string> q;
    q.push(s); 
    int ans = INT_MIN,mx=INT_MIN;
    while (!q.empty()) {
        string curr = q.front();
        q.pop();
        int ind = curr.find('?');
        if (ind != string::npos) {
            for (char c = '0'; c <= '9'; ++c) {
                string nw = curr;
                nw[ind] = c;  
                q.push(nw);      
            }
        } else {
            int num = stoll(curr);  
            int set = give_number_of_one_in_binary(num);  
            if (set > mx || (set == mx && num > ans)) {
                ans = num;
                mx = set;
            }
        }
    }

    cout << ans << endl;
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
