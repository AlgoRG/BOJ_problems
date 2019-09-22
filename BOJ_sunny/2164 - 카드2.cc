#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int n, tmp;
	queue<int> q;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		q.pop();
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	cout << q.front();
	return 0;
}