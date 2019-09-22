#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector <pair<int, int>> num(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i].first >> num[i].second;
	}

	sort(num.begin(), num.end());

	for (int i = 0; i < n; i++){
		cout << num[i].first << " " << num[i].second << "\n";
	}

	return 0;
}