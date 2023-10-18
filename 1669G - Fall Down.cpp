#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
char arr[100][100];

void dfs(int i, int j) {
    if (i + 1 >= n || arr[i + 1][j] == 'o' || arr[i + 1][j] == '*') return;
    swap(arr[i][j], arr[i + 1][j]);
    dfs(i + 1, j);
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '*') dfs(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
