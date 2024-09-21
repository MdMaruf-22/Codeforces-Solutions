#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int testCases;
    cin >> testCases; // Number of test cases
    for (int caseNum = 1; caseNum <= testCases; caseNum++) {
        int n;
        cin >> n; // Size of the array
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // Input array elements
        }

        // Calculate GCD of adjacent elements
        vector<int> gcdArray;
        for (int i = 0; i < n - 1; i++) {
            gcdArray.push_back(gcd(arr[i], arr[i + 1]));
        }

        int index = -1;
        for (int i = 0; i < n - 2; i++) {
            if (gcdArray[i] > gcdArray[i + 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "YES" << endl;
            continue;
        }

        // Remove one element and recalculate GCD
        vector<int> modifiedArr1, modifiedArr2, modifiedArr3;
        for (int i = 0; i < n; i++) {
            if (i != index + 1) {
                modifiedArr1.push_back(arr[i]);
            }
            if (i != index + 2) {
                modifiedArr2.push_back(arr[i]);
            }
            if (i != index) {
                modifiedArr3.push_back(arr[i]);
            }
        }

        vector<int> modifiedGcd1, modifiedGcd2, modifiedGcd3;
        for (int i = 0; i < n - 2; i++) {
            modifiedGcd1.push_back(gcd(modifiedArr1[i], modifiedArr1[i + 1]));
            modifiedGcd2.push_back(gcd(modifiedArr2[i], modifiedArr2[i + 1]));
            modifiedGcd3.push_back(gcd(modifiedArr3[i], modifiedArr3[i + 1]));
        }

        // Check if GCDs are in increasing order
        bool flag1 = true, flag2 = true, flag3 = true;
        for (int i = 0; i < n - 3; i++) {
            if (modifiedGcd1[i] > modifiedGcd1[i + 1]) {
                flag1 = false;
                break;
            }
        }
        for (int i = 0; i < n - 3; i++) {
            if (modifiedGcd2[i] > modifiedGcd2[i + 1]) {
                flag2 = false;
                break;
            }
        }
        for (int i = 0; i < n - 3; i++) {
            if (modifiedGcd3[i] > modifiedGcd3[i + 1]) {
                flag3 = false;
                break;
            }
        }

        if (!(flag1 || flag2 || flag3)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
