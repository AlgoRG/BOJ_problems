#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n, x;
	string str;
	deque<int> d;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push_back") {
			cin >> x;
			d.push_back(x);
		}
		else if (str == "push_front") {
			cin >> x;
			d.push_front(x);
		}
		else if (str == "front") {
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.front() << '\n';
		}
		else if (str == "back") {
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.back() << '\n';
		}
		else if (str == "size") {
			cout << d.size() << '\n';
		}
		else if (str == "empty") {
			if (d.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "pop_front") {
			if (d.empty())
				cout << -1 << '\n';
			else {
				int tmp = d.front();
				d.pop_front();
				cout << tmp << '\n';
			}
		}
		else if (str == "pop_back") {
			if (d.empty())
				cout << -1 << '\n';
			else {
				int tmp = d.back();
				d.pop_back();
				cout << tmp << '\n';
			}
		}
	}
	return 0;
}