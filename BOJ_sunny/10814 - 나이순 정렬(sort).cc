#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(const pair<int, pair<int, string>> &a, const pair<int, pair<int, string>> &b) {
	if (a.second.first == b.second.first)
		return a.first < b.first;
	return a.second.first < b.second.first;
}

int main(void) {
	int n, age;
	string name;
	vector<pair<int, pair<int, string>>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		v.push_back(pair<int, pair<int, string>>(i, make_pair(age, name)));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
		cout << v[i].second.first << ' ' << v[i].second.second << '\n';
	return 0;
}