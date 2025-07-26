#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Total number of valid subsequences
    long long result = 0;
    // Length of the current arithmetic progression
    int length = 0;

    for (int i = 0; i < N; i++) {
        if (i >= 2 && A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
            length++;
        } else {
            length = 1;
        }
        result += length;
    }

    cout << result << endl;
    return 0;
}
