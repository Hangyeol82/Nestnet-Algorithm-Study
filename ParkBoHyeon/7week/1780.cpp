#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;
int count_minus = 0, count_zero = 0, count_plus = 0;

void count_paper(int x, int y, int size) {
    int first = paper[x][y];
    bool same = true;
    
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != first) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }
    
    if (same) {
        if (first == -1) count_minus++;
        else if (first == 0) count_zero++;
        else count_plus++;
    } else {
        int new_size = size / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                count_paper(x + i * new_size, y + j * new_size, new_size);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    paper.resize(N, vector<int>(N));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    
    count_paper(0, 0, N);
    
    cout << count_minus << '\n' << count_zero << '\n' << count_plus << '\n';
    
    return 0;
}