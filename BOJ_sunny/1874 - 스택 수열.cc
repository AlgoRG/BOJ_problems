#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

stack<int> s;
queue<int> q;
vector<char> v;

int main(void) {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	int n, x, index = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
		s.push(i + 1);
		v.push_back('+');
		while (!s.empty() && q.front() == s.top()) {
			s.pop();
			q.pop();
			v.push_back('-');
		}
	}
	if (!q.empty())
		cout << "NO" << '\n';
	else
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << '\n';
	return 0;
}