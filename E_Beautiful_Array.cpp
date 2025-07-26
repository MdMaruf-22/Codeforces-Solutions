#include <bits/stdc++.h>
using namespace std;

bool isValid(int n, int a, int b, vector<int>& arr) {
    arr.clear();
    arr.resize(n, b); 

    int totalSum = a * n;
    int currentSum = b * n;

    int diff = totalSum - currentSum;

    for (int i = 0; i < n; i++) {
        if (diff == 0) break;

        int change = min(1000000 - b, diff); 
        arr[i] += change;
        diff -= change;
    }

    if (diff != 0) return false; 

    sort(arr.begin(), arr.end());
    double median = (n % 2 == 1) ? arr[n / 2] : (arr[n / 2 - 1] + arr[n / 2]) / 2.0;

    return median == b;
}

int main() {
    int a, b;
    cin >> a >> b;

    int left = 1, right = 1000, bestN = -1;
    vector<int> bestArray;

    while (left <= right) {
        int mid = (left + right) / 2;
        vector<int> tempArr;

        if (isValid(mid, a, b, tempArr)) {
            bestN = mid;
            bestArray = tempArr;
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }


    cout << bestN << endl;
    for (int num : bestArray) cout << num << " ";
    cout << endl;

    return 0;
}
