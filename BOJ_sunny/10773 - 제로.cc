#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	int n, x, sum = 0;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0)
			s.pop();
		else
			s.push(x);
	}
	while(!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
	return 0;
}