#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = n; i > m; i--) {
        cout << i << " ";
    }
    for (int i = 1; i <= m; i++) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
