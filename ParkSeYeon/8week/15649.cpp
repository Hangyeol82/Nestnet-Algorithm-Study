#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<int> suyeol;
set<int> s;

void dfs(const int select, const int N, const int M) {
	suyeol.push_back(select);
	s.insert(select);

	if (s.size() == M) {
		v.push_back(vector<int>(suyeol));

		suyeol.pop_back();
		s.erase(select);

		return;
	}

	for (int i = 1; i <= N; i++) {
		if (s.find(i) == s.end()) dfs(i, N, M);
	}

	suyeol.pop_back();
	s.erase(select);
}

int main() {
	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) dfs(i, N, M);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << ((j != v[i].size() - 1) ? ' ' : '\n');
		}
	}

	return 0;
}