#include <iostream>
using namespace std;

int main() {
    int L = 7, R = 14;
    int maxSum = 0;
    int bestA = -1, bestB = -1, bestC = -1;

    // Iterate over all unique triplets (A, B, C) with A <= B <= C in the range [L, R]
    for (int A = L; A <= R; ++A) {
        for (int B = A; B <= R; ++B) { // Start B from A
            for (int C = B; C <= R; ++C) { // Start C from B
                int currentSum = (A ^ B) + (B ^ C) + (C ^ A);
                if (currentSum >= maxSum) {
                    maxSum = currentSum;
                    bestA = A;
                    bestB = B;
                    bestC = C;
                }
            }
        }
    }

    cout << "Maximum XOR sum: " << maxSum << endl;
    cout << "A: " << bestA << ", B: " << bestB << ", C: " << bestC << endl;
    cout << "All unique triplets with maximum XOR sum:\n";
    for (int A = L; A <= R; ++A) {
        for (int B = A; B <= R; ++B) {
            for (int C = B; C <= R; ++C) {
                int currentSum = (A ^ B) + (B ^ C) + (C ^ A);
                if (currentSum == maxSum) {
                    //if(B == C-1 && C==R)
                        cout << A << " " << B << " " << C << endl;
                }
            }
        }
    }

    return 0;
}
