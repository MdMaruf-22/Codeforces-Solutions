#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

map<pair<int, int>, bool> minMemo, maxMemo;


bool findMin(int pos, int m, int s, string &minNum) {
    if (pos == m) {
        return s == 0;
    }

    if (minMemo.find({pos, s}) != minMemo.end()) {
        return minMemo[{pos, s}];
    }

    for (int digit = (pos == 0) ? 1 : 0; digit <= 9; digit++) {
        if (s - digit >= 0 && s - digit <= 9 * (m - pos - 1)) {
            minNum[pos] = digit + '0';
            if (findMin(pos + 1, m, s - digit, minNum)) {
                return minMemo[{pos, s}] = true;
            }
        }
    }
    return minMemo[{pos, s}] = false;
}

bool findMax(int pos, int m, int s, string &maxNum) {
    if (pos == m) {
        return s == 0;
    }

    if (maxMemo.find({pos, s}) != maxMemo.end()) {
        return maxMemo[{pos, s}];
    }

    for (int digit = 9; digit >= 0; digit--) {
        if (s - digit >= 0 && s - digit <= 9 * (m - pos - 1)) {
            maxNum[pos] = digit + '0';
            if (findMax(pos + 1, m, s - digit, maxNum)) {
                return maxMemo[{pos, s}] = true;
            }
        }
    }
    return maxMemo[{pos, s}] = false;
}


void solve() {
    int m, s;
    cin >> m >> s;

    if (s == 0) {
        if (m == 1) {
            cout << "0 0\n"; 
        } else {
            cout << "-1 -1\n"; 
        }
        return;
    }
    if (s > 9 * m) {
        cout << "-1 -1\n";
        return;
    }

    string minNum(m, '0');
    string maxNum(m, '0');

    findMin(0, m, s, minNum);
    findMax(0, m, s, maxNum);

    cout << minNum << " " << maxNum << "\n";
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t= 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
