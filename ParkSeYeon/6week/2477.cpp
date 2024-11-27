#include <iostream>
#include <vector>
using namespace std;

string get_blank(const int size) {
	string str;

	for (int i = 0; i < size; i++) {
		str += " ";
	}
	return str;
}

vector<string> star(const int count) {
	if (count == 1) return { "*" };

	vector<string> v = star(count / 3);
	vector<string> v2;

	for (auto str : v) {
		v2.push_back(str + str + str);
	}
	for (auto str : v) {
		v2.push_back(str + get_blank(count / 3) + str);
	}
	for (auto str : v) {
		v2.push_back(str + str + str);
	}
	
	return v2;
}

int main() {
	int N;

	cin >> N;
	vector<string> v = star(N);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}