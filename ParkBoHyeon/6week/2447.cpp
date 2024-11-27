#include <iostream>
#include <vector>
using namespace std;

void drawStars(vector<vector<char>>& stars, int x, int y, int n) {
    if (n == 1) {
        stars[x][y] = '*';
        return;
    }
    
    int div = n / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            drawStars(stars, x + i * div, y + j * div, div);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    vector<vector<char>> stars(N, vector<char>(N, ' '));
    
    drawStars(stars, 0, 0, N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << stars[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}