#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(char aa, char bb) {
	return aa > bb;
}

int main() {
	string a;
	cin >> a;

	sort(a.begin(), a.end(), compare);

	cout << a;
}