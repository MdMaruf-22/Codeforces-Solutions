#include <iostream>
#include <string>

using namespace std;

bool chk(const string &number, string &result) {
    int len = number.size();

    // Check for single digits
    for (int i = 0; i < len; i++) {
        if (number[i] == '0' || number[i] == '8') {
            result = string(1, number[i]);
            return true;
        }
    }

    // Check for two digits
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int num = (number[i] - '0') * 10 + (number[j] - '0');
            if (num % 8 == 0) {
                result = to_string(num);
                return true;
            }
        }
    }

    // Check for three digits
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            for (int k = j + 1; k < len; k++) {
                int num = (number[i] - '0') * 100 + (number[j] - '0') * 10 + (number[k] - '0');
                if (num % 8 == 0) {
                    result = to_string(num);
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    string s;
    cin >> s;

    string result;
    if (chk(s, result)) {
        cout << "YES" << endl;
        cout << result << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
