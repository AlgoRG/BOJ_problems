#include <queue>
#include <iostream>
#include <string>

using namespace std;

int n;
queue<int> q;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;

		if (command == "push") {
			int num;
			cin >> num;

			q.push(num);
		}
		else if (command == "pop") {
			if (!q.empty()) {
				printf("%d\n", q.front());
				q.pop();
			}
			else
				printf("-1\n");
		}
		else if (command == "size") {
			printf("%d\n", q.size());
		}
		else if (command == "empty") {
			printf("%d\n", q.empty());
		}
		else if (command == "front") {
			if (!q.empty()) {
				printf("%d\n", q.front());
			}
			else
				printf("-1\n");
		}
		else if (command == "back") {
			if (!q.empty()) {
				printf("%d\n", q.back());
			}
			else
				printf("-1\n");
		}
	}
	return 0;
}