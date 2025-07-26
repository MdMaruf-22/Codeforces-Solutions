#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void buildSegMin(vector<int>& seg, const vector<int>& arr, int idx, int left, int right) {
    if(left == right) {
        seg[idx] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    buildSegMin(seg, arr, 2*idx, left, mid);
    buildSegMin(seg, arr, 2*idx+1, mid+1, right);
    seg[idx] = min(seg[2*idx], seg[2*idx+1]);
}

int querySegMin(vector<int>& seg, int idx, int left, int right, int ql, int qr) {
    if(ql > right || qr < left)
        return LLONG_MAX;
    if(ql <= left && right <= qr)
        return seg[idx];
    int mid = (left + right) / 2;
    return min(querySegMin(seg, 2*idx, left, mid, ql, qr),
               querySegMin(seg, 2*idx+1, mid+1, right, ql, qr));
}

void buildSegMax(vector<int>& seg, const vector<int>& arr, int idx, int left, int right) {
    if(left == right) {
        seg[idx] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    buildSegMax(seg, arr, 2*idx, left, mid);
    buildSegMax(seg, arr, 2*idx+1, mid+1, right);
    seg[idx] = max(seg[2*idx], seg[2*idx+1]);
}

int querySegMax(vector<int>& seg, int idx, int left, int right, int ql, int qr) {
    if(ql > right || qr < left)
        return -LLONG_MAX;
    if(ql <= left && right <= qr)
        return seg[idx];
    int mid = (left + right) / 2;
    return max(querySegMax(seg, 2*idx, left, mid, ql, qr),
               querySegMax(seg, 2*idx+1, mid+1, right, ql, qr));
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vc(n+1);
    for (int i = 1; i <= n; i++){
        cin >> vc[i];
    }
    
    int m = k / 2;    
    if(n == k) {
        int ans = m + 1;
        for (int i = 1; i <= m; i++){
            if(2 * i <= n) {
                if(vc[2 * i] != i){
                    ans = i;
                    break;
                }
            }
        }
        cout << ans << "\n";
        return;
    }
    
    vector<int> pnt(n+2, n+1);
    pnt[n] = n+1;
    for (int i = n-1; i >= 1; i--){
        if(vc[i] == vc[i+1])
            pnt[i] = pnt[i+1];
        else
            pnt[i] = i+1;
    }
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        arr[i] = vc[i+1];
    }
    
    vector<int> segMin(4 * n, 0), segMax(4 * n, 0);
    buildSegMin(segMin, arr, 1, 0, n - 1);
    buildSegMax(segMax, arr, 1, 0, n - 1);
    
    int ans = LLONG_MAX;
    for (int j = 1; j <= m; j++){
        int L = 2 * j;
        int R = 2 * j + (n - k);
        if(R > n) R = n;
        int mn = querySegMin(segMin, 1, 0, n - 1, L - 1, R - 1);
        int mx = querySegMax(segMax, 1, 0, n - 1, L - 1, R - 1);
        int curr;
        if(mn != j || mx != j) curr = j;
        else curr = j + (pnt[L] - R);
        ans = min(ans, curr);
    }
    ans = min(ans, n - m + 1);
    
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
