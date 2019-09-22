#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

bool compare(pair<int, int> a, pair <int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else
		return a.first < b.first;
}
int main() {
	int a, b;
	scanf("%d", &n);
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		v.push_back(pair<int, int>(a, b));
	}
	sort(v.begin(), v.end(), compare);
	
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}


}