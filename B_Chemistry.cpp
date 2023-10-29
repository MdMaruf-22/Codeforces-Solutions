#include <iostream>
#include <vector>

using namespace std;

bool isPossibleToFormPalindrome(string s, int k) {
    int n = s.length();
    vector<int> freq(26, 0);

    for (char c : s) {
        freq[c - 'a']++;
    }

    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    if (k >= n) {
        return n % 2 == 0;
    }

    if (k >= oddCount) {
        return true;
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if (isPossibleToFormPalindrome(s, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
