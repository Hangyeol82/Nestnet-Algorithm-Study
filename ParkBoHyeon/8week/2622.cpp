#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    for (int x = 1; x <= n/3; x++) {
        for (int y = x; y <= (n-x)/2; y++) {
            int z = n - x - y;
            if (y <= z && x + y > z) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}