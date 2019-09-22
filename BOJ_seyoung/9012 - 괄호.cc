#include <stack>
#include <iostream>
#include <string>

using namespace std;

int n;
stack<char> s;

int main() {
	scanf("%d", &n);


	for (int i = 0; i < n; i++) {
		string ps;
		cin >> ps;

		for (int j = 0; j < ps.length(); j++) {
			if (ps[j] == '(' || s.empty()) {
				s.push(ps[j]);
			}
			else if (s.top() == '(' ) {
					s.pop();
				}
		}
		if (s.empty()) {
			printf("YES\n");
		}else printf("NO\n");
		while (!s.empty()) s.pop();
	}


	return 0;
}