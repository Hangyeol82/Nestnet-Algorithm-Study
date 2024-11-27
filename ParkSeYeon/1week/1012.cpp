#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void investigate_near_lettuces(const int X_, const int Y_, const int M, const int N, vector<vector<int>>& v) {
    queue<pair<int, int>> q;

    q.push({ X_, Y_ });
    v[Y_][X_] = 2;

    while (!q.empty()) {
        auto p = q.front();
        int x = p.first;
        int y = p.second;

        q.pop();

        if (x + 1 < M && v[y][x + 1] == 1) {
            q.push({ x + 1, y });
            v[y][x + 1] = 2;
        }
        if (x - 1 >= 0 && v[y][x - 1] == 1) {
            q.push({ x - 1, y });
            v[y][x - 1] = 2;
        }
        if (y + 1 < N && v[y + 1][x] == 1) {
            q.push({ x, y + 1 });
            v[y + 1][x] = 2;
        }
        if (y - 1 >= 0 && v[y - 1][x] == 1) {
            q.push({ x, y - 1 });
            v[y - 1][x] = 2;
        }
    }
}

bool is_ended(const vector<vector<int>>& v, queue<pair<int, int>>& pos, pair<int, int>& pos_returned) {
    while (!pos.empty()) {
        auto p = pos.front();
        pos.pop();

        if (v[p.second][p.first] == 1) {
            pos_returned = p;
            return false;
        }
    }

    return true;
}

int main() {
    int T;
    vector<vector<int>> v; //0: unavailable, 1: available, but not visited, 2: available and already visited
    queue<pair<int, int>> pos;

    cin >> T;

    for (int i = 0; i < T; i++) {
        int M; //width
        int N; //height
        int K; //lettuce position's count
        int count = 0;

        cin >> M >> N >> K;

        v.clear();
        v.assign(N, vector<int>(M, 0));
        while (!pos.empty()) pos.pop();

        for (int j = 0; j < K; j++) {
            int X, Y;
            
            cin >> X >> Y;
            v[Y][X] = 1;
            pos.push({ X, Y });
        }

        auto p = pos.front();
        pos.pop();

        do {
            investigate_near_lettuces(p.first, p.second, M, N, v);
            count++;
        } while (!is_ended(v, pos, p));

        cout << count << '\n';
    }
    return 0;
}

