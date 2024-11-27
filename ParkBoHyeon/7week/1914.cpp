#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << from << " " << to << "\n";
        return;
    }
    hanoi(n-1, from, aux, to);
    cout << from << " " << to << "\n";
    hanoi(n-1, aux, to, from);
}

string bigPowerOfTwo(int n) {
    string result = "1";
    int carry = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < result.length(); j++) {
            int digit = (result[j] - '0') * 2 + carry;
            result[j] = (digit % 10) + '0';
            carry = digit / 10;
        }
        if (carry) {
            result += (carry + '0');
            carry = 0;
        }
    }
    for (int i = 0; i < result.length() / 2; i++) {
        swap(result[i], result[result.length() - 1 - i]);
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    string moves = bigPowerOfTwo(n);
    int lastDigit = moves.back() - '0';
    moves.back() = (lastDigit - 1) + '0';

    cout << moves << "\n";

    if (n <= 20) {
        hanoi(n, 1, 3, 2);
    }

    return 0;
}