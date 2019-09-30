#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000 + 1;
int parent[MAX];
bool visited[MAX];
vector<int> tree[MAX];
void findp(int num) {
	visited[num] = true;
	for (int i = 0; i < tree[num].size(); i++) {
		int next = tree[num][i];
		if (!visited[next]) {
			parent[next] = num;
			findp(next);
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x, y;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	findp(1);
	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
	return 0;
}