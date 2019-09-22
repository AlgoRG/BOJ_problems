#include <stack>
#include <iostream>
#include <string>

using namespace std;

int n;
stack<int> s;

int main() {
	int sum = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int num;
		
		scanf("%d", &num);
		if (num == 0) {
			s.pop();
		}
		else {
			s.push(num);
		}
	}

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	printf("%d", sum);
	return 0;
}