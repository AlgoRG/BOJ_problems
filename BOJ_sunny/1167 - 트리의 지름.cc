#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100000 + 1;
bool visited[MAX];
vector<pair<int, int>> graph[MAX];
int diameter = 0;
int farthestNode = 0;
void DFS(int node, int cost) {
	if (visited[node])
		return;
	visited[node] = true;
	if (diameter < cost) {
		diameter = cost;
		farthestNode = node;
	}
	for (int i = 0; i < graph[node].size(); i++)
		DFS(graph[node][i].first, cost + graph[node][i].second);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int v, n, m,cost;
	cin >> v;
	for (int i = 0; i < v; i++) {
		cin >> n;
		while (1) {
			cin >> m;
			if (m == -1)
				break;
			cin >> cost;
			graph[n].push_back({ m,cost });
		}
	}
	memset(visited, false, sizeof(visited));
	DFS(1, 0);
	memset(visited, false, sizeof(visited));
	diameter = 0;
	DFS(farthestNode, 0);
	cout << diameter << '\n';
	return 0;
}