#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n;
    cin >> n;
    
    vector<string> board(n);
    vector<vector<int>> result(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '.') {
                int mines = board[i][j] - '0';
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        result[nx][ny] += mines;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '.') {
                cout << '*';
            } else if (result[i][j] >= 10) {
                cout << 'M';
            } else {
                cout << result[i][j];
            }
        }
        cout << '\n';
    }
    
    return 0;
}