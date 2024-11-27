#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
int graph[MAX];
int visited[MAX];
int finished[MAX];
int cycle_size;

void dfs(int node, int id) {
    visited[node] = id;
    int next = graph[node];
    
    if (visited[next] == 0) {
        dfs(next, id);
    } else if (finished[next] == 0) {
        for (int i = next; i != node; i = graph[i]) {
            cycle_size++;
        }
        cycle_size++;
    }
    
    finished[node] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            cin >> graph[i];
            visited[i] = finished[i] = 0;
        }
        
        cycle_size = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i, i);
            }
        }
        
        cout << n - cycle_size << '\n';
    }
    
    return 0;
}