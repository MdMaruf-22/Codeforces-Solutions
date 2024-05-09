#include <iostream>
#include <vector>

using namespace std;

// Function to determine the winner for each test case
void winner(int t, vector<pair<int, vector<int>>> &test_cases) {
    for (int i = 0; i < t; ++i) {
        int n = test_cases[i].first;
        vector<int> piles = test_cases[i].second;

        // Check if the number of nonempty piles is odd or even
        // If odd, Alice wins since she can make all piles equal
        // If even, Bob wins since he can make all piles equal on his turn
        int count_odd = 0;
        for (int j = 0; j < n; ++j) {
            if (piles[j] % 2 != 0) {
                count_odd++;
            }
        }

        if (count_odd % 2 != 0) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
}

int main() {
    int t;
    cin >> t; // number of test cases

    vector<pair<int, vector<int>>> test_cases(t);

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n; // number of piles

        vector<int> piles(n);
        for (int j = 0; j < n; ++j) {
            cin >> piles[j]; // sizes of piles
        }

        test_cases[i] = make_pair(n, piles);
    }

    winner(t, test_cases);

    return 0;
}
