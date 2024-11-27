#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> sequence;
vector<bool> used;

void backtrack(int depth) {
    if (depth == M) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            used[i] = true;
            sequence.push_back(i);
            backtrack(depth + 1);
            sequence.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    used.resize(N + 1, false);

    backtrack(0);

    return 0;
}