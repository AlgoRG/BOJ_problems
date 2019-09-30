#include <iostream>
using namespace std;
int p[201];
int find(int a) {
	if (p[a] == a)	return a;
	return p[a] = find(p[a]);
}
void union_(int a, int b) {
	a = find(a); 
	b = find(b);
	p[a] = b;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> x;
			if (x)
				union_(i, j);
		}
	}
	cin >> x;
	y = find(x);
	for (int i = 1; i < m; ++i) {
		cin >> x;
		if (y != find(x)) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}