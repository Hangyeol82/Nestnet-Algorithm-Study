#include <iostream>
#include <vector>

using namespace std;

int N, answer = 0;
vector<int> col;

bool is_valid(int row) {
    for (int i = 0; i < row; i++) {
        if (col[i] == col[row] || abs(col[row] - col[i]) == row - i) {
            return false;
        }
    }
    return true;
}

void solve(int row) {
    if (row == N) {
        answer++;
        return;
    }
    
    for (int i = 0; i < N; i++) {
        col[row] = i;
        if (is_valid(row)) {
            solve(row + 1);
        }
    }
}

int main() {
    cin >> N;
    col.resize(N);
    
    solve(0);
    
    cout << answer << endl;
    
    return 0;
}