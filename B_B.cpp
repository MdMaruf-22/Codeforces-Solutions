#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int val = vc[i]^vc[j];
            if(mp.count(val)){
                cout<<"Yes"<<endl;
                return;
            }
            mp[val]++;
        }
    }
    cout<<"No"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


/*

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

vector<tuple<int, int, char>> pr;

void solve() {
    int n;
    cin >> n;
    vector<int> vc(n), to(n);
    for (int i = 0; i < n; i++) cin >> vc[i];
    for (int i = 0; i < n; i++) cin >> to[i];
    sort(vc.begin(), vc.end());

    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = 0; j < n; j++) {
            if (to[i] == vc[j]) {
                pos = j;
                break;
            }
        }
        if (pos != i) {
            int start = min(i, pos);
            int end = max(i, pos) + 1;  

            if (vc[start] == to[i]) {
                pr.emplace_back(start + 1, end, 'I');  
                sort(vc.begin() + start, vc.begin() + end);
            } else {
                pr.emplace_back(start + 1, end, 'D');
                sort(vc.begin() + start, vc.begin() + end, greater<int>());
            }
        }
    }

    // Output the operations
    cout << pr.size() << endl;
    for (auto& op : pr) {
        int l, r;
        char dir;
        tie(l, r, dir) = op;
        cout << l << " " << r << " " << dir << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

*/