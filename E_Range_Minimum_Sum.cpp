#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> calculate_contributions(const vector<int>& a, int n) {
    vector<ll> left(n), right(n);
    vector<ll> contributions(n);
    stack<int> st;

    // Calculate left limits
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] > a[i]) st.pop();
        if (st.empty()) left[i] = i + 1;
        else left[i] = i - st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();

    // Calculate right limits
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) right[i] = n - i;
        else right[i] = st.top() - i;
        st.push(i);
    }

    // Calculate contributions
    for (int i = 0; i < n; ++i) {
        contributions[i] = (left[i] * right[i]) * a[i];
    }

    return contributions;
}

ll initial_sum(const vector<int>& a, const vector<ll>& contributions) {
    ll sum = 0;
    for (ll contribution : contributions) {
        sum += contribution;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> contributions = calculate_contributions(a, n);
        ll total_sum = initial_sum(a, contributions);

        vector<ll> results(n);
        for (int i = 0; i < n; ++i) {
            results[i] = total_sum - contributions[i];
        }

        for (int i = 0; i < n; ++i) {
            cout << results[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
