#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
using namespace std;

vector<int> students;

set<int> s;
vector<int> visited; //0: init, 1: team, 2: alone

int dfs(const int student, const int n) {
	int next = students[student];

	if (s.find(next) != s.end()) return next;
	if (visited[next] == 2 || visited[next] == 1) return -1;

	s.insert(next);
	int result = dfs(next, n);

	if (result != -1 && s.find(result) != s.end()) visited[next] = 1;
	else visited[next] = 2;

	s.erase(next);

	return result;
}

int main() {
	int T;
	
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;

		students.clear();
		visited.clear();

		students.push_back(0);
		visited.push_back(0);

		cin >> n;
		for (int j = 0; j < n; j++) {
			int value;

			cin >> value;
			students.push_back(value);
			visited.push_back(0);
		}

		int count = 0;

		for (int j = 1; j <= n; j++) {
			if (visited[j] == 0) {
				s.insert(j);

				int result = dfs(j, n);
				if (j == result) visited[j] = 1;
				else visited[j] = 2;

				s.erase(j);
			}
			if (visited[j] == 2) count++;
		}

		cout << count << '\n';
	}

	return 0;
}